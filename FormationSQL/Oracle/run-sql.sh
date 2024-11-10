#!/bin/bash

# Fonction pour attendre que la base de données soit prête
function wait_for_db() {
  echo "Waiting for database to be ready..."
  while true; do
    if echo "SELECT 1 FROM dual;" | sqlplus -s / as sysdba | grep -q "1"; then
      echo "Database is ready!"
      break
    else
      echo "Database is not ready yet. Waiting..."
      sleep 5
    fi
  done
}

# Attendre que la base de données soit prête
wait_for_db

# Exécuter les scripts SQL
echo "Running SQL scripts..."
sqlplus / as sysdba <<EOF
@/opt/oracle/scripts/setup/init-config.sql
@/opt/oracle/scripts/setup/cinema.sql
EXIT;
EOF
echo "SQL scripts executed successfully."
