/etc/init.d/mariadb setup
service mariadb start
sleep 3
mysql -u root --password=$MYSQL_ROOT_PASSWORD << EOF
CREATE DATABASE IF NOT EXISTS wordpress;
create user "$MYSQL_USER" identified by "$MYSQL_PASSWORD";
GRANT ALL PRIVILEGES ON wordpress.* TO $MYSQL_USER@'localhost' identified by "$MYSQL_PASSWORD";
create user 'root' identified by "$MYSQL_ROOT_PASSWORD";
flush privileges;
ALTER USER 'root'@'localhost' IDENTIFIED BY "$MYSQL_ROOT_PASSWORD";
grant all privileges on wordpress.* to 'root';
flush privileges;
EOF

mysql -u root --password=$MYSQL_ROOT_PASSWORD < wp.sql
service mariadb stop
/usr/bin/mysqld --datadir="/var/lib/mysql"