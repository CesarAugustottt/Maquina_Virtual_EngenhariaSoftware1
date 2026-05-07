#include "bib.hpp"

//implementação da função fatorial
int calcularFatorial(int n) {
    if (n <= 1) 
    	return 1;
    return n * calcularFatorial(n - 1);
}

//implementar função fibonacci
int calcularFibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int anterior = 0;
    int atual = 1;
    int proximo;

    for (int i = 2; i <= n; i++) {
        proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }
    return atual;
}
