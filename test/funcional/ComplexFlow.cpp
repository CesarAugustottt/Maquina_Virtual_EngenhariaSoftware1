#include "ComplexFlow.h"

// Invoca o construtor padrao da classe base
ComplexFlow::ComplexFlow() {
    this->name = "";
    this->source = nullptr;
    this->target = nullptr;
}

// Repassa os parametros para inicializacao direta
ComplexFlow::ComplexFlow(std::string name, System* source, System* target) 
    : name(name), source(source), target(target) {}

ComplexFlow::~ComplexFlow() {} 

void ComplexFlow::setName(std::string name) {
    this->name = name;
}

std::string ComplexFlow::getName() const {
    return this->name;
}

void ComplexFlow::setSource(System* source) {
    this->source = source;
}

System* ComplexFlow::getSource() const {
    return this->source;
}

void ComplexFlow::setTarget(System* target) {
    this->target = target;
}

System* ComplexFlow::getTarget() const {
    return this->target;
}

// Implementacao do calculo
double ComplexFlow::execute() {
    if (this->source != nullptr) { 
        return 0.01 * this->source->getValue(); 
    }
    return 0.0;
}
