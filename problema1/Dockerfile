FROM alpine:3.15.4

# See
# https://github.com/prantlf/docker-alpine-make-gcc
# https://github.com/prantlf/docker-alpine-make-gcc/blob/master/Dockerfile

### Install compiler tools and git:
RUN apk --no-cache add make gcc g++ musl-dev binutils autoconf automake libtool pkgconfig check-dev file patch git
### :Install compiler tools

### Create working folder:
RUN mkdir /src
### :Create working folder

WORKDIR /src
