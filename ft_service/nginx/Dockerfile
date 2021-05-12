FROM alpine:3.12

RUN apk update &&\
	apk upgrade &&\
	apk add --no-cache nginx &&\
	adduser -D -g 'www' www &&\
	mkdir /www &&\
	chown -R www:www /var/lib/nginx &&\
	chown -R www:www /www

COPY nginx.conf /etc/nginx/nginx.conf
COPY index.html /www/index.html

EXPOSE 80 443
ENTRYPOINT ["nginx"]
CMD ["-g", "daemon off;"]
