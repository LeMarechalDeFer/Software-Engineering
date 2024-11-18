
-- docker exec -it oracle-database sqlplus hotel_app/"3X?c5K/w6E3d%R{x7u}"@//localhost:1521/FREEPDB1
-- dans le futur, utiliser oracle wallet pour sécuriser les mots de passe

SPOOL /opt/oracle/scripts/setup/initUser_$(date +%Y%m%d%H%M%S).log;

CONNECT / AS SYSDBA;
ALTER SESSION SET CONTAINER = FREEPDB1;


-- USER hotel_admin
CREATE USER hotel_admin IDENTIFIED BY "AdminSecurePassword"
DEFAULT TABLESPACE users
QUOTA UNLIMITED ON users; 

GRANT CONNECT, RESOURCE TO hotel_admin;

-- USER hotel_app
CREATE USER hotel_app IDENTIFIED by "3X?c5K/w6E3d%R{x7u" 
DEFAULT TABLESPACE users
QUOTA UNLIMITED ON users; 

GRANT CONNECT TO hotel_app; ;
-- cf le script grant_existing_privileges.sql et grant_trigger.sql



-- -- Audit

-- AUDIT INSERT, UPDATE, DELETE ON users BY hotel_app;
-- AUDIT SESSION BY hotel_app;
-- AUDIT SESSION BY hotel_app WHENEVER NOT SUCCESSFUL;

-- AUDIT CREATE, ALTER, DROP ON SCHEMA hotel_admin;


-- CREATE PROFILE hotel_app_profile LIMIT
--     SESSIONS_PER_USER 50,        -- Nombre maximal de connexions dans le pool
--     CPU_PER_SESSION UNLIMITED,   -- Pas de limite sur le temps CPU total par session
--     CPU_PER_CALL 5000,           -- Limite raisonnable (5 secondes) par requête
--     CONNECT_TIME UNLIMITED,      -- Pas de limite sur la durée totale de la session
--     IDLE_TIME UNLIMITED;         -- Pas de déconnexion automatique pour inactivité

-- ALTER USER hotel_app PROFILE hotel_app_profile;

SELECT USERNAME, PROFILE FROM DBA_USERS WHERE USERNAME = 'HOTEL_APP';
SELECT * FROM DBA_PROFILES WHERE PROFILE = 'HOTEL_APP_PROFILE';


SPOOL OFF;

-- SELECT USERNAME, TIMESTAMP, ACTION_NAME, RETURNCODE 
-- FROM UNIFIED_AUDIT_TRAIL 
-- WHERE USERNAME = 'HOTEL_APP' AND RETURNCODE != 0;


-- -- Nombre maximal de processus
-- SELECT name, value FROM v$parameter WHERE name = 'processes';
-- -- Nombre maximal de sessions
-- SELECT name, value FROM v$parameter WHERE name = 'sessions';

-- SELECT COUNT(*) AS current_sessions FROM v$session WHERE status = 'ACTIVE';
-- SELECT COUNT(*) AS current_processes FROM v$process;



-- processus = 200 et donc par definition sessions = 322 car sessions = (1.1 * processes) + 5


-- politique d'audit
-- les triggers
-- les seed insert (roles, frequency, etc)
-- les views (vu user avec roles et informations, vu services avec horraires, vue devis avec detaille, vue chambre avec tarifs par saison)
-- les procedures
-- rman et oracle scheduler


-- oracle wallet manager
-- les requete V$XXXX
