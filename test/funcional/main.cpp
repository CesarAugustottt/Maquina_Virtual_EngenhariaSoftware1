#include "funcional_tests.h"
#include "funcional_compositeSystem_tests.h"

int main(){
    std::cout <<"INICIANDO TESTES FUNCIONAIS" << std::endl;

    //chamar função teste exponencial
    exponentialFuncionalTest();

    std::cout <<"Função de teste do Fluxo Exponencial passou!" << std::endl;

    //chamar função teste logistico
    logisticalFuncionalTest();

    std::cout <<"Função de teste do Fluxo Logistico passou!" << std::endl;

    //Chamr função complexa
    complexFuncionalTest();

    std::cout <<"Função de teste do Fluxo Complexo passou!" << std::endl;

    compositeSystemFuncionalTest();

    std::cout <<"Função de teste do Sistema Composto passou!" << std::endl;

    std::cout <<"TODOS OS TESTES PASSARAM!!" << std::endl;
    return 0;
}
