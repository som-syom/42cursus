#!/bin/bash

service mysql start
if [ -z "$USE_AUTOINDEX" ]
then
mv default /etc/nginx/sites-available/default
else
mv default_autoindex /etc/nginx/sites-available/default
fi

# SSL

openssl req -newkey rsa:4096 -nodes -x509 -keyout localhost.dev.key \
			-out localhost.dev.crt -days 365 \
			-subj "/C=KR/ST=Seoul/L=Eunpyeong/O=42Seoul/OU=Dhyeon/CN=localhost"
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

# Install phpMyAdmin

tar -xvf phpMyAdmin-5.0.2.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin/* /var/www/html/phpmyadmin/
rm -rf phpmyadmin
rm phpMyAdmin-5.0.2.tar.gz

# phpMyAdmin

cd /var/www/html
chown -R root:root  phpmyadmin
chmod -R 707 phpmyadmin
cd phpmyadmin
chmod 705 config.inc.php
cd /

# MySQL

echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root --skip-password
echo "Grant all privileges on wordpress.* to 'root'@'localhost' with grant option;" | mysql -u root --skip-password
echo "update mysql.user set plugin='mysql_native_password' where user='root';" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password

# Wordpress

tar -xvf wordpress-5.5.1.tar.gz
mv wordpress/* var/www/html/wordpress
chown -R www-data:www-data /var/www/html/wordpress
rm -rf wordpress
rm wordpress-5.5.1.tar.gz

service php7.3-fpm start
service nginx start

bash
