<?php

/**
 * @file
 * syn_service_weed_id.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function syn_service_weed_id_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'add terms in service_weed_id_criteria'.
  $permissions['add terms in service_weed_id_criteria'] = array(
    'name' => 'add terms in service_weed_id_criteria',
    'roles' => array(
      'administrator' => 'administrator',
      'Site Admin' => 'Site Admin',
      'Editor' => 'Editor',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in service_weed_id_criteria_group'.
  $permissions['add terms in service_weed_id_criteria_group'] = array(
    'name' => 'add terms in service_weed_id_criteria_group',
    'roles' => array(
      'administrator' => 'administrator',
      'Site Admin' => 'Site Admin',
      'Editor' => 'Editor',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in service_weed_id_criteria_type'.
  $permissions['add terms in service_weed_id_criteria_type'] = array(
    'name' => 'add terms in service_weed_id_criteria_type',
    'roles' => array(
      'administrator' => 'administrator',
      'Site Admin' => 'Site Admin',
      'Editor' => 'Editor',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'administer panelizer
  // taxonomy_term service_weed_id_criteria defaults'.
  $permissions['administer panelizer taxonomy_term service_weed_id_criteria defaults'] = array(
    'name' => 'administer panelizer taxonomy_term service_weed_id_criteria defaults',
    'roles' => array(
      'administrator' => 'administrator',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer
  // taxonomy_term service_weed_id_criteria_group defaults'.
  $permissions['administer panelizer taxonomy_term service_weed_id_criteria_group defaults'] = array(
    'name' => 'administer panelizer taxonomy_term service_weed_id_criteria_group defaults',
    'roles' => array(
      'administrator' => 'administrator',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer
  // taxonomy_term service_weed_id_criteria_type defaults'.
  $permissions['administer panelizer taxonomy_term service_weed_id_criteria_type defaults'] = array(
    'name' => 'administer panelizer taxonomy_term service_weed_id_criteria_type defaults',
    'roles' => array(
      'administrator' => 'administrator',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer service_weed_id_criteria
  // taxonomy manager vocabulary'.
  $permissions['administer service_weed_id_criteria taxonomy manager vocabulary'] = array(
    'name' => 'administer service_weed_id_criteria taxonomy manager vocabulary',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_manager',
  );

  // Exported permission: 'administer service_weed_id_criteria_group
  // taxonomy manager vocabulary'.
  $permissions['administer service_weed_id_criteria_group taxonomy manager vocabulary'] = array(
    'name' => 'administer service_weed_id_criteria_group taxonomy manager vocabulary',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_manager',
  );

  // Exported permission: 'administer service_weed_id_criteria_type
  // taxonomy manager vocabulary'.
  $permissions['administer service_weed_id_criteria_type taxonomy manager vocabulary'] = array(
    'name' => 'administer service_weed_id_criteria_type taxonomy manager vocabulary',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_manager',
  );

  // Exported permission: 'administer slick'.
  $permissions['administer slick'] = array(
    'name' => 'administer slick',
    'roles' => array(
      'administrator' => 'administrator',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'slick_ui',
  );

  // Exported permission: 'delete terms in service_weed_id_criteria'.
  $permissions['delete terms in service_weed_id_criteria'] = array(
    'name' => 'delete terms in service_weed_id_criteria',
    'roles' => array(
      'administrator' => 'administrator',
      'Site Admin' => 'Site Admin',
      'Editor' => 'Editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in service_weed_id_criteria_group'.
  $permissions['delete terms in service_weed_id_criteria_group'] = array(
    'name' => 'delete terms in service_weed_id_criteria_group',
    'roles' => array(
      'administrator' => 'administrator',
      'Site Admin' => 'Site Admin',
      'Editor' => 'Editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in service_weed_id_criteria_type'.
  $permissions['delete terms in service_weed_id_criteria_type'] = array(
    'name' => 'delete terms in service_weed_id_criteria_type',
    'roles' => array(
      'administrator' => 'administrator',
      'Site Admin' => 'Site Admin',
      'Editor' => 'Editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'eck add service_configuration weed_id entities'.
  $permissions['eck add service_configuration weed_id entities'] = array(
    'name' => 'eck add service_configuration weed_id entities',
    'roles' => array(
      'Agronomic Services Manager' => 'Agronomic Services Manager',
      'administrator' => 'administrator',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer service_configuration weed_id
  // entities'.
  $permissions['eck administer service_configuration weed_id entities'] = array(
    'name' => 'eck administer service_configuration weed_id entities',
    'roles' => array(
      'administrator' => 'administrator',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete service_configuration weed_id entities'.
  $permissions['eck delete service_configuration weed_id entities'] = array(
    'name' => 'eck delete service_configuration weed_id entities',
    'roles' => array(
      'Agronomic Services Manager' => 'Agronomic Services Manager',
      'administrator' => 'administrator',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit service_configuration weed_id entities'.
  $permissions['eck edit service_configuration weed_id entities'] = array(
    'name' => 'eck edit service_configuration weed_id entities',
    'roles' => array(
      'Agronomic Services Manager' => 'Agronomic Services Manager',
      'administrator' => 'administrator',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list service_configuration weed_id entities'.
  $permissions['eck list service_configuration weed_id entities'] = array(
    'name' => 'eck list service_configuration weed_id entities',
    'roles' => array(
      'Agronomic Services Manager' => 'Agronomic Services Manager',
      'administrator' => 'administrator',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view service_configuration weed_id entities'.
  $permissions['eck view service_configuration weed_id entities'] = array(
    'name' => 'eck view service_configuration weed_id entities',
    'roles' => array(
      'Agronomic Services Manager' => 'Agronomic Services Manager',
      'administrator' => 'administrator',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'edit terms in service_weed_id_criteria'.
  $permissions['edit terms in service_weed_id_criteria'] = array(
    'name' => 'edit terms in service_weed_id_criteria',
    'roles' => array(
      'administrator' => 'administrator',
      'Site Admin' => 'Site Admin',
      'Editor' => 'Editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in service_weed_id_criteria_group'.
  $permissions['edit terms in service_weed_id_criteria_group'] = array(
    'name' => 'edit terms in service_weed_id_criteria_group',
    'roles' => array(
      'administrator' => 'administrator',
      'Site Admin' => 'Site Admin',
      'Editor' => 'Editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in service_weed_id_criteria_type'.
  $permissions['edit terms in service_weed_id_criteria_type'] = array(
    'name' => 'edit terms in service_weed_id_criteria_type',
    'roles' => array(
      'administrator' => 'administrator',
      'Site Admin' => 'Site Admin',
      'Editor' => 'Editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'flag service_weed_id'.
  $permissions['flag service_weed_id'] = array(
    'name' => 'flag service_weed_id',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag service_weed_id'.
  $permissions['unflag service_weed_id'] = array(
    'name' => 'unflag service_weed_id',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'Site Admin' => 'Site Admin',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
