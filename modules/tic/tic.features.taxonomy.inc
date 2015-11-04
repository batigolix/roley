<?php
/**
 * @file
 * tic.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tic_taxonomy_default_vocabularies() {
  return array(
    'kitchen' => array(
      'name' => 'Kitchen',
      'machine_name' => 'kitchen',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
