DOCKER_COMPOSE = docker-compose -f srcs/docker-compose.yml

DATA_DIR = /home/${USER}/data
WP_FILES = $(DATA_DIR)/wp_files
DB_FILES = $(DATA_DIR)/db_files

all: setup build

setup:
	mkdir -p $(WP_FILES)
	mkdir -p $(DB_FILES)

build:
	$(DOCKER_COMPOSE) up -d --build

stop:
	$(DOCKER_COMPOSE) stop

start:
	$(DOCKER_COMPOSE) start

restart:
	$(DOCKER_COMPOSE) restart

status:
	docker ps -a

logs:
	$(DOCKER_COMPOSE) logs

live-logs:
	$(DOCKER_COMPOSE) logs -f

clean:
	$(DOCKER_COMPOSE) down -v

fclean: clean
	sudo rm -rf $(DATA_DIR)
	docker system prune -af

re: fclean all