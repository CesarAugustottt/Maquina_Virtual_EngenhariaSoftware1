#include "Unit_Model.h"
#include "../../src/SystemImpl.h"
#include "../funcional/ComplexFlow.h"
#include <cassert>
#include <string>
#include<cmath>


bool Unit_Model::construtor_default(void) {
    ModelImpl m1;
    assert(m1.name == "");
    assert(m1.time == 0.0);
    assert(m1.systems.size() == 0);
    assert(m1.flows.size() == 0);

    return true;
}

bool Unit_Model::construtor(void) {
    ModelImpl m2("Modelo Dinamico", 10.0);
    assert(m2.name == "Modelo Dinamico");
    assert(m2.time == 10.0);

    return true;
}

bool Unit_Model::destrutor(void){
    ModelImpl* m = new ModelImpl();
    System* s1 = new SystemImpl();
    
    m->systems.push_back(s1);
    
    delete m; 
    delete s1; 
    
    return true;
}

bool Unit_Model::execute(void) {
    ModelImpl m("Modelo Teste", 0.0);
    System* s1 = new SystemImpl("Origem", 100.0);
    System* s2 = new SystemImpl("Destino", 0.0);

    Flow* f = new ComplexFlow("Fluxo", s1, s2);

    m.add(s1);
    m.add(s2);
    m.add(f);

    m.execute(0, 2, 1);

    assert(m.time == 2.0);

    assert(round(fabs(s1->getValue() - 98.01) * 100) == 0);
    assert(round(fabs(s2->getValue() - 1.99) * 100) == 0);
    delete f;
    delete s1;
    delete s2;

    return true;
}

bool Unit_Model::increment(void){
    ModelImpl m("Modelo", 5.0);
    m.incrementTime(3);
    assert(m.time == 8.0);
    return true;
}

bool Unit_Model::add(void) {
    ModelImpl m;
    System* s1 = new SystemImpl("S1", 10.0);
    System* s2 = new SystemImpl("S2", 0.0);
    Flow* f = new ComplexFlow("F1", s1, s2);

    //adicionar sistema 
    m.add(s1);
    assert(m.systems.size() == 1);
    assert(m.systems[0] == s1);

    //adicionar fluxo
    m.add(f);
    assert(m.flows.size() == 1);
    assert(m.flows[0] == f);

    delete f;
    delete s1;
    delete s2;
    return true;
}

bool Unit_Model::remove(void) {
    ModelImpl m;
    System* s1 = new SystemImpl("S1", 10.0);
    System* s2 = new SystemImpl("S2", 0.0);
    Flow* f = new ComplexFlow("F1", s1, s2);

    m.add(s1);
    m.add(f);

    m.remove(s1);
    assert(m.systems.size() == 0);

    m.remove(f);
    assert(m.flows.size() == 0);

    delete f;
    delete s1;
    delete s2;
    return true;
}

bool Unit_Model::getName(void) {
    ModelImpl m("Nome Teste", 0.0);
    assert(m.getName() == "Nome Teste");
    return true;
}

bool Unit_Model::setName(void) {
    ModelImpl m;
    m.setName("Nome Novo");
    assert(m.name == "Nome Novo");
    return true;
}

bool Unit_Model::getTime(void) {
    ModelImpl m("Modelo", 20.0);
    assert(m.getTime() == 20.0);
    return true;
}

bool Unit_Model::setTime(void) {
    ModelImpl m;
    m.setTime(20.5);
    assert(m.time == 20.5);
    return true;
}

bool Unit_Model::construtorCopia(void) {
    ModelImpl original("Original", 10.0);
    System* s = new SystemImpl("S1", 0.0);
    original.add(s);

    // Invoca o construtor de cópia
    ModelImpl copia(original);
    assert(copia.name == "Original");
    assert(copia.time == 10.0);
    assert(copia.systems.size() == 1); // verific se os vetores foram copiados
    assert(copia.systems[0] == s);

    delete s;
    return true;
}

bool Unit_Model::atribuicao(void) {
    ModelImpl original("Original", 10.0);
    ModelImpl destino("Destino", 0.0);

    destino = original;
    assert(destino.name == "Original");
    assert(destino.time == 10.0);
    return true;
}

bool Unit_Model::regressiveTest(void) {
    // Executa todasa as funções
    assert(construtor_default());
    assert(construtor());
    assert(destrutor());
    assert(execute());
    assert(increment());
    assert(add());
    assert(remove());
    assert(getName());
    assert(setName());
    assert(getTime());
    assert(setTime());
    assert(construtorCopia());
    assert(atribuicao());
    
    return true;
}