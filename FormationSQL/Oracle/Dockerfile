# FROM oraclelinux:9
# Utiliser l'image Oracle Database Express Edition
FROM container-registry.oracle.com/database/express:21.3.0-xe

# Copier le script SQL dans le conteneur
COPY cinema.sql /opt/oracle/scripts/startup/

# Variables d'environnement pour la configuration de la base de données
ENV ORACLE_PWD=motdepasse
ENV ORACLE_CHARACTERSET=AL32UTF8

# Exposer le port par défaut d'Oracle
EXPOSE 1521

# Instructions pour l'utilisation :
    
#
# 1. Construire l'image :
#    docker build -t oracle-cinema .
#
# 2. Lancer le conteneur :
#    docker run --name oracle-cinema-container -p 1521:1521 oracle-cinema
#
# 3. Se connecter à la base de données (après initialisation) :
#    docker exec -it oracle-cinema-container sqlplus sys/motdepasse@XE as sysdba
#
# 4. Pour exécuter le script cinema.sql :
#    SQL> @/opt/oracle/scripts/startup/cinema.sql
#
# Ces commandes doivent être exécutées depuis le terminal, pas dans le Dockerfile.
