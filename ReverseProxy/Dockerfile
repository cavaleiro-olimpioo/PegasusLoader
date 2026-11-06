FROM gcc:14-bookworm AS build
WORKDIR /src
COPY . .
RUN g++ -std=c++20 -O2 -Wall -Wextra -o proxy main.cpp Controller/*.cpp -lcurl

FROM debian:bookworm-slim
RUN g++ -std=c++20 -O2 -Wall -Wextra -o proxy main.cpp Controller/*.cpp \
    -static-libstdc++ -static-libgcc -lcurl
COPY --from=build /src/proxy /usr/local/bin/proxy
EXPOSE 3000
CMD ["proxy"]