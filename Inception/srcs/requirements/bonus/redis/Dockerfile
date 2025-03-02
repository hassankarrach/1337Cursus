FROM debian:bullseye

RUN apt-get update && apt-get install -y redis-server \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

# Copy configuration script
COPY tools/entrypoint.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/entrypoint.sh

# Expose Redis port
EXPOSE 6379

# Start Redis server with setup script
ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]