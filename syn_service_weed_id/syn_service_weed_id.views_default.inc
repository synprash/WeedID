<?php

/**
 * @file
 * syn_service_weed_id.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function syn_service_weed_id_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'service_subscribers__service_weed_id';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Services subscribers: Weed ID';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access syngenta service configuration page';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'field_profile_first_name' => 'field_profile_first_name',
    'field_profile_last_name' => 'field_profile_last_name',
    'timestamp' => 'timestamp',
    'mail' => 'mail',
    'field_profile_customer_type' => 'field_profile_customer_type',
    'nothing' => 'nothing',
    'nothing_1' => 'nothing_1',
    'nothing_2' => 'nothing_2',
  );
  $handler->display->display_options['style_options']['default'] = 'field_profile_last_name';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_profile_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_profile_customer_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Total subscribers: @total';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No found subscribers!';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Flags: service_weed_id */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'service_weed_id';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Relationship: Flags: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'flagging';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Profile: First name */
  $handler->display->display_options['fields']['field_profile_first_name']['id'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['table'] = 'field_data_field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['field'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['relationship'] = 'profile';
  /* Field: Profile: Last name */
  $handler->display->display_options['fields']['field_profile_last_name']['id'] = 'field_profile_last_name';
  $handler->display->display_options['fields']['field_profile_last_name']['table'] = 'field_data_field_profile_last_name';
  $handler->display->display_options['fields']['field_profile_last_name']['field'] = 'field_profile_last_name';
  $handler->display->display_options['fields']['field_profile_last_name']['relationship'] = 'profile';
  /* Field: Flags: Flagged time */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'flagging';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Subscription date';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'syngenta_short';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'syngenta_short';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  $handler->display->display_options['fields']['mail']['label'] = 'Email';
  /* Field: Profile: I am a */
  $handler->display->display_options['fields']['field_profile_customer_type']['id'] = 'field_profile_customer_type';
  $handler->display->display_options['fields']['field_profile_customer_type']['table'] = 'field_data_field_profile_customer_type';
  $handler->display->display_options['fields']['field_profile_customer_type']['field'] = 'field_profile_customer_type';
  $handler->display->display_options['fields']['field_profile_customer_type']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_customer_type']['label'] = 'Customer type';
  $handler->display->display_options['fields']['field_profile_customer_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'My dashboard';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'My dashboard';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'user/[uid]/dashboard';
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'My services';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'My services';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'user/[uid]/services';
  $handler->display->display_options['fields']['nothing_1']['alter']['absolute'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = 'My profile';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = 'My profile';
  $handler->display->display_options['fields']['nothing_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['path'] = 'user/[uid]/profile';
  $handler->display->display_options['fields']['nothing_2']['alter']['absolute'] = TRUE;
  /* Sort criterion: Profile: First name (field_profile_first_name) */
  $handler->display->display_options['sorts']['field_profile_first_name_value']['id'] = 'field_profile_first_name_value';
  $handler->display->display_options['sorts']['field_profile_first_name_value']['table'] = 'field_data_field_profile_first_name';
  $handler->display->display_options['sorts']['field_profile_first_name_value']['field'] = 'field_profile_first_name_value';
  $handler->display->display_options['sorts']['field_profile_first_name_value']['relationship'] = 'profile';
  /* Sort criterion: Profile: Last name (field_profile_last_name) */
  $handler->display->display_options['sorts']['field_profile_last_name_value']['id'] = 'field_profile_last_name_value';
  $handler->display->display_options['sorts']['field_profile_last_name_value']['table'] = 'field_data_field_profile_last_name';
  $handler->display->display_options['sorts']['field_profile_last_name_value']['field'] = 'field_profile_last_name_value';
  $handler->display->display_options['sorts']['field_profile_last_name_value']['relationship'] = 'profile';
  /* Sort criterion: Flags: Flagged time */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'flagging';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['relationship'] = 'flag_content_rel';
  /* Sort criterion: User: E-mail */
  $handler->display->display_options['sorts']['mail']['id'] = 'mail';
  $handler->display->display_options['sorts']['mail']['table'] = 'users';
  $handler->display->display_options['sorts']['mail']['field'] = 'mail';
  $handler->display->display_options['sorts']['mail']['relationship'] = 'uid';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Profile: I am a (field_profile_customer_type) */
  $handler->display->display_options['filters']['field_profile_customer_type_target_id']['id'] = 'field_profile_customer_type_target_id';
  $handler->display->display_options['filters']['field_profile_customer_type_target_id']['table'] = 'field_data_field_profile_customer_type';
  $handler->display->display_options['filters']['field_profile_customer_type_target_id']['field'] = 'field_profile_customer_type_target_id';
  $handler->display->display_options['filters']['field_profile_customer_type_target_id']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_profile_customer_type_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_profile_customer_type_target_id']['expose']['operator_id'] = 'field_profile_customer_type_target_id_op';
  $handler->display->display_options['filters']['field_profile_customer_type_target_id']['expose']['label'] = 'Customer type';
  $handler->display->display_options['filters']['field_profile_customer_type_target_id']['expose']['operator'] = 'field_profile_customer_type_target_id_op';
  $handler->display->display_options['filters']['field_profile_customer_type_target_id']['expose']['identifier'] = 'field_profile_customer_type_target_id';
  $handler->display->display_options['filters']['field_profile_customer_type_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_profile_customer_type_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    3 => 0,
    8 => 0,
    6 => 0,
    4 => 0,
    7 => 0,
    11 => 0,
    9 => 0,
    5 => 0,
    12 => 0,
  );
  /* Filter criterion: Profile: Last name (field_profile_last_name) */
  $handler->display->display_options['filters']['field_profile_last_name_value']['id'] = 'field_profile_last_name_value';
  $handler->display->display_options['filters']['field_profile_last_name_value']['table'] = 'field_data_field_profile_last_name';
  $handler->display->display_options['filters']['field_profile_last_name_value']['field'] = 'field_profile_last_name_value';
  $handler->display->display_options['filters']['field_profile_last_name_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_profile_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_profile_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_profile_last_name_value']['expose']['operator_id'] = 'field_profile_last_name_value_op';
  $handler->display->display_options['filters']['field_profile_last_name_value']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['field_profile_last_name_value']['expose']['operator'] = 'field_profile_last_name_value_op';
  $handler->display->display_options['filters']['field_profile_last_name_value']['expose']['identifier'] = 'field_profile_last_name_value';
  $handler->display->display_options['filters']['field_profile_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    3 => 0,
    8 => 0,
    6 => 0,
    4 => 0,
    7 => 0,
    11 => 0,
    9 => 0,
    5 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['field_profile_last_name_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_profile_last_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_profile_last_name_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_profile_last_name_value']['expose']['autocomplete_field'] = 'field_profile_last_name';
  $handler->display->display_options['filters']['field_profile_last_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_profile_last_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_profile_last_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Date: Date (flagging) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'flagging';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Subscription date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    3 => 0,
    8 => 0,
    6 => 0,
    4 => 0,
    7 => 0,
    11 => 0,
    9 => 0,
    5 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'flagging.timestamp' => 'flagging.timestamp',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';

  /* Display: Service Weed ID: CSV Export */
  $handler = $view->new_display('views_data_export', 'Service Weed ID: CSV Export', 'service_weed_id_export');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['separator'] = ';';
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Profile: First name */
  $handler->display->display_options['fields']['field_profile_first_name']['id'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['table'] = 'field_data_field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['field'] = 'field_profile_first_name';
  $handler->display->display_options['fields']['field_profile_first_name']['relationship'] = 'profile';
  /* Field: Profile: Last name */
  $handler->display->display_options['fields']['field_profile_last_name']['id'] = 'field_profile_last_name';
  $handler->display->display_options['fields']['field_profile_last_name']['table'] = 'field_data_field_profile_last_name';
  $handler->display->display_options['fields']['field_profile_last_name']['field'] = 'field_profile_last_name';
  $handler->display->display_options['fields']['field_profile_last_name']['relationship'] = 'profile';
  /* Field: Flags: Flagged time */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'flagging';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Subscription date';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'syngenta_short';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'syngenta_short';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  $handler->display->display_options['fields']['mail']['label'] = 'Email';
  /* Field: Profile: I am a */
  $handler->display->display_options['fields']['field_profile_customer_type']['id'] = 'field_profile_customer_type';
  $handler->display->display_options['fields']['field_profile_customer_type']['table'] = 'field_data_field_profile_customer_type';
  $handler->display->display_options['fields']['field_profile_customer_type']['field'] = 'field_profile_customer_type';
  $handler->display->display_options['fields']['field_profile_customer_type']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_customer_type']['label'] = 'Customer type';
  $handler->display->display_options['fields']['field_profile_customer_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Subscribe';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '1';
  $handler->display->display_options['path'] = 'admin/services/weed_id_service/export';
  $handler->display->display_options['displays'] = array(
    'service_weed_id' => 'service_weed_id',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '50';

  /* Display: Service Weed ID: Listing */
  $handler = $view->new_display('panel_pane', 'Service Weed ID: Listing', 'service_weed_id');
  $handler->display->display_options['pane_category']['name'] = 'Syngenta: My Services Admin';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['service_subscribers__service_weed_id'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Total subscribers: @total'),
    t('No found subscribers!'),
    t('flag'),
    t('Flag user'),
    t('Profile'),
    t('First name'),
    t('Last name'),
    t('Subscription date'),
    t('Email'),
    t('Customer type'),
    t('My dashboard'),
    t('My services'),
    t('My profile'),
    t('All'),
    t('Service Weed ID: CSV Export'),
    t('Subscribe'),
    t('1'),
    t('Service Weed ID: Listing'),
    t('Syngenta: My Services Admin'),
  );
  $export['service_subscribers__service_weed_id'] = $view;

  $view = new view();
  $view->name = 'service_weed_id_criteria';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Service: Weed ID: Criteria';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '16';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '4';
  $handler->display->display_options['pager']['options']['tags']['first'] = '';
  $handler->display->display_options['pager']['options']['tags']['previous'] = 'Previous';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'Next';
  $handler->display->display_options['pager']['options']['tags']['last'] = '';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'service_weed_id_criteria_expanded';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Contextual filter: Taxonomy term: Weed types (field_weed_id_weed_types) */
  $handler->display->display_options['arguments']['field_weed_id_weed_types_value']['id'] = 'field_weed_id_weed_types_value';
  $handler->display->display_options['arguments']['field_weed_id_weed_types_value']['table'] = 'field_data_field_weed_id_weed_types';
  $handler->display->display_options['arguments']['field_weed_id_weed_types_value']['field'] = 'field_weed_id_weed_types_value';
  $handler->display->display_options['arguments']['field_weed_id_weed_types_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_weed_id_weed_types_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_weed_id_weed_types_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_weed_id_weed_types_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_weed_id_weed_types_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_weed_id_weed_types_value']['limit'] = '0';
  /* Contextual filter: Taxonomy term: Type (field_weed_id_criteria_type) */
  $handler->display->display_options['arguments']['field_weed_id_criteria_type_target_id']['id'] = 'field_weed_id_criteria_type_target_id';
  $handler->display->display_options['arguments']['field_weed_id_criteria_type_target_id']['table'] = 'field_data_field_weed_id_criteria_type';
  $handler->display->display_options['arguments']['field_weed_id_criteria_type_target_id']['field'] = 'field_weed_id_criteria_type_target_id';
  $handler->display->display_options['arguments']['field_weed_id_criteria_type_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_weed_id_criteria_type_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_weed_id_criteria_type_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_weed_id_criteria_type_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_weed_id_criteria_type_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  $handler->display->display_options['arguments']['tid']['not'] = TRUE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'service_weed_id_criteria' => 'service_weed_id_criteria',
  );

  /* Display: Block: Step 2: Add */
  $handler = $view->new_display('block', 'Block: Step 2: Add', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: Taxonomy term: Picture */
  $handler->display->display_options['fields']['field_term_image']['id'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image']['table'] = 'field_data_field_term_image';
  $handler->display->display_options['fields']['field_term_image']['field'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image']['label'] = '';
  $handler->display->display_options['fields']['field_term_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_term_image']['settings'] = array(
    'file_view_mode' => 'service_weed_id_criteria_img',
  );
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['description_field_et']['id'] = 'description_field_et';
  $handler->display->display_options['fields']['description_field_et']['table'] = 'field_data_description_field';
  $handler->display->display_options['fields']['description_field_et']['field'] = 'description_field_et';
  $handler->display->display_options['fields']['description_field_et']['label'] = '';
  $handler->display->display_options['fields']['description_field_et']['element_label_colon'] = FALSE;
  /* Field: Entity translation: Name: translated */
  $handler->display->display_options['fields']['name_field_et']['id'] = 'name_field_et';
  $handler->display->display_options['fields']['name_field_et']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field_et']['field'] = 'name_field_et';
  $handler->display->display_options['fields']['name_field_et']['label'] = '';
  $handler->display->display_options['fields']['name_field_et']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_field_et']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="service-weed-id-add" data-tid="[tid]">+</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[name_field_et]
[nothing]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';

  /* Display: Block: Step 3: Selection */
  $handler = $view->new_display('block', 'Block: Step 3: Selection', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entity translation: Name: translated */
  $handler->display->display_options['fields']['name_field_et']['id'] = 'name_field_et';
  $handler->display->display_options['fields']['name_field_et']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field_et']['field'] = 'name_field_et';
  $handler->display->display_options['fields']['name_field_et']['label'] = '';
  $handler->display->display_options['fields']['name_field_et']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;

  /* Display: Block: Step 2: Selection */
  $handler = $view->new_display('block', 'Block: Step 2: Selection', 'block_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: Taxonomy term: Picture */
  $handler->display->display_options['fields']['field_term_image']['id'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image']['table'] = 'field_data_field_term_image';
  $handler->display->display_options['fields']['field_term_image']['field'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image']['label'] = '';
  $handler->display->display_options['fields']['field_term_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_term_image']['settings'] = array(
    'file_view_mode' => 'service_weed_id_criteria_img',
  );
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['description_field_et']['id'] = 'description_field_et';
  $handler->display->display_options['fields']['description_field_et']['table'] = 'field_data_description_field';
  $handler->display->display_options['fields']['description_field_et']['field'] = 'description_field_et';
  $handler->display->display_options['fields']['description_field_et']['label'] = '';
  $handler->display->display_options['fields']['description_field_et']['element_label_colon'] = FALSE;
  /* Field: Entity translation: Name: translated */
  $handler->display->display_options['fields']['name_field_et']['id'] = 'name_field_et';
  $handler->display->display_options['fields']['name_field_et']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field_et']['field'] = 'name_field_et';
  $handler->display->display_options['fields']['name_field_et']['label'] = '';
  $handler->display->display_options['fields']['name_field_et']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_field_et']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="service-weed-id-remove" data-tid="[tid]">X</div>';
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '<front>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[name_field_et]
[nothing]
';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;

  /* Display: Block: Step 4: Comparison */
  $handler = $view->new_display('block', 'Block: Step 4: Comparison', 'block_3');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'slick';
  $handler->display->display_options['style_options']['slide_field_wrapper'] = 0;
  $handler->display->display_options['style_options']['asnavfor_auto'] = 0;
  $handler->display->display_options['style_options']['optionset'] = 'weed_id';
  $handler->display->display_options['style_options']['slide_caption'] = array(
    'nothing' => 0,
    'field_term_image' => 0,
    'nothing_1' => 0,
    'field_weed_targets' => 0,
  );
  $handler->display->display_options['style_options']['slide_overlay'] = '';
  $handler->display->display_options['style_options']['preserve_keys'] = 0;
  $handler->display->display_options['style_options']['override'] = 0;
  $handler->display->display_options['style_options']['overridables'] = array(
    'arrows' => 0,
    'autoplay' => 0,
    'dots' => 0,
    'draggable' => 0,
  );
  $handler->display->display_options['style_options']['cache'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<div id="weed-id-comparison-scroll-up">SCROLL UP</div>';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<div id="weed-id-comparison-scroll-down">SCROLL DOWN</div>';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Taxonomy term: Weed data (field_weed_data) */
  $handler->display->display_options['relationships']['field_weed_data_value']['id'] = 'field_weed_data_value';
  $handler->display->display_options['relationships']['field_weed_data_value']['table'] = 'field_data_field_weed_data';
  $handler->display->display_options['relationships']['field_weed_data_value']['field'] = 'field_weed_data_value';
  $handler->display->display_options['relationships']['field_weed_data_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_weed_data_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'dot dot-left dot-@dot_class';
  /* Field: Taxonomy term: Picture */
  $handler->display->display_options['fields']['field_term_image']['id'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image']['table'] = 'field_data_field_term_image';
  $handler->display->display_options['fields']['field_term_image']['field'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image']['label'] = '';
  $handler->display->display_options['fields']['field_term_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_term_image']['settings'] = array(
    'file_view_mode' => 'service_weed_id_criteria_img',
  );
  $handler->display->display_options['fields']['field_term_image']['group_column'] = 'entity_id';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'dot dot-right dot-@dot_class';
  /* Field: Field collection item: Targets */
  $handler->display->display_options['fields']['field_weed_targets']['id'] = 'field_weed_targets';
  $handler->display->display_options['fields']['field_weed_targets']['table'] = 'field_data_field_weed_targets';
  $handler->display->display_options['fields']['field_weed_targets']['field'] = 'field_weed_targets';
  $handler->display->display_options['fields']['field_weed_targets']['relationship'] = 'field_weed_data_value';
  $handler->display->display_options['fields']['field_weed_targets']['label'] = '';
  $handler->display->display_options['fields']['field_weed_targets']['element_type'] = '0';
  $handler->display->display_options['fields']['field_weed_targets']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_weed_targets']['element_wrapper_class'] = 'element-invisible';
  $handler->display->display_options['fields']['field_weed_targets']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_weed_targets']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_weed_targets']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field collection item: Weed Type (field_weed_type) */
  $handler->display->display_options['arguments']['field_weed_type_value']['id'] = 'field_weed_type_value';
  $handler->display->display_options['arguments']['field_weed_type_value']['table'] = 'field_data_field_weed_type';
  $handler->display->display_options['arguments']['field_weed_type_value']['field'] = 'field_weed_type_value';
  $handler->display->display_options['arguments']['field_weed_type_value']['relationship'] = 'field_weed_data_value';
  $handler->display->display_options['arguments']['field_weed_type_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_weed_type_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_weed_type_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_weed_type_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_weed_type_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_weed_type_value']['limit'] = '0';
  /* Contextual filter: Field collection item: Targets (field_weed_targets) */
  $handler->display->display_options['arguments']['field_weed_targets_target_id']['id'] = 'field_weed_targets_target_id';
  $handler->display->display_options['arguments']['field_weed_targets_target_id']['table'] = 'field_data_field_weed_targets';
  $handler->display->display_options['arguments']['field_weed_targets_target_id']['field'] = 'field_weed_targets_target_id';
  $handler->display->display_options['arguments']['field_weed_targets_target_id']['relationship'] = 'field_weed_data_value';
  $handler->display->display_options['arguments']['field_weed_targets_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_weed_targets_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_weed_targets_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_weed_targets_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_weed_targets_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_weed_targets_target_id']['break_phrase'] = TRUE;
  $translatables['service_weed_id_criteria'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Previous'),
    t('Next'),
    t('All'),
    t('Block: Step 2: Add'),
    t('.'),
    t('<div class="service-weed-id-add" data-tid="[tid]">+</div>'),
    t('[name_field_et]
[nothing]'),
    t('Block: Step 3: Selection'),
    t('Block: Step 2: Selection'),
    t('<div class="service-weed-id-remove" data-tid="[tid]">X</div>'),
    t('[name_field_et]
[nothing]
'),
    t('Block: Step 4: Comparison'),
    t('<div id="weed-id-comparison-scroll-up">SCROLL UP</div>'),
    t('<div id="weed-id-comparison-scroll-down">SCROLL DOWN</div>'),
    t('field collection item from field_weed_data'),
  );
  $export['service_weed_id_criteria'] = $view;

  $view = new view();
  $view->name = 'service_weed_id_target';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Service: Weed ID: Target';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Service: Weed ID: Target';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '4';
  $handler->display->display_options['pager']['options']['tags']['first'] = '';
  $handler->display->display_options['pager']['options']['tags']['previous'] = 'Previous';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'Next';
  $handler->display->display_options['pager']['options']['tags']['last'] = '';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '<div class="weed-id-percent-container weed-id-@match_percent_number-percent-match">
  @match_percent_text
  @image_zoom_link
</div>';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  /* Field: Content: Teaser image */
  $handler->display->display_options['fields']['field_teaser_image']['id'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['table'] = 'field_data_field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['field'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['label'] = '';
  $handler->display->display_options['fields']['field_teaser_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_teaser_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_teaser_image']['settings'] = array(
    'file_view_mode' => 'product_teaser',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'service-weed-id/popup/nojs/weed/[nid]';
  $handler->display->display_options['fields']['title']['alter']['link_class'] = 'ctools-use-modal ctools-modal-weedid-modal-style';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '100',
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_target_type']['id'] = 'field_target_type';
  $handler->display->display_options['fields']['field_target_type']['table'] = 'field_data_field_target_type';
  $handler->display->display_options['fields']['field_target_type']['field'] = 'field_target_type';
  $handler->display->display_options['fields']['field_target_type']['label'] = '';
  $handler->display->display_options['fields']['field_target_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_target_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_target_type']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_target_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[body]

[field_target_type]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'service-weed-id/popup/nojs/weed/[nid]';
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'ctools-use-modal ctools-modal-weedid-modal-style';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '@compare';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'weed-id-compare-container';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'target' => 'target',
  );

  /* Display: Block: Step 3: Results */
  $handler = $view->new_display('block', 'Block: Step 3: Results', 'block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '<div class="weed-id-percent-container weed-id-@match_percent_number-percent-match">
  @match_percent_text
  @image_zoom_link
</div>';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  /* Field: Content: Teaser image */
  $handler->display->display_options['fields']['field_teaser_image']['id'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['table'] = 'field_data_field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['field'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['label'] = '';
  $handler->display->display_options['fields']['field_teaser_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_teaser_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_teaser_image']['settings'] = array(
    'file_view_mode' => 'product_teaser',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'service-weed-id/popup/nojs/weed/[nid]';
  $handler->display->display_options['fields']['title']['alter']['link_class'] = 'ctools-use-modal ctools-modal-weedid-modal-style';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '100',
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_target_type']['id'] = 'field_target_type';
  $handler->display->display_options['fields']['field_target_type']['table'] = 'field_data_field_target_type';
  $handler->display->display_options['fields']['field_target_type']['field'] = 'field_target_type';
  $handler->display->display_options['fields']['field_target_type']['label'] = '';
  $handler->display->display_options['fields']['field_target_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_target_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_target_type']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_target_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[body]

[field_target_type]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'service-weed-id/popup/nojs/weed/[nid]';
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'ctools-use-modal ctools-modal-weedid-modal-style';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '@compare';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'weed-id-compare-container';

  /* Display: Block: Step 4: Compare */
  $handler = $view->new_display('block', 'Block: Step 4: Compare', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '<div class="weed-id-percent-container weed-id-@match_percent_number-percent-match">
  @match_percent_text
</div>';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['link_class'] = 'ctools-use-modal ctools-modal-weedid-modal-style';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Code EPPO */
  $handler->display->display_options['fields']['field_target_code_eppo']['id'] = 'field_target_code_eppo';
  $handler->display->display_options['fields']['field_target_code_eppo']['table'] = 'field_data_field_target_code_eppo';
  $handler->display->display_options['fields']['field_target_code_eppo']['field'] = 'field_target_code_eppo';
  $handler->display->display_options['fields']['field_target_code_eppo']['label'] = '';
  $handler->display->display_options['fields']['field_target_code_eppo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_target_code_eppo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_target_code_eppo']['type'] = 'text_plain';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '100',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[title] ([field_target_code_eppo])
[body]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'service-weed-id/popup/nojs/weed/[nid]';
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'ctools-use-modal ctools-modal-weedid-modal-style';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Go to target page';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Read more';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = '<front>';
  $handler->display->display_options['fields']['nothing_1']['alter']['link_class'] = 'weed-compare-read-more';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'weed-id-compare-container';
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'service_weed_id_target';
  $handler->display->display_options['fields']['view']['display'] = 'block_2';
  $handler->display->display_options['fields']['view']['arguments'] = '[!nid]';
  /* Field: Global: View */
  $handler->display->display_options['fields']['view_1']['id'] = 'view_1';
  $handler->display->display_options['fields']['view_1']['table'] = 'views';
  $handler->display->display_options['fields']['view_1']['field'] = 'view';
  $handler->display->display_options['fields']['view_1']['label'] = '';
  $handler->display->display_options['fields']['view_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_1']['view'] = 'service_weed_id_target';
  $handler->display->display_options['fields']['view_1']['display'] = 'block_3';
  $handler->display->display_options['fields']['view_1']['arguments'] = '[!nid]';
  /* Field: Global: View */
  $handler->display->display_options['fields']['view_2']['id'] = 'view_2';
  $handler->display->display_options['fields']['view_2']['table'] = 'views';
  $handler->display->display_options['fields']['view_2']['field'] = 'view';
  $handler->display->display_options['fields']['view_2']['label'] = '';
  $handler->display->display_options['fields']['view_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_2']['view'] = 'service_weed_id_target';
  $handler->display->display_options['fields']['view_2']['display'] = 'block_4';
  $handler->display->display_options['fields']['view_2']['arguments'] = '[!nid]';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Block: Step 4: More information */
  $handler = $view->new_display('block', 'Block: Step 4: More information', 'block_2');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_target_hfn_potential_target_id']['id'] = 'field_target_hfn_potential_target_id';
  $handler->display->display_options['relationships']['field_target_hfn_potential_target_id']['table'] = 'field_data_field_target_hfn_potential';
  $handler->display->display_options['relationships']['field_target_hfn_potential_target_id']['field'] = 'field_target_hfn_potential_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Picture */
  $handler->display->display_options['fields']['field_term_image']['id'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image']['table'] = 'field_data_field_term_image';
  $handler->display->display_options['fields']['field_term_image']['field'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image']['relationship'] = 'field_target_hfn_potential_target_id';
  $handler->display->display_options['fields']['field_term_image']['label'] = 'Harmfullness';
  $handler->display->display_options['fields']['field_term_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_term_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_term_image']['settings'] = array(
    'file_view_mode' => 'term_thumbnail',
  );
  /* Field: Content: Latin name */
  $handler->display->display_options['fields']['field_target_latin_name']['id'] = 'field_target_latin_name';
  $handler->display->display_options['fields']['field_target_latin_name']['table'] = 'field_data_field_target_latin_name';
  $handler->display->display_options['fields']['field_target_latin_name']['field'] = 'field_target_latin_name';
  $handler->display->display_options['fields']['field_target_latin_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_target_latin_name']['hide_empty'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_target_type']['id'] = 'field_target_type';
  $handler->display->display_options['fields']['field_target_type']['table'] = 'field_data_field_target_type';
  $handler->display->display_options['fields']['field_target_type']['field'] = 'field_target_type';
  $handler->display->display_options['fields']['field_target_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_target_type']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_target_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Family */
  $handler->display->display_options['fields']['field_target_family']['id'] = 'field_target_family';
  $handler->display->display_options['fields']['field_target_family']['table'] = 'field_data_field_target_family';
  $handler->display->display_options['fields']['field_target_family']['field'] = 'field_target_family';
  $handler->display->display_options['fields']['field_target_family']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_target_family']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_target_family']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Synonyme */
  $handler->display->display_options['fields']['field_target_synonyme']['id'] = 'field_target_synonyme';
  $handler->display->display_options['fields']['field_target_synonyme']['table'] = 'field_data_field_target_synonyme';
  $handler->display->display_options['fields']['field_target_synonyme']['field'] = 'field_target_synonyme';
  $handler->display->display_options['fields']['field_target_synonyme']['label'] = 'Synonyms';
  $handler->display->display_options['fields']['field_target_synonyme']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_target_synonyme']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_target_synonyme']['delta_offset'] = '0';
  /* Field: Content: Description seedling */
  $handler->display->display_options['fields']['field_target_description_seedlin']['id'] = 'field_target_description_seedlin';
  $handler->display->display_options['fields']['field_target_description_seedlin']['table'] = 'field_data_field_target_description_seedlin';
  $handler->display->display_options['fields']['field_target_description_seedlin']['field'] = 'field_target_description_seedlin';
  $handler->display->display_options['fields']['field_target_description_seedlin']['label'] = 'Young';
  $handler->display->display_options['fields']['field_target_description_seedlin']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_target_description_seedlin']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_target_description_seedlin']['type'] = 'text_plain';
  /* Field: Content: Description adult plant */
  $handler->display->display_options['fields']['field_target_description_adult_p']['id'] = 'field_target_description_adult_p';
  $handler->display->display_options['fields']['field_target_description_adult_p']['table'] = 'field_data_field_target_description_adult_p';
  $handler->display->display_options['fields']['field_target_description_adult_p']['field'] = 'field_target_description_adult_p';
  $handler->display->display_options['fields']['field_target_description_adult_p']['label'] = 'Adult';
  $handler->display->display_options['fields']['field_target_description_adult_p']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_target_description_adult_p']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_target_description_adult_p']['type'] = 'text_plain';
  /* Field: Content: Likelihood of confusion */
  $handler->display->display_options['fields']['field_target_liklihood_confusion']['id'] = 'field_target_liklihood_confusion';
  $handler->display->display_options['fields']['field_target_liklihood_confusion']['table'] = 'field_data_field_target_liklihood_confusion';
  $handler->display->display_options['fields']['field_target_liklihood_confusion']['field'] = 'field_target_liklihood_confusion';
  $handler->display->display_options['fields']['field_target_liklihood_confusion']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_target_liklihood_confusion']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_target_liklihood_confusion']['type'] = 'text_plain';
  /* Field: Content: Particularities */
  $handler->display->display_options['fields']['field_target_particularities']['id'] = 'field_target_particularities';
  $handler->display->display_options['fields']['field_target_particularities']['table'] = 'field_data_field_target_particularities';
  $handler->display->display_options['fields']['field_target_particularities']['field'] = 'field_target_particularities';
  $handler->display->display_options['fields']['field_target_particularities']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_target_particularities']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_target_particularities']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Block: Seeding carousel */
  $handler = $view->new_display('block', 'Block: Seeding carousel', 'block_3');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'owlcarousel';
  $handler->display->display_options['style_options']['instance'] = 'owlcarousel_settings_single_without_autoscroll';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Multimedia seedling */
  $handler->display->display_options['fields']['field_target_multimedia_seedling']['id'] = 'field_target_multimedia_seedling';
  $handler->display->display_options['fields']['field_target_multimedia_seedling']['table'] = 'field_data_field_target_multimedia_seedling';
  $handler->display->display_options['fields']['field_target_multimedia_seedling']['field'] = 'field_target_multimedia_seedling';
  $handler->display->display_options['fields']['field_target_multimedia_seedling']['label'] = '';
  $handler->display->display_options['fields']['field_target_multimedia_seedling']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_target_multimedia_seedling']['alter']['text'] = '<a href="/service-weed-id/popup/nojs/image/[field_target_multimedia_seedling-fid]" class="ctools-use-modal ctools-modal-weedid-modal-style">ZOOM</a>
[field_target_multimedia_seedling]';
  $handler->display->display_options['fields']['field_target_multimedia_seedling']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_target_multimedia_seedling']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_target_multimedia_seedling']['settings'] = array(
    'file_view_mode' => 'syngenta_large',
  );
  $handler->display->display_options['fields']['field_target_multimedia_seedling']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_target_multimedia_seedling']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;

  /* Display: Block: Adult plant carousel */
  $handler = $view->new_display('block', 'Block: Adult plant carousel', 'block_4');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'owlcarousel';
  $handler->display->display_options['style_options']['instance'] = 'owlcarousel_settings_single_without_autoscroll';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Multimedia adult plant */
  $handler->display->display_options['fields']['field_target_multimedia_adult_pl']['id'] = 'field_target_multimedia_adult_pl';
  $handler->display->display_options['fields']['field_target_multimedia_adult_pl']['table'] = 'field_data_field_target_multimedia_adult_pl';
  $handler->display->display_options['fields']['field_target_multimedia_adult_pl']['field'] = 'field_target_multimedia_adult_pl';
  $handler->display->display_options['fields']['field_target_multimedia_adult_pl']['label'] = '';
  $handler->display->display_options['fields']['field_target_multimedia_adult_pl']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_target_multimedia_adult_pl']['alter']['text'] = '<a href="/service-weed-id/popup/nojs/image/[field_target_multimedia_adult_pl-fid]" class="ctools-use-modal ctools-modal-weedid-modal-style">ZOOM</a>
[field_target_multimedia_adult_pl]';
  $handler->display->display_options['fields']['field_target_multimedia_adult_pl']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_target_multimedia_adult_pl']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_target_multimedia_adult_pl']['settings'] = array(
    'file_view_mode' => 'default',
  );
  $handler->display->display_options['fields']['field_target_multimedia_adult_pl']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_target_multimedia_adult_pl']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;

  /* Display: Block: Step 4: More information */
  $handler = $view->new_display('block', 'Block: Step 4: More information', 'block_5');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'owlcarousel';
  $handler->display->display_options['style_options']['instance'] = 'owlcarousel_settings_single_without_autoscroll';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_target_hfn_potential_target_id']['id'] = 'field_target_hfn_potential_target_id';
  $handler->display->display_options['relationships']['field_target_hfn_potential_target_id']['table'] = 'field_data_field_target_hfn_potential';
  $handler->display->display_options['relationships']['field_target_hfn_potential_target_id']['field'] = 'field_target_hfn_potential_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Multimedia seedling */
  $handler->display->display_options['fields']['field_target_multimedia_seedling']['id'] = 'field_target_multimedia_seedling';
  $handler->display->display_options['fields']['field_target_multimedia_seedling']['table'] = 'field_data_field_target_multimedia_seedling';
  $handler->display->display_options['fields']['field_target_multimedia_seedling']['field'] = 'field_target_multimedia_seedling';
  $handler->display->display_options['fields']['field_target_multimedia_seedling']['label'] = '';
  $handler->display->display_options['fields']['field_target_multimedia_seedling']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_target_multimedia_seedling']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_target_multimedia_seedling']['settings'] = array(
    'file_view_mode' => 'syngenta_large',
  );
  $handler->display->display_options['fields']['field_target_multimedia_seedling']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_target_multimedia_seedling']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_target_multimedia_seedling']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['block_description'] = 'Seedling target carousel';

  /* Display: Block: Step 4: More information */
  $handler = $view->new_display('block', 'Block: Step 4: More information', 'block_7');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'owlcarousel';
  $handler->display->display_options['style_options']['instance'] = 'owlcarousel_settings_single_without_autoscroll';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_target_hfn_potential_target_id']['id'] = 'field_target_hfn_potential_target_id';
  $handler->display->display_options['relationships']['field_target_hfn_potential_target_id']['table'] = 'field_data_field_target_hfn_potential';
  $handler->display->display_options['relationships']['field_target_hfn_potential_target_id']['field'] = 'field_target_hfn_potential_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Multimedia adult plant */
  $handler->display->display_options['fields']['field_target_multimedia_adult_pl']['id'] = 'field_target_multimedia_adult_pl';
  $handler->display->display_options['fields']['field_target_multimedia_adult_pl']['table'] = 'field_data_field_target_multimedia_adult_pl';
  $handler->display->display_options['fields']['field_target_multimedia_adult_pl']['field'] = 'field_target_multimedia_adult_pl';
  $handler->display->display_options['fields']['field_target_multimedia_adult_pl']['label'] = '';
  $handler->display->display_options['fields']['field_target_multimedia_adult_pl']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_target_multimedia_adult_pl']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_target_multimedia_adult_pl']['settings'] = array(
    'file_view_mode' => 'syngenta_large',
  );
  $handler->display->display_options['fields']['field_target_multimedia_adult_pl']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_target_multimedia_adult_pl']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['block_description'] = 'Adult target carousel';
  $translatables['service_weed_id_target'] = array(
    t('Master'),
    t('Service: Weed ID: Target'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Previous'),
    t('Next'),
    t('<div class="weed-id-percent-container weed-id-@match_percent_number-percent-match">
  @match_percent_text
  @image_zoom_link
</div>'),
    t('[body]

[field_target_type]'),
    t('@compare'),
    t('All'),
    t('Block: Step 3: Results'),
    t('Block: Step 4: Compare'),
    t('<div class="weed-id-percent-container weed-id-@match_percent_number-percent-match">
  @match_percent_text
</div>'),
    t('[title] ([field_target_code_eppo])
[body]'),
    t('Go to target page'),
    t('Read more'),
    t('Block: Step 4: More information'),
    t('Taxonomy term entity referenced from field_target_hfn_potential'),
    t('Harmfullness'),
    t('Latin name'),
    t('Type'),
    t('Family'),
    t('Synonyms'),
    t('Young'),
    t('Adult'),
    t('Likelihood of confusion'),
    t('Particularities'),
    t('Block: Seeding carousel'),
    t('<a href="/service-weed-id/popup/nojs/image/[field_target_multimedia_seedling-fid]" class="ctools-use-modal ctools-modal-weedid-modal-style">ZOOM</a>
[field_target_multimedia_seedling]'),
    t('Block: Adult plant carousel'),
    t('<a href="/service-weed-id/popup/nojs/image/[field_target_multimedia_adult_pl-fid]" class="ctools-use-modal ctools-modal-weedid-modal-style">ZOOM</a>
[field_target_multimedia_adult_pl]'),
    t('Seedling target carousel'),
    t('Adult target carousel'),
  );
  $export['service_weed_id_target'] = $view;

  return $export;
}
