#include "LogisticFlow.h"

// Construtor padrao
LogisticFlow::LogisticFlow() {
    this->name = "";
    this->source = nullptr;
    this->target = nullptr;
}

// Construtor parametrizado
LogisticFlow::LogisticFlow(std::string name, System* source, System* target)
    : name(name), source(source), target(target) {}

LogisticFlow::~LogisticFlow() {} 

void LogisticFlow::setName(std::string name) {
    this->name = name;
}

std::string LogisticFlow::getName() const {
    return this->name;
}

void LogisticFlow::setSource(System* source) {
    this->source = source;
}

System* LogisticFlow::getSource() const {
    return this->source;
}

void LogisticFlow::setTarget(System* target) {
    this->target = target;
}

System* LogisticFlow::getTarget() const {
    return this->target;
}

// Implementacao do calculo
double LogisticFlow::execute() {
    if(this->target == nullptr) { // Proteção contra ponteiro nulo
        return 0.0;
    }
    double valueTarget = this->target->getValue();
    return 0.01 * valueTarget * (1 - valueTarget / 70.0);
}
