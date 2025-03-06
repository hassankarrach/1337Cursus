FROM debian:bullseye

RUN apt-get update && apt-get install -y nginx

COPY ./html /var/www/html

COPY conf/nginx.conf /etc/nginx/nginx.conf

EXPOSE 8082

CMD ["nginx", "-g", "daemon off;"]