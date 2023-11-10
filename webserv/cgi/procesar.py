#!/usr/bin/python3
import cgi
import cgitb

# Habilitar la salida de errores detallados en el navegador para depuración
cgitb.enable()

# Crear una instancia de FieldStorage para manejar los datos del formulario
form = cgi.FieldStorage()

# Obtener los valores de los campos 'f_name' y 'email' del formulario
nombre = form.getvalue('nombre', '')  # Si no se proporciona 'f_name', asigna una cadena vacía
email = form.getvalue('email', '')  # Si no se proporciona 'email', asigna una cadena vacía

# Obtener los valores de los campos 'f_name' y 'email' de la cadena de consulta GET


# Imprimir encabezado de tipo de contenido para el navegador
print("Content-type: text/html; charset=utf-8\n")

# Imprimir contenido HTML con los valores obtenidos
print("<html>")
print("<head><title>Resultado del formulario</title></head>")
print("<body>")
print("<h1>Resultado del formulario</h1>")
print(f"<h2>Datos del formulario POST:</h2>")
print(f"<p>Nombre (POST): {nombre}</p>")
print(f"<p>Email (POST): {email}</p>")
print("</body>")
print("</html>")