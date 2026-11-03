FROM gcc:14 AS build
WORKDIR /src
COPY . .
RUN g++ -std=c++20 -O2 -Wall -Wextra -o proxy src/*.cpp

FROM debian:stable-slim
COPY --from=build /src/proxy /usr/local/bin/proxy
EXPOSE 3000
CMD ["proxy"]