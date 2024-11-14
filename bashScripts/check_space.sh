#!/bin/zsh
source ~/.zshrc
source ~/.bashrc

clear
progress_bar 2
# Seuil bas et haut de l'espace disque en pourcentage
THRESHOLD_LOW=10
THRESHOLD_HIGH=30

# Couleurs (uniquement pour le terminal actuel)
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # Pas de couleur

# Vérifie l'espace disque sur le point de montage /
usage=$(df -h / | grep -v Filesystem | awk '{print $5}' | sed 's/%//g')

# Comparer l'espace disponible avec les seuils
if [ $usage -lt $THRESHOLD_LOW ]; then
    message="T'as assez d'espace bg (${usage}% disponible)."
    echo -e "${GREEN}$message${NC}"
elif [ $usage -ge $THRESHOLD_LOW ] && [ $usage -le $THRESHOLD_HIGH ]; then
    message="Ça devient chaud (${usage}% disponible)."
    echo -e "${YELLOW}$message${NC}"
else
    message="Alerte: L'espace disque disponible est inférieur à $THRESHOLD_LOW% (${usage}% disponible)."
    echo -e "${RED}$message${NC}"
fi
