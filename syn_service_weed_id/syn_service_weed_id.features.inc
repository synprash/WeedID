<?php

/**
 * @file
 * syn_service_weed_id.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function syn_service_weed_id_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "slick" && $api == "slick_default_preset") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function syn_service_weed_id_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function syn_service_weed_id_eck_bundle_info() {
  $items = array(
    'service_configuration_weed_id' => array(
      'machine_name' => 'service_configuration_weed_id',
      'entity_type' => 'service_configuration',
      'name' => 'weed_id',
      'label' => 'Weed ID',
      'config' => array(
        'managed_properties' => array(
          'title' => 'title',
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_flag_default_flags().
 */
function syn_service_weed_id_flag_default_flags() {
  $flags = array();
  // Exported flag: "Service Weed ID".
  $flags['service_weed_id'] = array(
    'entity_type' => 'node',
    'title' => 'Service Weed ID',
    'global' => 0,
    'types' => array(
      0 => 'service',
    ),
    'flag_short' => 'Flag this item',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unflag this item',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'diff_standard' => 0,
      'print' => 0,
      'question' => 0,
      'bookmarks' => 0,
      'listing' => 0,
      'syngenta_teaser_small' => 0,
      'hero' => 0,
      'related_video' => 0,
      'related_video_small' => 0,
      'related' => 0,
      'full_width_hero' => 0,
      'content_slider' => 0,
      'media_gallery' => 0,
      'media_banner_full_width' => 0,
      'news_landing' => 0,
      'product_thumbnail' => 0,
      'legal_information' => 0,
      'product_cp_registration_on_product_cp' => 0,
      'product_cp_registration_on_product_cp_content' => 0,
      'pm_model_preview_mail' => 0,
      'pm_model_preview_fax' => 0,
      'pm_model_mail' => 0,
      'pm_model_fax' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'syn_service_weed_id',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_image_default_styles().
 */
function syn_service_weed_id_image_default_styles() {
  $styles = array();

  // Exported image style: service__weed_id__criteria.
  $styles['service__weed_id__criteria'] = array(
    'label' => 'Service: Weed ID: Criteria (105*125)',
    'effects' => array(
      146 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 105,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      151 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 105,
          'height' => 125,
          'anchor' => 'center-center',
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}
