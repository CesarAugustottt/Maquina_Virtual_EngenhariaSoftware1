# API do simulador de Sistemas Dinâmicos

**Nome:** César Augusto Tiago Totô  
**Matrícula:** 24.1.4038  

**Nome:** Luiz Fernando Modesto Freitas Rezende  
**Matrícula:** 24.2.4038  

## Descrição do Projeto
Este projeto consiste em uma API para um simulador de Sistemas Dinâmicos, baseado na linguagem de modelagem de J. W. Forrester. Nele, os sistemas atuam como variáveis numéricas diretas que armazenam quantidades de matéria ou energia. A interação é feita por fluxos, que transferem esses recursos de um sistema de origem para um de destino.

## Tecnologias Utilizadas
* Linguagem C++
* Compilador G++ / Make
* Git e GitHub (GitFlow)

## Estrutura do Repositório
* `src/`: Código fonte (.cpp) com as implementações das funcionalidades e cabeçalhos (.h).
* `bin/`: Binários e executáveis.
* `test/`: Testes funcionais e regressivos.
* `doc/`: Documentação técnica.

## Como Compilar e Executar
Para compilar todo o projeto:
```bash
make all
```

Para rodar os testes funcionais:
```bash
make run_funcional
```

Para rodar os testes unitários:
```bash
make run_unit
```

## Fluxo de Desenvolvimento
O projeto segue um padrão rigoroso de ramificações para garantir a estabilidade e a qualidade do código:

1.  **master:** Código estável e pronto para produção (versão final).
2.  **staging:** Ambiente de pré-produção para testes finais.
3.  **develop:** Integração de novas funcionalidades que já passaram nos testes de regressão.
4.  **feat-:** Ramos temporários para desenvolvimento de funcionalidades específicas
