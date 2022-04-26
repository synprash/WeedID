<?php

/**
 * @file
 * syn_service_weed_id.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function syn_service_weed_id_taxonomy_default_vocabularies() {
  return array(
    'service_weed_id_criteria' => array(
      'name' => 'Service Weed ID criteria',
      'machine_name' => 'service_weed_id_criteria',
      'description' => 'Weed ID criteria',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'service_weed_id_criteria_group' => array(
      'name' => 'Service weed ID criteria group',
      'machine_name' => 'service_weed_id_criteria_group',
      'description' => 'Weed ID service criteria ',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'service_weed_id_criteria_type' => array(
      'name' => 'Service Weed ID criteria type',
      'machine_name' => 'service_weed_id_criteria_type',
      'description' => 'Weed ID service criteria types',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
