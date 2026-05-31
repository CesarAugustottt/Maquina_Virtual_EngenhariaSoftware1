#include "Unit_Model.h"
#include "unit_System.h"
#include <iostream>

int main(){
    std::cout << "INICIANDO TESTES UNITÁRIOS" << std::endl;
    //TESTES REGRESSIVOS DE MODEL
    Unit_Model :: regressiveTest();
    std::cout << "Testes unitários de Model passaram com sucesso!" << std::endl;

    //TESTES REGRESSIVOS DE SYSTM
    Unit_System::regressiveTest();
    std::cout << "Testes unitarios de System passaram com sucesso!" << std::endl;

    //TESTES REGRESSIVOS DE FLOW

    std::cout << "TODOS OS TESTES PASSARAM COM SUCESSO!" << std::endl;
    return 0;
}
