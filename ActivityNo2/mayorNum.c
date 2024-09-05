#include <stdio.h>

void mayorNum(){
	
	int num1 , num2, num3;
	
	printf("Ingrese el primer numero: ");
	scanf("%i", &num1);
	printf("Ingrese el segundo numero: ");
	scanf("%i", &num2);
	printf("Ingrese el tercer numero: ");
	scanf("%i", &num3);
	
	if(num1 > num2 && num1 > num3){
		printf("El numero mayor es %i \n", num1);	
	}
	else if(num2 > num1 && num2 > num3){
		printf("El numero mayor es %i \n", num2);
	}
	else{
		printf("El numero mayor es %i \n", num3);
	}
		

}


int main(){
	mayorNum();
	return 0;
}