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

    // Valores finais esperados pelo Vensim
    assert(pop1.getValue() < 36.6033 && pop1.getValue() > 36.6031); //erro de 0,0001
    assert(pop2.getValue() < 63.3969 && pop2.getValue() > 63.3967); //erro de 0,0001
}

void logisticalFuncionalTest(){
    Model m;
    // Valores iniciais de acordo com o Vensim
    System p1("p1", 100.0); 
    System p2("p2", 10.0); 

    // O fluxo logistico conecta p1 a p2
    LogisticFlow f1("logistica", &p1, &p2);

    // Adiciona elementos ao modelo
    m.add(&p1);
    m.add(&p2);
    m.add(&f1);

    m.execute(0, 100, 1);

    // Valores finais esperados pelo Vensim
    assert(fabs(p1.getValue() - 88.2167) <= 0.0001);
    assert(fabs(p2.getValue() - 21.7833) <= 0.0001);
}

void complexFuncionalTest(){
    Model m;
    //Criar sistemas
    System q1("Q1", 100.0); 
    System q2("Q2", 0.0);
    System q3("Q3", 100.0);
    System q4("Q4", 0.0);
    System q5("Q5", 0.0);

    //Criar fluxos
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
    assert(fabs(q1.getValue() - 31.8513) <= 0.0001); 
    assert(fabs(q2.getValue() - 18.4003) <= 0.0001);
    assert(fabs(q3.getValue() - 77.1143) <= 0.0001);
    assert(fabs(q4.getValue() - 56.1728) <= 0.0001);
    assert(fabs(q5.getValue() - 16.4612) <= 0.0001);
}
