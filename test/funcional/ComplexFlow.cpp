#include "ComplexFlow.h"

// Aciona o construtor padrão do invólucro para alocar o Body vazio
ComplexFlow::ComplexFlow() : FlowHandle() {}

// Repassa os parâmetros diretamente para o construtor do invólucro pai
ComplexFlow::ComplexFlow(std::string name, System* source, System* target) 
    : FlowHandle(name, source, target) {}

ComplexFlow::~ComplexFlow() {} 

// A amarração tardia acessa os dados através dos métodos da base
double ComplexFlow::execute() {
    if (this->getSource() != nullptr) { 
        return 0.01 * this->getSource()->getValue(); 
    }
    return 0.0;
}
