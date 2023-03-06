FROM alpine:3.17

RUN apk update && apk upgrade
RUN	apk add php81-fpm \
		php81 \
		php81-curl \
		php81-phar \
		php81-mysqli \
		php81-iconv \
		mariadb-client 
RUN apk add curl

WORKDIR /tmp
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin
RUN chmod +x /usr/local/bin/wp-cli.phar
RUN ln -sf /usr/local/bin/wp-cli.phar /usr/local/bin/wp

RUN mkdir -p /var/www/html
WORKDIR /var/www/html

RUN sed -i 's/;chdir = \/var\/www/chdir = \/var\/www\/html/g' /etc/php81/php-fpm.d/www.conf
RUN sed -i 's/listen = 127.0.0.1:9000/listen = 0.0.0.0:9000/g' /etc/php81/php-fpm.d/www.conf
RUN sed -i 's/;clear_env = no/clear_env = no/g' /etc/php81/php-fpm.d/www.conf

COPY ./tools/wp.sh /tmp/wp.sh
RUN chmod +x /tmp/wp.sh

EXPOSE 9000

ENTRYPOINT [ "sh", "/tmp/wp.sh" ]
