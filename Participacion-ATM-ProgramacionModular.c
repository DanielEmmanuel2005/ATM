#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Cliente 
{
    int NoCliente;
    float Saldo;
    char Nombre[40];
    int NIP;
    int Movimientos[10];
};
void Registrar_Cuenta(struct Cliente *cliente) 
{
    printf("Ingrese el nombre de su cuenta: ");
    fgets(cliente->Nombre, sizeof(cliente->Nombre), stdin);
    cliente->Nombre[strcspn(cliente->Nombre, "\n")] = '\0';

    printf("Ingrese el NIP de la cuenta: ");
    scanf("%d", &cliente->NIP);

    cliente->Saldo = 0.0; 
    cliente->NoCliente = 1;

    printf("Cuenta creada correctamente.\n");
    printf("Los Datos de tu Cuenta son los siguientes\n\n");
    printf("Nombre: %s\n", cliente->Nombre);
    printf("NIP: %d\n", cliente->NIP);
    printf("Saldo: %.2f\n", cliente->Saldo);
}
void MostrarSaldo(struct Cliente cliente)
{
    printf("Saldo de cuenta #%d (%s): %.2f\n", cliente.NoCliente, cliente.Nombre, cliente.Saldo);
}
int Depositar(float cantidad)
{
    if (cantidad > 0)
    {
        printf("Depositado correctamente, revise su saldo.\n");
        return 1;
    }
    else if (cantidad == 0)
    {
        printf("El deposito es 0, tu saldo es el mismo.\n");
        return 1;
    }
    else
    {
        printf("Esa cantidad es negativa, por favor no me haga perder tiempo.\n");
        return 101;
    }
}
int Retirar(float cantidad, float saldo)
{
    if (cantidad > 0 && cantidad <= saldo)
    {
        printf("Retiro aceptado, saliendo billetes...\n");
        return 1;
    }
    else if (cantidad > saldo)
    {
        printf("El retiro es mayor a tu saldo. Es imposible que te de ese dinero.\n");
        return 101;
    }
    else if (cantidad == 0)
    {
        printf("Entonces no vas a retirar nada? Anda, vete de aquí.\n");
        return 1;
    }
    else
    {
        printf("Esa cantidad es negativa, por favor no me haga perder tiempo.\n");
        return 101;
    }
}
int main()
{
    struct Cliente clientes[3];
    int Opcion, opcion1;
    float Cantidad;

    do
    {
        printf("\n\n\t\t\t----Menu del Cajero Automatico---\n\n");
        printf("1. Registrar Cliente\n");
        printf("2. Busqueda de cuenta\n");
        printf("3. Iniciar Sesion de una cuenta\n")
        printf("4. Depositar\n");
        printf("5. Guardar o Exportar\n")
        printf("6. Salir\n");
        printf("Seleccione una de las opciones: ");
        scanf("%d", &Opcion);

    switch (Opcion)
    {
        case 1:
            Registrar_Cuenta();
            break;
        case 2:
            //Funcion Busqueda de cuenta
            break;
        case 3:
            //Inicio de sesion
            break;

        case 4:
            //Depositar
            break;
        case 5:
            //Funcion de guardar y exportar
        case 6:
        default:
        printf("Esa opcion no está disponible.\n");
    }

    } while (Opcion != 4);
    system("pause");
    return 0;
}


