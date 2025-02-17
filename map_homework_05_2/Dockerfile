FROM gcc:latest
COPY . /usr/src/app
WORKDIR /usr/src/app/
RUN apt update
RUN apt install -y build-essential cmake
WORKDIR /usr/src/app/build
RUN cmake ..
RUN make
CMD ["./map_homework_05_2"]