#include "ExponentialFlow.h"
#include "../../src/System.h"

// Invoca o construtor padrao
ExponentialFlow::ExponentialFlow() {
    this->name = "";
    this->source = nullptr;
    this->target = nullptr;
}

// Construtor parametrizado
ExponentialFlow::ExponentialFlow(std::string name, System* source, System* target) 
    : name(name), source(source), target(target) {}

ExponentialFlow::~ExponentialFlow() {} 

void ExponentialFlow::setName(std::string name) {
    this->name = name;
}

std::string ExponentialFlow::getName() const {
    return this->name;
}

void ExponentialFlow::setSource(System* source) {
    this->source = source;
}

System* ExponentialFlow::getSource() const {
    return this->source;
}

void ExponentialFlow::setTarget(System* target) {
    this->target = target;
}

System* ExponentialFlow::getTarget() const {
    return this->target;
}

// Implementacao do calculo
double ExponentialFlow::execute() {
    if (this->getSource() != nullptr) {
        return this->getSource()->getValue() * 0.01; 
    }
    return 0.0;
}

// Construtor de copia
ExponentialFlow::ExponentialFlow(const ExponentialFlow& flow) {
    this->name = flow.name;
    this->source = flow.source;
    this->target = flow.target;
}

// Operador de atribuicao
ExponentialFlow& ExponentialFlow::operator=(const ExponentialFlow& flow) {
    if (this == &flow) {
        return *this; // Protecao contra auto-atribuicao
    }
    
    this->name = flow.name;
    this->source = flow.source;
    this->target = flow.target;
    
    return *this;
}
