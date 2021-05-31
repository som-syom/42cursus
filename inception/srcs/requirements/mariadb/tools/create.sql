CREATE DATABASE IF NOT EXISTS wordpress;
GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'%' identified by 'password' WITH GRANT OPTION;
create user 'root' identified by 'password';
ALTER USER 'root'@'localhost' IDENTIFIED BY 'password';
grant all privileges on wordpress.* to 'root';
flush privileges;