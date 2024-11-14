#!/bin/zsh
source ~/.zshrc
source ~/.bashrc

# Fichier pour stocker les tâches
task_file="/Users/leonardo/tasks.txt"

# Afficher les tâches
function show_tasks() {
	clear
	progress_bar 2
    echo "\033[0;33mTâches actuelles :\033[0m"
    cat "$task_file"
	echo ""

	echo "\033[0;37mAppuyez sur enter pour continuer...\033[0m"
	read enter
	clear
}

# Ajouter une nouvelle tâche
function add_task() {
	clear
	progress_bar 2
    echo "\033[0;32mEntrez une nouvelle tâche :\033[0m"
    read new_task
    echo "$new_task" >> "$task_file"
	progress_bar 1
    echo "\033[0;32mTâche ajoutée.\033[0m"
	echo ""

	echo "\033[0;37mAppuyez sur ENTER pour continuer...\033[0m"
	read enter
	clear
}

# Supprimer une tâche
function delete_task() {
	clear
	progress_bar 2
    echo "\033[0;31mQuelle tâche souhaitez-vous supprimer ?\033[0m (entrez le numéro)"
    read task_number

    # Utiliser sed pour supprimer la ligne spécifiée
    sed -i '' "${task_number}d" "$task_file"
	progress_bar 1
    echo "\033[0;31mTâche supprimée.\033[0m"
	echo ""

	echo "\033[0;37mAppuyez sur ENTER pour continuer...\033[0m"
	read enter
	clear
}

# Boucle principale
clear
while true; do
	progress_bar 2
    echo "Gestionnaire de Tâches"
    echo "1. \033[0;33mAfficher les tâches\033[0m"
    echo "2. \033[0;32mAjouter une tâche\033[0m"
    echo "3. \033[0;31mSupprimer une tâche\033[0m"
    echo "4. \033[1;30mQuitter\033[0m"
	echo ""
    echo "\033[0;37mEntrez votre choix :\033[0m"
    read choice

    case $choice in
        1) show_tasks ;;
        2) add_task ;;
        3) delete_task ;;
        4) break ;;
        *) echo "Option invalide." ;;
    esac
done
