#include <stdio.h>
#include <stdlib.h>
#include "cajero.h"

/*//Función para verificar que la cantidad ingresada no sea negativa
int verificacion(float cantidad){

        if(cantidad<0){
            return 1;
        }else{
            return 2;
        }
}

//Función para verificar que la cantidad ingresada no sea mayor al saldo
int verificacionRetiro(float cantidad, float saldo[], int cuenta){

        if(cantidad>saldo[cuenta]){
            return 1;
        }else{
            return 2;
        }
}

//Función para consultar saldo
void consultarSaldo(float saldo[], int cuenta){
    printf("\n\tConsultar saldo\n\n");
    printf("Tu saldo es: %f\n", saldo[cuenta]);
}

//función para depositar saldo
float depositarSaldo(float saldo[], float deposito, int cuenta){
    saldo[cuenta]+=deposito;
    printf("Deposito exitoso\n");
    return saldo[cuenta];
}

//función para retirar dinero
float retirarSaldo(float saldo[], float retiro, int cuenta){
    saldo[cuenta]-=retiro;
    printf("Retiro exitoso\n");
    return saldo[cuenta];
}

//Función para limpiar pantalla
void limpiarPantalla(){
    #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
}

//Función para pausar antes de limpiar
void pausa(){
    #ifdef _WIN32
            system("pause");
        #else
            system("read -p 'Press any key to continue...' var");
        #endif
}*/

int main()
{

    int op, i, v=0, b=1, h=0, cuenta;
    float saldo[3]={1000, 2000, 1500}, deposito, retiro;


    int inte=0, nip=2177, res;

    do{
            limpiarPantalla();
            printf("\tBienvenido al cajero automatico\n\n");
            printf("Ingresa tu NIP de cuatro digitos: ");
            scanf("%i", &res);

            if(res==nip){
                limpiarPantalla();
                printf("Ingresa el numero de cuenta al que quieres acceder: ");
                scanf("%d", &cuenta);

        do{

        //Aquí se limpia la pantalla

        limpiarPantalla();

        //Menú

        printf("\n\t Bienvenido al programa de cajero automatico\n\n");
        printf("Elige una opcion\n");
        printf("1. Consultar saldo\n");
        printf("2. Depositar dinero\n");
        printf("3. Retirar dinero\n");
        printf("4. Salir\n");
        printf("opción: ");
        scanf("%d", &op);

        //Se vuelve a limpiar pantalla
        limpiarPantalla();

        switch(op){

        case 1:

            consultarSaldo(saldo,cuenta);
            break;

        case 2:
            printf("\t Depositar dinero\n\n");
            printf("Ingresa la cantdad a depositar: ");
            scanf("%f", &deposito);

            //No se hara el deposito hasta que se ingrese una cantidad aceptable
            while(v!=2){

            v=verificacion(deposito);

            if(deposito==0){
            printf("Necesitas un numero mayor a cero para tu deposito, vuelve a ingresar la cantidad: \n");
            scanf("%f", &deposito);
            }else if(v==1){
                printf("No se pueden depositar valores negativos a tu cuenta\nVuelve a ingresar la cantidad: \n");
                scanf("%f", &deposito);
            }}

            saldo[cuenta]=depositarSaldo(saldo, deposito, cuenta);
            break;

        case 3:
            printf("\t Retirar dinero\n\n");
            printf("Ingresa la cantdad a retirar: ");
            scanf("%f", &retiro);

            //No se hara el retiro hasta que se ingrese una cantidad aceptable
            while(v!=2){

            //Aquí se verifica que no se ingresen cantidades negativas
            h=verificacion(retiro);
            if(h==1){

                printf("No se pueden depositar valores negativos a tu cuenta\nVuelve a ingresar la cantidad: \n");
                scanf("%f", &deposito);

            }else{

            v=verificacionRetiro(retiro,saldo, cuenta);

            if(retiro==0){
            printf("Necesitas un numero mayor a cero para tu retiro, vuelve a ingresar la cantidad: \n");
            scanf("%f", &retiro);
            }else if(v==1){
                printf("No se puede retirar valores mayores al saldo de tu cuenta\nVuelve a ingresar la cantidad: \n");
                scanf("%f", &retiro);
            }}

            }

            saldo[cuenta]=retirarSaldo(saldo,retiro, cuenta);

            break;

        case 4:
            printf("\nHasta pronto\n\n");
            b=2;
            break;

        }

        //En esta parte, esta una pausa entre cada opción antes de limpiar la pantalla
        pausa();


    }while(b==1);



            }else{
                printf("\nNIP incorrecto, intentalo de nuevo\n\n");

                pausa();
            }

    inte+=1;

    if(inte==3){
        printf("\nLimite de intentos excedido\n");
    }
    }while(inte!=3);




    return 0;
}

