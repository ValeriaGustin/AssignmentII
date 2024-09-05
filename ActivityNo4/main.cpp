#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "controlUnit.h"
#include "memorySimu.h"
#include "registersSimu.h"
#include "operationalRegisters.h"

using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "controlUnit.h"
#include "memorySimu.h"
#include "registersSimu.h"
#include "operationalRegisters.h"

using namespace std;

// Variables globales
operationalRegisters PC; 
operationalRegisters ALU;
registersSimu ICR = registersSimu();
registersSimu MAR = registersSimu();
registersSimu MDR = registersSimu();
registersSimu ACC = registersSimu();
controlUnit CUnit = controlUnit();
memorySimu memory = memorySimu();

string toUpper(string str);
registersSimu fetch();
bool execute(vector<string> IDecode, registersSimu aux);
int cycleSimulator();

// Función para convertir a mayúsculas
string toUpper(string str) {
    string upperStr = str;  // Copia de la cadena original
    transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);
    return upperStr;
}

registersSimu fetch() {
    MAR.setInstruction(PC.getInsComple());
    registersSimu aux = memory.getFromMem(MAR);
    MDR.setInstruction(aux.getInsComple());
    ICR.setInstruction(MDR.getInsComple());
    PC.increase(1);
    CUnit.setInstructionU(ICR);
    return aux;
}

bool execute(vector<string> IDecode, registersSimu aux) {
    bool nextInstrution = false;
    
    if (toUpper(IDecode[0]) == "SET") {
        MAR.setInstruction(IDecode[1]);
        MDR.setInstruction(IDecode[2]); 
        memory.setInMem(MAR, MDR.getInsComple());
    }
    else if (toUpper(IDecode[0]) == "LDR") {
        MAR.setInstruction(IDecode[1]);
        aux = memory.getFromMem(MAR);
        MDR.setInstruction(aux.getInsComple());
        ACC.setInstruction(MDR.getInsComple());
    }
    else if (toUpper(IDecode[0]) == "ADD") {
        MAR.setInstruction(IDecode[1]);
        aux = memory.getFromMem(MAR);
        MDR.setInstruction(aux.getInsComple());
        
        if (toUpper(IDecode[2]) == "NULL" && toUpper(IDecode[3]) == "NULL") {
            ALU.setInstruction(MDR.getInsComple());
            ALU.add(ACC);
            ACC.setInstruction(ALU.getInsComple());
        }
        else {
            ACC.setInstruction(MDR.getInsComple());
            MAR.setInstruction(IDecode[2]);
            aux = memory.getFromMem(MAR);
            MDR.setInstruction(aux.getInsComple());
            ALU.setInstruction(MDR.getInsComple());
            ALU.add(ACC);
            ACC.setInstruction(ALU.getInsComple());
            
            if (toUpper(IDecode[2]) != "NULL" && toUpper(IDecode[3]) != "NULL") {
                MAR.setInstruction(IDecode[3]);
                MDR.setInstruction(ACC.getInsComple());
                memory.setInMem(MAR, MDR.getInsComple());
            }
        }
    }
    else if (toUpper(IDecode[0]) == "INC") {
        MAR.setInstruction(IDecode[1]);
        aux = memory.getFromMem(MAR);
        MDR.setInstruction(aux.getInsComple());
        ACC.setInstruction(MDR.getInsComple());
        ALU.setInstruction(ACC.getInsComple());
        ALU.increase(1);
        ACC.setInstruction(ALU.getInsComple());
        MDR.setInstruction(ACC.getInsComple());
        memory.setInMem(MAR, MDR.getInsComple());
    }
    else if (toUpper(IDecode[0]) == "DEC") {
        MAR.setInstruction(IDecode[1]);
        aux = memory.getFromMem(MAR);
        MDR.setInstruction(aux.getInsComple());
        ACC.setInstruction(MDR.getInsComple());
        ALU.setInstruction(ACC.getInsComple());
        ALU.increase(0);
        ACC.setInstruction(ALU.getInsComple());
        MDR.setInstruction(ALU.getInsComple());
        memory.setInMem(MAR, MDR.getInsComple());
    }
    else if (toUpper(IDecode[0]) == "STR") {
        MAR.setInstruction(IDecode[1]);
        MDR.setInstruction(ACC.getInsComple());
        memory.setInMem(MAR, MDR.getInsComple());
    }
    else if (toUpper(IDecode[0]) == "SHW") {
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
        else {
            cout << "From Mem: ";
            MAR.setInstruction(IDecode[1]);
            show = memory.getFromMem(MAR);
            MDR.setInstruction(show.getInsComple());
        }
        cout << show.getInsComple() << endl;
    }
    else if (toUpper(IDecode[0]) == "PAUSE") {
        cout << "------------------------ PAUSE ------------------------" << endl;
        cout << " - MAR:" << MAR.getInsComple() << endl;
        cout << " - MDR:" << MDR.getInsComple() << endl;
        cout << " - PC:" << PC.getInsComple() << endl;
        cout << " - ICR:" << ICR.getInsComple() << endl;
        cout << " - Control Unity:" << CUnit.getInstructionU().getInsComple() << endl;
        cout << " - ACC:" << ACC.getInsComple() << endl;
    }
    else if (toUpper(IDecode[0]) == "END") {
        nextInstrution = true;
    }
    return nextInstrution;
}

int cycleSimulator() {
    PC.setInstruction("0");
    bool nextInstrution = false;
    
    while (!nextInstrution) {
        // FETCH
        registersSimu aux = fetch();
        
        // DECODE
        vector<string> IDecode = CUnit.decodeIns();
        
        // EXECUTE
        nextInstrution = execute(IDecode, aux);
    }
    return 0;
}

int main() {
    string nameFile; 
    do {
        cout << "Ponga el nombre del programa (archivo) sin .txt, de lo contrario marque 0 to exit: ";
        cin >> nameFile;
        nameFile = nameFile + ".txt";
        ifstream file(nameFile.c_str());
        if (!file.is_open()) {
            std::cerr << "Error: No se pudo abrir el archivo " << nameFile << std::endl;
            return 404;  
        }
        else {
            string line;
            vector<registersSimu> A;
            memory = memorySimu(A); // Inicializa la variable global
            int i = 0;
            while (getline(file, line)) {
                memory.setRegister(line);
                i++;
            }
            
            cycleSimulator();
            cout << endl;
        }
    } while (nameFile != "0.txt");
    
    return 0;
}

