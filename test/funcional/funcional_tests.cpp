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

void complexFuncionalTest(){
    Model m;
    System q1("q1", 100.0); 
    System q2("Q2", 0.0);
    System q3("Q3", 100.0);
    System q4("Q4", 0.0);
    System q5("Q5", 0.0);

    ComplexFlow f("f", &q1, &q2);  
    ComplexFlow g("g", &q1, &q3);
    ComplexFlow r("r", &q2, &q5);  
    ComplexFlow t("t", &q2, &q3);
    ComplexFlow u("u", &q3, &q4);  
    ComplexFlow v("v", &q4, &q1);

    //Adicionar sistemas
    m.add(&q1); m.add(&q2); m.add(&q3); m.add(&q4); m.add(&q5);
    //adicionar fluxos
    m.add(&f); m.add(&g); m.add(&r); m.add(&t); m.add(&u); m.add(&v);

    //executar
    m.execute(0, 100, 1);

    // Valores finais esperados pelo Vensim
    assert(abs(q1.getValue() - 31.8513) <= 0.0001);
    assert(abs(q2.getValue() - 18.4003) <= 0.0001);
    assert(abs(q3.getValue() - 77.1143) <= 0.0001);
    assert(abs(q4.getValue() - 56.1728) <= 0.0001);
    assert(abs(q5.getValue() - 16.4612) <= 0.0001);
}