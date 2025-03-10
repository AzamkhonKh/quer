# building C/C++ on docker

## Overview
This repository contains code for system and device programming in C/C++. The project is structured to support building and running C++ 23 code on a Linux machine using Docker and Makefile commands.

## Requirements
- Docker installed
- VSCode with Debug extension (for debugging)

## Building and Running
### Using Docker
To build and run the project inside a Docker container with access to all files, use:
```sh
make up
```

### Compiling a C File
To compile a specific C file and generate an executable in the `bin/` directory, use:
```sh
make compile C=pathto/cfile.c
```

### Cleaning Up
To clean the build files and reset the environment, use:
```sh
make clean
```

## Debugging
For debugging, use VSCode IDE with the Debug extension.
