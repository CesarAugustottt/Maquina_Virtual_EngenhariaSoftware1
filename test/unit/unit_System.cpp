#include "unit_System.h"
#include "../../src/SystemImpl.h"
#include <cassert>

bool Unit_System::defaultConstructor(void) {
    SystemHandle s1;
    assert(s1.pImpl_->name == "");
    assert(s1.pImpl_->value == 0.0);
    return true;
}

bool Unit_System::constructor(void) {
    SystemHandle s2("Sys", 10.0);
    assert(s2.pImpl_->name == "Sys");
    assert(s2.pImpl_->value == 10.0);
    return true;
}

bool Unit_System::destructor(void) {
    SystemHandle* s = new SystemHandle();
    delete s;
    return true;
}

bool Unit_System::getName(void) {
    SystemHandle s;
    s.pImpl_->name = "TestName";
    assert(s.getName() == "TestName");
    return true;
}

bool Unit_System::setName(void) {
    SystemHandle s;
    s.setName("NewName");
    assert(s.pImpl_->name == "NewName");
    return true;
}

bool Unit_System::getValue(void) {
    SystemHandle s;
    s.pImpl_->value = 10.0;
    assert(s.getValue() == 10.0);
    return true;
}

bool Unit_System::setValue(void) {
    SystemHandle s;
    s.setValue(100.0);
    assert(s.pImpl_->value == 100.0);
    return true;
}

bool Unit_System::copyConstructor(void) {
    SystemHandle original;
    original.pImpl_->name = "Original";
    original.pImpl_->value = 10.0;
    
    SystemHandle copy(original);
    assert(copy.pImpl_->name == "Original");
    assert(copy.pImpl_->value == 10.0);
    return true;
}

bool Unit_System::assignmentOperator(void) {
    SystemHandle original;
    original.pImpl_->name = "Original";
    original.pImpl_->value = 10.0;
    
    SystemHandle destination;
    destination = original;

    assert(destination.pImpl_->name == "Original");
    assert(destination.pImpl_->value == 10.0);
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
