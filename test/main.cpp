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

    std::cout << "Sucesso! Todos os cenários de teste foram aprovados." << std::endl;
    
    return 0;
}
