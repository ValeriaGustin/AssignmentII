#include <stdio.h>

void bisiesto(){
	int ano;
	
	printf("Ingrese un ano para saber si es bisiesto: ");
	scanf("%i", &ano);
	
	if (ano % 4 == 0){
		printf("El ano %i es bisiesto\n", ano);
	}
	else{
		printf("El ano %i no es bisiesto\n", ano);
	}
	
}


int main(){
	bisiesto();
	return 0;
}