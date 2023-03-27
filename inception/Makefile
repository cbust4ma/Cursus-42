# Variables
NAME = inception
FILE = srcs/docker-compose.yml
# Defining the default target

all: build
	@echo "All done!"
help:
	@echo "Usage: make [target]"
	@echo "Targets:"
	@echo "  build            : Start build containers"
	@echo "  up               : Start the containers"
	@echo "  restart          : Restart the containers"
	@echo "  ps               : List containers"
	@echo "  clean            : Remove all containers and volumes"
	@echo "  fclean           : Remove all"
	@echo ""

# Targets
up:
	@docker-compose -p $(NAME) -f $(FILE) up -d
restart:
	@docker-compose -p $(NAME) -f $(FILE) restart
ps:
	@docker-compose -p $(NAME) -f $(FILE) ps
clean:
	@docker-compose -p $(NAME) -f $(FILE) down -v --remove-orphans
	@docker-compose -p $(NAME) -f $(FILE) down --rmi all --volumes --remove-orphans
	@docker system prune -a

build:
	@mkdir -p $(HOME)/data/db
	@mkdir -p $(HOME)/data/wordpress
	@docker-compose build  -d $(FILE) --force-rm
	@docker-compose -p $(NAME) -f $(FILE) up --no-recreate --remove-orphans -d
re: clean build
.PHONY: clean re  up build help restart ps fclean
