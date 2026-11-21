#!/bin/bash

echo "Verificando atualizações no código"

git pull

echo "Inicializando docker"

docker compose up --build
