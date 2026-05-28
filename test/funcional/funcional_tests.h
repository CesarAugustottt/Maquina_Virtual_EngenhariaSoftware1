#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H
#include "../../src/Model.h"

#include<cassert> //para a função assert
#include<cmath> //Para a função fabs()

//! Functional tests header
/**
 * Prototypes for the funcional tests of the simulation framework.
 * This file declares the test cases responsible for validating the dynamics 
 * between the Model, System, and Flow.
 */

// Fábricas para criação oculta dos fluxos (Padrão de Encapsulamento)
/*!
  Factory function prototype to create an ExponentialFlow instance hiddenly.
*/
Flow* createExponentialFlow(std::string name, System* source, System* target);

/*!
  Factory function prototype to create a LogisticFlow instance hiddenly.
*/
Flow* createLogisticFlow(std::string name, System* source, System* target);

/*!
  Factory function prototype to create a ComplexFlow instance hiddenly.
*/
Flow* createComplexFlow(std::string name, System* source, System* target);

//assinatura das funções:
/*!
  Function prototype for the exponential flow functional test.
*/
void exponentialFuncionalTest();

/*!
  Function prototype for the logistical flow functional test.
*/
void logisticalFuncionalTest();

/*!
  Function prototype for the complex flows functional tests.
*/
void complexFuncionalTest();

#endif
