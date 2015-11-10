#!/bin/sh

echo "hello wurld"

./bin/phing -verbose fetch-multisite
./bin/phing -verbose make-multisite
cp -R temp_docroot/* docroot
rm -rf temp_docroot
./bin/phing -verbose symlink-all
#./bin/phing -verbose copy-platform-settings
#./bin/phing install-drupal
