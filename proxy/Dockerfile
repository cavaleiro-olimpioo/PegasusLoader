FROM debian:bookworm AS build
RUN apt-get update && apt-get install -y --no-install-recommends g++ libcurl4-openssl-dev \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /src
COPY . .
RUN g++ -std=c++20 -O2 -Wall -Wextra -o proxy src/main.cpp -lcurl

FROM debian:bookworm-slim
RUN apt-get update && apt-get install -y --no-install-recommends libcurl4 \
    && rm -rf /var/lib/apt/lists/*
COPY --from=build /src/proxy /usr/local/bin/proxy
EXPOSE 3000
CMD ["proxy"]