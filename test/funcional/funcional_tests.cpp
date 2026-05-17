#include "funcional_tests.h"

void exponentialFuncionalTest(){
    Model m;
    System pop1("pop1", 100.0);
    System pop2("pop2", 0.0);

    ExponentialFlow f1 ("exponencial", &pop1, &pop2); //conectar os sistemas

    //adicionar elementos ao modelo
    m.add(&pop1);
    m.add(&pop2);
    m.add(&f1);

    m.execute(0, 100, 1);

    assert(pop1.getValue() < 36.6033 && pop1.getValue() > 36.6031);
    assert(pop2.getValue() < 63.3969 && pop2.getValue() > 63.3967);
}