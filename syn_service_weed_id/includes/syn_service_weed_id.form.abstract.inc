<?php

/**
 * @file
 * Contains abstract class Service Weed ID with common funcitonalities.
 */

/**
 * Class SynServiceWeedIdFormAbstract.
 */
abstract class SynServiceWeedIdFormAbstract {

  /**
   * The current service node entity metadata wrapper.
   *
   * @var object
   */
  protected $serviceWrapper;

  /**
   * Class constructor.
   */
  final public function __construct() {
    if (($node = menu_get_object()) && $node->type === 'service') {
      $this->serviceWrapper = entity_metadata_wrapper('node', $node);
    }
  }

  /**
   * Form build handler for the selected step.
   */
  abstract protected function doBuild($form, &$form_state);

  /**
   * Called in each child implementations after form is submited.
   *
   * The child classes can change the form state or the form if needed.
   */
  abstract protected function postBuild(&$form, &$form_state, $executed_class);

  /**
   * Form submit handler for the selected step.
   */
  abstract protected function doSubmit(&$form, &$form_state);

  /**
   * Called in each child implementations after form is submited.
   *
   * The child classes can change the form state or the form if needed.
   */
  abstract protected function postSubmit(&$form, &$form_state, $executed_class);

  /**
   * Form build handler.
   *
   * Called from the main form build function. Based on the child class calls
   * the class build function. After that calls other class post build
   * functions for modifying the form or form state if needed.
   */
  final public function build($form, &$form_state) {
    // Call the form build handler.
    $form = $this->doBuild($form, $form_state);

    // Loop threw all class definitions and call the post build form handler.
    foreach (_syn_service_weed_id_form_get_class($form_state, NULL, TRUE) as $form_class) {
      $form_class->postBuild($form, $form_state, get_class($this));
    }

    return $form;
  }

  /**
   * Form submit handler.
   *
   * Called from the main form submit function. Based on the child class calls
   * the class submit function. After that calls other class post submit
   * functions for modifying the form  or form state if needed.
   */
  final public function submit(&$form, &$form_state) {
    // Call the form submit handler.
    $this->doSubmit($form, $form_state);

    // Loop threw all class definitions and call the post submit form handler.
    foreach (_syn_service_weed_id_form_get_class($form_state, NULL, TRUE) as $form_class) {
      $form_class->postSubmit($form, $form_state, get_class($this));
    }
  }

  /**
   * Function returning default ajax configurations.
   *
   * @return array
   *   Array of ajax configurations.
   */
  protected function defaultAjaxConf() {
    return array(
      'callback' => 'syn_service_weed_id_form_ajax',
      'wrapper' => 'weed-id-form',
      'method' => 'replace',
      'effect' => 'none',
    );
  }

  /**
   * Calculates the founded targets based on the criteria selection.
   *
   * @param array $form_state
   *   The form state array.
   */
  protected function calculateSelectionResults(array &$form_state) {
    // Instantiate the language.
    global $language;

    // Reset the previous results.
    $form_state['weed']['criteria_selection']['100_percent'] = array();
    $form_state['weed']['criteria_selection']['75_percent'] = array();

    // Store selected target nid as key and the mathching count as value.
    $selected_targets = array();
    // Get the count of selected criterias.
    $selected_criterias = count($form_state['weed']['criteria_selection']['criterias']);
    // Loop threw all selected criterias and get the targets.
    foreach ($form_state['weed']['criteria_selection']['criterias'] as $criteria_tid) {
      // Instantiate the grouped target current criteria array.
      $grouped_targets[$criteria_tid] = array();
      // Instantiate the criteria metadata wrapper.
      $criteria_wrapper = entity_metadata_wrapper('taxonomy_term', $criteria_tid);
      // Loop threw all the weed data.
      foreach ($criteria_wrapper->field_weed_data->getIterator() as $weed_data) {
        if (
        // If the weed type is as the currently selected weed type and we
        // have targets selected add them to the grouped targets.
            ($weed_data->field_weed_type->value() === $form_state['weed']['weed_type']) &&
            ($targets = $weed_data->field_weed_targets->value())
        ) {
          foreach ($targets as $target) {
            // Get the translated target node.
            if (
                !in_array($target->language, array(LANGUAGE_NONE, $language->language)) &&
                module_exists('translation') &&
                ($translations = module_invoke('translation', 'node_get_translations', $target->nid)) &&
                isset($translations[$language->language])
            ) {
              $target = $translations[$language->language];
            }
            // Continue if we have target from another language.
            if (!in_array($target->language, array(LANGUAGE_NONE, $language->language))) {
              continue;
            }
            // Continue if we have not published target.
            if (!$target->status) {
              continue;
            }
            // Instantiate the counter.
            if (!isset($selected_targets[$target->nid])) {
              $selected_targets[$target->nid] = 0;
            }
            // Increment the counter.
            $selected_targets[$target->nid]++;
          }
        }
      }
    }

    // Loop threw all selected targets.
    foreach ($selected_targets as $selected_target_nid => $match_count) {
      // If the selected target match count is equal to the selected criterias
      // then we have 100% match.
      if ($match_count === $selected_criterias) {
        $form_state['weed']['criteria_selection']['100_percent'][$selected_target_nid] = $selected_target_nid;
      }
      // If the selected target match count is equal to 3/4 from the selected
      // criterias then we have 75% match.
      if ($match_count == ($selected_criterias * 0.75)) {
        $form_state['weed']['criteria_selection']['75_percent'][$selected_target_nid] = $selected_target_nid;
      }
    }
  }

}
