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
## Estructura del Cliente 
La siguiente estructura representa la información de un cliente del cajero automático.

```c
struct Cliente 
{
    char Nombre[40];           // Cadena de caracteres: nombre del cliente
    char Apellido[40];         // Cadena de caracteres: apellido del cliente
    int NoCliente;             // Número entero: ID único del cliente
    int NIP;                   // Número entero: clave de acceso del cliente
    float Saldo;               // Número decimal: saldo disponible en la cuenta
    int Movimientos[10];       // Arreglo de enteros: historial de movimientos
};
```
Caracteristicas de la struct cliente.

* Nombre : Este es un tipo de dato de cadena de caracteres el cual el cliente debe de poner su Nombre al crear la nueva cuenta. 
* Apellido : Este es un tipo de dato de cadena de caracteres el cual el cliente debe de complementar su nombre con el apellido al crear la nueva cuenta.
* NIP : Este es un tipo de dato entero el cual guarda el **NIP** de que el cliente hizo al crear la cuenta.
* Saldo de la cuenta: Este es un tipo de dato float el cual se inicializa en 0 al crear la nueva cuenta.
* Ultimos 10 movimientos en la cuenta : Este es un arreglo de 10 enteros el cual tambien se inicializa en 0 al crear la cuenta, y este dato va a mostrar los ultimos 10 movimientos de la cuenta (Depositos o retiros que se le hicieron a la cuenta).
* Numero del cliente **ID** : Este es un tipo de dato entero el cual es el ID que se le asigna al crear la cuenta.

## Acciones del programa (Funciones del Cajero Automatico)
El programa cuenta con 6 Funciones las cuales son las siguientes:
1. Registrar_Cliente(struct Cliente *cliente, int numeroCliente)
   ```c
   void 
	* Descripción: Registra un nuevo cliente solicitando nombre, apellido, NIP y saldo inicial.
	* Retorno: No retorna nada.
	* Parámetros:
	    * cliente: Puntero a un struct Cliente.
	    * numeroCliente: Número entero que se asigna como ID al nuevo cliente.

3. Busqueda(struct Cliente *clientes)
	* Descripción: Permite buscar a un cliente por nombre y devuelve su número de cliente.
	* Retorno: Imprime el número del cliente si se encuentra, o un mensaje de error si no.
	* Parámetros:
	    * clientes: Arreglo de structs Cliente.

4. Depositar(struct Cliente *clientes, int NumClientes)
	* Descripción: Permite depositar una cantidad en la cuenta de un cliente.
	* Retorno: Actualiza el saldo del cliente y almacena el movimiento.
	* Parámetros:
	    * clientes: Arreglo de structs Cliente.
	    * NumClientes: Número total de clientes registrados.

5. Consulta(struct Cliente *cliente)
	* Descripción: Permite consultar el saldo o ver el historial de movimientos de una cuenta.
	* Retorno: Imprime el saldo o los movimientos.
	* Parámetros:
	    * cliente: Puntero a un struct Cliente.

6. Retiro(struct Cliente *cliente)
	* Descripción: Permite retirar dinero de una cuenta, validando que haya saldo suficiente. Pide confirmación antes de hacer el retiro.
	* Retorno: Actualiza el saldo y registra el movimiento si es aprobado.
	* Parámetros:
	    * cliente: Puntero a un struct Cliente.

7. IniciarSesion(struct Cliente *clientes, int numClientes)
	* Descripción: Verifica que el número de cliente y el NIP sean correctos. Permite al usuario consultar o retirar dinero.
	* Retorno: Ejecuta un menú exclusivo para la cuenta autenticada.
	* Parámetros:
	    * clientes: Arreglo de structs Cliente.
	    * numClientes: Número total de clientes registrados.
