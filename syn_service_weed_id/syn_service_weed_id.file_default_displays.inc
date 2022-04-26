<?php

/**
 * @file
 * syn_service_weed_id.file_default_displays.inc
 */

/**
 * Implements hook_file_default_displays().
 */
function syn_service_weed_id_file_default_displays() {
  $export = array();

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__service_weed_id_criteria_img__brightcove_media_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__service_weed_id_criteria_img__brightcove_media_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__service_weed_id_criteria_img__brightcove_media_playlist';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'player' => '',
    'width' => '',
    'height' => '',
  );
  $export['image__service_weed_id_criteria_img__brightcove_media_playlist'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__service_weed_id_criteria_img__brightcove_media_video';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'player' => '',
    'width' => '',
    'height' => '',
  );
  $export['image__service_weed_id_criteria_img__brightcove_media_video'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__service_weed_id_criteria_img__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__service_weed_id_criteria_img__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__service_weed_id_criteria_img__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['image__service_weed_id_criteria_img__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__service_weed_id_criteria_img__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__service_weed_id_criteria_img__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__service_weed_id_criteria_img__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['image__service_weed_id_criteria_img__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__service_weed_id_criteria_img__file_field_image';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'service__weed_id__criteria',
    'image_link' => '',
  );
  $export['image__service_weed_id_criteria_img__file_field_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__service_weed_id_criteria_img__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__service_weed_id_criteria_img__file_field_media_large_icon'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__service_weed_id_criteria_img__file_field_owlcarousel_formatter';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'settings_group' => 'owlcarousel_settings_default',
  );
  $export['image__service_weed_id_criteria_img__file_field_owlcarousel_formatter'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__service_weed_id_criteria_img__file_image';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'image_style' => '',
  );
  $export['image__service_weed_id_criteria_img__file_image'] = $file_display;

  return $export;
}
