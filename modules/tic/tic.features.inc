<?php
/**
 * @file
 * tic.features.inc
 */

/**
 * Implements hook_node_info().
 */
function tic_node_info() {
  $items = array(
    'recipe' => array(
      'name' => t('recipe'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
