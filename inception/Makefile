include $(PWD)/srcs/.env

all:
	grep -r ${DOMAIN_NAME} /etc/hosts || echo "127.0.0.1 ${DOMAIN_NAME}" >> /etc/hosts
	echo "127.0.0.1 ${DOMAIN_NAME}"
	mkdir -p ${HOME}/data/db
	mkdir -p ${HOME}/data/wp
	docker-compose -f srcs/docker-compose.yml up
clean:
	docker-compose -f srcs/docker-compose.yml down
fclean: clean
	docker rmi $(docker image ls -aq)
re: clean all
