FROM container-registry.oracle.com/database/free:latest


COPY 01_user_roles.sql /opt/oracle/scripts/setup/
COPY 02_tables.sql /opt/oracle/scripts/setup/
COPY grant_existing_privileges.sql /opt/oracle/scripts/setup/

COPY db-init.sh /opt/oracle/scripts/startup/

# Copie du fichier SQL dans le conteneur

# COPY cinema.sql /opt/oracle/scripts/setup/
# COPY cinema-init.sh /opt/oracle/scripts/setup/
# COPY .env /opt/oracle/scripts/setup/


# # Ajout des permissions via l'utilisateur root
# USER root
# RUN chmod +x /opt/oracle/scripts/setup/run-sql.sh
# USER oracle

# CMD ["/bin/bash", "-c", "/opt/oracle/scripts/setup/run-sql.sh && tail -f /dev/null"]

# docker exec -it oracle-database sqlplus / as sysdba
# @/opt/oracle/scripts/setup/init-config.sql
# @/opt/oracle/scripts/setup/cinema.sql
