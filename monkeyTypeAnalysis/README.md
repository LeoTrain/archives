# MonkeyTypeAnalasysis

# Outil d'Analyse des Données de MonkeyType

Cette application Python automatise le processus de téléchargement, de déplacement et d'analyse des données de vitesse de frappe provenant de MonkeyType. Elle offre une manière conviviale de visualiser les mots par minute (MPM) maximum enregistrés chaque jour.

## Fonctionnalités

- **Interaction Automatisée avec le Navigateur** : Utilise Selenium pour naviguer et interagir automatiquement avec le site web de MonkeyType.
- **Gestion des Données** : Télécharge, déplace et renomme automatiquement le fichier CSV contenant les résultats de frappe.

## Prérequis

- Python 3
- Bibliothèques Python : pandas, matplotlib, selenium
- Un pilote de navigateur (par exemple, geckodriver pour Firefox)

## Installation

1. Clonez le dépôt ou téléchargez les fichiers sources.
2. Installez les dépendances nécessaires :
```bash
pip install pandas matplotlib selenium
```
3. Assurez-vous que le pilote du navigateur est correctement installé et accessible.

## Utilisation

Pour lancer l'analyse, exécutez le script depuis la ligne de commande :
```bash
read_monkey_data.py
```


Le script ouvrira un navigateur en mode sans tête, se connectera au site MonkeyType, téléchargera les données de frappe et affichera une visualisation des MPM maximum par jour.

## Structure du Code

- `__init__` : Configure et lance les principales fonctionnalités.
- `download_csv` : Connecte au site MonkeyType, gère les modales de consentement, se connecte et télécharge les données.
- `move_downloaded_csv_data` : Déplace et renomme le fichier CSV téléchargé.
- `plotting` : Génère et affiche le graphique des MPM maximaux par jour.

