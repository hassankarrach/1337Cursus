#!/bin/sh
set -e  # Exit on error

CONFIG_FILE="/etc/redis/redis.conf"

# Modify only if changes are not already applied
if ! grep -q "#bind 127.0.0.1" "$CONFIG_FILE"; then
    echo "Configuring Redis..."
    sed -i "s|bind 127.0.0.1|#bind 127.0.0.1|g" "$CONFIG_FILE"
    sed -i "s|# maxmemory <bytes>|maxmemory 2mb|g" "$CONFIG_FILE"
    sed -i "s|# maxmemory-policy noeviction|maxmemory-policy allkeys-lru|g" "$CONFIG_FILE"
fi

# Start Redis server with protected mode disabled
exec redis-server --protected-mode no
