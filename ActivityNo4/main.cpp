#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "controlUnit.h"
#include "memorySimu.h"
#include "registersSimu.h"
#include "operationalRegisters.h"

using namespace std;

// Declaración de registros operacionales y de simulación
operationalRegisters PC; 
operationalRegisters ALU;
registersSimu ICR = registersSimu();
registersSimu MAR = registersSimu();
registersSimu MDR = registersSimu();
registersSimu ACC = registersSimu();
controlUnit CUnit = controlUnit();
	
string toUpper(string str);
registersSimu fetch(memorySimu memory);
bool execute(vector<string> IDecode, memorySimu memory, registersSimu aux);
int cycleSimulator(memorySimu memory);

// Función para convertir una cadena a mayúsculas
string toUpper(string str) {
    string upperStr = str;  // Copia de la cadena original
    transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);  // Convierte cada carácter
    return upperStr;
}

// Función de fetch: obtiene la instrucción de la memoria
registersSimu fetch(memorySimu memory){
	MAR.setInstruction(PC.getInsComple());  // Carga la instrucción de PC a MAR
	registersSimu aux = memory.getFromMem(MAR);  // Obtiene la instrucción de la memoria
	MDR.setInstruction(aux.getInsComple());  // Carga la instrucción en MDR
	ICR.setInstruction(MDR.getInsComple());  // Carga la instrucción en ICR
	PC.increase(1);  // Incrementa el contador de programa
	CUnit.setInstructionU(ICR);  // Actualiza la unidad de control
	return aux;  // Devuelve la instrucción
}

// Función de ejecución: ejecuta las instrucciones decodificadas
bool execute(vector<string> IDecode, memorySimu memory, registersSimu aux){
		bool nextInstrution = false;  // Control de la siguiente instrucción
		
		if      (toUpper(IDecode[0]) == "SET") {  // Almacena en memoria
			MAR.setInstruction(IDecode[1]);  // Dirección
			MDR.setInstruction(IDecode[2]);  // Valor
			memory.setInMem(MAR, MDR.getInsComple());  // Guarda en memoria
		}
		else if (toUpper(IDecode[0]) == "LDR") {  // Carga de registro
			MAR.setInstruction(IDecode[1]);  // Establece la dirección en MAR
			aux = memory.getFromMem(MAR);  // Obtiene el valor de memoria
			MDR.setInstruction(aux.getInsComple());  // Almacena en MDR
			ACC.setInstruction(MDR.getInsComple());  // Transfiere a ACC
		}
		else if (toUpper(IDecode[0]) == "ADD") {  // Suma
			MAR.setInstruction(IDecode[1]);  // Dirección de primer operando
			aux = memory.getFromMem(MAR);  // Obtiene valor de memoria
			MDR.setInstruction(aux.getInsComple());  // Almacena en MDR
			
			// Suma simple si no hay más operandos
			if (toUpper(IDecode[2]) == "NULL" and toUpper(IDecode[3]) == "NULL") {
				ALU.setInstruction(MDR.getInsComple());  // Pasa valor a la ALU
				ALU.add(ACC);  // Suma a ACC
				ACC.setInstruction(ALU.getInsComple());  // Actualiza ACC
			}
			else {  // Suma con múltiples operandos
				ACC.setInstruction(MDR.getInsComple());
				MAR.setInstruction(IDecode[2]);
				aux = memory.getFromMem(MAR);
				MDR.setInstruction(aux.getInsComple());
				ALU.setInstruction(MDR.getInsComple());
				ALU.add(ACC);
				ACC.setInstruction(ALU.getInsComple());
				
				if (toUpper(IDecode[2]) != "NULL" and toUpper(IDecode[3]) != "NULL") {
					MAR.setInstruction(IDecode[3]);
					MDR.setInstruction(ACC.getInsComple());
					memory.setInMem(MAR, MDR.getInsComple());
				}
			}
		}
		else if (toUpper(IDecode[0]) == "INC") {  // Incrementa un valor
			MAR.setInstruction(IDecode[1]);
			aux = memory.getFromMem(MAR);
			MDR.setInstruction(aux.getInsComple());
			ACC.setInstruction(MDR.getInsComple());
			ALU.setInstruction(ACC.getInsComple());
			ALU.increase(1);  // Incrementa en 1
			ACC.setInstruction(ALU.getInsComple());
			MDR.setInstruction(ACC.getInsComple());
			memory.setInMem(MAR, MDR.getInsComple());  // Almacena en memoria
		}
		else if (toUpper(IDecode[0]) == "DEC") {  // Decrementa un valor
			MAR.setInstruction((IDecode[1]));
			aux = memory.getFromMem(MAR);
			MDR.setInstruction(aux.getInsComple());
			ACC.setInstruction(MDR.getInsComple());
			ALU.setInstruction(ACC.getInsComple());
			ALU.increase(0);  // Decrementa en 1
			ACC.setInstruction(ALU.getInsComple());
			MDR.setInstruction(ALU.getInsComple());
			memory.setInMem(MAR, MDR.getInsComple());  // Almacena en memoria
		}
		else if (toUpper(IDecode[0]) == "STR") {  // Almacena el valor de ACC en memoria
			MAR.setInstruction(IDecode[1]);
			MDR.setInstruction(ACC.getInsComple());
			memory.setInMem(MAR, MDR.getInsComple());
		}
		else if (toUpper(IDecode[0]) == "SHW") {  // Muestra el valor de un registro o memoria
			registersSimu show;
			if (toUpper(IDecode[1]) == "ACC"){
				show = ACC;
				cout << "ACC: ";
			}
			else if (toUpper(IDecode[1]) == "PC"){
				show = PC;
				cout << "PC: ";
			}
			else if (toUpper(IDecode[1]) == "ICR"){
				show = ICR;
				cout << "ICR: ";
			}
			else if (toUpper(IDecode[1]) == "MAR"){
				show = MAR;
				cout << "MAR: ";
			}
			else if (toUpper(IDecode[1]) == "MDR"){
				show = MDR;
				cout << "MDR: ";
			}
			else if (toUpper(IDecode[1]) == "UC"){
				show = CUnit.getInstructionU();
				cout << "UC: ";
			}
			else {  // Muestra valor desde la memoria
				cout << "From Mem: ";
				MAR.setInstruction(IDecode[1]);
				show = memory.getFromMem(MAR);
				MDR.setInstruction(show.getInsComple());
			}
			cout << show.getInsComple() << endl;  // Imprime el valor
		}
		else if (toUpper(IDecode[0]) == "PAUSE") {  // Pausa y muestra estado actual
			cout << "------------------------ PAUSE ------------------------" << endl;
			cout << " - MAR:" << MAR.getInsComple() << endl;
			cout << " - MDR:" << MDR.getInsComple() << endl;
			cout << " - PC:" << PC.getInsComple() << endl;
			cout << " - ICR:" << ICR.getInsComple() << endl;
			cout << " - Control Unity:" << CUnit.getInstructionU().getInsComple() << endl;
			cout << " - ACC:" << ACC.getInsComple() << endl;
		}
		else if (toUpper(IDecode[0]) == "END") {  // Finaliza ejecución
			nextInstrution = true;
		}
	return nextInstrution;  // Control de ciclo de instrucciones
}

// Función que simula el ciclo de instrucciones
int cycleSimulator(memorySimu memory){
	PC.setInstruction("0");  // Inicia el PC en 0
	bool nextInstrution = false;  // Control de la siguiente instrucción
	
	while (not nextInstrution) {  // Bucle principal del ciclo de ejecución
		registersSimu aux = fetch(memory);  // FETCH
		vector<string> IDecode = CUnit.decodeIns();  // DECODE
		nextInstrution = execute(IDecode,memory,aux);  // EXECUTE
	}
	return 0;
}

// Función principal
int main() {
	string nameFile; 
	do {
		cout << "Ponga el nombre del programa (archivo) sin .txt, de lo contrario marque 0 to exit: ";
		cin >> nameFile;
		nameFile = nameFile + ".txt";
		ifstream file(nameFile.c_str());
		if (!file.is_open()) {
	        std::cerr << "Error: No se pudo abrir el archivo " << nameFile << std::endl;
	        return 404;  // Error si no se puede abrir el archivo
	    }
	    else {
			string line;
			vector<registersSimu> A;
			memorySimu memory(A);
			int i = 0;
			while (getline(file, line)) {
			    memory.setRegister(line);
			    i++;
			}
			cycleSimulator(memory);
			cout << endl;
		}
	} while (nameFile != "0.txt");  // Permite múltiples ejecuciones
	return 0;
}
