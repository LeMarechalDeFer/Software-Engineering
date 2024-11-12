#!/bin/bash

# Charger les variables d'environnement depuis .env
if [ -f .env ]; then
  export $(grep -v '^#' .env | xargs) # Ignorer les lignes de commentaire dans .env
else
  echo "Erreur : fichier .env non trouvé."
  exit 1
fi

# Configurations globales (dans CDB$ROOT)
sqlplus / as sysdba <<EOF
SPOOL /opt/oracle/scripts/setup/init-config.log;

-- Assurez-vous d'être dans le conteneur racine
-- ALTER SESSION SET CONTAINER=CDB$ROOT;

-- Configuration des ports HTTP et HTTPS pour APEX/EM
BEGIN
  DBMS_XDB_CONFIG.SETHTTPPORT(${ORACLE_HTTP_PORT});
  DBMS_XDB_CONFIG.SETHTTPSPORT(${ORACLE_HTTPS_PORT});
END;
/

SPOOL OFF;
EOF

# Configurations spécifiques à FREEPDB1
sqlplus / as sysdba <<EOF
SPOOL /opt/oracle/scripts/setup/cinema.log;

-- Passer au conteneur FREEPDB1
ALTER SESSION SET CONTAINER=FREEPDB1;

-- Créer l'utilisateur uniquement s'il n'existe pas déjà
BEGIN
   EXECUTE IMMEDIATE 'CREATE USER cinema_user IDENTIFIED BY "${ORACLE_PASSWORD}"';
   EXECUTE IMMEDIATE 'GRANT CONNECT, RESOURCE TO cinema_user';
EXCEPTION
   WHEN OTHERS THEN
      -- Ignorer l'erreur si l'utilisateur existe déjà
      IF SQLCODE != -01920 THEN
         RAISE;
      END IF;
END;
/

-- Exécuter le script SQL pour configurer l'application
@/opt/oracle/scripts/setup/cinema.sql

SPOOL OFF;
EOF
