#include "LogisticFlow.h"
#include "../../src/System.h"

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

double LogisticFlow::execute() {
    if(this->getTarget() == nullptr) { //se não tiver sistema de destino
        return 0.0;
    }
    double valueTarget = getTarget()->getValue();
    return 0.01 * valueTarget * (1 - valueTarget/70);
}

// Construtor de copia
LogisticFlow::LogisticFlow(const LogisticFlow& flow) {
    this->name = flow.name;
    this->source = flow.source;
    this->target = flow.target;
}

// Atribuição por =
LogisticFlow& LogisticFlow::operator=(const LogisticFlow& flow) {
    if (&flow != this) { //se for diferente, faz a atribuição
        this->name = flow.name;
        this->source = flow.source;
        this->target = flow.target; 
    }
    return *this; 
}
