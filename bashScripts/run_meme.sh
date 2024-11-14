#!/bin/bash

# Directory containing your meme images
meme_dir="$HOME/Documents/memes"

# Check if the directory exists
if [ -d "$meme_dir" ]; then
    # Generate a list of files and pick one randomly
    meme_path=$(ls "$meme_dir" | gshuf -n 1)

    # Check if a file was found and construct the full path
    if [ -n "$meme_path" ]; then
        full_path="$meme_dir/$meme_path"
        # Display the image in iTerm2
        /Users/leonardo/.iterm2/imgcat "$full_path"
    else
        echo "No images found in $meme_dir"
    fi
else
    echo "Meme directory not found at $meme_dir"
fi
