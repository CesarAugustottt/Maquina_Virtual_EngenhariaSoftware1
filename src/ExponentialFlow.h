#ifndef EXPONENTIALFLOW_H
#define EXPONENTIALFLOW_H

#include "Flow.h"

class ExponentialFlow : public Flow {
public:
    // Construtor padrao
    ExponentialFlow();
    // Construtor parametrizado
    ExponentialFlow(std::string name, System* source, System* target);
    // Destrutor virtual
    virtual ~ExponentialFlow();
    // Sobrescrita do execute
    virtual double execute() override;
private:
    // Construtor de copia
    ExponentialFlow(const ExponentialFlow& flow);
    // Operador de atribuicao
    ExponentialFlow& operator=(const ExponentialFlow& flow);
};

#endif
