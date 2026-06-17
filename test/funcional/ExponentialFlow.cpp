#include "ExponentialFlow.h"

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
    if (this->source != nullptr) {
        return this->source->getValue() * 0.01; 
    }
    return 0.0;
}
