#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include <iostream>
#include <vector>
#include "registersSimu.h"

using namespace std;


// Clase que simula la unidad de control, manejando instrucciones.
class controlUnit {
	private:
		registersSimu instruction;  // Registro que almacena la instrucción actual.
		
	public:
		// Constructores
		controlUnit() = default;  // Constructor por defecto.
		controlUnit(registersSimu instruction);  // Constructor con una instrucción inicial.
		
		// Métodos para obtener y establecer la instrucción.
		registersSimu getInstructionU();
		void setInstructionU(registersSimu instruction);
		
		// Decodifica la instrucción almacenada en componentes.
		vector<string> decodeIns(); 
};



#endif