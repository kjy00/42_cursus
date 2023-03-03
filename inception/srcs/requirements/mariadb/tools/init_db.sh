mkdir -p /auth_pam_tool_dir
touch /auth_pam_tool_dir/auth_pam_tool

mysql_install_db --user=root \
								--basedir=/usr \
								--datadir=/var/lib/mysql \
								--skip-test-db

cat > /tmp/init_db_sql << EOF
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS wordpress;
CREATE USER IF NOT EXISTS 'jiyokim'@'%' IDENTIFIED BY '1234';
GRANT ALL PRIVILEGES ON wordpress.* TO 'jiyokim'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '1234';
FLUSH PRIVILEGES;
EOF

/usr/bin/mysqld -u root --bootstrap < /tmp/init_db_sql
/usr/bin/mysqld -u root
