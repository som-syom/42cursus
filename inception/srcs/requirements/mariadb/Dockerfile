FROM    alpine
RUN     apk upgrade && apk update && \
        apk add mysql mysql-client openrc
RUN     openrc default
COPY    tools/entrypoint.sh ./
COPY    conf/my.cnf /etc/mysql/my.cnf
COPY    tools/wp.sql ./
RUN     chmod +x entrypoint.sh
VOLUME [ "/run/mysqld" ]
ENTRYPOINT sh entrypoint.sh