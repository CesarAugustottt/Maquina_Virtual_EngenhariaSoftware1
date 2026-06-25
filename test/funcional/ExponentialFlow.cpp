#include "ExponentialFlow.h"

ExponentialFlow::ExponentialFlow() : FlowHandle() {}

ExponentialFlow::ExponentialFlow(std::string name, System* source, System* target) 
    : FlowHandle(name, source, target) {}

ExponentialFlow::~ExponentialFlow() {} 

double ExponentialFlow::execute() {
    if (this->getSource() != nullptr) {
        return this->getSource()->getValue() * 0.01; 
    }
    return 0.0;
}
