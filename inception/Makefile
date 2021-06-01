include $(PWD)/srcs/.env

all:
	echo "127.0.0.1 ${DOMAIN_NAME}" 
	docker-compose -f srcs/docker-compose.yml up --build
clean:
	docker-compose -f srcs/docker-compose.yml down --volume
fclean: clean
re: clean all