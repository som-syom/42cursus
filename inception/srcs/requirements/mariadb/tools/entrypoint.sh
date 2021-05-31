
/etc/init.d/mariadb setup
service mariadb start
sleep 5
mysql < create.sql
mysql < wp.sql
service mariadb stop
/usr/bin/mysqld --datadir="/var/lib/mysql"