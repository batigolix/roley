<?php
/**
 * Inspects wrapped entities & fields.
 */
function tic_wrapper_inspect($w) {
  $values = array();
  foreach ($w->getPropertyInfo() as $key => $val) {
    $values[$key] = $w->$key->value();
  }
  return $values;
}

/**
 * @file
 * Drush commands for fun and profit.
 */
/**
 * Implements hook_drush_command().
 */
function tic_drush_command() {
  $items['tic-set-schema'] = array(
    'callback' => 'tic_set_schema',
    'description' => "Reset the schema version of a module",
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_DATABASE,
    'aliases' => array('ss'),
    'arguments' => array(
      'module' => 'The module to set the schemaversion for.',
      'version' => 'The schemaversion to set.'
    ),
  );
  return $items;
}

function tic_set_schema($module = NULL, $version = NULL) {
  if (module_exists($module) && is_numeric($version)) {
    db_update('system')
      ->fields(array(
        'schema_version' => $version,
      ))
      ->condition('name', $module, '=')
      ->execute();
  }
  elseif (module_exists($module)) {
    $query = db_select('system', 's')
      ->fields('s', array('schema_version'))
      ->condition('name', $module, '=')
      ->execute();
    $version = $query->fetchField();
    drush_print($module . ' is at schema version ' . $version);
  }
  else {
    drush_print('Please check your syntax...');
  }
}