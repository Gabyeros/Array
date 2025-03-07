#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int A[5];
	
	printf("%d\n", A);

	printf("%d\n", &A);

	printf("%d\n", &A[0]);

	
	int numeros[5] = {10, 20, 30, 40, 50};
	for(int i=0;i<5;i++){
		printf("Elemento %d: %d\n", i, numeros[i]);
	}
	
	int matriz[2][3]={{1, 2 , 3}, {4, 5, 6}};
	
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			printf("Elemento [%d][%d]: %d\n", i, j, matriz[i][j]);
		}
	}
	
	
	return 0;
}
//El identificador de un arreglo es una direccion de memoria