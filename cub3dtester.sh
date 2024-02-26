#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <folder_path>"
    exit 1
fi

START_DIR=$(pwd)

cd "$1" || exit

for file in *; do
    if [ -f "$file" ]; then
        cd "$START_DIR"
        echo "Executing ./cub3d with $file..."
        ./cub3d "$1/$file"
        
        read -p "Press Enter to continue..."
        
        cd "$1" || exit
    fi
done

cd "$START_DIR"

