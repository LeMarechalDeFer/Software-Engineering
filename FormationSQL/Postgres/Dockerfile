FROM postgres:17

# Copier le script SQL d'initialisation
COPY cinema.sql /docker-entrypoint-initdb.d/

# Copier le fichier de configuration personnalisé
COPY postgresql.conf /etc/postgresql/postgresql.conf

# Définir les variables d'environnement pour la connexion à la base de données
ENV POSTGRES_DB=cinema
ENV POSTGRES_USER=utilisateur
ENV POSTGRES_PASSWORD=motdepasse

# Exposer le port par défaut de PostgreSQL
EXPOSE 5431

# Commande pour forcer PostgreSQL à utiliser la configuration personnalisée
CMD ["postgres", "-c", "config_file=/etc/postgresql/postgresql.conf"]

# Pour exécuter le conteneur et s'y connecter, utilisez les commandes suivantes :
# 
# 1. Construire l'image :
#    docker build -t postgres-cinema .
#
# 2. Lancer le conteneur :
#    docker run --name postgres-cinema-container -p 5431:5431 postgres-cinema
#
# 3. Se connecter à la base de données :
#    docker exec -it postgres-cinema-container psql -U utilisateur -d cinema
#
# Ces commandes doivent être exécutées depuis le terminal, pas dans le Dockerfile.
