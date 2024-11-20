CONNECT / AS SYSDBA;
ALTER SESSION SET CONTAINER = FREEPDB1;


BEGIN
  FOR t IN (SELECT table_name FROM all_tables WHERE owner = 'HOTEL_ADMIN') LOOP
    EXECUTE IMMEDIATE 'GRANT SELECT, INSERT, UPDATE, DELETE ON hotel_admin.' || t.table_name || ' TO hotel_app';
  END LOOP;

  FOR p IN (SELECT object_name FROM all_objects WHERE owner = 'HOTEL_ADMIN' AND object_type = 'PROCEDURE') LOOP
    EXECUTE IMMEDIATE 'GRANT EXECUTE ON hotel_admin.' || p.object_name || ' TO hotel_app';
  END LOOP;
END;
/
