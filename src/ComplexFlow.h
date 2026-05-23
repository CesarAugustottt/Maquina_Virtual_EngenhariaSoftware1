#ifndef COMPLEXFLOW_H
#define COMPLEXFLOW_H

#include "Flow.h"

class ComplexFlow : public Flow {
public:
    // Construtor padrao
    ComplexFlow();
    // Construtor parametrizado
    ComplexFlow(std::string name, System* source, System* target);
    // Destrutor virtual
    virtual ~ComplexFlow();

    // Sobrescrita do metodo execute
    virtual double execute() override;

private:
    // Construtor de copia
    ComplexFlow(const ComplexFlow& flow);
    // Operador de atribuicao
    ComplexFlow& operator=(const ComplexFlow& flow);
};

#endif
