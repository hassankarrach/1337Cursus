FROM debian:bullseye

RUN apt-get update && apt-get upgrade -y \
    && apt-get install -y \
    curl \
    php \
    php7.4-fpm \
    php-mysql \
    php-redis \
    sendmail \
    mariadb-client 

COPY ./tools/entrypoint.sh .
RUN chmod +x entrypoint.sh

EXPOSE 9000

ENTRYPOINT ["/entrypoint.sh"]