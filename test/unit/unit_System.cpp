#include "unit_System.h"
#include "../../src/SystemImpl.h"
#include <cassert>

bool Unit_System::defaultConstructor(void) {
    SystemImpl s1;
    assert(s1.name == "");
    assert(s1.value == 0.0);
    return true;
}

bool Unit_System::constructor(void) {
    SystemImpl s2("Sys", 10.0);
    assert(s2.name == "Sys");
    assert(s2.value == 10.0);
    return true;
}

bool Unit_System::destructor(void) {
    SystemImpl* s = new SystemImpl();
    delete s;
    return true;
}

bool Unit_System::getName(void) {
    SystemImpl s;
    s.name = "TestName";
    assert(s.getName() == "TestName");
    return true;
}

bool Unit_System::setName(void) {
    SystemImpl s;
    s.setName("NewName");
    assert(s.name == "NewName");
    return true;
}

bool Unit_System::getValue(void) {
    SystemImpl s("Sys", 10.0);
    assert(s.getValue() == 10.0);
    return true;
}

bool Unit_System::setValue(void) {
    SystemImpl s;
    s.setValue(100.0);
    assert(s.value == 100.0);
    return true;
}

bool Unit_System::copyConstructor(void) {
    SystemImpl original("Original", 10.0);
    SystemImpl copy(original);

    assert(copy.name == "Original");
    assert(copy.value == 10.0);
    return true;
}

bool Unit_System::assignmentOperator(void) {
    SystemImpl original("Original", 10.0);
    SystemImpl destination;

    destination = original;

    assert(destination.name == "Original");
    assert(destination.value == 10.0);
    return true;
}

bool Unit_System::regressiveTest(void) {
    assert(defaultConstructor());
    assert(constructor());
    assert(destructor());
    assert(getName());
    assert(setName());
    assert(getValue());
    assert(setValue());
    assert(copyConstructor());
    assert(assignmentOperator());
    return true;
}
