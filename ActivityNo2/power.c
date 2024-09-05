#include <stdio.h>

int powerAux(int base, int exp){
	int  ans;
    if (exp == 0)
    	ans = 1;
    else
        ans =  base * powerAux(base, exp - 1);
    return ans;
}

void power() {
	int base, exp, pow;

	printf("Ingrese la base: ");
	scanf("%i", &base);
	printf("Ingrese el exponente: ");
	scanf("%i", &exp);


	printf("%d^%d = %d\n", base, exp, powerAux(base,exp));



}


int main() {
	power();
	return 0;
}