#!/bin/zsh
source ~/.zshrc
source ~/.bashrc

clear
progress_bar 3
echo "\033[0;37mVérification des mises à jour disponibles...\033[0m"

# Exécuter softwareupdate et extraire les labels complets
updates=$(softwareupdate -l | awk '/\* Label:/{print substr($0, index($0, $3))}')

if [ -z "$updates" ]; then
    echo "Aucune mise à jour disponible."
else
    echo "\033[1;33mMises à jour disponibles :\033[0m"
    echo "$updates"

    # Demander à l'utilisateur s'il souhaite installer des mises à jour
	echo ""
    echo "\033[0;37mSouhaitez-vous installer des mises à jour ? (oui/non)\033[0m"
    read answer
    if [[ $answer == [oO]ui ]]; then
        # Demander quelle mise à jour installer
		echo ""
        echo "\033[0;37mIndiquez le label de la mise à jour à installer :\033[0m"
        read update_label

        # Exécuter la mise à jour et capturer la sortie
        update_output=$(softwareupdate --install "$update_label" 2>&1)
        
        # Vérifier la sortie et afficher en conséquence
        if [[ $update_output == *"No such update"* ]]; then
            echo "\033[0;31mNo such update\033[0m"  # Afficher en rouge
        else
            echo "\033[0;32m$update_output\033[0m"  # Afficher en vert
        fi
    fi
fi

echo "\033[0;37mVérification terminée.\033[0m"
