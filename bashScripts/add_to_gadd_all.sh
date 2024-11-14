#!/bin/zsh
source ~/.zshrc
source ~/.bashrc

clear
# Vérifiez si un nom de dossier a été fourni
if [ "$#" -ne 1 ]; then
    echo "\033[0;31maddgadd <nom_du_dossier>\033[0m"
	sleep 1
    exit 1
fi

nouveau_dossier="$1"

script_gadd_all="/Users/leonardo/documents/git_repos/bash_scripts/gadd_all.sh"

if [ ! -f "$script_gadd_all" ]; then
    echo "\033[0;31mLe fichier $script_gadd_all n'existe pas.\033[0m"
	sleep 1
    exit 1
fi

# Ajoutez le nouveau dossier à la liste des répertoires dans gadd_all.sh
sed -i '' "/^repos=(/ s/)$/ $nouveau_dossier)/" "$script_gadd_all"

progress_bar 2
echo "\033[0;32mDossier $nouveau_dossier ajouté à $script_gadd_all\033[0m"
sleep 1
