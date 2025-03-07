#ifndef CAJERO_H_INCLUDED
#define CAJERO_H_INCLUDED

//Función para verificar que la cantidad ingresada no sea negativa
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
}

#endif // CAJERO_H_INCLUDED
