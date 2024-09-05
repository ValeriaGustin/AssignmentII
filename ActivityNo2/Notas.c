#include <stdio.h>

// Definición de la estructura Pesos
struct Pesos {
    float lab1, lab2, lab3;
    float par1, par2, par3;
};

// Definición de la estructura Notas
struct Notas {
    float notaLab1, notaLab2, notaLab3;
    float notaPar1, notaPar2, notaPar3;
    float notaFinal;
};



void calcularNotaFinal(struct Notas *notas, struct Pesos pesos) {
    notas->notaFinal = (notas->notaLab1 * pesos.lab1) +
					   (notas->notaLab2 * pesos.lab2) +
                       (notas->notaLab3 * pesos.lab3) +
                       (notas->notaPar1 * pesos.par1) +
                       (notas->notaPar2 * pesos.par2) +
                       (notas->notaPar3 * pesos.par3);
}


void datos(){
	struct Pesos pesos;
    struct Notas notas;
    int confirmacion = 0;
    
    while (confirmacion == 0){
    	
	    printf("Ingrese el porcentaje del laboratorio 1: ");
	    scanf("%f", &pesos.lab1);
	    printf("Ingrese el porcentaje del laboratorio 2: ");
	    scanf("%f", &pesos.lab2);
	    printf("Ingrese el porcentaje del laboratorio 3: ");
	    scanf("%f", &pesos.lab3);

    	printf("Ingrese el porcentaje del parcial 1: ");
	    scanf("%f", &pesos.par1);
	    printf("Ingrese el porcentaje del parcial 2: ");
	    scanf("%f", &pesos.par2);
	    printf("Ingrese el porcentaje del parcial 3: ");
	    scanf("%f", &pesos.par3);
	    
	    if((pesos.lab1 + pesos.lab2 + pesos.lab3 + pesos.par1 + pesos.par2 + pesos.par3) == 1.0f) {
        	confirmacion = 1;
        	printf("\n");
    	}
    	else{
    		printf("Error: La suma de los porcentajes no es igual a 100%%.\n");
		}
	}
	
	printf("Ingrese la nota del laboratorio 1: ");
    scanf("%f", &notas.notaLab1);
    printf("Ingrese la nota del laboratorio 2: ");
    scanf("%f", &notas.notaLab2);
    printf("Ingrese la nota del laboratorio 3: ");
    scanf("%f", &notas.notaLab3);

    printf("Ingrese la nota del parcial 1: ");
    scanf("%f", &notas.notaPar1);
    printf("Ingrese la nota del parcial 2: ");
    scanf("%f", &notas.notaPar2);
    printf("Ingrese la nota del parcial 3: ");
    scanf("%f", &notas.notaPar3);

    calcularNotaFinal(&notas, pesos);
    printf("La nota final del curso es: %.2f\n", notas.notaFinal);

    
}


int main(){
	datos();
	return 0;
}