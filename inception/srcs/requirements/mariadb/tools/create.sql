CREATE DATABASE IF NOT EXISTS wordpress;
create user 'dhyeon' identified by 'password';
GRANT ALL PRIVILEGES ON wordpress.* TO 'dhyeon'@'%' identified by 'password' WITH GRANT OPTION;
create user 'root' identified by 'password';
flush privileges;
ALTER USER 'root'@'localhost' IDENTIFIED BY 'password';
grant all privileges on wordpress.* to 'root';
flush privileges;