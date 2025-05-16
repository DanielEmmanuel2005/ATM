#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente {
    int NoCliente;
    float Saldo;
    char Nombre[40];
    int NIP;
    float Movimientos[10];
    int numMovimientos;
};

void agregarMovimiento(struct cliente *cliente, float cantidad);

void Busqueda(struct cliente *clientes, int tamano) {
    char nombre[40];
    printf("Introduce tu nombre: ");
    scanf("%s", nombre);
    int encontrado = 0;
    for (int i = 0; i < tamano; i++) {
        if (strcmp(nombre, clientes[i].Nombre) == 0) {
            printf("Tu numero de cliente es: %d\n", clientes[i].NoCliente);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("No existe este usuario.\n");
    }
}

int valida(float cantidad) {
    if (cantidad <= 0) {
        printf("No se puede hacer el deposito.\n");
        return 0;
    }
    return 1;
}


void ConsultarSaldo(struct cliente clientes) {
    printf("Saldo de cuenta #%d (%s): %.2f\n", clientes.NoCliente, clientes.Nombre, clientes.Saldo);
}

float Depositar(struct cliente *clientes) {
    float cantidad;
    printf("\nIngrese la cantidad a depositar: ");
    scanf("%f", &cantidad);
    if (valida(cantidad)) {
        agregarMovimiento(clientes, cantidad);
        (*clientes).Saldo += cantidad;
        printf("Depósito exitoso. Nuevo saldo: %.2f\n", (*clientes).Saldo);
    }
    return (*clientes).Saldo;
}

float Retirar(struct cliente *clientes) {
    float cantidad;
    char confirmacion;
    printf("\nIngrese la cantidad a retirar: ");
    scanf("%f", &cantidad);
    if (valida(cantidad)) {
        if (cantidad > (*clientes).Saldo) {
            printf("\nSaldo insuficiente. ¿Quiere continuar aun asi? (S o N): ");
            scanf(" %c", &confirmacion);
            if (confirmacion == 'S') {
                agregarMovimiento(clientes, -cantidad);
                (*clientes).Saldo -= cantidad;
                printf("\nRetiro exitoso. Nuevo saldo: %.2f\n", (*clientes).Saldo);
            } else {
                printf("\nRetiro cancelado\n");
            }
        } else {
            agregarMovimiento(clientes, -cantidad);
            (*clientes).Saldo -= cantidad;
            printf("Retiro exitoso. Nuevo saldo: %.2f\n", (*clientes).Saldo);
        }
    }
    return (*clientes).Saldo;
}

void CrearCuenta(struct cliente *clientes, int *numClientes) {
    if (*numClientes >= 100) {
        printf("No se pueden agregar mas clientes. Límite alcanzado.\n");
        return;
    }

    struct cliente nuevaCuenta;
    printf("\nIntroduce el nombre del nuevo cliente: ");
    scanf("%s", nuevaCuenta.Nombre);
    printf("Introduce el saldo inicial: ");
    scanf("%f", &nuevaCuenta.Saldo);
    printf("Introduce el NIP: ");
    scanf("%d", &nuevaCuenta.NIP);

    nuevaCuenta.NoCliente = 123 + *numClientes;
    nuevaCuenta.numMovimientos = 0;
    for (int i = 0; i < 10; i++) {
        nuevaCuenta.Movimientos[i] = 0.0;
    }

    clientes[*numClientes] = nuevaCuenta;
    (*numClientes)++;
    printf("Cuenta creada exitosamente para %s con ID #%d.\n", nuevaCuenta.Nombre, nuevaCuenta.NoCliente);
}

void ConsultarMovimientos(struct cliente cliente) {
    printf("Ultimos movimientos de la cuenta #%d (%s):\n", cliente.NoCliente, cliente.Nombre);

    if (cliente.numMovimientos == 0) {
        printf("No hay movimientos registrados.\n");
        return;
    }

    for (int i = cliente.numMovimientos - 1; i >= 0; i--) {
        float movimiento = cliente.Movimientos[i];
        if (movimiento > 0) {
            printf("Deposito: +%.2f\n", movimiento);
        } else {
            printf("Retiro: %.2f\n", movimiento);
        }
    }
}

void agregarMovimiento(struct cliente *cliente, float cantidad) {
    if ((*cliente).numMovimientos < 10) {
        (*cliente).Movimientos[(*cliente).numMovimientos] = cantidad;
        (*cliente).numMovimientos++;
    } else {
        for (int i = 0; i < 9; i++) {
            (*cliente).Movimientos[i] = (*cliente).Movimientos[i+1];
        }
        (*cliente).Movimientos[9] = cantidad;
    }
}

int main() {
    struct cliente clientes[100] = {
        {123, 1010.00, "Jose", 4321, {0}, 0},
        {124, 1020.00, "Maria", 2222, {0}, 0},
        {125, 1030.00, "Luis", 8721, {0}, 0}
    };

    int Accion, IDdeposito, IDlogin, Niplogin, Consultalogin;
    int numClientes = 3;

    printf("\n----- Cajero Automatico -----\n");

    do {
        printf("\n\n¿Que deseas hacer?\n1.-Login\n2.-Buscar cliente\n3.-Deposito\n4.-Crear Cuenta\n5.-Guarddar\n6.-Salir\n");
        scanf("%d", &Accion);

        switch (Accion) {
            case 1:
                printf("Introduce ID: ");
                scanf("%d", &IDlogin);
                int loginEncontrado = 0;
                for (int i = 0; i < numClientes; i++) {
                    if (IDlogin == clientes[i].NoCliente) {
                        printf("Introduce NIP: ");
                        scanf("%d", &Niplogin);
                        if (Niplogin == clientes[i].NIP) {
                            loginEncontrado = 1;
                            do {
                                printf("\n\n¿Que deseas hacer?\n1.-Consultar Saldo\n2.-Consultar Movimientos\n3.-Retiro\n4.-Salir\n");
                                scanf("%d", &Consultalogin);

                                switch (Consultalogin) {
                                    case 1:
                                        ConsultarSaldo(clientes[i]);
                                        break;
                                    case 2:
                                        ConsultarMovimientos(clientes[i]);
                                        break;
                                    case 3:
                                        Retirar(&clientes[i]);
                                        break;
                                    case 4:
                                        break;
                                }
                            } while (Consultalogin != 4);
                        }
                    }
                }
                if (!loginEncontrado) {
                    printf("No existe este usuario.\n");
                }
                break;

            case 2:
                Busqueda(clientes, numClientes);
                break;

            case 3:
                printf("Introduce ID del deposito: ");
                scanf("%d", &IDdeposito);
                int encontrado2 = 0;
                for (int i = 0; i < numClientes; i++) {
                    if (IDdeposito == clientes[i].NoCliente) {
                        Depositar(&clientes[i]);
                        encontrado2 = 1;
                    }
                }
                if (!encontrado2) {
                    printf("No existe este usuario.\n");
                }
                break;

            case 4:
                CrearCuenta(clientes, &numClientes);
                break;
        case 5:
            //Guardar
            break;
        case 6:
            //Salir
            break;
    }
    }while(Accion !=6);

    return 0;
}
