#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H
#include "../../src/Model.h"
#include "LogisticFlow.h"
#include "ExponentialFlow.h"
#include "ComplexFlow.h"

#include<cassert> //para a função assert
#include<cmath> //Para a função fabs()

//! Functional tests header
/**
 * Prototypes for the funcional tests of the simulation framework.
 * This file declares the test cases responsible for validating the dynamics 
 * between the Model, System, and Flow.
 */

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
