#!/bin/bash

# Check if database directory is initialized
if [ ! -d "/var/lib/mysql/mysql" ]; then
    # Initialize database directory
    mysql_install_db --user=mysql --datadir=/var/lib/mysql

    # Start MariaDB in bootstrap mode (for initial setup)
    # Using bootstrap mode prevents socket connections during setup
    mysqld --user=mysql --bootstrap << EOF
USE mysql;
FLUSH PRIVILEGES;
-- Delete anonymous users
DELETE FROM mysql.user WHERE User='';
-- Drop test database
DROP DATABASE IF EXISTS test;
DELETE FROM mysql.db WHERE Db='test';
-- Remove remote root access
DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');
-- Set root password
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASS}';
-- Create database and user
CREATE DATABASE ${DB_NAME} CHARACTER SET utf8 COLLATE utf8_general_ci;
CREATE USER '${DB_USER}'@'%' IDENTIFIED by '${DB_USER_PASS}';
GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%';
FLUSH PRIVILEGES;
EOF
else
    echo "Database directory already initialized"
fi

# Start MariaDB with the mysql user
exec mysqld_safe --user=mysql