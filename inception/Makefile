include $(PWD)/srcs/.env

all:
	grep -r ${DOMAIN_NAME} /etc/hosts || echo "127.0.0.1 ${DOMAIN_NAME}" >> /etc/hosts
	mkdir -p ${HOME}/data/db
	mkdir -p ${HOME}/data/wp
	docker-compose -p inception -f srcs/docker-compose.yml up --build

bonus: clean
	docker-compose -p inception_bonus -f srcs/requirements/bonus/docker-compose.yml up --build

clean:
	docker-compose -p inception -f srcs/docker-compose.yml down --volume
	docker-compose -p inception_bonus -f srcs/requirements/bonus/docker-compose.yml down --volume

fclean: clean
	docker image rm -f $$(docker images -aq)
	docker container rm -f $$(docker container ls -aq)

re: clean all
