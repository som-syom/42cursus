sudo groupadd docker
sudo usermod -aG docker $USER

docker stop $(docker ps -qa);
docker container rm -f $(docker container ls -aq);
docker rm $(docker ps -qa);
docker rmi -f $(docker images -qa);
docker volume rm $(docker volume ls -q);
docker network rm $(docker network ls -q) 2>/dev/null;
