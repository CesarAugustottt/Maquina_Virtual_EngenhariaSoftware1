#include "ComplexFlow.h"

// Invoca o construtor padrao da classe base
ComplexFlow::ComplexFlow() : FlowImpl() {}

// Repassa os parametros para o construtor da classe base
ComplexFlow::ComplexFlow(std::string name, System* source, System* target) 
    : FlowImpl(name, source, target) {}

ComplexFlow::~ComplexFlow() {} // Vazio devido ao virtual da classe mae

// Implementacao do calculo
double ComplexFlow::execute() {
    if (this->getSource() != nullptr) { // se tiver sistema de origem
        return 0.01 * this->getSource()->getValue(); 
    }
    return 0.0;
}

// Invoca o construtor de copia da classe base
ComplexFlow::ComplexFlow(const ComplexFlow& flow) : FlowImpl(flow) {}

// Atribuicao por =
ComplexFlow& ComplexFlow::operator=(const ComplexFlow& flow) {
    if (this != &flow) { // se for diferente, faz a atribuicao
        FlowImpl::operator=(flow); // chama o operador = da base para copiar name, source e target
    }
    
    return *this; // retorna o conteudo
}
