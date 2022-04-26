<?php

/**
 * @file
 * syn_service_weed_id.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function syn_service_weed_id_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'field_collection_item-field_weed_data-field_weed_targets'.
  $field_instances['field_collection_item-field_weed_data-field_weed_targets'] = array(
    'bundle' => 'field_weed_data',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_weed_targets',
    'label' => 'Targets',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'entityreference_autocreate' => array(
          'active' => 0,
          'author' => '',
          'author_current_user' => 1,
          'status' => -1,
        ),
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 2,
    ),
    'workbench_assignee_field' => 0,
  );

  // Exported field_instance:
  // 'field_collection_item-field_weed_data-field_weed_type'.
  $field_instances['field_collection_item-field_weed_data-field_weed_type'] = array(
    'bundle' => 'field_weed_data',
    'default_value' => NULL,
    'default_value_function' => '',
    'default_value_php' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_weed_type',
    'label' => 'Weed Type',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 1,
    ),
    'workbench_assignee_field' => 0,
  );

  // Exported field_instance:
  // 'service_configuration-weed_id-field_service_weed_id_combine_ma'.
  $field_instances['service_configuration-weed_id-field_service_weed_id_combine_ma'] = array(
    'bundle' => 'weed_id',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'default_value_function' => '',
    'default_value_php' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'service_configuration',
    'field_name' => 'field_service_weed_id_combine_ma',
    'label' => 'Combine maturity',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 4,
    ),
    'workbench_assignee_field' => 0,
  );

  // Exported field_instance:
  // 'service_configuration-weed_id-field_service_weed_id_descriptio'.
  $field_instances['service_configuration-weed_id-field_service_weed_id_descriptio'] = array(
    'bundle' => 'weed_id',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'service_configuration',
    'field_name' => 'field_service_weed_id_descriptio',
    'label' => 'Description',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
          'syn_message_body_html' => 'syn_message_body_html',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => -10,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
            'syn_message_body_html' => array(
              'weight' => 0,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
      'wysiwyg_unload' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
        'show_token_tree' => 0,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
    'workbench_assignee_field' => 0,
  );

  // Exported field_instance:
  // 'service_configuration-weed_id-field_service_weed_id_image'.
  $field_instances['service_configuration-weed_id-field_service_weed_id_image'] = array(
    'bundle' => 'weed_id',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'news_landing',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'service_configuration',
    'field_name' => 'field_service_weed_id_image',
    'label' => 'Image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'brightcove' => 0,
          'brightcove-playlist' => 0,
          'bynder' => 0,
          'http' => 0,
          'https' => 0,
          'private' => 0,
          'public' => 'public',
          'youtube' => 0,
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'external' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'brightcove' => 0,
          'brightcove_playlist' => 0,
          'external' => 0,
          'media_bynder' => 'media_bynder',
          'media_default--media_browser_1' => 'media_default--media_browser_1',
          'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
          'media_internet' => 0,
          'upload' => 'upload',
        ),
      ),
      'type' => 'media_generic',
      'weight' => 2,
    ),
    'workbench_assignee_field' => 0,
  );

  // Exported field_instance:
  // 'service_configuration-weed_id-field_service_weed_id_maturity'.
  $field_instances['service_configuration-weed_id-field_service_weed_id_maturity'] = array(
    'bundle' => 'weed_id',
    'default_value' => NULL,
    'default_value_function' => '',
    'default_value_php' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'service_configuration',
    'field_name' => 'field_service_weed_id_maturity',
    'label' => 'Maturity',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 3,
    ),
    'workbench_assignee_field' => 0,
  );

  // Exported field_instance:
  // 'taxonomy_term-service_weed_id_criteria-description_field'.
  $field_instances['taxonomy_term-service_weed_id_criteria-description_field'] = array(
    'bundle' => 'service_weed_id_criteria',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'description_field',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
          'syn_message_body_html' => 'syn_message_body_html',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => -10,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
            'syn_message_body_html' => array(
              'weight' => 0,
            ),
          ),
        ),
      ),
      'display_summary' => 0,
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
      'wysiwyg_unload' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
        'show_token_tree' => 0,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 1,
    ),
    'workbench_assignee_field' => 0,
  );

  // Exported field_instance:
  // 'taxonomy_term-service_weed_id_criteria-field_term_image'.
  $field_instances['taxonomy_term-service_weed_id_criteria-field_term_image'] = array(
    'bundle' => 'service_weed_id_criteria',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'mediafield',
        'settings' => array(
          'file_view_mode' => 'teaser',
        ),
        'type' => 'media',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_term_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'file_extensions' => 'jpg jpeg gif png txt doc docx xls xlsx pdf ppt pptx pps ppsx odt ods odp mp3 mov mp4 m4a m4v mpeg avi ogg oga ogv weba webp webm',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'brightcove' => 0,
          'brightcove-playlist' => 0,
          'bynder' => 0,
          'http' => 0,
          'https' => 0,
          'private' => 0,
          'public' => 'public',
          'youtube' => 0,
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'external' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'brightcove' => 0,
          'brightcove_playlist' => 0,
          'external' => 0,
          'media_bynder' => 'media_bynder',
          'media_default--media_browser_1' => 'media_default--media_browser_1',
          'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
          'media_internet' => 0,
          'upload' => 'upload',
        ),
      ),
      'type' => 'media_generic',
      'weight' => 2,
    ),
    'workbench_assignee_field' => 0,
  );

  // Exported field_instance:
  // 'taxonomy_term-service_weed_id_criteria-field_weed_data'.
  $field_instances['taxonomy_term-service_weed_id_criteria-field_weed_data'] = array(
    'bundle' => 'service_weed_id_criteria',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
        ),
        'type' => 'field_collection_list',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_weed_data',
    'label' => 'Weed data',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 4,
    ),
    'workbench_assignee_field' => 0,
  );

  // Exported field_instance:
  // 'taxonomy_term-service_weed_id_criteria-field_weed_id_criteria_type'.
  $field_instances['taxonomy_term-service_weed_id_criteria-field_weed_id_criteria_type'] = array(
    'bundle' => 'service_weed_id_criteria',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_weed_id_criteria_type',
    'label' => 'Type',
    'required' => 1,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 3,
    ),
    'workbench_assignee_field' => 0,
  );

  // Exported field_instance:
  // 'taxonomy_term-service_weed_id_criteria-field_weed_id_weed_types'.
  $field_instances['taxonomy_term-service_weed_id_criteria-field_weed_id_weed_types'] = array(
    'bundle' => 'service_weed_id_criteria',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'title',
        'settings' => array(
          'title_class' => '',
          'title_link' => '',
          'title_style' => '',
        ),
        'type' => 'title_linked',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_weed_id_weed_types',
    'label' => 'Weed types',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
          'syn_message_body_html' => 'syn_message_body_html',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => -10,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
            'syn_message_body_html' => array(
              'weight' => 0,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
      'wysiwyg_unload' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'show_token_tree' => 0,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
    'workbench_assignee_field' => 0,
  );

  // Exported field_instance:
  // 'taxonomy_term-service_weed_id_criteria-name_field'.
  $field_instances['taxonomy_term-service_weed_id_criteria-name_field'] = array(
    'bundle' => 'service_weed_id_criteria',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'name_field',
    'label' => 'Name',
    'required' => TRUE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'hide_label' => array(
        'entity' => FALSE,
        'page' => FALSE,
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'show_token_tree' => FALSE,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-service_weed_id_criteria_group-description_field'.
  $field_instances['taxonomy_term-service_weed_id_criteria_group-description_field'] = array(
    'bundle' => 'service_weed_id_criteria_group',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'description_field',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
          'syn_message_body_html' => 'syn_message_body_html',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => -10,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
            'syn_message_body_html' => array(
              'weight' => 0,
            ),
          ),
        ),
      ),
      'display_summary' => 0,
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
      'wysiwyg_unload' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
        'show_token_tree' => 0,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 1,
    ),
    'workbench_assignee_field' => 0,
  );

  // Exported field_instance:
  // 'taxonomy_term-service_weed_id_criteria_group-name_field'.
  $field_instances['taxonomy_term-service_weed_id_criteria_group-name_field'] = array(
    'bundle' => 'service_weed_id_criteria_group',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'name_field',
    'label' => 'Name',
    'required' => TRUE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'hide_label' => array(
        'entity' => FALSE,
        'page' => FALSE,
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'show_token_tree' => FALSE,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -5,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-service_weed_id_criteria_type-description_field'.
  $field_instances['taxonomy_term-service_weed_id_criteria_type-description_field'] = array(
    'bundle' => 'service_weed_id_criteria_type',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'description_field',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
          'syn_message_body_html' => 'syn_message_body_html',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => -10,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
            'syn_message_body_html' => array(
              'weight' => 0,
            ),
          ),
        ),
      ),
      'display_summary' => 0,
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
      'wysiwyg_unload' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
        'show_token_tree' => 0,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 1,
    ),
    'workbench_assignee_field' => 0,
  );

  // Exported field_instance:
  // 'taxonomy_term-service_weed_id_criteria_type-field_weed_id_group'.
  $field_instances['taxonomy_term-service_weed_id_criteria_type-field_weed_id_group'] = array(
    'bundle' => 'service_weed_id_criteria_type',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_weed_id_group',
    'label' => 'Group',
    'required' => 1,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 2,
    ),
    'workbench_assignee_field' => 0,
  );

  // Exported field_instance:
  // 'taxonomy_term-service_weed_id_criteria_type-name_field'.
  $field_instances['taxonomy_term-service_weed_id_criteria_type-name_field'] = array(
    'bundle' => 'service_weed_id_criteria_type',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'name_field',
    'label' => 'Name',
    'required' => TRUE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'hide_label' => array(
        'entity' => FALSE,
        'page' => FALSE,
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'show_token_tree' => FALSE,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Combine maturity');
  t('Description');
  t('Group');
  t('Image');
  t('Maturity');
  t('Name');
  t('Targets');
  t('Type');
  t('Weed Type');
  t('Weed data');
  t('Weed types');

  return $field_instances;
}
