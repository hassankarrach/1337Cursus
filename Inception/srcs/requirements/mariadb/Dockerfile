FROM debian:bullseye

# Install MariaDB && create directories && change owner
RUN apt-get update && apt-get install -y mariadb-server \
    && rm -rf /var/lib/apt/lists/* \
	&& mkdir -p /var/run/mysqld /var/log/mysql \
    && chown mysql:mysql /var/run/mysqld /var/log/mysql /var/lib/mysql

# Copy configuration file
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

# Copy initialization script
COPY tools/init.sh /usr/local/bin/init.sh
RUN chmod +x /usr/local/bin/init.sh

# Expose port
EXPOSE 3306

# Run the initialization script
CMD ["/usr/local/bin/init.sh"]
