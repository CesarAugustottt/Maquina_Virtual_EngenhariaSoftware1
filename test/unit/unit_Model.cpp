#include "unit_Model.h"
#include "../../src/ModelImpl.h"
#include <cassert>
#include <string>
#include <cmath>
#include<algorithm>
#include <iostream>

/*!
 * @brief Class used exclusively to instantiate and test System.
 */
class SystemTest : public System{
public:
    std :: string name;
    double value;  
    SystemTest() {
        this->name = "";
        this->value = 0.0;
    }
    SystemTest(std::string name, double value) : name(name), value(value){}
    virtual ~SystemTest(){}
    virtual std::string getName() const override{ return this->name; }
    virtual void setName(std::string n) override{ this->name = n; }
    virtual double getValue() const override{ return this->value; }
    virtual void setValue(double v) override{ this->value = v; }
};

/*!
 * @brief Class used exclusively to instantiate and test Flow.
 */
class FlowTest2 : public Flow {
public:
    std::string name;
    System* source;
    System* target;

    FlowTest2(){
        this->name= "";
        this->source= nullptr;
        this->target= nullptr;
    }
    FlowTest2(std::string name, System* source, System* target) 
        : name(name), source(source), target(target) {}
    virtual ~FlowTest2() {}
    virtual std::string getName() const override{ return this->name; }
    virtual void setName(std::string n) override{ this->name = n; }
    virtual System* getSource() const override{ return this->source; }
    virtual void setSource(System* s) override{ this->source = s; }
    virtual System* getTarget() const override{ return this->target; }
    virtual void setTarget(System* t) override{ this->target = t; }
    virtual double execute() override { 
        if (this->getSource() != nullptr) { // se tiver sistema de origem
            return 0.01 * this->getSource()->getValue(); 
        }
        return 0.0;
    }
};


bool Unit_Model::defaultConstructor(void) {
    ModelImpl m;
    assert(m.name == "");
    assert(m.time == 0.0);
    assert(m.systems.size() == 0);
    assert(m.flows.size() == 0);
    return true;
}

bool Unit_Model::constructor(void) {
    ModelImpl m("Modelo", 10.0);
    assert(m.name == "Modelo");
    assert(m.time == 10.0);
    return true;
}

bool Unit_Model::destructor(void){
    ModelImpl* m = new ModelImpl();
    System* s1 = new SystemTest();
    
    m->systems.push_back(s1);
    
    delete m;
    
    return true;
}

bool Unit_Model::execute(void) {
    ModelImpl m;
    SystemTest* s1 = new SystemTest("Origem", 100.0);
    SystemTest* s2 = new SystemTest("Destino", 0.0);

    Flow* f = new FlowTest2("Fluxo", s1, s2);

    //adicionar sistemas
    m.systems.push_back(s1);
    m.systems.push_back(s2);

    //adicionar fluxos
    m.flows.push_back(f);

    m.execute(0, 2, 1);

    assert(m.time == 2.0);

    assert(s1->value == 98.01);
    assert(s2->value == 1.99);

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

bool Unit_Model::addModel(void){
    //tamanho inicial do vetor models
    size_t tamanhoInicial = Model::models.size();
    Model* m = new ModelImpl();
    Model::addModel(m); //adicionar model ao vetor
    assert(Model::models.size() == tamanhoInicial + 1);
    
    //remover model
    auto it = std::find(Model::models.begin(), Model::models.end(), m);
    if (it != Model::models.end()) {
        Model::models.erase(it);
    }
     
    delete m;
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

bool Unit_Model::createModel(void) {
    Model* m = Model::createModel("Modelo", 10.0);
    assert(m != nullptr);

    ModelImpl* mImpl = static_cast<ModelImpl*>(m); //cast
    assert(mImpl->name == "Modelo");
    assert(mImpl->time == 10.0);
    
    //remover model
    auto it = std::find(Model::models.begin(), Model::models.end(), m);
    if (it != Model::models.end()) {
        Model::models.erase(it);
    }
     
    delete m;
    
    return true;
}

bool Unit_Model::createSystem(void) {
    ModelImpl* m = new ModelImpl();
    System* s = m->createSystem("Sistema", 10.0);
    
    assert(s != nullptr);
    SystemTest * sTest = static_cast<SystemTest*>(s); //cast
    assert(sTest->name == "Sistema");
    assert(sTest->value == 10.0);
    
    //testar se system ja foi inserido no vetor
    assert(m->systems.size() == 1);
    assert(m->systems[0] == s);

    delete m;
    return true;
}

bool Unit_Model::createFlow(void) {
    ModelImpl* m = new ModelImpl();
    Flow* f = m->createFlow<FlowTest2>("Fluxo", nullptr, nullptr);
    
    assert(f != nullptr);
    FlowTest2* fTest = static_cast<FlowTest2*>(f); //cast
    assert(fTest->name == "Fluxo");
    
    //testar se flow foi inserido no vetor
    assert(m->flows.size() == 1);
    assert(m->flows[0] == f);

    delete m;
    return true;
}

bool Unit_Model::deleteModel(void) {
    Model* m = new ModelImpl();
    Model::deleteModel(m);
    return true;
}

bool Unit_Model::deleteSystem(void) {
    ModelImpl* m = new ModelImpl();
    System* s = new SystemTest();
    
    m->systems.push_back(s); //adiciona system
    
    //Deleta
    m->deleteSystem(s);
    assert(m->systems.size() == 0);

    delete m;
    return true;
}

bool Unit_Model::deleteFlow(void) {
    ModelImpl* m = new ModelImpl();
    Flow* f = new FlowTest2();
    
    m->flows.push_back(f); //adicionar flow ao modelo
    
    //Deletar
    m->deleteFlow(f);
    assert(m->flows.size() == 0);

    delete m;
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
    assert(addModel());
    assert(removeSystem());
    assert(removeFlow());
    assert(getName());
    assert(setName());
    assert(getTime());
    assert(setTime());
    assert(copyConstructor());
    assert(assignmentOperator());

    //testes metodos da fabrica
    assert(createModel());
    assert(createSystem());
    assert(createFlow());
    assert(deleteModel());
    assert(deleteSystem());
    assert(deleteFlow());
    
    return true;
}