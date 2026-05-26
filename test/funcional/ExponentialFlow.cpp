#include "ExponentialFlow.h"

// Invoca o construtor padrão da classe base
ExponentialFlow::ExponentialFlow() : Flow() {}

// Repassa os parametros para o construtor da classe base
ExponentialFlow::ExponentialFlow(std::string name, System* source, System* target) 
    : Flow(name, source, target) {}

ExponentialFlow::~ExponentialFlow() {} // Vazio pelo mesmo motivo da base

// Implementacao do calculo
double ExponentialFlow::execute() {
    if (this->getSource() != nullptr) {
        return this->getSource()->getValue() * 0.01; 
    }
    return 0.0;
}

// Invoca o construtor de copia da classe base
ExponentialFlow::ExponentialFlow(const ExponentialFlow& flow) : Flow(flow) {}

// Operador de atribuicao
ExponentialFlow& ExponentialFlow::operator=(const ExponentialFlow& flow) {
    if (this == &flow) {
        return *this; // Protecao contra auto-atribuicao
    }
    
    // Chama o operador de atribuicao da classe base para copiar name, source e target
    Flow::operator=(flow); 
    
    return *this;
}
