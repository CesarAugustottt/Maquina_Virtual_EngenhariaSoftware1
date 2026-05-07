#include <iostream>
#include <cassert>
#include "../src/bib.hpp" //biblioteca .hpp com o cabeçalho

int main() {
    std::cout << "Iniciando testes funcionais..." << std::endl;

    //cenarios de teste para o calculo do Fatorial
    assert(calcularFatorial(0) == 1);
    assert(calcularFatorial(1) == 1);
    assert(calcularFatorial(5) == 120);
    assert(calcularFatorial(10) == 3628800);
    
    
    //cenarios de teste para o calculo do fibonacci
    assert(calcularFibonacci(1) == 1);
    assert(calcularFibonacci(2) == 1);
    assert(calcularFibonacci(3) == 2);
    assert(calcularFibonacci(4) == 3);
    assert(calcularFibonacci(5) == 5);
    assert(calcularFibonacci(6) == 8);
    assert(calcularFibonacci(7) == 13);
    assert(calcularFibonacci(8) == 21);


    std::cout << "Sucesso! Todos os cenários de teste foram aprovados." << std::endl;
    
    return 0;
}
