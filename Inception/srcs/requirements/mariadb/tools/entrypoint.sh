#!/bin/bash

# Start MariaDB
mysqld_safe &
echo "=> Waiting for MariaDB to start"
sleep 5

mariadb -v -u root << EOF
CREATE DATABASE IF NOT EXISTS ${DB_NAME};
CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_USER_PASS}';
GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_USER'@'%' IDENTIFIED BY '$DB_USER_PASS';
GRANT ALL PRIVILEGES ON $DB_NAME.* TO 'root'@'%' IDENTIFIED BY '$DB_ROOT_PASS';
SET PASSWORD FOR 'root'@'localhost' = PASSWORD('$DB_ROOT_PASS');
EOF

echo "=> Restarting MariaDB..."

# Stop MariaDB
mysqladmin shutdown -u root -p$DB_ROOT_PASS

# Start MariaDB
exec mysqld_safe
