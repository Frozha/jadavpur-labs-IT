#!/bin/bash

# Set HOME to the current working directory to ensure consistency
HOME=$(pwd)

# 1. Move all .c files from 'All My Cprogs Files' back to the parent directory
if [ -d "$HOME/All My Cprogs Files" ]; then
    echo "Moving .c files back to the parent directory..."
    mv "$HOME/All My Cprogs Files"/*.c "$HOME/"
    
    # Check if move was successful
    if [ $? -eq 0 ]; then
        echo "Successfully moved .c files back to '$HOME'."
    else
        echo "No .c files to move or an error occurred during moving."
    fi
else
    echo "'All My Cprogs Files' directory does not exist. Skipping moving .c files."
fi

# 2. Remove the directory 'All My Cprogs Files' if it exists
if [ -d "$HOME/All My Cprogs Files" ]; then
    rmdir "$HOME/All My Cprogs Files"
    echo "Removed directory 'All My Cprogs Files'."
else
    echo "'All My Cprogs Files' directory does not exist. Skipping removal."
fi

# 3. Remove the c_files_list.txt file if it exists
if [ -f "$HOME/c_files_list.txt" ]; then
    rm "$HOME/c_files_list.txt"
    echo "Removed file 'c_files_list.txt'."
else
    echo "'c_files_list.txt' file does not exist. Skipping removal."
fi

# 4. Remove any files that start with "converted_" as per the case conversion step
if ls "$HOME"/converted_* 1> /dev/null 2>&1; then
    rm "$HOME"/converted_*
    echo "Removed converted files starting with 'converted_'."
else
    echo "No converted files to remove. Skipping."
fi

echo "Reset of current directory state completed."
