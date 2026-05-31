#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H

class Unit_Flow {
public:
    static bool defaultConstructor(void);
    static bool constructor(void);
    static bool destructor(void);
    
    static bool getName(void);
    static bool setName(void);
    static bool getSource(void);
    static bool setSource(void);
    static bool getTarget(void);
    static bool setTarget(void);
    
    static bool copyConstructor(void);
    static bool assignmentOperator(void);

    static bool regressiveTest(void);
};

#endif
