-- -- Configuration des paramètres de la base
-- ALTER DATABASE ARCHIVELOG;

-- ALTER SYSTEM SET processes=300;
-- ALTER SYSTEM SET sessions=400;
-- ALTER SYSTEM SET open_cursors=200;

-- -- Création d'un tablespace pour les logs
-- CREATE TABLESPACE logs_data
-- DATAFILE 'logs_data.dbf' SIZE 50M AUTOEXTEND ON;
