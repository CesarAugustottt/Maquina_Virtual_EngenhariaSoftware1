#include "unit_Model.h"
#include "../../src/ModelImpl.h"
#include "../../src/SystemImpl.h"
#include "../../src/FlowImpl.h"
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
    ModelHandle m;
    assert(m.pImpl_->name == "");
    assert(m.pImpl_->time == 0.0);
    assert(m.pImpl_->systems.size() == 0);
    assert(m.pImpl_->flows.size() == 0);
    return true;
}

bool Unit_Model::constructor(void) {
    ModelHandle m("Modelo", 10.0);
    assert(m.pImpl_->name == "Modelo");
    assert(m.pImpl_->time == 10.0);
    return true;
}

bool Unit_Model::destructor(void){
    ModelHandle* m = new ModelHandle();
    System* s1 = new SystemTest();
    
    m->pImpl_->systems.push_back(s1);
    
    delete m;
    
    return true;
}

bool Unit_Model::execute(void) {
    ModelHandle m;
    SystemTest* s1 = new SystemTest("Origem", 100.0);
    SystemTest* s2 = new SystemTest("Destino", 0.0);

    Flow* f = new FlowTest2("Fluxo", s1, s2);

    //adicionar sistemas
    m.pImpl_->systems.push_back(s1);
     m.pImpl_->systems.push_back(s2);

    //adicionar fluxos
    m.pImpl_->flows.push_back(f);

    m.execute(0, 2, 1);

    assert(m.pImpl_->time == 2.0);

    assert(s1->value == 98.01);
    assert(s2->value == 1.99);

    //liberar memoria
    m.pImpl_->systems.clear();
    m.pImpl_->flows.clear();
    delete f;
    delete s1;
    delete s2;

    return true;
}

bool Unit_Model::increment(void){
    ModelHandle m;
    m.pImpl_->time = 5.0;
    m.incrementTime(3);
    assert(m.pImpl_->time == 8.0);
    return true;
}

bool Unit_Model::addSystem(void) {
    ModelHandle m;
    System* s1 = new SystemTest("S1", 10.0);

    //adicionar sistema 
    m.add(s1);

    assert(m.pImpl_->systems.size() == 1);
    assert(m.pImpl_->systems[0] == s1);

    //liberar sistema
    m.pImpl_->systems.clear();
    delete s1;
    return true;
}

bool Unit_Model::addFlow(void) {
    ModelHandle m;
    Flow* f = new FlowTest2("F1", nullptr, nullptr);

    //adicionar fluxo
    m.add(f);
    assert(m.pImpl_->flows.size() == 1);
    assert(m.pImpl_->flows[0] == f);

    //liberar memoria
    m.pImpl_->flows.clear();
    delete f;
    return true;
}

bool Unit_Model::addModel(void){
    //tamanho inicial do vetor models
    size_t tamanhoInicial = Model::models.size();
    ModelHandle* m = new ModelHandle();

    Model::addModel(m); //adicionar model ao vetor
    assert(Model::models.size() == tamanhoInicial + 1);
     
    delete m;
    return true;
}

bool Unit_Model::removeSystem(void) {
    ModelHandle m;
    System* s1 = new SystemTest("S1", 10.0);

    m.pImpl_->systems.push_back(s1);

    m.remove(s1);
    assert(m.pImpl_->systems.size() == 0);

    //liberar memoria
    delete s1;
    return true;
}

bool Unit_Model::removeFlow(void) {
    ModelHandle m;
    Flow* f = new FlowTest2("F1", nullptr, nullptr);

    m.pImpl_->flows.push_back(f);

    m.remove(f);
    assert(m.pImpl_->flows.size() == 0);

    //liberar memoria
    delete f;
    return true;
}

bool Unit_Model::getName(void) {
    ModelHandle m;
    m.pImpl_->name = "Modelo";
    assert(m.getName() == "Modelo");
    return true;
}

bool Unit_Model::setName(void) {
    ModelHandle m;
    m.setName("Modelo");
    assert(m.pImpl_->name == "Modelo");
    return true;
}

bool Unit_Model::getTime(void) {
    ModelHandle m;
    m.pImpl_->time = 20.0;
    assert(m.getTime() == 20.0);
    return true;
}

bool Unit_Model::setTime(void) {
    ModelHandle m;
    m.setTime(20.5);
    assert(m.pImpl_->time == 20.5);
    return true;
}

bool Unit_Model::copyConstructor(void) {
    ModelHandle original;
    original.pImpl_->name = "Original";
    original.pImpl_->time = 10.0;
    System* s = new SystemTest("S1", 0.0);

    //adiciona sistema no modelo original
    original.pImpl_->systems.push_back(s);

    // Invoca o construtor de cópia
    ModelHandle copia(original);
    assert(copia.pImpl_->name == "Original");
    assert(copia.pImpl_->time == 10.0);
    assert(copia.pImpl_->systems.size() == 1); // verific se os vetores foram copiados
    assert(copia.pImpl_->systems[0] == s);

    //liberar memoria
    original.pImpl_->systems.clear();
    delete s;
    return true;
}

bool Unit_Model::assignmentOperator(void) {
    ModelHandle original;
    original.pImpl_->name = "Original";
    original.pImpl_->time = 10.0;
    
    ModelHandle destino;
    destino.pImpl_->name = "Destino";
    destino.pImpl_->time = 0.0;

    destino = original;
    assert(destino.pImpl_->name == "Original");
    assert(destino.pImpl_->time == 10.0);
    return true;
}

bool Unit_Model::createModel(void) {
    Model* m = Model::createModel("Modelo", 10.0);
    assert(m != nullptr);

    ModelHandle* m2 = static_cast<ModelHandle*>(m); //cast
    assert(m2->pImpl_->name == "Modelo");
    assert(m2->pImpl_->time == 10.0);
     
    delete m;
    
    return true;
}

bool Unit_Model::createSystem(void) {
    ModelHandle* m = new ModelHandle();
    System* s = m->createSystem("Sistema", 10.0);
    
    assert(s != nullptr);
    SystemHandle* sTest = static_cast<SystemHandle*>(s);
    assert(sTest->pImpl_->name == "Sistema");
    assert(sTest->pImpl_->value == 10.0);
    
    //testar se system ja foi inserido no vetor
    assert(m->pImpl_->systems.size() == 1);
    assert(m->pImpl_->systems[0] == s);

    delete m;
    return true;
}

bool Unit_Model::createFlow(void) {
    ModelHandle* m = new ModelHandle();
    Flow* f = m->createFlow<FlowTest2>("Fluxo", nullptr, nullptr);
    
    assert(f != nullptr);
    FlowHandle* fTest = static_cast<FlowHandle*>(f); //cast
    assert(fTest->pImpl_->name == "Fluxo");
    
    //testar se flow foi inserido no vetor
    assert(m->pImpl_->flows.size() == 1);
    assert(m->pImpl_->flows[0] == f);

    delete m;
    return true;
}

bool Unit_Model::deleteModel(void) {
    Model* m = new ModelHandle();
    Model::deleteModel(m);
    return true;
}

bool Unit_Model::deleteSystem(void) {
    ModelHandle* m = new ModelHandle();
    System* s = new SystemTest();
    
    m->pImpl_->systems.push_back(s); //adiciona system
    
    //Deleta
    m->deleteSystem(s);
    assert(m->pImpl_->systems.size() == 0);

    delete m;
    return true;
}

bool Unit_Model::deleteFlow(void) {
    ModelHandle* m = new ModelHandle();
    Flow* f = new FlowTest2();
    
    m->pImpl_->flows.push_back(f); //adicionar flow ao modelo
    
    //Deletar
    m->deleteFlow(f);
    assert(m->pImpl_->flows.size() == 0);

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