-- Création des utilisateurs et des rôles
CREATE USER hotel_admin IDENTIFIED BY securepassword;
GRANT CONNECT, RESOURCE, DBA TO hotel_admin;

CREATE USER hotel_user IDENTIFIED BY userpassword;
GRANT CONNECT, RESOURCE TO hotel_user;
ALTER USER hotel_user QUOTA UNLIMITED ON USERS;

-- Permissions spécifiques
REVOKE DBA FROM hotel_user;
GRANT SELECT, INSERT, UPDATE, DELETE ON ALL TABLES IN SCHEMA hotel_admin TO hotel_user;
