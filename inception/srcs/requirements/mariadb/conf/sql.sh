#mkdir -p /var/run/mysqld 
#mkdir /var/run/mysqld
#chown -R mysql:mysql /var/run/mysqld
#chmod 777 /var/run/mysqld
chown -R mysql /var/lib/mysql
# Reemplaza la ubicación del archivo PID
sed -i 's/^pid-file\s*=.*/pid-file=\/var\/lib\/mysql\/mysql.pid/g' /etc/mysql/mariadb.conf.d/50-server.cnf
#sed -i 's/^socket\s*=.*/socket=\/var\/lib\/mysql\/mysql.sock/g' /etc/mysql/debian.cnf

# Reemplaza la ubicación del archivo de socket
sed -i 's/^socket\s*=.*/socket=\/var\/lib\/mysql\/mysql.sock/g' /etc/mysql/mariadb.conf.d/50-server.cnf

#rm /var/lib/mysql/ib_logfile0 /var/lib/mysql/b_logfile1 /var/lib/mysql/aria_log_control
sed -i "s/^bind-address\s*=.*$/#bind-address = 127.0.0.1/" /etc/mysql/mariadb.conf.d/50-server.cnf

#sed -i "s/bind-address\s*=.*/bind-address=0.0.0.0/" /etc/mysql/mariadb.conf.d/50-server.cnf
sed -i "s/skip-networking/#skip-networking/g" /etc/mysql/mariadb.conf.d/50-server.cnf
# Configurar puerto en my.cnf
sed -i "s/#\?port\s*=.*/port=3306/" /etc/mysql/mariadb.conf.d/50-server.cnf
/etc/init.d/mysql restart
#printf "CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
#CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}'
#GRANT ALL PRIVILEGES ON *.* TO '${MYSQL_USER}'@'localhost'
#ALTER USER 'root'@'localhost' IDENTIFIED BY '${ROOT_PASSWORD}';
#FLUSH PRIVILEGES;" > create.sql
chmod +x /tmp/create.sh
service mysql restart
