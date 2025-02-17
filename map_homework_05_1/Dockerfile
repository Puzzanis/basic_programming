FROM gcc:latest
COPY . /usr/src/app
WORKDIR /usr/src/app
RUN apt update
RUN g++ -o for_each main.cpp
CMD ["./for_each"]