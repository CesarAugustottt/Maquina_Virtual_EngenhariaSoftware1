# Maquina_Virtual_EngenhariaSoftware1

## Descrição do Projeto
Este projeto consiste no desenvolvimento de uma maquina virtual em C++ aplicando conceitos fundamentais de Engenharia de Software, como **Ciclo de Vida do Projeto**, **Modelo de desenvolvimento**, **Arquitetura de Software**, **TDD (Test Driven Development)** e **Testes de Integração Contínua**.

## Tecnologias Utilizadas
* Linguagem C++
* Compilador G++ / Make
* Framework de Testes (TDD)
* Git e GitHub (GitFlow)
* Freamework Qt (interface futura)

## Estrutura do Repositório
* `src/`: Código fonte (.cpp) com as implementações das funcionalidades.
* `include/`: Cabeçalhos (.hpp)
* `bin/`: Binários e executáveis.
* `test/`: Testes funcionais e regressivos.
* `doc/`: Documentação técnica.

## Como Compilar e Executar
###Compilação geral
Para compilar todo o projeto:
```bash
make
```

###Teste de Regressão (TDD)
Para compilar e rodar os testes funcionais:
```bash
make testeRegressivo
```

Para rodar os testes funcionais:
```bash
./bin/testeRegressivo.exe
```

## Fluxo de Desenvolvimento
O projeto segue um padrão rigoroso de ramificações para garantir a estabilidade e a qualidade do código:

1.  **master:** Código estável e pronto para produção (versão final).
2.  **staging:** Ambiente de pré-produção para testes finais.
3.  **develop:** Integração de novas funcionalidades que já passaram nos testes de regressão.
4.  **feat-:** Ramos temporários para desenvolvimento de funcionalidades específicas (ex: `feat-fatorial`, `feat-fibonacci`).
