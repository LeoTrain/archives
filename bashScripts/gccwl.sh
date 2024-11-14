#!/bin/zsh

source ~/.zshrc

#compile main.c with first found lib into prog --> launch prog

echo "Finding lib..."
libfile=$(find . -name "*.a" | head -n 1)

if [ -z "$libfile" ]; then
    echo "Aucun fichier .a trouvé dans le répertoire courant."
    exit 1
fi
progress_bar 1

echo "Creating prog..."
gcc main.c -L. "$libfile" -o prog
progress_bar 3

echo "Opening prog..."
progress_bar 2
./prog
