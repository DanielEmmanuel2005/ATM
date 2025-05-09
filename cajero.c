#include <stdio.h>
#include <stdlib.h>
#include "atm.h"


void consultarSaldo(struct cliente info) {
    printf("\nTu saldo actual es: %.2f\n", info.saldo);
}

float retirar(float saldouso) {
    float cantidad;
    printf("\nIngrese la cantidad a retirar: ");
    scanf("%f", &cantidad);
    if (cantidad <= 0) {
        printf("Cantidad no válida. Deja de perder el tiempo.\n");
    } else if (cantidad > saldouso) {
        printf("Fondos insuficientes.\n");
    } else {
        saldouso = saldouso - cantidad;
        printf("Retiro exitoso. Tu nuevo saldo es %.2f\n", saldouso);
    }
    return saldouso;
}

float depositar(float saldouso) {
    float cantidad;
    printf("\nIngrese la cantidad a depositar: ");
    scanf("%f", &cantidad);
    if (valida(cantidad)) {
        saldouso =saldouso + cantidad;
        printf("Deposito exitoso. Nuevo saldo: %.2f\n", saldouso);
    }
    return saldouso;
}

struct cliente
{
    int NoCliente;
    float Saldo;
    char Nombre [40];
    int NIP;
};

int main()
{
    int opciones, opciones2;
    float cantidad;
    float saldouso;
    int NIPdado;
    int tamano=3;

    struct cliente clientes[3] ={
        Jose={123, 1010.00, "Jose", 4321},
        Maria={124, 1020.00, "Maria", 2222},
        Luis={125, 1030.00, "Luis", 8721}
    };

    printf("\n-----Cajero Automatico-----\n");
    printf("Introduce Nombre\n");
    scanf("%s",&opciones2);


/*
    for(int i=0;i<tamano;i++){
        if(opciones2==clientes[i].NoCliente){
            printf("Introduce NIP: ");
            scanf("%d",&NIPdado);

            for(int e=0;e<tamano;e++){
                if(NIPdado==clientes[e].NIP)
                Printf("Bienvenido, %s", clientes[e].Nombre);
                saldouso=clientes[e].Saldo;
            }

        }

*/

    do{
        //MENU
        printf("\n-----Cajero Automatico-----\n");
        printf("1.-Consulta de saldo\n");
        printf("2.-Deposito\n");
        printf("3.-Retiro\n");
        printf("4.-Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opciones);

        switch(opciones){
            case 1:
                consultarSaldo(opciones2);
            break;
            case 2:
                //Funcion deposito
                saldouso = depositar(saldouso);
            break;
            case 3:
                //Funcion retiro
                saldouso = retirar(saldouso);
            break;
            case 4:
                //Salida
                printf("!!Espero haber ayudado!!\n");
            break;
        }
    }while(opciones!=4);
    return 0;
}
