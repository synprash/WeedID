<?php

/**
 * @file
 * syn_service_weed_id.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function syn_service_weed_id_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:service:weed_id_full';
  $panelizer->title = 'Weed ID full';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'service';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = 'weed-id-service';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = 'weed-id-service';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'onecol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'row_1' => NULL,
      'row_2' => NULL,
      'row_3' => NULL,
      'row_4' => NULL,
      'row_5' => NULL,
      'row_6' => NULL,
      'row_7' => NULL,
      'row_8' => NULL,
      'row_9' => NULL,
      'row_10' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '9df7a69e-4cc2-43b3-8bc7-f3ef0b2b0c76';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-5f640ea3-9a42-4eaf-a4fa-25810160f82f';
  $pane->panel = 'row_1';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_service_picture';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 1,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'media',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'file_view_mode' => 'default',
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5f640ea3-9a42-4eaf-a4fa-25810160f82f';
  $display->content['new-5f640ea3-9a42-4eaf-a4fa-25810160f82f'] = $pane;
  $display->panels['row_1'][0] = 'new-5f640ea3-9a42-4eaf-a4fa-25810160f82f';
  $pane = new stdClass();
  $pane->pid = 'new-aa46ee2a-f904-49ec-84e9-f404e4468341';
  $pane->panel = 'row_1';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_service_premium_picture';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 1,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => TRUE,
      ),
    ),
  );
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'media',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'file_view_mode' => 'default',
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'aa46ee2a-f904-49ec-84e9-f404e4468341';
  $display->content['new-aa46ee2a-f904-49ec-84e9-f404e4468341'] = $pane;
  $display->panels['row_1'][1] = 'new-aa46ee2a-f904-49ec-84e9-f404e4468341';
  $pane = new stdClass();
  $pane->pid = 'new-b8f2419d-a291-496f-83a7-6a35532673ac';
  $pane->panel = 'row_1';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
    'override_title' => 1,
    'override_title_text' => '%node:title',
    'override_title_heading' => 'h1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'b8f2419d-a291-496f-83a7-6a35532673ac';
  $display->content['new-b8f2419d-a291-496f-83a7-6a35532673ac'] = $pane;
  $display->panels['row_1'][2] = 'new-b8f2419d-a291-496f-83a7-6a35532673ac';
  $pane = new stdClass();
  $pane->pid = 'new-cdfd1b9a-ece5-48b7-9f47-1d9ac56db1c5';
  $pane->panel = 'row_1';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'cdfd1b9a-ece5-48b7-9f47-1d9ac56db1c5';
  $display->content['new-cdfd1b9a-ece5-48b7-9f47-1d9ac56db1c5'] = $pane;
  $display->panels['row_1'][3] = 'new-cdfd1b9a-ece5-48b7-9f47-1d9ac56db1c5';
  $pane = new stdClass();
  $pane->pid = 'new-358acb8d-1883-40cd-9a6b-392805151ac2';
  $pane->panel = 'row_1';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_service_help_message';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
    'override_title' => 1,
    'override_title_text' => 'Need more help?',
    'override_title_heading' => 'div',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '358acb8d-1883-40cd-9a6b-392805151ac2';
  $display->content['new-358acb8d-1883-40cd-9a6b-392805151ac2'] = $pane;
  $display->panels['row_1'][4] = 'new-358acb8d-1883-40cd-9a6b-392805151ac2';
  $pane = new stdClass();
  $pane->pid = 'new-72ba18a5-e6c7-4b1e-8c23-a934cf7ad97b';
  $pane->panel = 'row_1';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_service_sign_up_page';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 1,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '72ba18a5-e6c7-4b1e-8c23-a934cf7ad97b';
  $display->content['new-72ba18a5-e6c7-4b1e-8c23-a934cf7ad97b'] = $pane;
  $display->panels['row_1'][5] = 'new-72ba18a5-e6c7-4b1e-8c23-a934cf7ad97b';
  $pane = new stdClass();
  $pane->pid = 'new-295a5b9c-4d31-436c-8a01-099e64ccea09';
  $pane->panel = 'row_1';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_service_offline_message';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_field_value:node:service:field_service_status',
        'settings' => array(
          'field_service_status' => array(
            'und' => array(
              0 => array(
                'value' => '0',
              ),
            ),
          ),
          'field_service_status_value' => array(
            0 => '0',
          ),
        ),
        'context' => 'panelizer',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '295a5b9c-4d31-436c-8a01-099e64ccea09';
  $display->content['new-295a5b9c-4d31-436c-8a01-099e64ccea09'] = $pane;
  $display->panels['row_1'][6] = 'new-295a5b9c-4d31-436c-8a01-099e64ccea09';
  $pane = new stdClass();
  $pane->pid = 'new-26fc3d25-437c-4fb1-be06-37e298138b7b';
  $pane->panel = 'row_1';
  $pane->type = 'syn_service_weed_id_form_pane';
  $pane->subtype = 'syn_service_weed_id_form_pane';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'entity_field_value:node:service:field_service_status',
        'settings' => array(
          'field_service_status' => array(
            'und' => array(
              0 => array(
                'value' => '1',
              ),
            ),
          ),
          'field_service_status_value' => array(
            0 => '1',
          ),
        ),
        'context' => 'panelizer',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '26fc3d25-437c-4fb1-be06-37e298138b7b';
  $display->content['new-26fc3d25-437c-4fb1-be06-37e298138b7b'] = $pane;
  $display->panels['row_1'][7] = 'new-26fc3d25-437c-4fb1-be06-37e298138b7b';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-cdfd1b9a-ece5-48b7-9f47-1d9ac56db1c5';
  $panelizer->display = $display;
  $export['node:service:weed_id_full'] = $panelizer;

  return $export;
}
