# Define variables
DOCKER_IMAGE = cpp21_debug_container
DOCKER_COMPOSE = docker-compose
DOCKER_BUILD_CMD = $(DOCKER_COMPOSE) up -d --build
DOCKER_EXEC_CMD = docker exec -it $(DOCKER_IMAGE)
BIN_DIR = bin
EXECUTABLE = $(BIN_DIR)/last
GDB_CMD = "/usr/bin/gdb --interpreter=mi"
GCC = g++

# Default target (build the Docker image)
all: up

# Build the Docker image
up:
	mkdir ${BIN_DIR}
	$(DOCKER_BUILD_CMD)

# Compile the C++ code inside the Docker container
# Usage: make compile FILE_NAME=example.cpp
compile:
	$(DOCKER_EXEC_CMD) g++ -std=c++23 -g -o $(EXECUTABLE) $(C)

# Run the executable inside the container
# Usage: make run FILE_NAME=example.cpp
run:
	$(DOCKER_EXEC_CMD) ./$(EXECUTABLE)

# Debug the executable inside the container using gdb
# Usage: make debug FILE_NAME=example.cpp
debug:
	$(DOCKER_EXEC_CMD) /bin/sh -c "$(GDB_CMD) $(EXECUTABLE)"

# Clean up generated files
clean:
	rm -rf $(BIN_DIR)
	$(DOCKER_COMPOSE) down -v
