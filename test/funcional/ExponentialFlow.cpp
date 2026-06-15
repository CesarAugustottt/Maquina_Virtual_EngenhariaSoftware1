#include "ExponentialFlow.h"

// Invoca o construtor padrao
ExponentialFlow::ExponentialFlow() : FlowHandle() {}

// Construtor parametrizado
ExponentialFlow::ExponentialFlow(std::string name, System* source, System* target) 
    : FlowHandle(name, source, target) {}

ExponentialFlow::~ExponentialFlow() {} 

// Implementacao do calculo
double ExponentialFlow::execute() {
    if (this->getSource() != nullptr) {
        return this->getSource()->getValue() * 0.01; 
    }
    return 0.0;
}

// Construtor de copia
ExponentialFlow::ExponentialFlow(const ExponentialFlow& flow) : FlowHandle(flow) {}

// Operador de atribuicao
ExponentialFlow& ExponentialFlow::operator=(const ExponentialFlow& flow) {
    if (this == &flow) {
        return *this; // Protecao contra auto-atribuicao
    }
    
    FlowHandle::operator=(flow);
    
    return *this;
}
