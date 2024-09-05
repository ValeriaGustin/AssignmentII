#ifndef REGISTERSSIMU_H
#define REGISTERSSIMU_H



#include <iostream>
#include <vector>

using namespace std;

class registersSimu {
	protected:
		string instruction;  // Almacena la instrucción completa.
		
	public:
		// Constructor por defecto y con parámetro.
		registersSimu() = default;
		registersSimu(string instruction); 
		
		// Métodos para obtener y establecer la instrucción.
		string getInsComple();
		void setInstruction(string instruction);
		
		// Retorna una parte específica de la instrucción separada por espacios.
		string getInstruction(int pos);
};

#endif

