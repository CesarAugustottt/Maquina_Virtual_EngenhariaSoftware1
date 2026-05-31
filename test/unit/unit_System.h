#ifndef UNIT_SYSTEM_H
#define UNIT_SYSTEM_H

class Unit_System {
public:
    static bool construtor_default(void);
    static bool construtor(void);
    static bool destrutor(void);
    
    static bool getName(void);
    static bool setName(void);
    static bool getValue(void);
    static bool setValue(void);

    // Funcao chamada pela main
    static bool regressiveTest(void);
};

#endif
