FROM	debian:buster
RUN		apt-get update && apt-get install -y \
		php-mysql \
		php-fpm \
		openssl \
		vim
COPY	conf/wp-config.php /var/www/wordpress/wp-config.php
COPY	conf/www.conf /etc/php/7.3/fpm/pool.d
COPY	tools/wordpress-5.5.1.tar.gz ./
COPY	tools/entrypoint.sh ./
RUN     chmod +x entrypoint.sh
ENTRYPOINT	bash entrypoint.sh