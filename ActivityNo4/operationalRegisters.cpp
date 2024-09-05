#include "operationalRegisters.h"


// Aumenta o disminuye la instrucción según el valor de INCorDEC.
void operationalRegisters::increase(int select) {
	int sum;
	if (select) {
		sum = 1;  // Aumenta
	}
	else {
		sum = -1;  // Disminuye
	}
	this->instruction = to_string(stoi(this->instruction) + sum);
}

// Suma el valor del acumulador (acum) a la instrucción actual.
void operationalRegisters::add(registersSimu acum) {
	int num1 = stoi(acum.getInsComple());
	int num2 = stoi(this->getInsComple());
	string result = to_string(num1 + num2);
	this->instruction = result;
}