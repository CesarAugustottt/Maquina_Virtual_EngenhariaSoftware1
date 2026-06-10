#include "funcional_tests.h"

#include "ExponentialFlow.h"
#include "ComplexFlow.h"
#include "LogisticFlow.h"

void exponentialFuncionalTest(){
    Model* m = Model::createModel();
    System* pop1 = m->createSystem("pop1", 100.0);
    System* pop2 = m->createSystem("pop2", 0.0);

    Flow* f1 = m->createFlow<ExponentialFlow>("exponencial", pop1, pop2);

    //elementos ja adicionados ao modelo

    m->execute(0, 100, 1);

    // Valores finais esperados pelo Vensim
    assert(round(fabs(pop1->getValue() - 36.6032) * 10000) == 0);
    assert(round(fabs(pop2->getValue() - 63.3968) * 10000) == 0);

    Model::deleteModel(m); //deleta tudo
}

void logisticalFuncionalTest(){
    Model* m = Model::createModel();
    // Valores iniciais de acordo com o Vensim
    System* p1 = m->createSystem("p1", 100.0); 
    System* p2 = m->createSystem("p2", 10.0); 

    // O fluxo logistico conecta p1 a p2
    Flow* f1 = m->createFlow<LogisticFlow>("logistica", p1, p2);

    // Elementos já adicionados ao modelo

    m->execute(0, 100, 1);

    // Valores finais esperados pelo Vensim
    assert(round(fabs(p1->getValue() - 88.2167) * 10000) == 0);
    assert(round(fabs(p2->getValue() - 21.7833) * 10000) == 0);

    Model::deleteModel(m); //deleta tudo
}

void complexFuncionalTest(){
    Model* m = Model::createModel();
    //Criar sistemas
    System* q1 = m->createSystem("Q1", 100.0); 
    System* q2 = m->createSystem("Q2", 0.0);
    System* q3 = m->createSystem("Q3", 100.0);
    System* q4 = m->createSystem("Q4", 0.0);
    System* q5 = m->createSystem("Q5", 0.0);

    //Criar fluxos
    Flow* f = m->createFlow<ComplexFlow>("f", q1, q2);  
    Flow* g = m->createFlow<ComplexFlow>("g", q1, q3);
    Flow* r = m->createFlow<ComplexFlow>("r", q2, q5);  
    Flow* t = m->createFlow<ComplexFlow>("t", q2, q3);
    Flow* u = m->createFlow<ComplexFlow>("u", q3, q4);  
    Flow* v = m->createFlow<ComplexFlow>("v", q4, q1);

    //Elementos já adicionados

    //executar
    m->execute(0, 100, 1);

    // Valores finais esperados pelo Vensim
    assert(round(fabs(q1->getValue() - 31.8513) * 10000) == 0); 
    assert(round(fabs(q2->getValue() - 18.4003) * 10000) == 0);
    assert(round(fabs(q3->getValue() - 77.1143) * 10000) == 0);
    assert(round(fabs(q4->getValue() - 56.1728) * 10000) == 0);
    assert(round(fabs(q5->getValue() - 16.4612) * 10000) == 0);

    Model::deleteModel(m); //deleta tudo
}
