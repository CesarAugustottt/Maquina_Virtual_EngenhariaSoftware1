#include "funcional_tests.h"
#include "ExponentialFlow.h"
#include "LogisticFlow.h"
#include "ComplexFlow.h"

Flow* createExponentialFlow(std::string name, System* source, System* target) {
    return new ExponentialFlow(name, source, target);
}

Flow* createLogisticFlow(std::string name, System* source, System* target) {
    return new LogisticFlow(name, source, target);
}

Flow* createComplexFlow(std::string name, System* source, System* target) {
    return new ComplexFlow(name, source, target);
}