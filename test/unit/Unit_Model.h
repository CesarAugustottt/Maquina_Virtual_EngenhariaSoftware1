#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

#include "../../src/ModelImpl.h"

class Unit_Model{
public:
    static bool construtor_default(void);
    static bool construtor(void);
    static bool destrutor(void);

    static bool execute(void);
    static bool increment(void);

    static bool add(void);
    static bool remove(void);

    static bool getName(void);
    static bool setName(void);
    static bool getTime(void);
    static bool setTime(void);

    static bool atribuicao(void);
    static bool construtorCopia(void);

    //função global chamada pela main
    static bool regressiveTest(void);
};


#endif 