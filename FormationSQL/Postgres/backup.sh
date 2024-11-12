#!/bin/bash
pg_dumpall -U postgres | gzip > /backups/dump.sql.gz
