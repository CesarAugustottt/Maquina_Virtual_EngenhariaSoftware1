#include "funcional_tests.h"

#include "../../src/ModelImpl.h"
#include "../../src/SystemImpl.h"
#include "../../src/FlowImpl.h"

void exponentialFuncionalTest(){
    Model* m = new ModelImpl();
    System* pop1 = new SystemImpl("pop1", 100.0);
    System* pop2 = new SystemImpl("pop2", 0.0);

    Flow* f1 = createExponentialFlow("exponencial", pop1, pop2);

    //adicionar elementos ao modelo
    m->add(pop1);
    m->add(pop2);
    m->add(f1);

    m->execute(0, 100, 1);

    // Valores finais esperados pelo Vensim
    assert(round(fabs(pop1->getValue() - 36.6032) * 10000) == 0);
    assert(round(fabs(pop2->getValue() - 63.3968) * 10000) == 0);

    delete pop1;
    delete pop2;
    delete f1;
    delete m;
}

void logisticalFuncionalTest(){
    Model* m = new ModelImpl();
    // Valores iniciais de acordo com o Vensim
    System* p1 = new SystemImpl("p1", 100.0); 
    System* p2 = new SystemImpl("p2", 10.0); 

    // O fluxo logistico conecta p1 a p2
    Flow* f1 = createLogisticFlow("logistica", p1, p2);

    // Adiciona elementos ao modelo
    m->add(p1);
    m->add(p2);
    m->add(f1);

    m->execute(0, 100, 1);

    // Valores finais esperados pelo Vensim
    assert(round(fabs(p1->getValue() - 88.2167) * 10000) == 0);
    assert(round(fabs(p2->getValue() - 21.7833) * 10000) == 0);

    delete p1;
    delete p2;
    delete f1;
    delete m;
}

void complexFuncionalTest(){
    Model* m = new ModelImpl();
    //Criar sistemas
    System* q1 = new SystemImpl("Q1", 100.0); 
    System* q2 = new SystemImpl("Q2", 0.0);
    System* q3 = new SystemImpl("Q3", 100.0);
    System* q4 = new SystemImpl("Q4", 0.0);
    System* q5 = new SystemImpl("Q5", 0.0);

    //Criar fluxos
    Flow* f = createComplexFlow("f", q1, q2);  
    Flow* g = createComplexFlow("g", q1, q3);
    Flow* r = createComplexFlow("r", q2, q5);  
    Flow* t = createComplexFlow("t", q2, q3);
    Flow* u = createComplexFlow("u", q3, q4);  
    Flow* v = createComplexFlow("v", q4, q1);

    //Adicionar sistemas
    m->add(q1); m->add(q2); m->add(q3); m->add(q4); m->add(q5);
    //adicionar fluxos
    m->add(f); m->add(g); m->add(r); m->add(t); m->add(u); m->add(v);

    //executar
    m->execute(0, 100, 1);

    // Valores finais esperados pelo Vensim
    assert(round(fabs(q1->getValue() - 31.8513) * 10000) == 0); 
    assert(round(fabs(q2->getValue() - 18.4003) * 10000) == 0);
    assert(round(fabs(q3->getValue() - 77.1143) * 10000) == 0);
    assert(round(fabs(q4->getValue() - 56.1728) * 10000) == 0);
    assert(round(fabs(q5->getValue() - 16.4612) * 10000) == 0);

    delete q1; delete q2; delete q3; delete q4; delete q5;
    delete f; delete g; delete r; delete t; delete u; delete v;
}
