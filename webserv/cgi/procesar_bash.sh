#!/bin/bash
echo "Hola guapes"


# Leer los datos de la entrada estándar

argument="$1"

# Decode URL-encoded data
decoded_argument=$(printf '%b' "${argument//%/\\x}")

# Parse the values of 'nombre' and 'email'
nombre=$(echo "$decoded_argument" | awk -F'&' '{print $1}' | awk -F'=' '{print $2}')
email=$(echo "$decoded_argument" | awk -F'&' '{print $2}' | awk -F'=' '{print $2}')

# Print the parsed values
#echo "Nombre: $nombre" 
#echo "Email: $email"
## Obtener el valor de 'nombre' y 'email' de los datos decodificados
#nombre=$(echo "$decoded_data" | grep -oP 'nombre=\K[^\&]+')
#email=$(echo "$decoded_data" | grep -oP 'email=\K[^\&]+')
# Obtener el valor de 'nombre' y 'email' de los datos POST

echo "Content-type: text/html; charset=utf-8"
echo ""
echo "<html>"
echo "<head><title>Resultado del formulario</title></head>"
echo "<body>"
echo "<h1>Resultado del formulario</h1>"
echo "<h2>Datos del formulario POST:</h2>"
echo "<p>Nombre (POST): $nombre</p>"
echo "<p>Email (POST): $email</p>"
echo "</body>"
echo "</html>"