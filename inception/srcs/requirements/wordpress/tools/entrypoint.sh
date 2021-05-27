#!/bin/bash
tar -xvf wordpress-5.5.1.tar.gz
mv wordpress/* var/www/wordpress
chown -R www-data:www-data /var/www/wordpress
rm -rf wordpress
rm wordpress-5.5.1.tar.gz

echo -e "\nenv[MYSQL_ROOT_PASSWORD] = $MYSQL_ROOT_PASSWORD" >> /etc/php/7.3/fpm/pool.d/www.conf
echo -e "\nenv[MYSQL_USER]=$MYSQL_USER" >> /etc/php/7.3/fpm/pool.d/www.conf
echo -e "\nenv[MYSQL_PASSWORD]=$MYSQL_PASSWORD" >> /etc/php/7.3/fpm/pool.d/www.conf
# service php7.3-fpm start
# sleep infinity
php-fpm7.3 -F