#!/bin/sh

echo "hello wurld"

pwd
ls

./bin/phing -verbose fetch-multisite
#./bin/phing make-multisite
#./bin/phing make-project
#./bin/phing symlink-all
#./bin/phing install-drupal