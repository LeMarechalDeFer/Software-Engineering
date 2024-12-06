#!/bin/bash

# Vérifie si un fichier est passé en argument
if [ $# -ne 1 ]; then
    echo "Erreur : Aucun fichier ou trop d'arguments fournis."
    echo "Usage : $0 <nom_du_fichier>"
    exit 1
fi

# Récupère le fichier depuis l'argument
fichier=$1

# Vérifie si le fichier existe
if [ ! -e "$fichier" ]; then
    echo "Erreur : Le fichier $fichier n'existe pas."
    exit 1
fi

# Obtenir les informations sur le fichier
inode=$(ls -i "$fichier" | awk '{print $1}')           # Numéro d'inode
liens=$(stat -c "%h" "$fichier")                      # Nombre de liens
proprietaire=$(stat -c "%U" "$fichier")               # Propriétaire
groupe=$(stat -c "%G" "$fichier")                     # Groupe
taille=$(stat -c "%s" "$fichier")                     # Taille
type=$(stat -c "%F" "$fichier")                       # Type du fichier

# Affiche les résultats
echo "Informations sur le fichier : $fichier"
echo "1. Numéro d'inode : $inode"
echo "2. Nombre de liens : $liens"
echo "3. Propriétaire : $proprietaire"
echo "4. Groupe : $groupe"
echo "5. Taille : $taille octets"
echo "6. Type : $type"
