/etc/init.d/mariadb setup
service mariadb start
sleep 5
mysql -u root --password=$MYSQL_ROOT_PASSWORD < create.sql
mysql -u root --password=$MYSQL_ROOT_PASSWORD < wp.sql
service mariadb stop
/usr/bin/mysqld --datadir="/var/lib/mysql"