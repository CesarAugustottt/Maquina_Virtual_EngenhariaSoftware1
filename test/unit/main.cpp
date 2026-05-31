#include "Unit_Model.h"
#include "unit_System.h"
#include "unit_Flow.h"
#include <iostream>

int main(){
    std::cout << "INICIANDO TESTES UNITARIOS" << std::endl;
    
    // TESTES REGRESSIVOS DE MODEL
    Unit_Model::regressiveTest();
    std::cout << "Testes unitarios de Model passaram com sucesso!" << std::endl;

    // TESTES REGRESSIVOS DE SYSTEM
    Unit_System::regressiveTest();
    std::cout << "Testes unitarios de System passaram com sucesso!" << std::endl;

    // TESTES REGRESSIVOS DE FLOW
    Unit_Flow::regressiveTest();
    std::cout << "Testes unitarios de Flow passaram com sucesso!" << std::endl;

    std::cout << "TODOS OS TESTES PASSARAM COM SUCESSO!" << std::endl;
    return 0;
}
