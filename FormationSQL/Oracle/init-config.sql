SPOOL /opt/oracle/scripts/setup/init-config.log;

ALTER SESSION SET CONTAINER=CDB$ROOT;

-- Activation du port HTTP pour APEX
exec dbms_xdb_config.sethttpport(8080);

-- Activation du port HTTPS pour EM Express
exec dbms_xdb_config.sethttpsport(5500);

-- Autres configurations (si nécessaires)
commit;

SPOOL OFF;
-- dois être en tant que SYSDBA





