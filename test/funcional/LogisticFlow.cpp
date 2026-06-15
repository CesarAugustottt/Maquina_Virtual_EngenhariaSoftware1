#include "LogisticFlow.h"

// Construtor padrao
LogisticFlow::LogisticFlow() : FlowHandle() {}

// Construtor parametrizado
LogisticFlow::LogisticFlow(std::string name, System* source, System* target)
    : FlowHandle(name, source, target) {}

LogisticFlow::~LogisticFlow() {} 

double LogisticFlow::execute() {
    if(this->getTarget() == nullptr) { //se não tiver sistema de destino
        return 0.0;
    }
    double valueTarget = getTarget()->getValue();
    return 0.01 * valueTarget * (1 - valueTarget/70);
}

// Construtor de copia
LogisticFlow::LogisticFlow(const LogisticFlow& flow) : FlowHandle(flow) {}

// Atribuição por =
LogisticFlow& LogisticFlow::operator=(const LogisticFlow& flow) {
    if (&flow != this) { //se for diferente, faz a atribuição
        FlowHandle::operator=(flow);
    }
    return *this; 
}
