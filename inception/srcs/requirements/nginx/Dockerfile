FROM alpine

RUN apk update &&\
	apk upgrade &&\
	apk add --no-cache nginx openssl &&\
	adduser -D -g 'www' www &&\
	mkdir /www &&\
	chown -R www:www /var/lib/nginx &&\
	chown -R www:www /www &&\
	mkdir -p run/nginx &&\
	openssl req -x509 -nodes -days 365 -subj "/C=KR/ST=Seoul/L=Gangnam/O=42Seoul/OU=dhyeon/CN=localhost" -newkey rsa:2048 -keyout /etc/ssl/private/nginx.key -out /etc/ssl/certs/nginx.crt;

COPY /conf/default.conf /etc/nginx/conf.d/default.conf
COPY /conf/nginx.conf /etc/nginx/nginx.conf
COPY /tools/index.html /var/www/localhost/htdocs/index.html
EXPOSE 443
ENTRYPOINT ["nginx"]
CMD ["-g", "daemon off;"]
