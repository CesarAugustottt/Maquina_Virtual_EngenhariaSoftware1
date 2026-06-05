#include "unit_Model.h"
#include "../../src/ModelImpl.h"
#include <cassert>
#include <string>
#include <cmath>
#include <iostream>

/*!
 * @brief Class used exclusively to instantiate and test System.
 */
class SystemTest : public System{
private:
    std :: string name;
    double value;
public:
    SystemTest() {
        this->name = "";
        this->value = 0.0;
    }
    SystemTest(std::string name, double value) : name(name), value(value){}
    virtual ~SystemTest(){}

    virtual std::string getName() const override{
        return this->name;
    }
    virtual void setName(std::string n) override{
        this->name = n;
    }
    virtual double getValue() const override{
        return this->value;
    }
    virtual void setValue(double v) override{
        this->value = v;
    }

};

/*!
 * @brief Class used exclusively to instantiate and test Flow.
 */
class FlowTest2 : public Flow {
private:
    std::string name;
    System* source;
    System* target;
public:
    FlowTest2(){
        this->name= "";
        this->source= nullptr;
        this->target= nullptr;
    }

    FlowTest2(std::string name, System* source, System* target) 
        : name(name), source(source), target(target) {}
    virtual ~FlowTest2() {}
    virtual std::string getName() const override{
        return this->name;
    }
    virtual void setName(std::string n) override{
        this->name = n;
    }
    virtual System* getSource() const override{
        return this->source;
    }
    virtual void setSource(System* s) override{
        this->source = s;
    }
    virtual System* getTarget() const override{
        return this->target;
    }
    virtual void setTarget(System* t) override{
        this->target = t;
    }
    virtual double execute() override { 
        if (this->getSource() != nullptr) { // se tiver sistema de origem
            return 0.01 * this->getSource()->getValue(); 
        }
        return 0.0;
    }
};


bool Unit_Model::defaultConstructor(void) {
    ModelImpl m1;
    assert(m1.name == "");
    assert(m1.time == 0.0);
    assert(m1.systems.size() == 0);
    assert(m1.flows.size() == 0);

    return true;
}

bool Unit_Model::constructor(void) {
    ModelImpl m2("Modelo", 10.0);
    assert(m2.name == "Modelo");
    assert(m2.time == 10.0);

    return true;
}

bool Unit_Model::destructor(void){
    ModelImpl* m = new ModelImpl();
    System* s1 = new SystemTest();
    
    m->systems.push_back(s1);
    
    delete m; 
    delete s1; 
    
    return true;
}

bool Unit_Model::execute(void) {
    ModelImpl m;
    System* s1 = new SystemTest("Origem", 100.0);
    System* s2 = new SystemTest("Destino", 0.0);

    Flow* f = new FlowTest2("Fluxo", s1, s2);

    //adicionar sistemas
    m.systems.push_back(s1);
    m.systems.push_back(s2);

    //adicionar fluxos
    m.flows.push_back(f);

    m.execute(0, 2, 1);

    assert(m.time == 2.0);

    assert(round(fabs(s1->getValue() - 98.01) * 100) == 0);
    assert(round(fabs(s2->getValue() - 1.99) * 100) == 0);

    //liberar memoria
    m.systems.clear();
    m.flows.clear();
    delete f;
    delete s1;
    delete s2;

    return true;
}

bool Unit_Model::increment(void){
    ModelImpl m;
    m.time = 5.0;
    m.incrementTime(3);
    assert(m.time == 8.0);
    return true;
}

bool Unit_Model::addSystem(void) {
    ModelImpl m;
    System* s1 = new SystemTest("S1", 10.0);

    //adicionar sistema 
    m.add(s1);

    assert(m.systems.size() == 1);
    assert(m.systems[0] == s1);

    //liberar sistema
    m.systems.clear();
    delete s1;
    return true;
}

bool Unit_Model::addFlow(void) {
    ModelImpl m;
    Flow* f = new FlowTest2("F1", nullptr, nullptr);

    //adicionar fluxo
    m.add(f);
    assert(m.flows.size() == 1);
    assert(m.flows[0] == f);

    //liberar memoria
    m.flows.clear();
    delete f;
    return true;
}

bool Unit_Model::removeSystem(void) {
    ModelImpl m;
    System* s1 = new SystemTest("S1", 10.0);

    m.systems.push_back(s1);

    m.remove(s1);
    assert(m.systems.size() == 0);

    //liberar memoria
    delete s1;
    return true;
}

bool Unit_Model::removeFlow(void) {
    ModelImpl m;
    Flow* f = new FlowTest2("F1", nullptr, nullptr);

    m.flows.push_back(f);

    m.remove(f);
    assert(m.flows.size() == 0);

    //liberar memoria
    delete f;
    return true;
}

bool Unit_Model::getName(void) {
    ModelImpl m;
    m.name = "Modelo";
    assert(m.getName() == "Modelo");
    return true;
}

bool Unit_Model::setName(void) {
    ModelImpl m;
    m.setName("Modelo");
    assert(m.name == "Modelo");
    return true;
}

bool Unit_Model::getTime(void) {
    ModelImpl m;
    m.time = 20.0;
    assert(m.getTime() == 20.0);
    return true;
}

bool Unit_Model::setTime(void) {
    ModelImpl m;
    m.setTime(20.5);
    assert(m.time == 20.5);
    return true;
}

bool Unit_Model::copyConstructor(void) {
    ModelImpl original;
    original.name = "Original";
    original.time = 10.0;
    System* s = new SystemTest("S1", 0.0);

    //adiciona sistema no modelo original
    original.systems.push_back(s);

    // Invoca o construtor de cópia
    ModelImpl copia(original);
    assert(copia.name == "Original");
    assert(copia.time == 10.0);
    assert(copia.systems.size() == 1); // verific se os vetores foram copiados
    assert(copia.systems[0] == s);

    //liberar memoria
    original.systems.clear();
    copia.systems.clear();
    delete s;
    return true;
}

bool Unit_Model::assignmentOperator(void) {
    ModelImpl original;
    original.name = "Original";
    original.time = 10.0;
    
    ModelImpl destino;
    destino.name = "Destino";
    destino.time = 0.0;

    destino = original;
    assert(destino.name == "Original");
    assert(destino.time == 10.0);
    return true;
}

//Implementar testes dos metodos da fabrica
bool Unit_Model::createModel(void){
    Model* m = Model::createModel("Modelo Fabrica", 2.0);

    assert(m->getName() == "Modelo Fabrica");
    assert(m->getTime() == 2.0);

    delete m;
    return true;
}

bool Unit_Model::createSystem(void){
    ModelImpl m;

    System* s = m.createSystem("Sistema", 10.0);

    assert(m.systems.size() == 1);
    assert(m.systems[0] == s);
    assert(s->getName() == "Sistema");
    assert(s->getValue() == 10.0);

    m.systems.clear();
    delete s;
    return true;
}

bool Unit_Model::creteFlow(void){
    ModelImpl m;
    System* s1 = m.createSystem("s1", 10.0);
    System* s2 = m.createSystem("s2", 0.0);

    Flow* f = m.createFlow<FlowTest2>("Fluxo", s1, s2);

    assert(m.flows.size() == 1);
    assert(m.flows[0] == f);
    assert(f->getName() == "Fluxo");
    assert(f->getSource() == s1);
    assert(f->getTarget() == s2);

    m.systems.clear();
    m.flows.clear();
    delete s1;
    delete s2;
    delete f;

    return true;
}

bool Unit_Model::regressiveTest(void) {
    // Executa todasa as funções
    assert(defaultConstructor());
    assert(constructor());
    assert(destructor());
    assert(execute());
    assert(increment());
    assert(addSystem());
    assert(addFlow());
    assert(removeSystem());
    assert(removeFlow());
    assert(getName());
    assert(setName());
    assert(getTime());
    assert(setTime());
    assert(copyConstructor());
    assert(assignmentOperator());
    
    return true;
}