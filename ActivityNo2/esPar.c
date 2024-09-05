#include <stdio.h>

void parOimpar(){
	
	int num;
	
	printf("Ingrese un numero: ");
	scanf("%i", &num);
	
	if(num % 2 == 0){
		printf("El numero %i es par \n", num);
	}
	else{
		printf("El numero %i es impar \n", num);
	}
	
}


int main(){
	parOimpar();
	return 0;
}