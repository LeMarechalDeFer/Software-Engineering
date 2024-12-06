-- CONNECT / AS SYSDBA;
-- ALTER SESSION SET CONTAINER = FREEPDB1;



-- CREATE OR REPLACE TRIGGER grant_privileges_on_new_objects
-- AFTER CREATE ON HOTEL_ADMIN.SCHEMA
-- BEGIN
--   -- Pour les nouvelles tables
--   IF ORA_DICT_OBJ_TYPE = 'TABLE' THEN
--     EXECUTE IMMEDIATE 'GRANT SELECT, INSERT, UPDATE, DELETE ON HOTEL_ADMIN.' || ORA_DICT_OBJ_NAME || ' TO hotel_app';
--   END IF;

--   -- Pour les nouvelles procédures
--   IF ORA_DICT_OBJ_TYPE = 'PROCEDURE' THEN
--     EXECUTE IMMEDIATE 'GRANT EXECUTE ON HOTEL_ADMIN.' || ORA_DICT_OBJ_NAME || ' TO hotel_app';
--   END IF;
-- END;
-- /


-- SELECT TRIGGER_NAME, STATUS
-- FROM USER_TRIGGERS
-- WHERE TRIGGER_NAME = 'GRANT_PRIVILEGES_ON_NEW_OBJECTS';

-- SHOW ERRORS TRIGGER GRANT_PRIVILEGES_ON_NEW_OBJECTS;

-- ALTER TRIGGER GRANT_PRIVILEGES_ON_NEW_OBJECTS ENABLE;


-- SELECT * FROM USER_TAB_PRIVS WHERE GRANTEE = 'HOTEL_APP';

-- SELECT USERNAME FROM DBA_USERS WHERE USERNAME IN ('HOTEL_ADMIN', 'HOTEL_APP');

-- @../../opt/oracle/scripts/setup/01_user_roles.sql
-- @../../opt/oracle/scripts/setup/grant_trigger.sql
-- @../../opt/oracle/scripts/setup/grant_existing_privileges.sql
-- @../../opt/oracle/scripts/setup/02_tables.sql


-- CONNECT hotel_admin/AdminSecurePassword@FREEPDB1;

-- CREATE TABLE test_table (
--   id NUMBER PRIMARY KEY,
--   name VARCHAR2(100)
-- );


-- comprendre pourquoi illegale trigger recursion