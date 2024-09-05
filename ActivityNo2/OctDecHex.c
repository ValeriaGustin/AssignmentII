#include <stdio.h>

void numOCtDecHex(){
    printf("Decimal\tOctal\tHexadecimal\n");
    for (int i = 1; i <= 10; i++) {
        printf("%d\t%o\t%x\n", i, i, i);
    }
}


int main() {
	numOCtDecHex();
	return 0;
}