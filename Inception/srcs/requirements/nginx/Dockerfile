# Use Alpine Linux as the base image
FROM debian:bullseye

# Install NGINX and OpenSSL
RUN apt-get update && apt-get upgrade -y \
    && apt-get install -y \
    nginx \
    openssl \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# SSL/TLS certificates with proper SAN extension
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/nginx-selfsigned.key \
    -out /etc/ssl/certs/nginx-selfsigned.crt \
    -subj "/C=MO/L=BG/O=1337/CN=hkarrach.42.fr" \
    -addext "subjectAltName = DNS:hkarrach.42.fr,DNS:www.hkarrach.42.fr"

# Copy NGINX configuration files
COPY conf/nginx.conf /etc/nginx/nginx.conf

EXPOSE 443

# Start NGINX in the foreground and keep the container running
CMD ["nginx", "-g", "daemon off;"]