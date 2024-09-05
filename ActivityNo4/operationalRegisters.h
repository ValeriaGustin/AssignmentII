#ifndef OPERATIONALREGISTERS_H
#define OPERATIONALREGISTERS_H

#include <iostream>
#include <vector>
#include "registersSimu.h"

using namespace std;


// Clase que extiende registersSimu con operaciones adicionales.
class operationalRegisters : public registersSimu {
	public:
		// Incrementa o decrementa el valor de la instrucción.
		void increase(int select);
		
		// Suma el valor de otro registro a la instrucción actual.
		void add(registersSimu acum);
};


#endif