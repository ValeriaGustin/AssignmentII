#include <stdio.h>

int hasLowercase(const char* str){
    int i = 0;
    int ans = 0;
    
    while (str[i] != '\0' && ans == 0) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            ans = 1; 
        }
        i++;
    }
    return ans; 
}

void hasLower(){
    char str[101];
    printf("Ingrese una cadena sin espacios no mayor a 100 caracteres:  ");
    scanf("%100s", str); 

    if (hasLowercase(str))
        printf("La cadena contiene una minuscula.\n");
    else
        printf("La cadena no contiene una minuscula.\n");
}


int main() {
	hasLower();
	return 0;
}