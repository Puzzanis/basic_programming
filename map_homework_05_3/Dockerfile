FROM ubuntu:latest
COPY . /usr/src/app
WORKDIR /usr/src/app/
RUN apt update
RUN apt install -y build-essential clang
RUN clang++ main.cpp
CMD ["./a.out"]