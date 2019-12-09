FROM alpine:3.8
RUN apk add --no-cache gcc libc-dev
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN gcc -o myapp main.c
CMD ["./myapp"]

