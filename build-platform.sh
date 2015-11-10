#!/bin/sh

echo "hello wurld"

pwd
ls

./bin/phing -verbose fetch-multisite
./bin/phing -verbose make-multisite
./bin/phing -verbose make-project
./bin/phing -verbose symlink-all
./bin/phing -verbose copy-platform-settings
#./bin/phing install-drupal
