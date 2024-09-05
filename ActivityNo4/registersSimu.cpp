#include "registersSimu.h" 



std::vector<std::string> split(std::string str, char delimiter);

// Función auxiliar para dividir una cadena en partes usando un delimitador.
std::vector<std::string> split(std::string str, char delimiter) {
    int posIn = 0;
    int posFound = 0;
    string splitted;
    vector<string> results;
    
    while(posFound >= 0){
        posFound = str.find(delimiter, posIn);
        splitted = str.substr(posIn, posFound - posIn);
        posIn = posFound + 1;
        results.push_back(splitted);
    }
    
    return results;
}

// Constructor que inicializa la instrucción.
registersSimu::registersSimu(string instruction) {
	this->instruction = instruction;
}

// Devuelve la instrucción completa.
string registersSimu::getInsComple() {
	return this->instruction;
}

// Establece una nueva instrucción.
void registersSimu::setInstruction(string instruction) {
	this->instruction = instruction;
}

// Devuelve una parte específica de la instrucción.
string registersSimu::getInstruction(int pos) {
	vector<string> inst = split(instruction, ' ');
	return inst[pos];
}



