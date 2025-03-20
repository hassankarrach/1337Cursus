FROM debian:bullseye

# Install MariaDB without triggering post-install scripts
RUN apt-get update && apt-get upgrade -y \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y mariadb-server \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/* /var/lib/mysql/* \
    && mkdir -p /var/run/mysqld /var/log/mysql /var/lib/mysql \
    && chown -R mysql:mysql /var/run/mysqld /var/log/mysql /var/lib/mysql

# Copy configuration file
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/

# Copy initialization script
COPY tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

EXPOSE 3306

ENTRYPOINT ["/entrypoint.sh"]