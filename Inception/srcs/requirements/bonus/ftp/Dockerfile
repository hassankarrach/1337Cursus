FROM debian:bullseye

RUN apt-get update && apt-get install -y vsftpd \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

COPY tools/entrypoint.sh .
RUN chmod +x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]