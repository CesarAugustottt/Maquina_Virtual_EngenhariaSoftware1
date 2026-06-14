#include "ModelImpl.h"
#include "SystemImpl.h"
#include <algorithm>


//GLOBAL
//atributo statico de model
std::vector<Model*> Model::models;

//Metodo estatico para adiconar modelo ao vetor
void Model::addModel(Model* model) {
    models.push_back(model);
}

//FABRICA MODEL
//criar model
Model* Model::createModel(std::string name, double time) {
    Model* m = new ModelHandle(name, time);
    Model::addModel(m);
    return m;
}
//metodos model
void Model::deleteModel(Model* model){
    if(!model){
        return;
    }
    delete model;
}

//IMPLEMENTAÇÃO DO MODELBODY
ModelBody::ModelBody() {
    this->name = "";
    this->time = 0.0;
}

ModelBody::ModelBody(std::string name, double time) : name(name), time(time) {}

ModelBody::~ModelBody() {
    //deletar systems
    for (std::vector<System*>::iterator it = systems.begin(); it != systems.end(); ++it) {
        delete *it; //deleta a memoria alocada dinamicamente
    }
    //deletar flows
    for (std::vector<Flow*>::iterator it = flows.begin(); it != flows.end(); ++it) {
        delete *it;
    }
    //limpar os apenas os vetores
    systems.clear();
    flows.clear();
}

void ModelBody::execute(double start, double end, double increment) {
    this->time = start;
    while (this->time < end) {
        std::vector<double> valueFlow; //vetor com os valores de cada fluxo
        //calcular a equação de cada fluxo
        for (auto f : flows) {
            valueFlow.push_back(f->execute());
        }
        //atualizar os sistemas com valores novos
        for (size_t i = 0; i < flows.size(); i++) {
            System* source = flows[i]->getSource();
            System* target = flows[i]->getTarget();
            //realizar o fluxo
            if (source) { //diminui o valor da origem
                source->setValue(source->getValue() - valueFlow[i]);
            }
            if (target) { //aumenta valor do destino
                target->setValue(target->getValue() + valueFlow[i]);
            }
        }
        //incrementar o tempo (time)
        this->incrementTime(increment);
    }
}

void ModelBody::add(System* sys) {
    systems.push_back(sys);
}

void ModelBody::add(Flow* flow) {
    flows.push_back(flow);
}

void ModelBody::remove(System* sys) {
    //deve procurar o ponteiro sys no vetor
    auto it = std::find(systems.begin(), systems.end(), sys);
    //se ele for diferente do fim o ponteiro foi encontrado e deve remover
    if (it != systems.end()) {
        systems.erase(it); //remove  o sistema do vetor.
    }
}

void ModelBody::remove(Flow* flow) {
    //deve procurar o ponteiro flow no vetor
    auto it = std::find(flows.begin(), flows.end(), flow);
    //se ele for diferente do fim o ponteiro foi encontrado e deve remover
    //se for igual ao fim é uma posição inválida.
    if (it != flows.end()) {
        flows.erase(it); //remove o fluxo do vetor.
    }
}

void ModelBody::setName(std::string name) {
    this->name = name;
}

std::string ModelBody::getName() const {
    return this->name;
}

void ModelBody::setTime(double time) {
    this->time = time;
}

double ModelBody::getTime() const {
    return this->time;
}

void ModelBody::incrementTime(double increment) {
    this->time += increment;
}


//Criar system FABRICA SYSTEM
System* ModelBody:: createSystem(std::string name, double value){
    //instancia
    System* sys = new SystemHandle(name, value);
    //adiciona systema ao modelo
    this->add(sys);
    return sys;
}

void ModelBody::deleteSystem(System* sys) {
    if (!sys) return;
    this->remove(sys); // Tira do vetor
    delete sys;        // Apagar
}

void ModelBody::deleteFlow(Flow* flow) {
    if (!flow) return;
    this->remove(flow); 
    delete flow;       
}

//IMPLEMENTAÇÃO DO MODELHANDLE

ModelHandle::ModelHandle() : Handle<ModelBody>() {}

ModelHandle::ModelHandle(std::string name, double time) {
    pImpl_->detach();
    pImpl_ = new ModelBody(name, time);
    pImpl_->attach();
}

ModelHandle::~ModelHandle() {
    for (auto it = Model::models.begin(); it != Model::models.end(); ++it) {
        if (*it == this) {
            Model::models.erase(it);
            break; 
        }
    }
    //destrutor de modelBody é chamado 
}

void ModelHandle::execute(double start, double end, double increment) {
    pImpl_->execute(start, end, increment);
}

void ModelHandle::add(System* sys) {
    pImpl_->add(sys);
}

void ModelHandle::add(Flow* flow) {
    pImpl_->add(flow);
}

void ModelHandle::remove(System* sys) {
    pImpl_->remove(sys);
}

void ModelHandle::remove(Flow* flow) {
    pImpl_->remove(flow);
}

void ModelHandle::setName(std::string name) {
    pImpl_->setName(name); 
}

std::string ModelHandle::getName() const {
    return pImpl_->getName();;
}

void ModelHandle::setTime(double time) {
    pImpl_->setTime(time);
}

double ModelHandle::getTime() const {
    return pImpl_->getTime();
}

void ModelHandle::incrementTime(double increment) {
    pImpl_->incrementTime(increment);
}


//IMPLEMENTAÇÃO metodos da fabrica

//Criar system
System* ModelHandle:: createSystem(std::string name, double value){
    return pImpl_->createSystem(name, value);
}

//metodos delete

void ModelHandle::deleteSystem(System* sys) {
    pImpl_->deleteSystem(sys);
}

void ModelHandle::deleteFlow(Flow* flow) {
    pImpl_->deleteFlow(flow);
}