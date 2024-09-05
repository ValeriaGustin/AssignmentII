#include <stdio.h>

int hasUppercase(const char* str){
    int i = 0;
    int ans = 0;
    
    while (str[i] != '\0' && ans == 0) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            ans = 1; 
        }
        i++;
    }
    return ans; 
}

void hasUpper(){
    char str[101];
    printf("Ingrese una cadena sin espacios no mayor a 100 caracteres:  ");
    scanf("%100s", str); 

    if (hasUppercase(str))
        printf("La cadena contiene una mayuscula.\n");
    else
        printf("La cadena no contiene una mayuscula.\n");

}


int main() {
	hasUpper();
	return 0;
}