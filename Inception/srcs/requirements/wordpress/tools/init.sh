#!/bin/bash

# Wait for MariaDB to be ready
echo "Waiting for database connection..."
until mariadb -h"${WORDPRESS_DB_HOST}" -u"${WORDPRESS_DB_USER}" -p"${WORDPRESS_DB_PASSWORD}" -e "SELECT 1;" > /dev/null 2>&1; do
    echo "MariaDB not ready yet, waiting..."
    sleep 2
done
echo "Database ready!"

cd /var/www/wordpress

# Install WordPress if not already installed
if [ ! -f /var/www/wordpress/wp-config.php ]; then
    echo "Installing WordPress..."
    wp core download --allow-root
    wp config create --dbhost="${WORDPRESS_DB_HOST}" --dbname="${WORDPRESS_DB_NAME}" --dbuser="${WORDPRESS_DB_USER}" --dbpass="${WORDPRESS_DB_PASSWORD}" --allow-root
    wp core install --url="${DOMAIN_NAME}" --title="${WP_TITLE}" --admin_user="${WP_ADMIN_N}" --admin_password="${WP_ADMIN_P}" --admin_email="${WP_ADMIN_E}" --allow-root
    wp user create "${WP_U_NAME}" "${WP_U_EMAIL}" --role="${WP_U_ROLE}" --user_pass="${WP_U_PASS}" --allow-root
    echo "WordPress installation complete!"
else
    echo "WordPress is already installed."
fi

# Ensure PHP-FPM runtime directory exists
mkdir -p /run/php
chown www-data:www-data /run/php

# Start PHP-FPM in foreground
exec php-fpm* --nodaemonize