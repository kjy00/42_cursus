FROM alpine:3.17

RUN mkdir -p /run/mysqld
RUN mkdir -p /var/lib/mysql
RUN apk update && apk upgrade
RUN	apk add mariadb mariadb-client

COPY ./tools/init_db.sh /tmp/init_db.sh
RUN chown -R mysql:mysql /run/mysqld

RUN sed -i "s|skip-networking|# skip-networking|g" /etc/my.cnf.d/mariadb-server.cnf
RUN sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|g" /etc/my.cnf.d/mariadb-server.cnf

RUN chmod +x /tmp/init_db.sh

EXPOSE 3306

ENTRYPOINT ["sh", "/tmp/init_db.sh"]
