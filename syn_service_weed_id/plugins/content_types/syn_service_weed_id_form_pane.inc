<?php

/**
 * @file
 * Contains Syngenta Service Weed ID form ctools content type plugin.
 */

/**
 * Plugin information.
 */
$plugin = array(
  'category' => t('Syngenta: Service'),
  'render callback' => 'syn_service_weed_id_form_pane_render',
  'title' => t('Service Weed ID form'),
);

/**
 * Render callback.
 */
function syn_service_weed_id_form_pane_render($subtype, array $conf = array()) {
  return (object) array(
    'content' => drupal_get_form('syn_service_weed_id_form'),
  );
}

/**
 * Pane callback to show more information about this plugin.
 *
 * @return object
 *   Information about the plugin.
 */
function syn_service_weed_id_syn_service_weed_id_form_content_type_admin_info() {
  return (object) array(
    'title' => t('Service Weed ID form'),
    'content' => t('Contains Syngenta Service Weed ID form.'),
  );
}
