-- -- Job pour supprimer les réservations annulées de plus de 30 jours
-- BEGIN
--     DBMS_SCHEDULER.CREATE_JOB (
--         job_name => 'delete_cancelled_reservations',
--         job_type => 'PLSQL_BLOCK',
--         job_action => 'DELETE FROM reservations WHERE status = ''cancelled'' AND check_in < SYSDATE - 30;',
--         start_date => SYSTIMESTAMP,
--         repeat_interval => 'FREQ=DAILY; BYHOUR=2;',
--         enabled => TRUE
--     );
-- END;
