FROM debian:bullseye

# Install MariaDB && create directories && change owner
RUN apt-get update && apt-get upgrade -y \
    && apt-get install -y mariadb-server \
    && rm -rf /var/lib/apt/lists/* \
    && mkdir -p /var/run/mysqld /var/log/mysql \
    && chown -R mysql:mysql /var/run/mysqld /var/log/mysql /var/lib/mysql

# Copy configuration file
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/

# Copy initialization script
COPY tools/entrypoint.sh /
RUN chmod +x entrypoint.sh

# Expose MariaDB port
EXPOSE 3306

# Set the working directory
WORKDIR /

# Switch to the mysql user
USER mysql

# Run the initialization script
CMD ["./entrypoint.sh"]