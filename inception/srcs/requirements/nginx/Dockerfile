FROM alpine:3.17

RUN apk update && apk upgrade
RUN apk add nginx \
		openssl

COPY ./conf/default.conf /etc/nginx/http.d

RUN openssl req \
        -x509 \
        -days 365 \
        -nodes \
        -newkey rsa:2048 \
        -keyout /etc/ssl/private/nginx.key \
        -out /etc/ssl/certs/nginx.crt \
        -subj "/C=KR/ST=Seoul/L=Gaepo/O=42Seoul/OU=Develop/CN=jiyokim_blog"

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
