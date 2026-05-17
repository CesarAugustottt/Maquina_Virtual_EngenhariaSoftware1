#include "funcional_tests.h"
#include<iostream>

int main(){
    std::cout <<"INICIANDO TESTES FUNCIONAIS" << std::endl;

    //chamar função teste exponencial
    exponentialFuncionalTest();

    //chamar função teste logistico
    logisticalFuncionalTest();

    //Chamr função complexa
    complexFuncionalTest();

    std::cout <<"TODOS OS TESTES PASSARAM!!" << std::endl;
    return 0;
}
