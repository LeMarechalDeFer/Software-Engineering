CONNECT / AS SYSDBA;
ALTER SESSION SET CONTAINER = FREEPDB1;


BEGIN
  FOR t IN (SELECT table_name FROM all_tables WHERE owner = 'HOTEL_ADMIN') LOOP
    EXECUTE IMMEDIATE 'GRANT SELECT, INSERT, UPDATE, DELETE ON HOTEL_ADMIN.' || t.table_name || ' TO HOTEL_APP';
  END LOOP;

  FOR p IN (SELECT object_name FROM all_objects WHERE owner = 'HOTEL_ADMIN' AND object_type = 'PROCEDURE') LOOP
    EXECUTE IMMEDIATE 'GRANT EXECUTE ON HOTEL_ADMIN.' || p.object_name || ' TO HOTEL_APP';
  END LOOP;
END;
/
