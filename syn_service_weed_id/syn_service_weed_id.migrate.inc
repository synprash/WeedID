<?php

 /**
  * @file
  * Echo "I m in migrate inc";exit;.
  */

/**
 * @file
 * Contains migration definition.
 */

/**
 * Implements hook_migrate_api().
 */
function syn_service_weed_id_migrate_api() {
  return array(
    'api' => 2,
    'groups' => array(
      'SynService' => array(
        'title' => t('Syngenta Weed ID migrations'),
      ),
    ),
    'migrations' => array(
      'SynService_WeedId' => array(
        'class_name' => 'SynServiceWeedIdImportCriteria',
        'group_name' => 'SynService',
        'label' => t('Weed ID criteria taxonomy import'),
      ),
    ),
  );
}
