<?php

/**
 * @file
 * Contains Service Weed ID form step two.
 */

/**
 * Class SynServiceWeedIdFormStepTwo.
 */
class SynServiceWeedIdFormStepTwo extends SynServiceWeedIdFormAbstract {

  /**
   * {@inheritdoc}
   */
  protected function doBuild($form, &$form_state) {
    // Populates selection data used in step 2.
    $this->prepopulateSelectionData($form_state);

    // Set step two container.
    $form['step_two'] = array(
      '#type' => 'container',
      '#id' => 'step-two',
      '#weight' => 20,
      '#attributes' => array(
        'class' => array('weedid-step-two'),
      ),
    );

    // Set the step two title.
    $form['step_two']['title'] = array(
      '#type' => 'markup',
      '#markup' => t('<h2 class="green _20 bigger"><b>Step 2:</b> Your selection</h2>'),
    );

    // Build the filter criteria selection.
    $this->buildCriteriaSelection($form, $form_state);

    // Build the filter criteria buttons.
    $this->buildCriteriaFilters($form, $form_state);

    // Build the filter criteria results view.
    $this->buildCriteriaResults($form, $form_state);

    // Return the form.
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  protected function postBuild(&$form, &$form_state, $executed_class) {

  }

  /**
   * {@inheritdoc}
   */
  protected function doSubmit(&$form, &$form_state) {
    // Get the triggering element.
    $triggering_element = str_replace('step_2__', '', $form_state['triggering_element']['#name']);

    switch (TRUE) {
      // Filtering on criteria type.
      case strpos($triggering_element, 'filter_criteria__') === 0:
        $selected_type = taxonomy_term_load(str_replace('filter_criteria__', '', $triggering_element));
        $selected_type_wrapper = entity_metadata_wrapper('taxonomy_term', $selected_type);
        $form_state['weed']['filter_criteria_type'] = $selected_type_wrapper->tid->value();
        $form_state['weed']['filter_criteria_group'] = $selected_type_wrapper->field_weed_id_group->value()->tid;
        break;

      // Add criteria.
      case $triggering_element === 'add_criteria':
        if (
            !empty($form_state['values']['added_criteria']) &&
            is_numeric($form_state['values']['added_criteria']) &&
            ($taxonomy = taxonomy_term_load($form_state['values']['added_criteria'])) &&
            $taxonomy->vocabulary_machine_name === 'service_weed_id_criteria'
        ) {
          $form_state['weed']['criteria_selection']['criterias'][$form_state['values']['added_criteria']] = $form_state['values']['added_criteria'];
          $this->calculateSelectionResults($form_state);
        }
        break;

      // Remove criteria.
      case $triggering_element === 'remove_criteria':
        if (
            !empty($form_state['values']['removed_criteria']) &&
            is_numeric($form_state['values']['removed_criteria']) &&
            ($taxonomy = taxonomy_term_load($form_state['values']['removed_criteria'])) &&
            $taxonomy->vocabulary_machine_name === 'service_weed_id_criteria' &&
            in_array($form_state['values']['removed_criteria'], $form_state['weed']['criteria_selection']['criterias'])
        ) {
          unset($form_state['weed']['criteria_selection']['criterias'][$form_state['values']['removed_criteria']]);
          $this->calculateSelectionResults($form_state);
        }
        break;

      // Clear all selected criterias.
      case $triggering_element === 'clear_selection':
        $this->prepopulateSelectionData($form_state, TRUE);
        $this->calculateSelectionResults($form_state);
        break;

      // Show results.
      case $triggering_element === 'show_results':
        // Change the form step.
        $form_state['weed']['step'] = 3;
        // Scroll the browser screen to step 3.
        drupal_add_js(
          array('syn_service_weed_id' => array('scroll' => '#step-three')),
          array('type' => 'setting')
        );
        break;

      default:
    }

    $form_state['rebuild'] = TRUE;
  }

  /**
   * {@inheritdoc}
   */
  protected function postSubmit(&$form, &$form_state, $executed_class) {
    // If the user executes again step one the filter criteria type, group and
    // criteria selections are reset.
    if ($executed_class === 'SynServiceWeedIdFormStepOne') {
      if (isset($form_state['weed']['filter_criteria_type'])) {
        unset($form_state['weed']['filter_criteria_type']);
      }
      if (isset($form_state['weed']['filter_criteria_group'])) {
        unset($form_state['weed']['filter_criteria_group']);
      }
      if (isset($form_state['weed']['criteria_selection'])) {
        unset($form_state['weed']['criteria_selection']);
      }
    }
  }

  /**
   * Populates selection data used in step 2.
   *
   * @param array $form_state
   *   The form state array.
   * @param bool $reset
   *   Flag if we should reset the data.
   */
  private function prepopulateSelectionData(array &$form_state, $reset = FALSE) {
    // Populate empty criteria selection if nothing selected.
    if (empty($form_state['weed']['criteria_selection']) || $reset) {
      $form_state['weed']['criteria_selection'] = array(
        'criterias' => array(),
        '100_percent' => array(),
        '75_percent' => array(),
      );
    }
  }

  /**
   * Build the filter criteria selection.
   */
  private function buildCriteriaSelection(&$form, &$form_state) {
    // Create a container for the selected criterias.
    $form['step_two']['criteria_results'] = array(
      '#type' => 'container',
      '#id' => 'criteria-results',
      '#weight' => 10,
      '#attributes' => array(
        'class' => array('lightgreen'),
      ),
    );

    // Create the container for showing the selected criterias and the results.
    $form['step_two']['criteria_results']['row_one'] = array(
      '#type' => 'container',
      '#id' => 'row-one',
      '#weight' => 10,
    );
    // Show the criteria selection.
    $form['step_two']['criteria_results']['row_one']['selection'] = array(
      '#type' => 'container',
      '#id' => 'row-one-selection',
    );
    // Show the selected criterias.
    $form['step_two']['criteria_results']['row_one']['selection']['selected_criterias'] = array(
      '#type' => 'markup',
      '#markup' => call_user_func_array('views_embed_view', array(
        'service_weed_id_criteria',
        'block_2',
        implode('+', $form_state['weed']['criteria_selection']['criterias']),
      )),
    );
    // Add the empty blocks.
    $empty_blocks = 5 - count($form_state['weed']['criteria_selection']['criterias']);
    while ($empty_blocks > 0) {
      $form['step_two']['criteria_results']['row_one']['selection']['empty_block_' . $empty_blocks] = array(
        '#type' => 'container',
        '#id' => 'empty-block-' . $empty_blocks,
        '#attributes' => array(
          'class' => array('criteria-empty-block'),
        ),
      );
      $empty_blocks--;
    }

    // Translate your results header.
    $your_results = t('Your result');
    // Translate 100% match strings.
    $match_100_percent = t('<span><strong>@match_count</strong></span><span class="colon"> : </span><span class="weed_match"> weeds match</span><span class="qnty"><strong>100%</strong></span>', array(
      '@match_count' => count($form_state['weed']['criteria_selection']['100_percent']),
    ));
    // Translate 75% match strings.
    $match_75_percent = t('<span><strong>@match_count</strong></span><span class="colon"> : </span><span class="weed_match"> weeds match </span><span class="qnty"><strong>75%</strong><span>', array(
      '@match_count' => count($form_state['weed']['criteria_selection']['75_percent']),
    ));
    // Create a markup for the your results html.
    $results_markup = <<<MARKUP
      <div class="left-buttons">
        <h2 class="orange_h2">$your_results</h2>
      </div>
      <div class="right-buttons">
        <h2 class="green result_info">$match_100_percent</h2>
        <h2 class="green result2_info">$match_75_percent</h2>
      </div>
MARKUP;

    // Show the results.
    $form['step_two']['criteria_results']['row_one']['results'] = array(
      '#type' => 'container',
      '#id' => 'row-one-results',
      'results' => array(
        '#type' => 'markup',
        '#markup' => $results_markup,
      ),
    );

    // Add hidden field for storing the removed criteria.
    // On clicking on remove sign from the criteria view mode javascript is
    // triggering the populating of the field.
    $form['step_two']['criteria_results']['row_one']['removed_criteria'] = array(
      '#type' => 'hidden',
      '#name' => 'removed_criteria',
    );
    // Add hidden submit handler for removing criteria.
    // On clicking on remove sign from the criteria view mode javascript is
    // triggering the button submission.
    $form['step_two']['criteria_results']['row_one']['step_2__remove_criteria'] = array(
      '#type' => 'submit',
      '#name' => 'step_2__remove_criteria',
      '#ajax' => $this->defaultAjaxConf(),
      '#attributes' => array(
        'class' => array('element-hidden'),
      ),
    );

    // Create the container for the clear selection and show results buttons.
    $form['step_two']['criteria_results']['row_two'] = array(
      '#type' => 'container',
      '#id' => 'row-two',
      '#weight' => 20,
      '#attributes' => array(
        'class' => array('row-two'),
      ),
    );
    // Show the clear selection button.
    if (count($form_state['weed']['criteria_selection']['criterias'])) {
      $form['step_two']['criteria_results']['row_two']['clear_selection'] = array(
        '#type' => 'submit',
        '#value' => t('Clear selection'),
        '#name' => 'step_2__clear_selection',
        '#ajax' => $this->defaultAjaxConf(),
        '#prefix' => '<span class="linktext linktextcancel">',
        '#suffix' => '</span>',
      );
    }
    // Show the show results button.
    if (
        (count($form_state['weed']['criteria_selection']['100_percent']) + count($form_state['weed']['criteria_selection']['75_percent'])) >= 1 &&
        (count($form_state['weed']['criteria_selection']['100_percent']) + count($form_state['weed']['criteria_selection']['75_percent'])) <= 10
    ) {
      $form['step_two']['criteria_results']['row_two']['show_results'] = array(
        '#type' => 'submit',
        '#value' => t('Show results'),
        '#name' => 'step_2__show_results',
        '#ajax' => $this->defaultAjaxConf(),
        '#prefix' => '<span class="linktext linktext-right">',
        '#suffix' => '</span>',
      );
    }
  }

  /**
   * Build the filter criteria buttons.
   */
  private function buildCriteriaFilters(&$form, &$form_state) {
    // Get all the grouped criteria types and groups.
    $grouped_data = $this->getGroupedCriteriaTypes($form_state);
    if (!empty($grouped_data)) {
      // Create a container for the filter criterias.
      $form['step_two']['filter_criterias'] = array(
        '#type' => 'container',
        '#id' => 'filter-criterias',
        '#weight' => 20,
        '#prefix' => '<div class="two-cols-75-25__region">',
        '#attributes' => array(
          'class' => array('two-cols-25'),
        ),
      );

      // Instantiate the language.
      global $language;
      // Set the selected criteria group to the first one if none selected.
      if (empty($form_state['weed']['filter_criteria_group'])) {
        $form_state['weed']['filter_criteria_group'] = array_keys($grouped_data)[0];
      }
      // Set the selected criteria type to the first one in the first group if
      // none selected.
      if (empty($form_state['weed']['filter_criteria_type'])) {
        $form_state['weed']['filter_criteria_type'] = array_keys(reset($grouped_data)['types'])[0];
      }

      // Loop threw the grouped data and create the form search buttons.
      foreach ($grouped_data as $group_tid => $group_data) {
        // Build the fieldset.
        $form['step_two']['filter_criterias'][$group_tid] = array(
          '#type' => 'fieldset',
          '#title' => $group_data['label'],
          '#collapsible' => TRUE,
          '#collapsed' => $form_state['weed']['filter_criteria_group'] != $group_tid,
          '#attributes' => array(
            'title' => $group_data['help_text'],
          ),
        );
        // Build the choosen types buttons.
        foreach ($group_data['types'] as $type) {
          // Load the metadata wrapper.
          $type_wrapper = entity_metadata_wrapper('taxonomy_term', $type);
          // Set the current language.
          $type_wrapper->language($language->language);
          $form['step_two']['filter_criterias'][$group_tid][$type_wrapper->tid->value()] = array(
            '#type' => 'submit',
            '#value' => $type_wrapper->name_field->value(),
            '#disabled' => $form_state['weed']['filter_criteria_type'] == $type_wrapper->tid->value(),
            '#name' => 'step_2__filter_criteria__' . $type_wrapper->tid->value(),
            '#ajax' => $this->defaultAjaxConf(),
            '#attributes' => array(
              'title' => $type_wrapper->description_field->value()['safe_value'],
            ),
          );
        }
      }
    }
  }

  /**
   * Build the filter criteria results view.
   */
  private function buildCriteriaResults(&$form, &$form_state) {
    // Create a container for the filter results.
    $form['step_two']['filter_results'] = array(
      '#type' => 'container',
      '#id' => 'filter-results',
      '#weight' => 30,
      '#attributes' => array(
        'class' => array('two-cols-75'),
      ),
      '#sufix' => '</div>',
    );

    // Return if no criteria type was selected.
    if (empty($form_state['weed']['filter_criteria_type'])) {
      return;
    }

    // Show the view with the criterias.
    $form['step_two']['filter_results']['view_results'] = array(
      '#type' => 'markup',
      '#markup' => call_user_func_array('views_embed_view', array(
        'service_weed_id_criteria',
        'block',
        $form_state['weed']['weed_type'],
        $form_state['weed']['filter_criteria_type'],
        !empty($form_state['weed']['criteria_selection']['criterias']) ? implode('+', $form_state['weed']['criteria_selection']['criterias']) : 'none',
      )),
    );
    // Add hidden field for storing the selected criteria.
    // On clicking on add sign from the criteria view mode javascript is
    // triggering the populating of the field.
    $form['step_two']['filter_results']['added_criteria'] = array(
      '#type' => 'hidden',
      '#name' => 'added_criteria',
    );
    // Add hidden submit handler for adding criteria.
    // On clicking on add sign from the criteria view mode javascript is
    // triggering the button submission.
    $form['step_two']['filter_results']['add_criteria'] = array(
      '#type' => 'submit',
      '#name' => 'step_2__add_criteria',
      '#ajax' => $this->defaultAjaxConf(),
      '#attributes' => array(
        'class' => array('element-hidden'),
      ),
    );
  }

  /**
   * Get all taxonomies from type criteria group and type and group them.
   *
   * @param array $form_state
   *   The form state array.
   *
   * @return array
   *   Array of grouped data.
   */
  private function getGroupedCriteriaTypes(array $form_state) {
    // Instantiate the language.
    global $language;
    // Instantiate the grouped data which will be returned.
    $grouped_data = array();

    // Get the criteria type tids which has the selected weed type.
    $query = db_select('field_data_field_weed_id_criteria_type', 'fdfwict');
    $query->fields('fdfwict', array('field_weed_id_criteria_type_target_id'));
    $query->join('field_data_field_weed_id_weed_types', 'fdfwiwt', 'fdfwiwt.entity_id = fdfwict.entity_id');
    $query->condition('fdfwiwt.field_weed_id_weed_types_value', $form_state['weed']['weed_type']);
    $tids = $query->execute()->fetchAll(PDO::FETCH_COLUMN);

    // Return if no criterias found.
    if (empty($tids)) {
      return $grouped_data;
    }

    $types_results = (new EntityFieldQuery())
      ->entityCondition('entity_type', 'taxonomy_term')
      ->entityCondition('bundle', 'service_weed_id_criteria_type')
      ->propertyCondition('tid', $tids, 'IN')
      ->propertyOrderBy('weight', 'ASC')
      ->execute();
    // Load the types taxonomies.
    $types = empty($types_results['taxonomy_term']) ? array() : taxonomy_term_load_multiple(array_keys($types_results['taxonomy_term']));

    $groups_results = (new EntityFieldQuery())
      ->entityCondition('entity_type', 'taxonomy_term')
      ->entityCondition('bundle', 'service_weed_id_criteria_group')
      ->propertyOrderBy('weight', 'ASC')
      ->execute();
    // Load the groups taxonomies.
    $groups = empty($groups_results['taxonomy_term']) ? array() : taxonomy_term_load_multiple(array_keys($groups_results['taxonomy_term']));

    // Group the types based on the selected groups inside them.
    if (!empty($types) && !empty($groups)) {
      // Loop threw all the groups.
      foreach ($groups as $group) {
        // Load the metadata wrapper.
        $group_wrapper = entity_metadata_wrapper('taxonomy_term', $group);
        // Set the current language.
        $group_wrapper->language($language->language);
        // Instantiate the grouped data.
        $grouped_data[$group_wrapper->tid->value()] = array(
          'label' => $group_wrapper->name_field->value(),
          'help_text' => $group_wrapper->description_field->value()['safe_value'],
          'selected' => FALSE,
          'types' => array(),
        );
        // Create a shortcut reference to the types data.
        $types_data = &$grouped_data[$group_wrapper->tid->value()]['types'];

        // Loop threw all types and add them to the grouped data.
        foreach ($types as $type) {
          // Load the metadata wrapper.
          $type_wrapper = entity_metadata_wrapper('taxonomy_term', $type);
          // Check if the group of the type is the same and add the taxonomy to
          // the grouped data.
          if (
              $type_wrapper->__isset('field_weed_id_group') &&
              $type_wrapper->field_weed_id_group->value() &&
              $type_wrapper->field_weed_id_group->value()->tid == $group_wrapper->tid->value()
          ) {
            $types_data[$type_wrapper->tid->value()] = $type;
          }
        }
        // If there are no types for the group we remove the group.
        if (empty($grouped_data[$group_wrapper->tid->value()]['types'])) {
          unset($grouped_data[$group_wrapper->tid->value()]);
        }
      }
    }

    // Return the results.
    return $grouped_data;
  }

}
