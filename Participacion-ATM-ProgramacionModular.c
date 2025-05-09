#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Cliente 
{
    int NoCliente;
    float Saldo;
    char Nombre[40];
    int NIP;
};
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
    int Usuario;
    int Num_intentos = 0;
    int Clave = 1234;

    struct Cliente clientes[3] = {
        {1, 1000.0, "Juan", 1234},
        {2, 2000.0, "Fernando", 1234},
        {3, 3000.0, "Pepe", 1234}
    };
    do
    {
        if (Num_intentos < 3)
        {
            printf("\n\n\t\t\t----Bienvenido al Cajero Automatico---\n\n");
            printf("Para ingresar a tu cuenta, ingrese su clave de 4 digitos.\n\nClave: ");
            scanf("%d", &Usuario);
            Num_intentos++;
        }
        else
        {
            printf("Demasiados intentos fallidos. Cerrando programa.\n");
            exit(1);
        }
    } while (Usuario != Clave);

    printf("\n\n\n\t\t\t\tContrasena Correcta\n");

    int Opcion, opcion1;
    float Cantidad;

    do
    {
        printf("\n\n\t\t\t----Menu del Cajero Automatico---\n\n");
        printf("1. Consultar Saldo\n");
        printf("2. Depositar Dinero\n");
        printf("3. Retirar Dinero\n");
        printf("4. Salir\n");
        printf("Seleccione una de las opciones: ");
        scanf("%d", &Opcion);

    switch (Opcion)
    {
        case 1:
        printf("\n\n\t\t\t----Que cuenta quieres usar?---\n\n");
        for (int i = 0; i < 3; i++)
        {
            printf("%d. Cuenta #%d - %s\n", i + 1, clientes[i].NoCliente, clientes[i].Nombre);
        }
        printf("Seleccione una de las opciones: ");
        scanf("%d", &opcion1);

        if (opcion1 >= 1 && opcion1 <= 3)
        {
            MostrarSaldo(clientes[opcion1 - 1]);
        }
        else
        {
            printf("Opcion de cuenta inválida.\n");
        }
        break;

        case 2:
        printf("\n\n\t\t\t----Que cuenta quieres usar?---\n\n");
        for (int i = 0; i < 3; i++)
        {
            printf("%d. Cuenta #%d - %s\n", i + 1, clientes[i].NoCliente, clientes[i].Nombre);
        }
        printf("Seleccione una de las opciones: ");
        scanf("%d", &opcion1);

        if (opcion1 >= 1 && opcion1 <= 3)
        {
            struct Cliente *cliente = &clientes[opcion1 - 1];
            MostrarSaldo(*cliente);
            printf("\nCuanto dinero quieres depositar?\nDeposito: ");
            scanf("%f", &Cantidad);
            if (Depositar(Cantidad) == 1)
            {
                cliente->Saldo += Cantidad;
            }
        }
        else
        {
            printf("Opcion de cuenta invalida.\n");
        }
        break;

        case 3:
        printf("\n\n\t\t\t----Que cuenta quieres usar?---\n\n");
        for (int i = 0; i < 3; i++)
        {
            printf("%d. Cuenta #%d - %s\n", i + 1, clientes[i].NoCliente, clientes[i].Nombre);
        }
        printf("Seleccione una de las opciones: ");
        scanf("%d", &opcion1);

        if (opcion1 >= 1 && opcion1 <= 3)
        {
            struct Cliente *cliente = &clientes[opcion1 - 1];
            MostrarSaldo(*cliente);
            printf("\nCuanto dinero quieres retirar?\nRetiro: ");
            scanf("%f", &Cantidad);
            if (Retirar(Cantidad, cliente->Saldo) == 1)
            {
                cliente->Saldo -= Cantidad;
            }
        }else
        {
            printf("Opcion de cuenta invalida.\n");
        }
        break;

        case 4:
        printf("Saliendo del sistema...\n");
        break;

        default:
        printf("Esa opcion no está disponible.\n");
    }

    } while (Opcion != 4);
    system("pause");
    return 0;
}
