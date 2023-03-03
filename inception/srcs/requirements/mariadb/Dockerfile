FROM alpine:3.17

RUN mkdir -p /run/mysqld
RUN mkdir -p /var/lib/mysql
RUN apk update && apk upgrade
RUN	apk add mariadb
RUN apk add mariadb-common
RUN	apk add mariadb-client
RUN	apk add mariadb-server-utils

COPY ./conf/my.cnf /etc/my.cnf
COPY ./tools/init_db.sh /tmp/init_db.sh

RUN chmod +x /tmp/init_db.sh

EXPOSE 3306

ENTRYPOINT ["sh", "/tmp/init_db.sh"]
