#!/bin/sh

#wget -P /tmp https://wordpress.org/latest.tar.gz
#tar -xzf /tmp/latest.tar.gz
mkdir -p /var/www/html/
#mv -f wordpress/* /var/www/html/.
#rm latest.tar.gz
# Copiar el archivo de configuración wp-config.php
#cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php
# Reemplazar los valores predeterminados en el archivo wp-config.php con los valores de entorno
#export WP_INSTALL_SKIP="yes"
#sed -i "s/database_name_here/${MYSQL_DATABASE}/" /var/www/html/wp-config.php
#sed -i "s/username_here/${MYSQL_USER}/" /var/www/html/wp-config.php
#sed -i "s/password_here/${MYSQL_PASSWORD}/" /var/www/html/wp-config.php
#sed -i "s/localhost/${MYSQL_HOST}/" /var/www/html/wp-config.php
# Establecer el idioma predeterminado de WordPress
#sed -i "s/^\(define('WPLANG',\).*/\1 '${WP_LANG:-es_ES}');/" /var/www/html/wp-config.php

# Definir el nombre de usuario y contraseña del administrador
#WP_ADMIN_USER="${WP_ADMIN_USER}"
#WP_ADMIN_PASSWORD="${WP_ADMIN_PASSWORD}"
#asegura de que el contenedor de la base de datos 
#esté disponible antes de continuar con el proceso 
#de configuración de WordPress.
# -z le indica a netcat que haga 
#una verificación de puerto en lugar de enviar o recibir datos.
echo "Me estoy ejecutando estoy harto ya"
while ! nc -z mariadb 3306; do
  echo "Esperando a que el contenedor 'db' esté disponible..."
  sleep 1
done
cd /var/www/html
wp core download --locale=es_ES --allow-root
wp --path=/var/www/html config create --dbname=${MYSQL_DATABASE} --dbuser=${MYSQL_USER} --dbpass=${MYSQL_PASSWORD} --dbhost=${MYSQL_HOST} --locale=es_ES --allow-root --skip-check
wp core install --path=/var/www/html  --url=${DOMAIN_NAME} --title="bienvenidos a ... NO HAY MUCHO QUE DECIR" --admin_name=${WP_ADMIN_USER} --admin_user=${WP_ADMIN_USER} --admin_password=${WP_ADMIN_PASSWORD} --admin_email="cbustama@urduliz.com" --skip-email --allow-root
wp --path=/var/www/html theme install https://downloads.wordpress.org/theme/zeever.1.0.9.zip --allow-root
wp --path=/var/www/html theme activate zeever --allow-root
echo "No soy capaz de llegar al final soy yo el script no eres tu tranquilo"
#wp core install --path=/var/www/html  --url=cbustama.42.fr --title="bienvenidos a ..." --admin_user=$WP_ADMIN_PASSWORD --role=administrador --user_pass=$WP_ADMIN_PASS --admin_email="cbustama@custama.com" --allow-root
# Crear un nuevo usuario con el rol de administrador
#wp --path=/var/www/html/ user create $WP_ADMIN_USER admin_email@example.com --role=administrator --user_pass=$WP_ADMIN_PASSWORD --display_name="Hola soy Cbustama bienvenidos" --allow-root
