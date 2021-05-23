FROM	debian:buster

RUN	apt-get update && apt-get install -y \
	nginx \
	vim

COPY	conf/default ./
COPY	conf/init.sh ./

CMD	bash init.sh