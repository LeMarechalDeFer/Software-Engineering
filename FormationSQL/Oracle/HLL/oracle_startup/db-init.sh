#!/bin/bash

sqlplus / as sysdba <<EOF
@/opt/oracle/scripts/setup/01_user_roles.sql
@/opt/oracle/scripts/setup/02_tables.sql
@/opt/oracle/scripts/setup/grant_existing_privileges.sql
EXIT;
EOF
