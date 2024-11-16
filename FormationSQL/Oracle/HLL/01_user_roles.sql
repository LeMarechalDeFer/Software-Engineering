-- dans le futur, utiliser oracle wallet pour sécuriser les mots de passe

CREATE USER hotel_app IDENTIFIED by "3X?c5K/w6E3d%R{x7u" ;
GRANT CONNECT, SELECT, INSERT, UPDATE, DELETE, EXECUTE ;

-- donner accès au séquences
GRANT SELECT ON user_seq TO hotel_app;
GRANT SELECT ON booking_seq TO hotel_app;
GRANT SELECT ON room_seq TO hotel_app;
GRANT SELECT ON payment_seq TO hotel_app;
GRANT SELECT ON invoice_seq TO hotel_app;

-- on utilisera NEXTVAL pour les séquences dans les futures insertions tq:
-- INSERT INTO users (id, name, email)
-- VALUES (user_seq.NEXTVAL, 'John Doe', 'john.doe@example.com');

-- -- Audit

AUDIT INSERT, UPDATE, DELETE ON users BY hotel_app;
AUDIT SESSION BY hotel_app;
AUDIT SESSION BY hotel_app WHENEVER NOT SUCCESSFUL;


AUDIT SELECT ON user_seq BY hotel_app;
-- ...ajouter les autres séquences

-- mettre un revok ou non par defaut ?
-- REVOKE CREATE TABLE, CREATE VIEW, CREATE PROCEDURE, CREATE SEQUENCE, CREATE TRIGGER FROM hotel_app;

CREATE PROFILE hotel_app_profile LIMIT
    SESSIONS_PER_USER 50,        -- Nombre maximal de connexions dans le pool
    CPU_PER_SESSION UNLIMITED,   -- Pas de limite sur le temps CPU total par session
    CPU_PER_CALL 5000,           -- Limite raisonnable (5 secondes) par requête
    CONNECT_TIME UNLIMITED,      -- Pas de limite sur la durée totale de la session
    IDLE_TIME UNLIMITED;         -- Pas de déconnexion automatique pour inactivité

ALTER USER hotel_app PROFILE hotel_app_profile;




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