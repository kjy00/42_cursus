NAME=inception
DOCKER_COMPOSE_PATH=./srcs/docker-compose.yml

all: dir build up

dir:
# mkdir -p /home/jiyokim/data/db-data
# mkdir -p /home/jiyokim/data/wp-data

build:
	docker-compose -f $(DOCKER_COMPOSE_PATH) build

up:
	docker-compose -f $(DOCKER_COMPOSE_PATH) up
	
clean:
	docker-compose -f $(DOCKER_COMPOSE_PATH) down --volumes

fclean: clean
	docker system prune -a
# rm -rf /home/jiyokim/data

.PHONY: dir build up clean fclean
