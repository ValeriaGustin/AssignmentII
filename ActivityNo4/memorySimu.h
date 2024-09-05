#ifndef MEMORYSIMU_H
#define MEMORYSIMU_H

#include <iostream>
#include <vector>
#include "registersSimu.h"


using namespace std;

// Clase que simula la memoria usando registros.
class memorySimu {
	private:
		vector<registersSimu> registers;  // Vector de registros que representa la memoria.
		
	public:
		// Constructores
		memorySimu() = default;  // Constructor por defecto.
		memorySimu(vector<registersSimu> registers);  // Constructor con un vector de registros.
		
		// Métodos para obtener y establecer registros.
		vector<registersSimu> getRegisters();
		void setRegister(registersSimu registers);
		
		// Obtiene y establece valores en la memoria.
		registersSimu getFromMem(registersSimu mar);
		void setInMem(registersSimu mar, string value);
		
		// Devuelve el tamaño de la memoria.
		int lenMem();
};

#endif