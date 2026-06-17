#include "unit_Flow.h"
#include "../../src/FlowImpl.h"
#include <cassert>

#define DEBUGING
#ifdef DEBUGING
    extern int numHandleCreated;
    extern int numHandleDeleted;
    extern int numBodyCreated;
    extern int numBodyDeleted;
#endif

class SystemMock : public System {
public:
    virtual ~SystemMock() {}
    virtual std::string getName() const override { return ""; }
    virtual void setName(std::string) override {}
    virtual double getValue() const override { return 0.0; }
    virtual void setValue(double) override {}
};

class FlowTest : public FlowHandle {
public:
    FlowTest() : FlowHandle() {}
    FlowTest(std::string name, System* source, System* target) : FlowHandle(name, source, target) {}
    virtual ~FlowTest() {}
    virtual double execute() override { return 0.0; }
};

bool Unit_Flow::defaultConstructor(void) {
    FlowTest f1;
    assert(f1.pImpl_->name == "");
    assert(f1.pImpl_->source == nullptr);
    assert(f1.pImpl_->target == nullptr);
    return true;
}

bool Unit_Flow::constructor(void) {
    SystemMock s1;
    SystemMock s2;
    FlowTest f2("Fluxo", &s1, &s2);
    
    assert(f2.pImpl_->name == "Fluxo");
    assert(f2.pImpl_->source == &s1);
    assert(f2.pImpl_->target == &s2);
    return true;
}

bool Unit_Flow::destructor(void) {
    FlowTest* f = new FlowTest();
    delete f;
    return true;
}

bool Unit_Flow::getName(void) {
    FlowTest f;
    f.pImpl_->name = "TestName";
    assert(f.getName() == "TestName");
    return true;
}

bool Unit_Flow::setName(void) {
    FlowTest f;
    f.setName("NewName");
    assert(f.pImpl_->name == "NewName");
    return true;
}

bool Unit_Flow::getSource(void) {
    SystemMock s;
    FlowTest f;
    f.pImpl_->source = &s;
    assert(f.getSource() == &s);
    return true;
}

bool Unit_Flow::setSource(void) {
    SystemMock s;
    FlowTest f;
    f.setSource(&s);
    assert(f.pImpl_->source == &s);
    return true;
}

bool Unit_Flow::getTarget(void) {
    SystemMock s;
    FlowTest f;
    f.pImpl_->target = &s;
    assert(f.getTarget() == &s);
    return true;
}

bool Unit_Flow::setTarget(void) {
    SystemMock s;
    FlowTest f;
    f.setTarget(&s);
    assert(f.pImpl_->target == &s);
    return true;
}

bool Unit_Flow::copyConstructor(void) {
    SystemMock s1;
    SystemMock s2;
    FlowTest original;
    original.pImpl_->name = "Original";
    original.pImpl_->source = &s1;
    original.pImpl_->target = &s2;

    FlowTest copy(original);
    assert(copy.pImpl_->name == "Original");
    assert(copy.pImpl_->source == &s1);
    assert(copy.pImpl_->target == &s2);
    return true;
}

bool Unit_Flow::assignmentOperator(void) {
    SystemMock s1;
    SystemMock s2;
    FlowTest original;
    original.pImpl_->name = "Original";
    original.pImpl_->source = &s1;
    original.pImpl_->target = &s2;
    
    FlowTest destination;
    destination = original;

    assert(destination.pImpl_->name == "Original");
    assert(destination.pImpl_->source == &s1);
    assert(destination.pImpl_->target == &s2);
    return true;
}

bool Unit_Flow::handleBodyTest(void) {
    #ifdef DEBUGING
        numHandleCreated = 0;
        numHandleDeleted = 0;
        numBodyCreated = 0;
        numBodyDeleted = 0;
    #endif

    {
        FlowTest f1("Fluxo 1", nullptr, nullptr);
        FlowTest f2("Fluxo 2", nullptr, nullptr);

        assert(numHandleCreated == 2);
        assert(numBodyCreated == 2);
        assert(numHandleDeleted == 0);
        assert(numBodyDeleted == 0);

        f1 = f2; 
        assert(numBodyDeleted == 1); 
    } 

    assert(numHandleCreated == 2);
    assert(numHandleDeleted == 2);
    assert(numBodyCreated == 2);
    assert(numBodyDeleted == 2);

    #ifdef DEBUGING
        numHandleCreated = 0; 
        numHandleDeleted = 0;
        numBodyCreated = 0; 
        numBodyDeleted = 0;
    #endif

    {
        FlowTest f3("Original", nullptr, nullptr); 
        
        {
            FlowTest f4(f3);
            assert(numHandleCreated == 2);
            assert(numBodyCreated == 1); 
        } 
        
        assert(numHandleDeleted == 1);
        assert(numBodyDeleted == 0);
    } 

    assert(numHandleDeleted == 2);
    assert(numBodyDeleted == 1);

    #ifdef DEBUGING
        numHandleCreated = 0; 
        numHandleDeleted = 0;
        numBodyCreated = 0; 
        numBodyDeleted = 0;
    #endif

    {
        FlowTest* p1 = new FlowTest("Ponteiro 1", nullptr, nullptr); 
        FlowTest* p2 = new FlowTest("Ponteiro 2", nullptr, nullptr); 

        assert(numHandleCreated == 2);
        assert(numBodyCreated == 2);

        *p1 = *p2;

        assert(numBodyDeleted == 1);
        assert(numHandleDeleted == 0); 

        delete p1; 
        assert(numHandleDeleted == 1);
        assert(numBodyDeleted == 1); 

        delete p2; 
        assert(numHandleDeleted == 2);
        assert(numBodyDeleted == 2); 
    }

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
    assert(handleBodyTest());
    return true;
}
