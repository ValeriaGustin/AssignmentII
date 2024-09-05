#include <stdio.h>

void fibonacci(){
	
	int num, f1 = 0, f2 = 1, suma;
	
	printf("Ingrese un numero: ");
	scanf("%i", &num);
	
	printf("fibonacci %i %i ", f1, f2);
	
	for(int i = 0; i < num; i++){
		suma = f1 + f2;
		printf("%i ", suma),
		f1 = f2;
		f2 = suma;
	}
	
}


int main(){
	fibonacci();
	return 0;
}