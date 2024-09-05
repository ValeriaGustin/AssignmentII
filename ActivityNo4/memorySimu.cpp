#include "memorySimu.h"

// Constructor que inicializa la memoria con un vector de registros.
memorySimu::memorySimu(vector<registersSimu> registers) {
	this->registers = registers;
}

// Retorna los registros actuales de la memoria.
vector<registersSimu> memorySimu::getRegisters() {
	return this->registers;
}

// Añade un registro al final de la memoria.
void memorySimu::setRegister(registersSimu reg) {
	this->registers.push_back(reg);
}

// Establece un valor en la posición de memoria indicada por el registro mar.
void memorySimu::setInMem(registersSimu mar, string value) {
	registersSimu aux = registersSimu(value);
	int pos = stoi(mar.getInsComple());
	this->registers[pos] = aux;
}

// Retorna el registro en la posición indicada por mar.
registersSimu memorySimu::getFromMem(registersSimu mar) {
	int pos = stoi(mar.getInsComple());
	return this->getRegisters()[pos];
}

// Retorna el tamaño de la memoria.
int memorySimu::lenMem() {
	return this->registers.size();
}