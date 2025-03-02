#!/bin/bash
echo "Downloading WP-CLI..."
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

mkdir -p /var/www/wordpress
chown -R www-data:www-data /var/www/wordpress
cd /var/www/wordpress

echo "Waiting for MariaDB to be ready..."
until mysql -u"$DB_USER" -p"$DB_USER_PASS" -hmariadb -P3306 "$DB_NAME" -e "SELECT 1" 2>/dev/null; do
  echo "Waiting for MariaDB..."
  sleep 1
done
echo "MariaDB is ready!"

if [ ! -f /var/www/wordpress/wp-config.php ]; then
    echo "Installing WordPress..."
    wp core download --allow-root
    echo "Configuring wp-config..."
    wp core config --dbname="$DB_NAME" \
                   --dbuser="$DB_USER" \
                   --dbpass="$DB_USER_PASS" \
                   --dbhost="mariadb:3306" \
                   --allow-root

    echo "Setting up Redis cache..."
    sed -i "/<?php/a define('WP_CACHE', true);\ndefine('WP_REDIS_HOST', 'redis');\ndefine('WP_REDIS_PORT', 6379);" wp-config.php

    echo "Installing WordPress core..."
    wp core install --url="$DOMAIN_NAME" \
                    --title="My Wordpress" \
                    --admin_user="$WP_ADMIN" \
                    --admin_password="$WP_ADMIN_PASS" \
                    --admin_email="admin@inception.net" \
                    --allow-root

    echo "Creating additional user..."
    wp user create "$WP_USER" \
                   "user@inception.net" \
                   --role=author \
                   --user_pass="$WP_USER_PASS" \
                   --allow-root

    echo "Installing Redis Object Cache plugin..."
    wp plugin install redis-cache --activate --allow-root
    echo "Enabling Redis Object Cache..."
    wp redis enable --allow-root

    echo "Fixing permissions after installation..."
    chown -R www-data:www-data /var/www/wordpress
    chmod -R 755 /var/www/wordpress
    chown -R www-data:www-data /var/www/wordpress/wp-content
    chmod -R 755 /var/www/wordpress/wp-content
else
    echo "WordPress is already installed"
    echo "Ensuring correct permissions..."
    chown -R www-data:www-data /var/www/wordpress
    chmod -R 755 /var/www/wordpress
    chown -R www-data:www-data /var/www/wordpress/wp-content
    chmod -R 755 /var/www/wordpress/wp-content
fi

# Configure php-fpm to listen on port 9000
sed -i 's@/run/php/php7.4-fpm.sock@9000@' /etc/php/7.4/fpm/pool.d/www.conf

mkdir -p /run/php

echo "Starting php-fpm..."
php-fpm7.4 -F