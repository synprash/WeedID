<?php

/**
 * @file
 * Pages for the Service: Weed ID feature.
 */

/**
 * Page callback for showing content in modal dialog.
 *
 * @param string $request_type
 *   The request type, e.g. ajax or nojs.
 * @param string $type
 *   The type of the content needed to be rendered, e.g. image or weed.
 * @param string $data
 *   Additional data which is needed for knowing what to be rendered.
 *
 * @return mixed
 *   Could be access denied, ajax commands or renderable html markup.
 */
function syn_service_weed_id_pages_ctools_modal($request_type, $type, $data) {
  // Check the type needed to be rendered.
  switch ($type) {
    // Type is image.
    case 'image':
      // Load the file, sanitize it and return access denied on error.
      $file = file_load((int) $data);
      if (!$file || $file->type !== 'image') {
        return drupal_access_denied();
      }
      // Build the html content.
      $content = '<img src="' . file_create_url($file->uri) . '" width="100%" height="100%"/>';
      // Check the request type and return the appropriate response.
      if ($request_type === 'ajax') {
        // Load the ctools modal library.
        ctools_include('modal');
        // Return the ajax commands.
        return ajax_deliver(array(
          '#type' => 'ajax',
          '#commands' => array(ctools_modal_command_display(NULL, $content)),
        ));
      }
      else {
        // Return simple html markup.
        return array(
          '#markup' => $content,
        );
      }

      // Type is weed (target).
    case 'weed':
      // Load the target, sanitize it and return access denied on error.
      $target = node_load((int) $data);
      if (!$target || $target->type !== 'target') {
        return drupal_access_denied();
      }
      // Load the target wrapper.
      $target_wrapper = entity_metadata_wrapper('node', $target);
      // Render the modal content.
      $content = theme('node_target__modal_dialog', array(
        'target' => $target,
        'target_title' => $target_wrapper->title->value(),
        'target_global_description' => $target_wrapper->body->value()['value'],
        'target_details' => $target_wrapper->field_target_code_eppo->value(),
        'target_seedling_carousel' => views_embed_view('service_weed_id_target', 'block_5', $target_wrapper->nid->value()),
        'target_adult_carousel' => views_embed_view('service_weed_id_target', 'block_7', $target_wrapper->nid->value()),
        'target_rightside' => views_embed_view('service_weed_id_target', 'block_2', $target_wrapper->nid->value()),
      ));
      // Check the request type and return the appropriate response.
      if ($request_type === 'ajax') {
        // Load the ctools modal library.
        ctools_include('modal');
        // Return the ajax commands.
        return ajax_deliver(array(
          '#type' => 'ajax',
          '#commands' => array(ctools_modal_command_display(NULL, $content)),
        ));
      }
      else {
        // Return simple html markup.
        return array(
          '#markup' => $content,
        );
      }

      // Return acces denied on unknown type.
    default:
      return drupal_access_denied();
  }
}
