<?php
// Configure relationships.
$relationships = json_decode(base64_decode($_ENV['PLATFORM_RELATIONSHIPS']), TRUE);

if (empty($databases['default']['default'])) {
  foreach ($relationships['database'] as $endpoint) {
    $database = array(
      'driver' => $endpoint['scheme'],
      'database' => $endpoint['path'],
      'username' => $endpoint['username'],
      'password' => $endpoint['password'],
      'host' => $endpoint['host'],
    );

    if (!empty($endpoint['query']['compression'])) {
      $database['pdo'][PDO::MYSQL_ATTR_COMPRESS] = TRUE;
    }

    if (!empty($endpoint['query']['is_master'])) {
      $databases['default']['default'] = $database;
    }
    else {
      $databases['default']['slave'][] = $database;
    }
  }
}

$routes = json_decode(base64_decode($_ENV['PLATFORM_ROUTES']), TRUE);

if (!isset($conf['file_private_path'])) {
  if(!$application_home = getenv('PLATFORM_APP_DIR')) {
    $application_home = '/app';
  }
  $conf['file_private_path'] = $application_home . '/private';
  $conf['file_temporary_path'] = $application_home . '/tmp';
}

$variables = json_decode(base64_decode($_ENV['PLATFORM_VARIABLES']), TRUE);

$prefix_len = strlen('drupal:');
foreach ($variables as $name => $value) {
  if (substr($name, 0, $prefix_len) == 'drupal:') {
    $conf[substr($name, $prefix_len)] = $value;
  }
}

// Default PHP settings.
ini_set('session.gc_probability', 1);
ini_set('session.gc_divisor', 100);
ini_set('session.gc_maxlifetime', 200000);
ini_set('session.cookie_lifetime', 2000000);
ini_set('pcre.backtrack_limit', 200000);
ini_set('pcre.recursion_limit', 200000);

// Force Drupal not to check for HTTP connectivity until we fixed the self test.
$conf['drupal_http_request_fails'] = FALSE;
