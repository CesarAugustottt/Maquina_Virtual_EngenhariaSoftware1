#include "unit_Model.h"
#include "../../src/ModelImpl.h"
#include <cassert>
#include <cmath>
#include<algorithm>
#include <iostream>


#ifdef DEBUGING
    extern int numHandleCreated;
    extern int numHandleDeleted;
    extern int numBodyCreated;
    extern int numBodyDeleted;
#endif

/*!
 * @brief Class used exclusively to instantiate and test System (Body).
 */
class SystemTestBody : public Body {
public:
    std::string name;
    double value;

    void setName(std::string n) { this->name = n; }
    std::string getName() const { return this->name; }
    void setValue(double v) { this->value = v; }
    double getValue() const { return this->value; }
};

/*!
 * @brief Class used exclusively to instantiate and test System (Handle).
 */
class SystemTestHandle : public System, public Handle<SystemTestBody> {
public:
    SystemTestHandle(std::string n = "", double v = 0.0) {
        pImpl_->setName(n);
        pImpl_->setValue(v);
    }
    virtual ~SystemTestHandle() {}
    std::string getName() const override { return pImpl_->getName(); }
    void setName(std::string n) override { pImpl_->setName(n); }
    double getValue() const override { return pImpl_->getValue(); }
    void setValue(double v) override { pImpl_->setValue(v); }
    friend class Unit_Model;
};

/*!
 * @brief Class used exclusively to instantiate and test Flow (Body).
 */
class FlowTestBody : public Body {
public:
    std::string name;
    System *source, *target;
    std::string getName() const { return this->name; }
    void setName(std::string n) { this->name = n; }
    System* getSource() const { return this->source; }
    void setSource(System* s) { this->source = s; }
    System* getTarget() const { return this->target; }
    void setTarget(System* t) { this->target = t; }
    double execute() { return source ? 0.01 * source->getValue() : 0.0; }
};

/*!
 * @brief Class used exclusively to instantiate and test Flow (Handle).
 */
class FlowTestHandle : public Flow, public Handle<FlowTestBody> {
public:
    FlowTestHandle(std::string n="", System* s=nullptr, System* t=nullptr) {
        this->setName(n);
        this->setSource(s);
        this->setTarget(t);
    }
    virtual ~FlowTestHandle() {}
    std::string getName() const override { return pImpl_->getName(); }
    void setName(std::string n) override { pImpl_->setName(n); }
    System* getSource() const override { return pImpl_->getSource(); }
    void setSource(System* s) override { pImpl_->setSource(s); }
    System* getTarget() const override { return pImpl_->getTarget(); }
    void setTarget(System* t) override { pImpl_->setTarget(t); }
    double execute() override { return pImpl_->execute(); }
    friend class Unit_Model;
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
    System* s1 = new SystemTestHandle();
    
    m->pImpl_->systems.push_back(s1);
    
    delete m;
    
    return true;
}

bool Unit_Model::execute(void) {
    ModelHandle m;
    SystemTestHandle* s1 = new SystemTestHandle("Origem", 100.0);
    SystemTestHandle* s2 = new SystemTestHandle("Destino", 0.0);

    Flow* f = new FlowTestHandle("Fluxo", s1, s2);

    //adicionar sistemas
    m.pImpl_->systems.push_back(s1);
    m.pImpl_->systems.push_back(s2);

    //adicionar fluxos
    m.pImpl_->flows.push_back(f);

    m.execute(0, 2, 1);

    assert(m.pImpl_->time == 2.0);

    assert(s1->pImpl_->value == 98.01);
    assert(s2->pImpl_->value == 1.99);

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
    System* s1 = new SystemTestHandle("S1", 10.0);

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
    Flow* f = new FlowTestHandle("F1", nullptr, nullptr);

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
    System* s1 = new SystemTestHandle("S1", 10.0);

    m.pImpl_->systems.push_back(s1);

    m.remove(s1);
    assert(m.pImpl_->systems.size() == 0);

    //liberar memoria
    delete s1;
    return true;
}

bool Unit_Model::removeFlow(void) {
    ModelHandle m;
    Flow* f = new FlowTestHandle("F1", nullptr, nullptr);

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
    System* s = new SystemTestHandle("S1", 0.0);

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
    SystemTestHandle* sReal = static_cast<SystemTestHandle*>(s);
    assert(sReal->pImpl_->name == "Sistema");
    assert(sReal->pImpl_->value == 10.0);
    
    //testar se system ja foi inserido no vetor
    assert(m->pImpl_->systems.size() == 1);
    assert(m->pImpl_->systems[0] == s);

    delete m;
    return true;
}

bool Unit_Model::createFlow(void) {
    ModelHandle* m = new ModelHandle();
    Flow* f = m->createFlow<FlowTestHandle>("Fluxo", nullptr, nullptr);
    
    assert(f != nullptr);
    FlowTestHandle* fTest = static_cast<FlowTestHandle*>(f);
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
    System* s = new SystemTestHandle();
    
    m->pImpl_->systems.push_back(s); //adiciona system
    
    //Deleta
    m->deleteSystem(s);
    assert(m->pImpl_->systems.size() == 0);

    delete m;
    return true;
}

bool Unit_Model::deleteFlow(void) {
    ModelHandle* m = new ModelHandle();
    Flow* f = new FlowTestHandle();
    
    m->pImpl_->flows.push_back(f); //adicionar flow ao modelo
    
    //Deletar
    m->deleteFlow(f);
    assert(m->pImpl_->flows.size() == 0);

    delete m;
    return true;
}

bool Unit_Model::handleBodyTest(void) {
    //resetar os contadores antes de começar o teste
    #ifdef DEBUGING
        numHandleCreated = 0;
        numHandleDeleted = 0;
        numBodyCreated = 0;
        numBodyDeleted = 0;
    #endif

    //teste 1:
    {
        ModelHandle m1("Sistema 1", 10.0);
        ModelHandle m2("Sistema 2", 20.0);

        //deve ter criado cada um 2 body e 2 handle
        assert(numHandleCreated == 2);
        assert(numBodyCreated == 2);
        assert(numHandleDeleted == 0);
        assert(numBodyDeleted == 0);

        //Atribuiçaõ, m1 aponta para m2
        m1 = m2; 

        // Como o pImpl_ antigo de m1 perdeu a referencia, ele é deletado
        assert(numBodyDeleted == 1); 
    } 
    // Saindo do bloco, m1 e m2 ssão destruidos

    assert(numHandleCreated == 2);
    assert(numHandleDeleted == 2);
    assert(numBodyCreated == 2);
    assert(numBodyDeleted == 2);

    //resetar os contadores
    #ifdef DEBUGING
        numHandleCreated = 0; 
        numHandleDeleted = 0;
        numBodyCreated = 0; 
        numBodyDeleted = 0;
    #endif

    //teste 2:
    {
        ModelHandle m3("Original", 50.0); // +1 handle e +1 body.
        
        {
            //construtor de copia ( +1 handle, 0 body)
            ModelHandle m4(m3);
            assert(numHandleCreated == 2);
            assert(numBodyCreated == 1); 
        } // m4 morre aqui, + 1 delete de handle
        
        assert(numHandleDeleted == 1);
        assert(numBodyDeleted == 0);
    } 
    // saindo m3 morre (+1 handle e +1 body deletado)

    assert(numHandleDeleted == 2);
    assert(numBodyDeleted == 1);

    //resetar os contadores
    #ifdef DEBUGING
        numHandleCreated = 0; 
        numHandleDeleted = 0;
        numBodyCreated = 0; 
        numBodyDeleted = 0;
    #endif

    //teste 3:
    {
        ModelHandle* m1 = new ModelHandle("Ponteiro 1", 100.0); // +1 handle e +1 body
        ModelHandle* m2 = new ModelHandle("Ponteiro 2", 200.0); // +1 handle e +1 body

        assert(numHandleCreated == 2);
        assert(numBodyCreated == 2);

        // Atribuição de ponteiros
        *m1 = *m2;

        // O conteúdo do handle de m1 agora aponta para o body de m2.
        // O body antigo de m1 foi morto
        assert(numBodyDeleted == 1);
        assert(numHandleDeleted == 0); // handle continua vivo

        // Deletar os ponteiros 
        delete m1; // m1 morre.
        assert(numHandleDeleted == 1);
        assert(numBodyDeleted == 1); // m1 do body já tinha morrido

        delete m2; // m2 morre
        assert(numHandleDeleted == 2);
        assert(numBodyDeleted == 2); // ambos os corpos foram destruidos
    }

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

    assert(handleBodyTest());
    
    return true;
}