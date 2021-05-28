all:
	docker-compose -f srcs/docker-compose.yml up --build
clean:
	docker-compose -f srcs/docker-compose.yml down --volume
fclean: clean
re: clean all