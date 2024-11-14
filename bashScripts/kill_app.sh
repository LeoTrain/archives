#!/bin/bash

heure_actuelle=$(date +%H:%M)  # Obtenez l'heure et les minutes au format "HH:MM"

# Extrayez l'heure et les minutes séparément
heure=$(echo "$heure_actuelle" | cut -d':' -f1)
minutes=$(echo "$heure_actuelle" | cut -d':' -f2)

# Effectuez la comparaison
if [[ (heure -ge 23 || heure -lt 8) ]]; then
    pkill Arc
fi
if [[ (heure -ge 21 || heure -lt 8) ]]; then
    pkill "Visual Studio Code"
fi
if [[ (heure -ge 21 || heure -lt 8) ]]; then
    pkill iTerm
fi
