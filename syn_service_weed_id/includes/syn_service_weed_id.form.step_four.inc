<?php

/**
 * @file
 * Contains Service Weed ID form step four.
 */

/**
 * Class SynServiceWeedIdFormStepFour.
 */
class SynServiceWeedIdFormStepFour extends SynServiceWeedIdFormAbstract {

  /**
   * {@inheritdoc}
   */
  protected function doBuild($form, &$form_state) {
    // Set step four container.
    $form['step_four'] = array(
      '#type' => 'container',
      '#id' => 'step-four',
      '#weight' => 40,
      '#attributes' => array(
        'class' => array('weedid-step-four'),
      ),
    );

    // Set the step four title.
    $form['step_four']['title'] = array(
      '#type' => 'markup',
      '#markup' => t('<div class="weedid-title"><h2 class="green _20 bigger">Compare</h2>'),
    );

    // Build the clear selection button.
    $this->buildClearSelection($form, $form_state);

    // Build the comparison structure.
    $this->buildComparisonStructure($form, $form_state);

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
    $triggering_element = str_replace('step_4__', '', $form_state['triggering_element']['#name']);

    switch (TRUE) {
      // Clear selection.
      case $triggering_element === 'clear_selection':
        // Change the form step.
        $form_state['weed']['step'] = 3;
        // Unset the comparison targets froms tep 3, we don't need them anymore.
        unset($form_state['weed']['comparison_targets']);
        // Scroll the browser screen to step 3.
        drupal_add_js(
          array('syn_service_weed_id' => array('scroll' => '#step-three')),
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

  }

  /**
   * Build the clear selection button.
   */
  private function buildClearSelection(&$form, &$form_state) {
    // Add hidden submit handler for removing criteria.
    // On clicking on remove sign from the criteria view mode javascript is
    // triggering the button submission.
    $form['step_four']['step_4__clear_selection'] = array(
      '#type' => 'submit',
      '#name' => 'step_4__clear_selection',
      '#value' => t('Clear selection'),
      '#ajax' => $this->defaultAjaxConf(),
      '#prefix' => '<span class="linktext">',
      '#suffix' => '</span></div>',
    );
  }

  /**
   * Build the comparison structure.
   */
  private function buildComparisonStructure(&$form, &$form_state) {
    // Set the comparison container.
    $form['step_four']['comparison'] = array(
      '#type' => 'container',
      '#id' => 'comparison',
    );
    // Set the left comparison target wrapper and content.
    $form['step_four']['comparison']['left_target'] = array(
      '#type' => 'markup',
      '#id' => 'left-target',
      '#markup' => views_embed_view('service_weed_id_target', 'block_1', array_keys($form_state['weed']['comparison_targets'])[0]),
    );
    // Set the comparison results.
    $form['step_four']['comparison']['comparison_results'] = array(
      '#type' => 'markup',
      '#id' => 'comparison-results',
      // Get the comparison results markup.
      '#markup' => views_embed_view('service_weed_id_criteria', 'block_3', $form_state['weed']['weed_type'], implode('+', $form_state['weed']['comparison_targets'])),
    );
    // Set the right comparison target wrapper and content.
    $form['step_four']['comparison']['right_target'] = array(
      '#type' => 'markup',
      '#id' => 'right-target',
      '#markup' => views_embed_view('service_weed_id_target', 'block_1', array_keys($form_state['weed']['comparison_targets'])[1]),
    );
  }

}
