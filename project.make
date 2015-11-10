api = 2
core = 7.x

; Drupal core.
projects[drupal][type] = core
projects[drupal][version] = 7.41
projects[drupal][patch][] = "https://drupal.org/files/issues/install-redirect-on-empty-database-728702-36.patch"

; Drush make allows a default sub directory for all contributed projects.
defaults[projects][subdir] = contrib

; Platform indicator module.
projects[platform][version] = 1.3

projects[webform][subdir] = contrib
projects[views][subdir] = contrib
projects[context][subdir] = contrib
projects[ctools][subdir] = contrib
projects[features][subdir] = contrib
projects[leaflet][subdir] = contrib
projects[admin_menu][subdir] = contrib

projects[shiny][type] = "theme"