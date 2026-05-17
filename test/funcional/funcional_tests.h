#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H

#include "../../src/Model.h"
#include "../../src/System.h"
#include "../../src/Flow.h"
#include "../../src/LogisticFlow.h"
#include "../../src/ExponentialFlow.h"
#include "../../src/ComplexFlow.h"

#include<cassert> //para a função assert
#include<cmath> //Para a função fabs()

//assinatura das funções:
void exponentialFuncionalTest();

void logisticalFuncionalTest();

void complexFuncionalTest();

#endif