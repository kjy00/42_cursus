FROM alpine:3.17

RUN apk update && apk upgrade
RUN apk add nginx \
		openssl

COPY ./conf/default.conf /etc/nginx/http.d

CMD ["nginx", "-g", "daemon off;"]
