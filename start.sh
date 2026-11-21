#!/bin/bash

echo "========================================"
echo "   Verificando atualizações no código"
echo "========================================"


git pull

echo "==========================="
echo "   Inicializando docker"
echo "==========================="

docker compose up --build
