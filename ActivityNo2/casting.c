#include <stdio.h>

void implicit(int integer){
    double implicit_cast;
    
    implicit_cast = integer;  
    printf("casting implicito:\n");
    printf("valor entero: %d\n", integer);
    printf("Despues de convertirlo impicitamente a decimal (double): %f\n\n", implicit_cast);
}

void explicit(double decimal){
    int explicit_cast;
    
    explicit_cast = (int)decimal;  
    printf("casting explicito:\n");
    printf("valor decimal(double): %f\n", decimal);
    printf("Despues de convertirlo explicitamente a entero: %d\n", explicit_cast);
}

void impExp() {
    double dec;
    int ent;
    printf("Ingrese un número decimal: ");
    scanf("%lf", &dec);
    explicit(dec);
    
    printf("Ingrese un número entero: ");
    scanf("%i", &ent);
    implicit(ent);
}

int main() {
	impExp();
	return 0;
}