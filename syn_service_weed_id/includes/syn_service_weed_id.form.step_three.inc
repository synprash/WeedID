<?php

/**
 * @file
 * Contains Service Weed ID form step three.
 */

/**
 * Class SynServiceWeedIdFormStepThree.
 */
class SynServiceWeedIdFormStepThree extends SynServiceWeedIdFormAbstract {

  /**
   * {@inheritdoc}
   */
  protected function doBuild($form, &$form_state) {
    // Instantiate session variable for storing the weed target matches.
    // @see syn_service_weed_id_preprocess_views_view_fields
    $_SESSION['weed_data']['matches'] = array(
      '100_percent' => $form_state['weed']['criteria_selection']['100_percent'],
      '75_percent' => $form_state['weed']['criteria_selection']['75_percent'],
    );

    // Set step three container.
    $form['step_three'] = array(
      '#type' => 'container',
      '#id' => 'step-three',
      '#weight' => 30,
      '#attributes' => array(
        'class' => array('weedid-step-three'),
      ),
    );

    // Set the step three title.
    $form['step_three']['title'] = array(
      '#type' => 'markup',
      '#markup' => t('<h2 class="green _20 bigger"><b>Step 3:</b> Your result</h2>'),
    );

    // Build the filter criteria selection.
    $this->buildCriteriaSelection($form, $form_state);

    // Build the filter criteria results.
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
    $triggering_element = str_replace('step_3__', '', $form_state['triggering_element']['#name']);

    switch (TRUE) {
      // Modify selection.
      case $triggering_element === 'modify_selection':
        // Change the form step.
        $form_state['weed']['step'] = 2;
        // Scroll the browser screen to step 2.
        drupal_add_js(
          array('syn_service_weed_id' => array('scroll' => '#step-two')),
          array('type' => 'setting')
        );
        break;

      // Choosing 2 targets for comparison..
      case $triggering_element === 'compare':
        // Decode the json encoded comparison target tids.
        $json_object = json_decode($form_state['values']['comparison_targets']);
        // Sanity check the comparison targets.
        if (!$json_object || (count((array) $json_object) !== 2)) {
          throw new Exception(t('Invalid coparison targets provided: @targets.', array(
            '@targets' => print_r($form_state['values']['comparison_targets'], TRUE),
          )));
        }
        // Get the targets tids.
        $target_tids = array_values((array) $json_object);
        // Loop threw them.
        foreach ($target_tids as $target_tid) {
          // Sanity check each target tid.
          if (!in_array($target_tid, $form_state['weed']['criteria_selection']['100_percent'] + $form_state['weed']['criteria_selection']['75_percent'])) {
            throw new Exception(t('Invalid coparison target selected: @target_tid.', array(
              '@target_tid' => print_r($target_tid, TRUE),
            )));
          }
          // Populate the comparison target tids.
          $form_state['weed']['comparison_targets'][$target_tid] = $target_tid;
        }
        // Change the form step.
        $form_state['weed']['step'] = 4;
        // Scroll the browser screen to step 4.
        drupal_add_js(
          array('syn_service_weed_id' => array('scroll' => '#step-four')),
          array('type' => 'setting')
        );
        break;

      default:
    }

    // Force form rebuild.
    $form_state['rebuild'] = TRUE;
  }

  /**
   * {@inheritdoc}
   */
  protected function postSubmit(&$form, &$form_state, $executed_class) {
    // If the submit class is not step 3 remove the stored comparison targets.
    if (
        $executed_class !== 'SynServiceWeedIdFormStepThree' &&
        isset($form_state['weed']['comparison_targets'])
    ) {
      unset($form_state['weed']['comparison_targets']);
    }
  }

  /**
   * Build the filter criteria selection.
   */
  private function buildCriteriaSelection(&$form, &$form_state) {
    // Create a container for the selected criterias.
    $form['step_three']['criteria_results'] = array(
      '#type' => 'container',
      '#id' => 'criteria-results',
      '#weight' => 10,
      '#attributes' => array(
        'class' => array('lightgreen-three'),
      ),
    );
    // Show the criteria selection.
    $form['step_three']['criteria_results']['selection'] = array(
      '#type' => 'container',
      '#id' => 'criteria-results-selection',
      '#prefix' => '<div class="result-region">',
      '#attributes' => array(
        'class' => array('left-result'),
      ),
    );
    // Show the selected criterias.
    $form['step_three']['criteria_results']['selection']['selected_criterias'] = array(
      '#type' => 'markup',
      '#markup' => call_user_func_array('views_embed_view', array(
        'service_weed_id_criteria',
        'block_1',
        implode('+', $form_state['weed']['criteria_selection']['criterias']),
      )),
    );
    // Add the empty blocks.
    $empty_blocks = 4 - count($form_state['weed']['criteria_selection']['criterias']);
    while ($empty_blocks > 0) {
      $form['step_three']['criteria_results']['selection']['empty_block_' . $empty_blocks] = array(
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
    $match_100_percent = t('<strong>@match_count:</strong> 100%', array(
      '@match_count' => count($form_state['weed']['criteria_selection']['100_percent']),
    ));
    // Translate 75% match strings.
    $match_75_percent = t('<strong>@match_count:</strong> 75%', array(
      '@match_count' => count($form_state['weed']['criteria_selection']['75_percent']),
    ));
    // Create a markup for the your results html.
    $results_markup = <<<MARKUP
      <div>
        <h3 class="orange_h2">$your_results</h3>
      </div>
      <div class="result_info">
        <h3>$match_100_percent</h3>
        <h3>$match_75_percent</h3>
      </div>
MARKUP;
    // Show the results.
    $form['step_three']['criteria_results']['results'] = array(
      '#type' => 'container',
      '#id' => 'step-three-criteria-results-results',
      'results' => array(
        '#type' => 'markup',
        '#markup' => $results_markup,
      ),
      '#attributes' => array(
        'class' => array('step-three-criteria-results-results'),
      ),
      '#prefix' => '<div class="right-result">',
    );
    // Show the modify selection button.
    $form['step_three']['criteria_results']['modify_selection'] = array(
      '#type' => 'submit',
      '#value' => t('Modify selection'),
      '#name' => 'step_3__modify_selection',
      '#ajax' => $this->defaultAjaxConf(),
      '#suffix' => '</span></div></div>',
      '#prefix' => '<span class="linktext">',
    );
  }

  /**
   * Build the filter criteria results view.
   */
  private function buildCriteriaResults(&$form, &$form_state) {
    // Create a container for the filter results.
    $form['step_three']['filter_results'] = array(
      '#type' => 'container',
      '#id' => 'filter-results',
      '#weight' => 30,
    );

    // Show the view with the criterias.
    $form['step_three']['filter_results']['view_results'] = array(
      '#type' => 'markup',
      '#markup' => call_user_func_array('views_embed_view', array(
        'service_weed_id_target',
        'block',
        implode('+', $form_state['weed']['criteria_selection']['100_percent'] + $form_state['weed']['criteria_selection']['75_percent']),
      )),
    );

    // Add hidden field for storing the targets for comparison.
    // On choosing of target for comparison javascript is triggering which
    // populates the the field.
    $form['step_three']['filter_results']['comparison_targets'] = array(
      '#type' => 'hidden',
      '#name' => 'comparison_targets',
    );
    // Add hidden submit handler for choosing targets for comparison.
    // On selecting second target for comparison javascript is triggered which
    // submits the form.
    $form['step_three']['filter_results']['step_3__compare'] = array(
      '#type' => 'submit',
      '#name' => 'step_3__compare',
      '#ajax' => $this->defaultAjaxConf(),
      '#attributes' => array(
        'class' => array('element-hidden'),
      ),
    );
  }

}
