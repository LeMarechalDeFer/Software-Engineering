#!/bin/bash

# Variables
ORACLE_HOME=/path/to/oracle_home
ORACLE_SID=your_database_sid
BACKUP_DIR=/path/to/rman_backups
LOG_FILE=/path/to/logs/rman_backup_$(date +%F).log

export ORACLE_HOME ORACLE_SID

# Lancer la sauvegarde RMAN
$ORACLE_HOME/bin/rman target / <<EOF >> $LOG_FILE 2>&1
RUN {
    ALLOCATE CHANNEL c1 DEVICE TYPE DISK;
    BACKUP DATABASE PLUS ARCHIVELOG;
    DELETE OBSOLETE;
    RELEASE CHANNEL c1;
}
EXIT;
EOF
