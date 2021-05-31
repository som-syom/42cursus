create database if not exists wordpress;
grant all privileges on *.* to 'root'@'%' identified by 'MYSQL_ROOT_PASSWORD';
create user 'MYSQL_USER' identified by 'MYSQL_PASSWORD';
ALTER USER 'MYSQL_USER'@'localhost' IDENTIFIED BY 'MYSQL_PASSWORD';
grant all privileges on wordpress.* to 'MYSQL_USER';
flush privileges;