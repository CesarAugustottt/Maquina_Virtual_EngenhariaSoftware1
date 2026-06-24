#include "funcional_compositeSystem_tests.h"
#include <iostream>
#include <cassert>
#include "../../src/Model.h"
#include "../../src/System.h"
#include "../../src/CompositeSystem.h"


void compositeSystemFuncionalTest(){
    Model* model = Model::createModel("Modelo", 0.0);

    // criar sistemas que representam "bairors"
    System* A = model->createSystem("A", 100.0);
    System* B = model->createSystem("B", 200.0);
    System* C = model->createSystem("C",  50.0);
    System* D = model->createSystem("D", 150.0);

    //criar sistemas composite (cidades)
    System* cidade1 = model->createCompositeSystem("cidade1");
    CompositeSystemHandle* city1 = static_cast<CompositeSystemHandle*>(cidade1); 
    city1->add(A);
    city1->add(B);

    System* cidade2 = model->createCompositeSystem("cidade2");
    CompositeSystemHandle* city2 = static_cast<CompositeSystemHandle*>(cidade2); 
    city2->add(C);
    city2->add(D);

    //criar um sistema país 
    System* pais = model->createCompositeSystem("pais");
    CompositeSystemHandle* country = static_cast<CompositeSystemHandle*>(pais); 
    country->add(city1);
    country->add(city2);

    assert(city1->getValue()   == 300.0);
    assert(city2->getValue()   == 200.0);
    assert(country->getValue() == 500.0);

    city2->remove(C); //remover sistema de valor 50
    
    assert(city1->getValue()   == 300.0);
    assert(city2->getValue()   == 150.0);
    assert(country->getValue() == 450.0);

    Model::deleteModel(model);
}