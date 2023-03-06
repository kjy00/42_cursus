mkdir -p /auth_pam_tool_dir
touch /auth_pam_tool_dir/auth_pam_tool

mysql_install_db --user=mysql \
								--basedir=/usr \
								--datadir=/var/lib/mysql \
								--skip-test-db

cat > /tmp/init_db_sql << EOF
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_USER_PASSWORD';
GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
FLUSH PRIVILEGES;
EOF

/usr/bin/mysqld -u mysql --bootstrap < /tmp/init_db_sql
/usr/bin/mysqld -u mysql
