#ifndef UNIT_SYSTEM_H
#define UNIT_SYSTEM_H

class Unit_System {
public:
    static bool defaultConstructor(void);
    static bool constructor(void);
    static bool destructor(void);
    
    static bool getName(void);
    static bool setName(void);
    static bool getValue(void);
    static bool setValue(void);

    static bool regressiveTest(void);
};

#endif
