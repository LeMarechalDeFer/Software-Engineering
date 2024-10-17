

# FROM oraclelinux:9

# ENV ORACLE_SID=MYORACLEDB
# ENV ORACLE_PDB=FIRSTDB
# ENV ORACLE_PWD=tempbeforechange
# ENV ORACLE_HOME=/opt/oracle/product/19c/firstdb

# # Install Oracle pre-requisites
# RUN dnf -y install oracle-database-preinstall-23ai && dnf clean all

# # Add the Oracle 23ai RPM file
# ADD oracle-database-ee-23ai-1.0-1.el8.x86_64.rpm /tmp/
# RUN dnf -y localinstall /tmp/oracle-database-ee-23ai-1.0-1.el8.x86_64.rpm && rm -f /tmp/oracle-database-ee-23ai-1.0-1.el8.x86_64.rpm

# # Define a volume for persistent data
# VOLUME ["/opt/oracle/ordata"]

# # Expose Oracle Database and Enterprise Manager ports
# EXPOSE 1521 5500

# # Configure and start Oracle Database
# CMD ["/etc/init.d/oracledb_ORCLCDB-23ai", "configure"]



FROM oraclelinux:9

ENV ORACLE_SID=MYORACLEDB
ENV ORACLE_PDB=FIRSTDB
ENV ORACLE_PWD=tempbeforechange
ENV ORACLE_HOME=/opt/oracle/product/19c/firstdb

# Install Oracle pre-requisites
RUN yum -y install oracle-database-preinstall-19c && \
    yum clean all && \
    rm -rf /var/cache/yum

# COPY init-database.sh /opt/oracle/scripts/startup/

# Define a volume for persistent data
VOLUME ["/opt/oracle/ordata"]

# Expose Oracle Database and Enterprise Manager ports
EXPOSE 1521 5500

# Commande pour démarrer Oracle Database
CMD ["/bin/bash", "-c", "/opt/oracle/runOracle.sh"]
