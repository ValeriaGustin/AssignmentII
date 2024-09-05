#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

using namespace std;

class Primos {
 public:
    // Método para verificar si un número es primo
    static int definidorDeNumPrimo(int numero) {
        int siesPrimo = 0;
        int numeroDivisor = 2;

        // Verifica casos especiales para 0 y 1
        if (numero <= 1) {
            siesPrimo = 1;
        } else {
            // Verifica si el número es primo
            while (siesPrimo == 0 && numero > numeroDivisor) {
                if (numero % numeroDivisor == 0) {
                    siesPrimo = 1;
                } else {
                    numeroDivisor++;
                }
            }
        }
        return siesPrimo;
    }

    // Método para encontrar números primos en una lista dada
    static void listaPrimos(int * nums, int len) {
        for (int i = 0; i < len; i++) {
        	printf("%d: %s\n", nums[i], definidorDeNumPrimo(nums[i]) ? "No primo" : "Es primo");
    	}
    }

    // Método para generar números primos en un rango dado
    static void primosEnRango(int inicio, int fin) {
        for (int i = inicio; i <= fin; ++i) {
            if (definidorDeNumPrimo(i) == 0){
            	printf("%d ", i);
			}
        }
    }
};

int main(){
	int numero;
    printf("Ingrese un numero para verificar si es primo: ");
    scanf("%d", &numero);
    if (Primos::definidorDeNumPrimo(numero) == 0) {
        printf("%d es un número primo.\n", numero);
    } else {
        printf("%d no es un número primo.\n", numero);
    }

    // 2. Probar el método sonPrimos
    int n;
    printf("Ingrese el numero de elementos en la lista: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(sizeof(int) * n);
    if (arr == nullptr) {
        printf("No se pudo asignar memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    Primos::listaPrimos(arr, n);

    free(arr);

    // 3. Probar el método primosEnRango
    int inicio, fin;
    printf("Ingrese el rango para encontrar numeros primos (inicio fin): ");
    scanf("%d %d", &inicio, &fin);
    printf("Numeros primos en el rango [%d, %d]:\n", inicio, fin);
    Primos::primosEnRango(inicio, fin);
	return 0;
}