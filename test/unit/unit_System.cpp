#include "unit_System.h"
#include "../../src/SystemImpl.h"
#include <cassert>

bool Unit_System::construtor_default(void) {
    SystemImpl s1;
    assert(s1.getName() == "");
    assert(s1.getValue() == 0.0);
    return true;
}

bool Unit_System::construtor(void) {
    SystemImpl s2("Sys", 10.0);
    assert(s2.getName() == "Sys");
    assert(s2.getValue() == 10.0);
    return true;
}

bool Unit_System::destrutor(void) {
    SystemImpl* s = new SystemImpl();
    delete s;
    return true;
}

bool Unit_System::getName(void) {
    SystemImpl s("TestName", 0.0);
    assert(s.getName() == "TestName");
    return true;
}

bool Unit_System::setName(void) {
    SystemImpl s;
    s.setName("NewName");
    assert(s.getName() == "NewName");
    return true;
}

bool Unit_System::getValue(void) {
    SystemImpl s("Sys", 15.5);
    assert(s.getValue() == 15.5);
    return true;
}

bool Unit_System::setValue(void) {
    SystemImpl s;
    s.setValue(20.0);
    assert(s.getValue() == 20.0);
    return true;
}

bool Unit_System::regressiveTest(void) {
    assert(construtor_default());
    assert(construtor());
    assert(destrutor());
    assert(getName());
    assert(setName());
    assert(getValue());
    assert(setValue());
    return true;
}
