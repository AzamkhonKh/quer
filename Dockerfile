FROM alpine:latest

# Upgrade Alpine to ensure access to latest packages
RUN apk update && apk upgrade

# Install GCC 12, G++, and other necessary tools
RUN apk add --no-cache g++ cmake make gdb bash musl-dev gcc g++

# Verify installation
RUN gcc --version && g++ --version

WORKDIR /app

CMD ["/bin/sh"]
