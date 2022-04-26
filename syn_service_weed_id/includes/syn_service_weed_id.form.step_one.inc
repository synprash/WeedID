<?php

/**
 * @file
 * Contains Service Weed ID form step one.
 */

/**
 * Class SynServiceWeedIdFormStepOne.
 */
class SynServiceWeedIdFormStepOne extends SynServiceWeedIdFormAbstract {

  /**
   * {@inheritdoc}
   */
  protected function doBuild($form, &$form_state) {
    // Store the service wrapper in the form state. Needed because if we are
    // returning from previous step the service wrapper could not be retrieved.
    if (empty($form_state['weed']['service_wrapper'])) {
      $form_state['weed']['service_wrapper'] = $this->serviceWrapper;
    }
    if (empty($form_state['weed']['service_wrapper'])) {
      return $form;
    }

    // Set step one container.
    $form['step_one'] = array(
      '#type' => 'container',
      '#id' => 'step-one',
      '#weight' => 10,
      '#attributes' => array(
        'class' => array('weedid-step-one'),
      ),
    );

    // Set the step one title.
    $form['step_one']['title'] = array(
      '#type' => 'markup',
      '#markup' => t('<h2 class="green _20 bigger"><b>Step 1:</b> Select the weed you want to identify</h2>'),
    );

    // Get the configurations.
    $configuration_wrappers = array();
    foreach ($form_state['weed']['service_wrapper']->field_service_conf->getIterator() as $configuration_wrapper) {
      if ($configuration_wrapper->value()) {
        $configuration_wrappers[] = $configuration_wrapper;
      }
    }
    krsort($configuration_wrappers);

    // Calculate the styling classes based on the configurations count.
    $configurations_count = count($configuration_wrappers);
    $classes = array(
      1 => array('', ''),
      2 => array('two-cols__region', 'panel-pane'),
      3 => array('three-cols-33__region', 'three-cols-33__item'),
      4 => array('four-cols__region', 'four-cols__region__item'),
    );
    $selected_classes = $classes[1];
    switch (TRUE) {
      case $configurations_count > 4:
        $selected_classes = $classes[4];
        break;

      case $configurations_count < 1:
        $selected_classes = $classes[1];
        break;

      default:
        $selected_classes = $classes[$configurations_count];
    }

    // Instantiate weed types container.
    $form['step_one']['weed_types'] = array(
      '#type' => 'container',
      '#tree' => TRUE,
      '#attributes' => array(
        'class' => array(
          $selected_classes[0],
          'clearfix',
          'service_configuration__weed_id_form',
        ),
      ),
    );

    $selected_weed_type = empty($form_state['weed']['weed_type']) ? NULL : 'step_1__' . $form_state['weed']['weed_type'];

    // Loop threw the service configurations where we are storing the weed types
    // and display them as a form components in order the user to choose weed
    // type.
    foreach ($configuration_wrappers as $configuration_wrapper) {
      // Get the renderable service configuration entity view.
      $view = entity_view('service_configuration', array($configuration_wrapper->value()));
      // Get the service configuration identifier.
      $id = $configuration_wrapper->id->value();

      // Create weed type container for specific weed type.
      $form['step_one']['weed_types'][$id] = array(
        '#prefix' => '<div class="' . $selected_classes[1] . '"><div class="weedid_block">' . drupal_render($view),
        '#suffix' => '</div></div>',
        '#type' => 'actions',
        '#tree' => TRUE,
      );
      // If weed type has combined maturity show only one button.
      if ($configuration_wrapper->field_service_weed_id_combine_ma->value()) {
        $name = 'step_1__' . syn_service_weed_id_get_keys($configuration_wrapper, 'combined');
        $form['step_one']['weed_types'][$id]['combined'] = array(
          '#type' => 'submit',
          '#name' => $name,
          '#value' => t('Young or Adult plant'),
          '#ajax' => $this->defaultAjaxConf(),
          '#disabled' => $selected_weed_type === $name,
          '#prefix' => '<span class="linktext-first">',
          '#suffix' => '</span>',
        );
      }
      // Loop threw the selected maturities and add submit buttons for each of
      // them.
      else {
        foreach ($configuration_wrapper->field_service_weed_id_maturity->getIterator() as $maturity) {
          $name = 'step_1__' . syn_service_weed_id_get_keys($configuration_wrapper, $maturity->value());
          $form['step_one']['weed_types'][$id][$maturity->value()] = array(
            '#type' => 'submit',
            '#name' => $name,
            '#value' => $maturity->value() === 'young' ? t('Young') : t('Adult'),
            '#ajax' => $this->defaultAjaxConf(),
            '#disabled' => $selected_weed_type === $name,
            '#prefix' => '<span class="linktext-first">',
            '#suffix' => '</span>',
          );
        }
      }
    }

    // Return the form.
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  protected function postBuild(&$form, &$form_state, $executed_class) {
    // Add the step one form if step two is executed.
    if ($executed_class === 'SynServiceWeedIdFormStepTwo') {
      $form += $this->build($form, $form_state);
    }
  }

  /**
   * {@inheritdoc}
   */
  protected function doSubmit(&$form, &$form_state) {
    // Set the weed type key.
    $form_state['weed']['weed_type'] = str_replace('step_1__', '', $form_state['triggering_element']['#name']);
    // Change the form step.
    $form_state['weed']['step'] = 2;
    // Force form rebuild.
    $form_state['rebuild'] = TRUE;
    // Set the service weed id js settings.
    drupal_add_js(
      array(
        'syn_service_weed_id' => array(
          // Scroll the browser screen to step 2.
          'scroll' => '#step-two',
          // Set the step.
          'step' => 2,
        ),
      ),
      array('type' => 'setting')
    );
  }

  /**
   * {@inheritdoc}
   */
  protected function postSubmit(&$form, &$form_state, $executed_class) {

  }

}
