#!/bin/bash
tar -xvf wordpress-5.5.1.tar.gz
mv wordpress/* var/www/wordpress
chown -R www-data:www-data /var/www/wordpress
rm -rf wordpress
rm wordpress-5.5.1.tar.gz
service php7.3-fpm start
sleep infinity