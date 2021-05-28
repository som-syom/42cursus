mariadb-install-db -u root --datadir=/var/lib/mysql

echo "flush privileges;
create database if not exists wordpress;
grant all privileges on *.* to 'root'@'%' identified by '$MYSQL_ROOT_PASSWORD';
create user '$MYSQL_USER' identified by '$MYSQL_PASSWORD';
grant all privileges on wordpress.* to '$MYSQL_USER';" | mysqld -u root --datadir=/var/lib/mysql --bootstrap 
mysql < wp.sql
service mariadb stop
mysqld -u root