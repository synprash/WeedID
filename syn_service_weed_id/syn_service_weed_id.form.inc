<?php

/**
 * @file
 * Code for the Service: Weed ID form.
 */

/**
 * Service Weed ID form callback.
 */
function syn_service_weed_id_form($form, &$form_state) {
  try {
    // Set prefix and suffix to the form.
    $form['#prefix'] = '<div id="weed-id-form">';
    $form['#suffix'] = '</div>';
    // Attach js to the form.
    $form['#attached']['js'][] = drupal_get_path('module', 'syn_service_weed_id') . '/js/jquery.touchSwipe.min.js';
    $form['#attached']['js'][] = drupal_get_path('module', 'syn_service_weed_id') . '/js/syn_service_weed_id.form.js';
    // Skip caching the form.
    $form_state['cache'] = FALSE;
    // Get the class which will render the content.
    $class = _syn_service_weed_id_form_get_class($form_state);
    // Set the javascript settings for defining the step.
    drupal_add_js(
      array(
        'syn_service_weed_id' => array(
          'step' => (int) $form_state['weed']['step'],
        ),
      ),
      array('type' => 'setting')
    );
    // Return the builded form.
    return $class->build($form, $form_state);
  }
  catch (Exception $exception) {
    // On error log a message and display another one to the end user.
    watchdog_exception(SYN_SERVICE_WEED_ID_WATCHDOG, $exception);
    drupal_set_message(t('There was an error processing you request.'), 'error');
    // On error add javascript.
    drupal_add_js(
      array(
        'syn_service_weed_id' => array(
          // Scroll the browser screen to the error messages element.
          'scroll' => '#weed-id-form',
          // Set the step if available.
          'step' => !empty($form_state['weed']['step']) ? (int) $form_state['weed']['step'] : NULL,
        ),
      ),
      array('type' => 'setting')
    );
  }
}

/**
 * Service Weed ID form submit callback.
 */
function syn_service_weed_id_form_submit(&$form, &$form_state) {
  try {
    // Get the step from the triggering element. All triggering elements should
    // follow the pattern: step_STEP_NUMBER__SOME_TEXT.
    $triggering_element_name = $form_state['triggering_element']['#name'];
    $form_state['weed']['step'] = str_replace('step_', '', explode('__', $triggering_element_name)[0]);

    return _syn_service_weed_id_form_get_class($form_state)
      ->submit($form, $form_state);
  }
  catch (Exception $exception) {
    // On error log a message and display another one to the end user.
    watchdog_exception(SYN_SERVICE_WEED_ID_WATCHDOG, $exception);
    drupal_set_message(t('Oops! Something went wrong while submitting the form'), 'error');
    // On error add javascript.
    drupal_add_js(
      array(
        'syn_service_weed_id' => array(
          // Scroll the browser screen to the error messages element.
          'scroll' => '#weed-id-form',
          // Set the step if available.
          'step' => !empty($form_state['weed']['step']) ? (int) $form_state['weed']['step'] : NULL,
        ),
      ),
      array('type' => 'setting')
    );
  }
}

/**
 * Service Weed ID form ajax callback.
 */
function syn_service_weed_id_form_ajax($form, &$form_state) {
  // Return the whole form.
  return $form;
}

/**
 * Gets form class instance based on which step we will use.
 *
 * @param array $form_state
 *   Form state array.
 * @param int $step
 *   The executed step if available.
 * @param bool $return_all
 *   If true all the form instances are returned. Setting a form state step is
 *   ommited and the $step parameter.
 *
 * @return object|array
 *   The form handler class instance or class instances if $return_all is
 *   selected.
 */
function _syn_service_weed_id_form_get_class(&$form_state, $step = NULL, $return_all = FALSE) {
  // Definition of all form classes.
  $classes = array(
    1 => 'SynServiceWeedIdFormStepOne',
    2 => 'SynServiceWeedIdFormStepTwo',
    3 => 'SynServiceWeedIdFormStepThree',
    4 => 'SynServiceWeedIdFormStepFour',
  );

  // If return all is selected we return all class instances.
  if ($return_all) {
    $return = array();
    foreach ($classes as $class) {
      // Check if the class exists.
      if (!class_exists($class)) {
        throw new Exception(t('Class @class does not exists.', array(
          '@class' => $class,
        )));
      }
      $return[] = new $class();
    }

    return $return;
  }

  // Set the step to be first one if none found.
  if (empty($form_state['weed']['step'])) {
    $form_state['weed']['step'] = 1;
  }

  // Check if the class index exists.
  if (empty($classes[$form_state['weed']['step']])) {
    throw new Exception(t('Class with identifier @identifier was not found.', array(
      '@identifier' => $form_state['weed']['step'],
    )));
  }
  // Check if the class exists.
  if (!class_exists($classes[$form_state['weed']['step']])) {
    throw new Exception(t('Class @class does not exists.', array(
      '@class' => $classes[$form_state['weed']['step']],
    )));
  }

  // Return the class which will handle form build/submit.
  return new $classes[$form_state['weed']['step']]();
}
