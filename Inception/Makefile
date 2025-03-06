# Colors for output
GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

SRC_DIR = srcs
COMPOSE_FILE = $(SRC_DIR)/docker-compose.yml
DOCKER_COMPOSE = docker-compose -f $(COMPOSE_FILE)


# Default target
all: build up

# Build Docker images
build:
	@echo "$(GREEN)Building Docker images...$(NC)"
	@$(DOCKER_COMPOSE) build

# Start containers
up:
	@echo "$(GREEN)Starting containers...$(NC)"
	@$(DOCKER_COMPOSE) up -d

# Stop containers
down:
	@echo "$(RED)Stopping containers...$(NC)"
	@$(DOCKER_COMPOSE) down

clean: down
	@echo "$(RED)Cleaning up Docker resources...$(NC)"
	@docker volume rm wp_database wp_files 2>/dev/null || true

# Full cleanup including images
fclean: clean
	@echo "$(RED)Removing all Docker images...$(NC)"
	@docker rmi nginx mariadb wordpress redis ftp adminer webapp cadvisor 2>/dev/null || true

prune:
	@echo "$(RED)Pruning Docker resources...$(NC)"
	@docker system prune -af

# Rebuild everything
re: down build up

# Show status
status:
	@$(DOCKER_COMPOSE) ps

# Show logs
logs:
	@$(DOCKER_COMPOSE) logs

live-logs:
	@$(DOCKER_COMPOSE) logs -f

# Shell access to containers
nginx-shell:
	@docker exec -it nginx sh

wp-shell:
	@docker exec -it wordpress sh

db-shell:
	@docker exec -it mariadb sh

redis-shell:
	@docker exec -it redis sh

ftp-shell:
	@docker exec -it ftp sh

adminer-shell:
	@docker exec -it adminer sh

webapp-shell:
	@docker exec -it webapp sh

cadvisor-shell:
	@docker exec -it cadvisor sh

.PHONY: all build up down clean fclean re status logs nginx-shell wp-shell db-shell redis-shell ftp-shell adminer-shell webapp-shell cadvisor-shell