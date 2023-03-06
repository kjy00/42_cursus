
db_name=`wp config get DB_NAME 2> /dev/null`
wp_admin=`wp user get admin --field=user_login 2> /dev/null`
wp_user=`wp user get ${WP_USER} --field=user_login 2> /dev/null`

if [ ! -f "/var/www/html/index.php" ]; then
  wp core download
	wp config create --dbhost=mariadb:3306 --dbname=${MYSQL_DATABASE} --dbuser=${MYSQL_USER} --dbpass=${MYSQL_USER_PASSWORD}
  wp core install --url=$WP_URL --title=$WP_TITLE \
                --admin_user=$WP_ADMIN_NAME --admin_password=$WP_ADMIN_PASS \
                --admin_email=$WP_ADMIN_MAIL --skip-email
  wp user create $WP_USER_NAME $WP_USER_MAIL --user_pass=$WP_USER_PASS
fi

php-fpm81 --nodaemonize
