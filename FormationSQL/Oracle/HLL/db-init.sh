#!/bin/bash

sqlplus hotel_admin/securepassword@orcl <<EOF
@01_user_roles.sql
@02_tables.sql
@03_views.sql
@04_procedures_and_functions.sql
@05_parameters_and_config.sql
@06_indexes.sql
@07_security.sql
@08_seed_data.sql
@09_jobs_and_automation.sql
EXIT;
EOF
