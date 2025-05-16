# Guía de Instalación
## Requisitos
* Peso: +9 KB.
* Programas Necesarios: Cualquier compilador de el lenguaje de programación C.

Pasos para la instalación:
1. **Contar con una cuenta de Github**
Una vez que hayas creado la cuenta, te encontraras con la pagina de inicio de Github.

2. En la esquina superior derecha encontraras varios botones, entre ellos encontraras la barra de búsqueda, haces click sobre ella y deberas escribir **“OmarMendez245”** para luego apretar la tecla “enter”.
Con esto Github te notificara que encontró un usuario con ese nombre.
![Con titulo](pictures/Segundo paso Instalacion.png "titulo")
3. Harás click sobre el aviso, lo que te mostrara el usuario **“OmarMendez245”**, haces click sobre el y se te mostrara su pagina de usuario.

4. En la parte inferior habrá un apartado llamado **“Contribution activity”**, en el que buscaras el mes de mayo de el 2025.

5. Veras que ahí hubo actividad en un enlace con el nombre de **“DanielEmmanuel2005/ATM”**, haz click sobre ese nombre.

6. Encontraras una pagina con una lista de nombres en la parte central de la pantalla, ahí buscaras **“ATM Terminado”**, haces click sobre el y te mostrara todo nuestro código.

7. Crearas un nuevo proyecto en tu compilador de C y pegaras nuestro código.

8. Haras click en compilar y luego correras el programa.

# Guía de usuario

Al ejecutar el código se mostrará un texto con el nombre del programa junto al menú principal donde puedes seleccionar las siguientes opciones:

*1.-Login : *
Al seleccionar 1 aparecerá “Introduce ID” donde deberás escribir en NoCliente si este existe pedirá el NIP para comprobar que es tu cuenta, en caso de que el NoCliente y NIP sean incorrectos se regresará al menú principal.
Al ser correcto tanto el NoCliente y el NIP se presentará un nuevo menú con las siguientes opciones:

1.Consultar Saldo:
Al seleccionar 1 se mostrará su ID de usuario junto a su nombre y el saldo actual de      
             la cuenta, y regresa al menú.

2.Consultar Movimientos:
Al seleccionar 2 si usted no a hecho movimientos previamente se escribira en la pantalla “No hay movimientos registros”, pero si previamente has hecho algún movimiento se mostrarán los últimos 10 movimientos hechos (positivos si son depósitos y negativo si son retiro.Una vez completado cualquier de los dos casos previos se regresará al menú anterior.

3.Retiro:
Al seleccionar 3 se pedirá la cantidad a retirar y se valida en dado caso de que su saldo sea insuficiente se pedirá una confirmación para seguir con el retiro si es ‘S’ se le restara y quedará el saldo en negativo y si es ‘N’ se cancelara y regresará directamente al menú.Si tiene el saldo suficiente segura con el retiro y regresa al menú.	

4.Salir:
Al seleccionar 4 regresarás al menú principal junto a las primeras opcionesmostradas.

*2.-Buscar cliente:*
Al seleccionar 2 pedirá el nombre de dueño de la cuenta si este no está registrado mostrará “No existe este usuario.” y regresarás al menú principal, pero sí en nombre sí está registrado se mostrará en Nocliente de ese usuario y regresará al menú principal.

*3.-Depósito:*
Al seleccionar 3 pedira el ID o NoCliente de la cuenta al que quieras depositar si este usuario no existe regresarás al menú. Si este existe pedirá la cantidad a depositar a la cuenta y se le sumará y regresas al menú principal. 

*4.-Crear Cuenta:*
Al seleccionar 4 y si existen menos de 100 usuarios se pedirá los datos de la nueva cuenta (nombre, Saldo, Nip) y una vez obtenidos se le asignará un número de cuenta a partir del número 125 y regresas al menú principal.
Si existen 100 usuarios no podrás registrar un nuevo usuario y regresarás al menú principal.

*5.-Guardar:*

*6.-Salir:*
Al seleccionar 6  se acabará el programa y se cerrará.

Explicación/Descripción
