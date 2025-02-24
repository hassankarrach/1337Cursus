# Use Alpine Linux as the base image
FROM alpine:3.18

# Install NGINX and OpenSSL
RUN apk update && apk add --no-cache \
	nginx \
	openssl

# SSL/TLS certificates
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
 	-keyout /etc/ssl/private/nginx-selfsigned.key \
	-out /etc/ssl/certs/nginx-selfsigned.crt \
	-subj "/C=MO/L=BG/O=1337/out=Student/CN=hkarrach.42.ma"
	
# Copy NGINX configuration files
COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY conf/default.conf /etc/nginx/conf.d/default.conf

# Expose port 443 for HTTPS
EXPOSE 443

# Start NGINX in the foreground and keep the container running
CMD ["nginx", "-g", "daemon off;"]