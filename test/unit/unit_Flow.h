#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H

class Unit_Flow {
public:
    static bool construtor_default(void);
    static bool construtor(void);
    static bool destrutor(void);
    
    static bool getName(void);
    static bool setName(void);
    static bool getSource(void);
    static bool setSource(void);
    static bool getTarget(void);
    static bool setTarget(void);
    
    static bool construtorCopia(void);
    static bool atribuicao(void);

    // Funcao chamada pela main
    static bool regressiveTest(void);
};

#endif
