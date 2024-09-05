#include <stdio.h>

void implicit(int integer){
    double implicit_cast;
    double add;
    
    implicit_cast = 2.5; 
    add = implicit_cast + integer;
    printf("casting implicito:\n");
    printf("valor entero: %d\n", integer);
    printf("Suma entre entero y decimal(double): %f\n\n", add);
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
