FROM alpine:3.20

RUN apt updat && apt install nginx -y

COPY . .

CMD [ "cat", "file.txt" ]