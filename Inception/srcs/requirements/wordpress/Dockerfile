FROM debian:bullseye

# Install required packages
RUN apt-get update && apt-get install -y \
    curl \
    php-fpm \
    php-mysql \
    mariadb-client \
    && rm -rf /var/lib/apt/lists/* \
    && mkdir -p /var/www/wordpress /run/php \
    && chown -R www-data:www-data /var/www/wordpress /run/php \
    && chmod -R 755 /var/www/wordpress

# Install WP-CLI
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

# Configure PHP-FPM to listen on port 9000
RUN sed -i 's/listen = \/run\/php\/php.*sock/listen = 9000/' /etc/php/*/fpm/pool.d/www.conf

# Copy initialization script
COPY tools/init.sh /usr/local/bin/init.sh
RUN chmod +x /usr/local/bin/init.sh

# Volume for WordPress files
VOLUME /var/www/wordpress

# Expose PHP-FPM port
EXPOSE 9000

# Run the script
CMD ["/usr/local/bin/init.sh"]