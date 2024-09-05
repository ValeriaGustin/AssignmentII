#include <stdio.h>



void factorial() {

	int num, fac = 1;

	printf("Ingrese un numero para calcular el factorial: ");
	scanf("%i", &num);

	for(int i = num; i > 0; i--) {
		fac *= i;
	}

	printf("El factorial de %i es: %i \n", num, fac);

    
}

int main()
{
	factorial();
	return 0;
}