#!/bin/zsh
source ~/.zshrc

clear

# Liste des répertoires à vérifier
repos=(bash_scripts calculator_c libft piscine pygame mon_blog)

# Boucle sur chaque répertoire
for repo in "${repos[@]}"; do
    echo "Looking into $repo..."
    progress_bar 1

    # Chemin complet vers le répertoire
    repo_path=~/documents/git_repos/"$repo"

    # Exécutez git status et stockez la sortie
    git_status=$(git -C "$repo_path" status)

    # Vérifiez si des fichiers sont modifiés ou non suivis
    if echo "$git_status" | grep -q "modified:\|Untracked files:"; then
        echo "Modified or Untracked files found in $repo:"
        echo "$git_status" | grep "modified:\|Untracked files:"

        echo -n "Enter commit message for $repo: "
        read commit_msg
        git -C "$repo_path" add .
        git -C "$repo_path" commit -m "$commit_msg" >/dev/null 2>&1
        if [ $? -eq 0 ]; then
            echo -e "\033[0;32mCommit successful in $repo.\033[0m"
        else
            echo -e "\033[0;31mCommit error in $repo.\033[0m"
        fi

    else
        echo -e "\033[0;32mNo modified or untracked files in $repo.\033[0m"
    fi
done
