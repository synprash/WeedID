<?php

/**
 * @file
 * Contents  Service Weed ID Criteria Import class.
 */

/**
 * Service Weed ID Criteria taxonomy migration class.
 */
class SynServiceWeedIdImportCriteria extends SynImportsTaxonomy {

  /**
   * The vocabulary machine name of the currently imported taxonomies.
   *
   * @var string
   */
  private $vocabularityMachineName;

  private $weedTypeKeys = array();

  /**
   * Class constructor.
   */
  public function __construct($arguments) {
    $this->vocabularityMachineName = 'service_weed_id_criteria';

    parent::__construct($arguments + array(
      'class_machine_name' => 'SynServiceWeedIdImportCriteria',
      'group_name' => 'SynService',
      'machine_name' => 'SynService_WeedIdCriteria',
      'taxonomy_vocabulary' => $this->vocabularityMachineName,
    ));

    $this->source = new MigrateSourceCSV($arguments['csv_filename'], array(
      array('id', 'External id'),
      array('language', 'Language'),
       array('term_name', 'Name'),
      array('description', 'Description'),
      array('picture', 'Image'),
      array('field_weed_id_criteria_type', 'Type'),
      array('field_weeds_data', 'Weed data'),
    ), array(
      'delimiter' => ';',
      'header_rows' => TRUE,
    )
    );

    $this->destination = new MigrateDestinationTerm($this->vocabularityMachineName);

    $fields = array_keys(field_info_instances('taxonomy_term', $this->vocabularityMachineName));

    if (!empty($fields)) {
      if (in_array('field_weed_id_criteria_type', $fields)) {
        $this->addFieldMapping('field_weed_id_criteria_type', 'field_weed_id_criteria_type');
      }
      if (in_array('field_weeds_data', $fields)) {
        $this->addFieldMapping('field_weeds_data', 'field_weed_data');
      }
      if (in_array('field_term_image', $fields)) {
        $this->addFieldMapping('field_term_image', 'picture');
      }
    }

  }

  /**
   * Prepares the row before processed from the migrator.
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $transaction = db_transaction();
    try {

      // Term image is available, store it.
      if (!empty($row->picture) &&
          isset($this->getFieldMappings()['field_term_image'])) {

        $file = $this->storeFile($row->picture);
        $row->picture = class_exists('MigrateMediaFieldHandler') ? $file->uri : $file->fid;

      }
    }
    catch (Exception $exception) {
      $transaction->rollback();
      drupal_set_message(t('prepareRow - Storefile : Error by importing row !row: @message', array(
        '!row' => $row->csvrownum,
        '@message' => $exception->getMessage(),
      )), 'error');
      watchdog_exception('syngenta_migrate', $exception);
      return FALSE;
    }

    try {
      // ICriteria Type available , store it.
      if (!empty($row->field_weed_id_criteria_type)) {
        $ctype_arr = explode('|', $row->field_weed_id_criteria_type);

        if (count($ctype_arr) == 2) {
          // @todo check Type & group taxonomy exists. if no will create on the fly.

          $matched_terms_cgroup = taxonomy_get_term_by_name($ctype_arr[0], 'service_weed_id_criteria_group');
          // If criterai group not exist then create it first.
          if (empty($matched_terms_cgroup)) {
            $vocab = taxonomy_vocabulary_machine_name_load('service_weed_id_criteria_group');
            $term1 = (object) array(
              'name' => $ctype_arr[0],
              'description' => $ctype_arr[0],
              'vid' => $vocab->vid,
            );
            taxonomy_term_save($term1);
          }
          // Load Group term again.
          $matched_terms_cgroup = taxonomy_get_term_by_name($ctype_arr[0], 'service_weed_id_criteria_group');
          $cgroup_term_key = key($matched_terms_cgroup);
          $matched_terms_ctype = taxonomy_get_term_by_name($ctype_arr[1], 'service_weed_id_criteria_type');

          $ctype_term_key = 0;
          if (!empty($matched_terms_ctype)) {

            foreach ($matched_terms_ctype as $key => $ctrow) {

              if (!empty($ctrow->field_weed_id_group['und'][0]['target_id']) &&
                      $ctrow->field_weed_id_group['und'][0]['target_id'] == $cgroup_term_key) {
                // This means that Group & type both are already exists.
                $ctype_term_key = $key;
                break;
              }
            }
          }

          if ($ctype_term_key == 0) {
            // If critera type not exist then create it first.
            $vocab = taxonomy_vocabulary_machine_name_load('service_weed_id_criteria_type');
            $term1 = (object) array(
              'name' => $ctype_arr[1],
              'description' => $ctype_arr[1],
              'vid' => $vocab->vid,
              'field_weed_id_group' => array('und' => array(array('target_id' => $cgroup_term_key))),
            );
            taxonomy_term_save($term1);
            // Load Type term again.
            $matched_terms_ctype = taxonomy_get_term_by_name($ctype_arr[1], 'service_weed_id_criteria_type');
            $ctype_term_key = key($matched_terms_ctype);
          }

          $row->field_weed_id_criteria_type = $ctype_term_key;

        }
      }

    }
    catch (Exception $exception) {
      $transaction->rollback();
      drupal_set_message(t('prepareRow - save Group/Type : Error by importing row !row: @message', array(
        '!row' => $row->csvrownum,
        '@message' => $exception->getMessage(),
      )), 'error');
      watchdog_exception('syngenta_migrate', $exception);
      return FALSE;
    }

    return TRUE;
  }

  /**
   * Save field collections .
   */
  public function prepare($entity, stdClass $row) {

    $transaction = db_transaction();
    try {
      $this->saveWeedData($entity, $row);
    }
    catch (Exception $exception) {
      $transaction->rollback();
      drupal_set_message(t('prepare - saveWeedData : Error by importing row !row: @message', array(
        '!row' => $row->csvrownum,
        '@message' => $exception->getMessage(),
      )), 'error');
      watchdog_exception('syngenta_migrate', $exception);
      return FALSE;
    }
    return TRUE;
  }

  /**
   * Save Weed data .
   */
  private function saveWeedData($entity, stdClass $row) {
    // Extract the field collection data.
    $data = $this->extractFieldCollectionData($row, 'field_weeds_data');

    try {
      // Remove old field collection data.
      $this->removeOldFieldCollectionData($entity, 'field_weeds_data');
    }
    catch (Exception $exception) {
      $transaction->rollback();
      drupal_set_message(t('saveWeedData - remove filed collection : Error while importing row !row: @message', array(
        '!row' => $row->csvrownum,
        '@message' => $exception->getMessage(),
      )), 'error');
      watchdog_exception('syngenta_migrate', $exception);
      return FALSE;
    }

    if (empty($data)) {
      drupal_set_message(t('saveWeedData - field_weeds_data empty : Error while importing row !row: @message', array(
        '!row' => $row->csvrownum,
        '@message' => 'field_weeds_data is not present',
      )), 'error');
      return FALSE;
    }
    $service_weed_types = syn_service_weed_id_get_weed_types();

    $missing_types = array();
    $missing_targets = array();
    // Store the new data.
    foreach ($data as $key => $single_data) {
      $field_collection_item = entity_create('field_collection_item', array('field_name' => 'field_weed_data'));
      $field_collection_item->setHostEntity('taxonomy_term', $entity);
      // Validate the weed type first.
      $weed_type_key = array_search($single_data[0], $service_weed_types);
      if (!empty($weed_type_key)) {
        $this->weedTypeKeys[] = array_search($single_data[0], $service_weed_types);
        $field_collection_item->field_weed_type[LANGUAGE_NONE][]['value'] = $weed_type_key;
      }
      else {
        // Skip the next part.
        $missing_types[] = $single_data[0];
        continue;
      }
      unset($single_data[0]);
      reset($single_data);

      $targets_match = 0;
      foreach ($single_data as $target) {
          //What if there are multiple targets with same name. We will consider its EPPO code also.
          $target_meta = explode('_',$target);
          if(!empty($target_meta) && count($target_meta)==2){
              $target_node_result = (new EntityFieldQuery())
                  ->entityCondition('entity_type', 'node')
                  ->propertyCondition('title', $target_meta[0])
                  ->fieldCondition('field_target_code_eppo','value',$target_meta[1],'=')
                  ->execute();
          }else {
              $target_node_result = (new EntityFieldQuery())
                  ->entityCondition('entity_type', 'node')
                  ->propertyCondition('title', $target)
                  ->execute();
          }

        if (!empty($target_node_result['node']) && count($target_node_result['node']) == 1 ) {
          $targets_match = 1;
          // key($matched_target);
          $field_collection_item->field_weed_targets[LANGUAGE_NONE][]['target_id'] = key($target_node_result['node']);
        }
        else {
          $missing_targets[] = $target;
        }
      }
      if ($targets_match == 1) {
        $field_collection_item->save(TRUE);
      }

    }
    if (!empty($missing_types)) {
      drupal_set_message(t('saveWeedData - Weed Types Data not found :  by importing row !row: @message', array(
        '!row' => $row->csvrownum,
        '@message' => implode(',', $missing_types),
      )), 'warning');
    }
    if (!empty($missing_targets)) {
      drupal_set_message(t('saveWeedData - Targets not found or multiple targets found with same name  :  by importing row !row: @message', array(
        '!row' => $row->csvrownum,
        '@message' => implode(',', $missing_targets),
      )), 'warning');
    }

    return TRUE;
  }

  /**
   * On updating row we delete the old data stored in the field collections.
   *
   * @param object $node
   *   The node instance.
   * @param string $field_collection_id
   *   The name of the field collection.
   */
  protected function removeOldFieldCollectionData($node, $field_collection_id) {
    if (!empty($node->nid)) {
      $node->$field_collection_id = array();
      foreach ((array) field_get_items('node', $node, $field_collection_id) as $field_collection_data) {
        if (!empty($field_collection_data['value'])) {
          entity_delete('field_collection_item', $field_collection_data['value']);
        }
      }
    }
  }

  /**
   * On updating row we fetch the field collection data.
   *
   * Each field collection item is separated with '|' and the components inside
   * are separated with '","'.
   *
   * @param object $row
   *   The row being migrated instance.
   * @param string $field_collection_id
   *   The name of the field collection.
   *
   * @return array
   *   Array of the extracted field colelction data.
   */
  protected function extractFieldCollectionData($row, $field_collection_id) {
    $data = array();

    if (!empty($row->$field_collection_id)) {
      $data = explode('|', $row->$field_collection_id);

      foreach ($data as $k => $single_data) {
        $data[$k] = array_map(function ($column) {
          return trim(trim($column), '"');
        }, explode(',', $single_data));
      }
    }

    return $data;
  }

}
