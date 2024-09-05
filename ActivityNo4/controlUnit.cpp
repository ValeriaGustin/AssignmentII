#include "controlUnit.h"

// Constructor que inicializa la unidad de control con una instrucción.
controlUnit::controlUnit(registersSimu instruction) {
	this->instruction = instruction;
}

// Retorna la instrucción actual almacenada en la unidad de control.
registersSimu controlUnit::getInstructionU() {
	return this->instruction;	
}

// Establece una nueva instrucción en la unidad de control.
void controlUnit::setInstructionU(registersSimu instruction) {
	this->instruction = instruction;
}

// Decodifica la instrucción en una lista de cadenas.
vector<string> controlUnit::decodeIns() {
	vector<string> decode;
	for (int i = 0; i <= 3; i++){
		decode.push_back(this->getInstructionU().getInstruction(i));
		// Elimina el primer carácter si es 'D' y no es el primer elemento.
		if (decode[i][0] == 'D' && i != 0) {
			decode[i] = decode[i].substr(1);
		}
	}
	return decode;
}