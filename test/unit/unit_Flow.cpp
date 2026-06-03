#include "unit_Flow.h"
#include "../../src/FlowImpl.h"
#include <cassert>

/*!
 * @brief Mock Object to isolate Flow dependencies.
 */
class SystemMock : public System {
public:
    virtual ~SystemMock() {}
    virtual std::string getName() const override { return ""; }
    virtual void setName(std::string) override {}
    virtual double getValue() const override { return 0.0; }
    virtual void setValue(double) override {}
};

/*!
 * @brief Class used exclusively to instantiate and test FlowImpl.
 */
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
    SystemMock s1;
    SystemMock s2;
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
    SystemMock s;
    FlowTest f;
    f.source = &s;
    assert(f.getSource() == &s);
    return true;
}

bool Unit_Flow::setSource(void) {
    SystemMock s;
    FlowTest f;
    f.setSource(&s);
    assert(f.source == &s);
    return true;
}

bool Unit_Flow::getTarget(void) {
    SystemMock s;
    FlowTest f;
    f.target = &s;
    assert(f.getTarget() == &s);
    return true;
}

bool Unit_Flow::setTarget(void) {
    SystemMock s;
    FlowTest f;
    f.setTarget(&s);
    assert(f.target == &s);
    return true;
}

bool Unit_Flow::copyConstructor(void) {
    SystemMock s1;
    SystemMock s2;
    FlowTest original;
    original.name = "Original";
    original.source = &s1;
    original.target = &s2;

    FlowTest copy(original);
    assert(copy.name == "Original");
    assert(copy.source == &s1);
    assert(copy.target == &s2);
    return true;
}

bool Unit_Flow::assignmentOperator(void) {
    SystemMock s1;
    SystemMock s2;
    FlowTest original;
    original.name = "Original";
    original.source = &s1;
    original.target = &s2;
    FlowTest destination;

    destination = original;
    assert(destination.name == "Original");
    assert(destination.source == &s1);
    assert(destination.target == &s2);
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
