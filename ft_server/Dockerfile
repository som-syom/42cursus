FROM	debian:buster

LABEL	MAINTAINER="Dhyeon <dhyeon@student.42seoul.kr>"

ENV	DEBAIN_FRONTEND noninteractive

RUN apt-get update && apt-get install -y \
	nginx \
	mariadb-server \
	php-mysql \
	php-fpm \
	openssl \
	vim

COPY	srcs/default /.
COPY	srcs/default_autoindex /.
COPY	srcs/config.inc.php /var/www/html/phpmyadmin/config.inc.php
COPY	srcs/wp-config.php /var/www/html/wordpress/wp-config.php
COPY	srcs/phpMyAdmin-5.0.2.tar.gz ./
COPY	srcs/wordpress-5.5.1.tar.gz ./
COPY	srcs/init.sh ./

EXPOSE	80
EXPOSE	443

CMD	bash init.sh
