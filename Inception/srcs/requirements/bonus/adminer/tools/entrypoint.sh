#!/bin/bash

# Ensure the directory exists
mkdir -p /var/www/wordpress

# Download Adminer and set correct permissions
wget -q "http://www.adminer.org/latest.php" -O /var/www/wordpress/adminer.php
chown www-data:www-data /var/www/wordpress/adminer.php
chmod 755 /var/www/wordpress/adminer.php

# Remove default index.html if it exists
rm -f /var/www/wordpress/index.html

# Start PHP's built-in server
exec php -S 0.0.0.0:8080 -t /var/www/wordpress
