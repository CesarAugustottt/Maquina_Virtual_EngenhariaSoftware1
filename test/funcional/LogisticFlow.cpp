#include "LogisticFlow.h"

LogisticFlow::LogisticFlow() : FlowHandle() {}

LogisticFlow::LogisticFlow(std::string name, System* source, System* target)
    : FlowHandle(name, source, target) {}

LogisticFlow::~LogisticFlow() {} 

double LogisticFlow::execute() {
    if (this->getTarget() == nullptr) {
        return 0.0;
    }
    double valueTarget = this->getTarget()->getValue();
    return 0.01 * valueTarget * (1 - valueTarget / 70.0);
}
