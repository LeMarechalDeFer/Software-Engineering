SPOOL /opt/oracle/scripts/setup/init-config.log;

-- Activation du port HTTP pour APEX
exec dbms_xdb_config.sethttpport(8080);

-- Activation du port HTTPS pour EM Express
exec dbms_xdb_config.sethttpsport(5500);

-- Autres configurations (si nécessaires)
commit;

SPOOL OFF;
-- fonctionne pas pour le moment