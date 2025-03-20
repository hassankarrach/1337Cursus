FROM debian:buster

# Update package lists and install necessary packages in one RUN to reduce layers
RUN apt update -y && \
    apt install -y wget php php-mysql && \
    rm -rf /var/lib/apt/lists/*

# Copy and set permissions for the script
COPY ./tools/entrypoint.sh .
RUN chmod +x /entrypoint.sh
	
# Set the entrypoint
ENTRYPOINT ["/entrypoint.sh"]
