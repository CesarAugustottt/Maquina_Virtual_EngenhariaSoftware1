#include "unit_Flow.h"
#include "../../src/FlowImpl.h"
#include "../../src/SystemImpl.h"
#include <cassert>

class FlowTest : public FlowImpl {
public:
    FlowTest() : FlowImpl() {}
    FlowTest(std::string name, System* source, System* target) : FlowImpl(name, source, target) {}
    virtual ~FlowTest() {}
    virtual double execute() override { return 0.0; }
};

bool Unit_Flow::defaultConstructor(void) {
    FlowTest f1;
    assert(f1.name == "");
    assert(f1.source == nullptr);
    assert(f1.target == nullptr);
    return true;
}

bool Unit_Flow::constructor(void) {
    SystemImpl s1("Src", 10.0);
    SystemImpl s2("Tgt", 0.0);
    FlowTest f2("Fluxo", &s1, &s2);
    
    assert(f2.name == "Fluxo");
    assert(f2.source == &s1);
    assert(f2.target == &s2);
    return true;
}

bool Unit_Flow::destructor(void) {
    FlowTest* f = new FlowTest();
    delete f;
    return true;
}

bool Unit_Flow::getName(void) {
    FlowTest f;
    f.name = "TestName";
    assert(f.getName() == "TestName");
    return true;
}

bool Unit_Flow::setName(void) {
    FlowTest f;
    f.setName("NewName");
    assert(f.name == "NewName");
    return true;
}

bool Unit_Flow::getSource(void) {
    SystemImpl s("Src", 10.0);
    FlowTest f;
    f.source = &s;
    assert(f.getSource() == &s);
    return true;
}

bool Unit_Flow::setSource(void) {
    SystemImpl s("Src", 10.0);
    FlowTest f;
    f.setSource(&s);
    assert(f.source == &s);
    return true;
}

bool Unit_Flow::getTarget(void) {
    SystemImpl s("Tgt", 5.0);
    FlowTest f;
    f.target = &s;
    assert(f.getTarget() == &s);
    return true;
}

bool Unit_Flow::setTarget(void) {
    SystemImpl s("Tgt", 5.0);
    FlowTest f;
    f.setTarget(&s);
    assert(f.target == &s);
    return true;
}

bool Unit_Flow::copyConstructor(void) {
    SystemImpl s1("S1", 10.0);
    SystemImpl s2("S2", 0.0);
    FlowTest original("Original", &s1, &s2);

    FlowTest copia(original);
    assert(copia.name == "Original");
    assert(copia.source == &s1);
    assert(copia.target == &s2);
    return true;
}

bool Unit_Flow::assignmentOperator(void) {
    SystemImpl s1("S1", 10.0);
    SystemImpl s2("S2", 0.0);
    FlowTest original("Original", &s1, &s2);
    FlowTest destino;

    destino = original;
    assert(destino.name == "Original");
    assert(destino.source == &s1);
    assert(destino.target == &s2);
    return true;
}

bool Unit_Flow::regressiveTest(void) {
    assert(defaultConstructor());
    assert(constructor());
    assert(destructor());
    assert(getName());
    assert(setName());
    assert(getSource());
    assert(setSource());
    assert(getTarget());
    assert(setTarget());
    assert(copyConstructor());
    assert(assignmentOperator());
    return true;
}
