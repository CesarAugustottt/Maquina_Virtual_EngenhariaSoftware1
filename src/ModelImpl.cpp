#include "ModelImpl.h"
#include "SystemImpl.h"
#include <algorithm>

//atributo statico de model
std::vector<Model*> Model::models;

//Metodo estatico para adiconar modelo ao vetor
void Model::addModel(Model* model) {
    models.push_back(model);
}

ModelImpl::ModelImpl() {
    this->name = "";
    this->time = 0.0;
}

ModelImpl::ModelImpl(std::string name, double time) : name(name), time(time) {}

ModelImpl::~ModelImpl() {
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
    //deletar model no vetor!!
    for (auto it = Model::models.begin(); it != Model::models.end(); ++it) {
        if (*it == this) {
            Model::models.erase(it);
            break; // Sai do laço imediatamente após remover
        }
    }
}

void ModelImpl::execute(double start, double end, double increment) {
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

void ModelImpl::add(System* sys) {
    systems.push_back(sys);
}

void ModelImpl::add(Flow* flow) {
    flows.push_back(flow);
}

void ModelImpl::remove(System* sys) {
    //deve procurar o ponteiro sys no vetor
    auto it = std::find(systems.begin(), systems.end(), sys);
    //se ele for diferente do fim o ponteiro foi encontrado e deve remover
    if (it != systems.end()) {
        systems.erase(it); //remove  o sistema do vetor.
    }
}

void ModelImpl::remove(Flow* flow) {
    //deve procurar o ponteiro flow no vetor
    auto it = std::find(flows.begin(), flows.end(), flow);
    //se ele for diferente do fim o ponteiro foi encontrado e deve remover
    //se for igual ao fim é uma posição inválida.
    if (it != flows.end()) {
        flows.erase(it); //remove o fluxo do vetor.
    }
}

void ModelImpl::setName(std::string name) {
    this->name = name;
}

std::string ModelImpl::getName() const {
    return this->name;
}

void ModelImpl::setTime(double time) {
    this->time = time;
}

double ModelImpl::getTime() const {
    return this->time;
}

void ModelImpl::incrementTime(double increment) {
    this->time += increment;
}

//construtor de copia
ModelImpl::ModelImpl(const ModelImpl& model) {
    this->name = model.name;
    this->time = model.time;
    this->systems = model.systems; //copia os ponteiros
    this->flows = model.flows;
}

//operador = de atribuição
ModelImpl& ModelImpl::operator=(const ModelImpl& model) {
    if (&model != this) {
        this->name = model.name;
        this->time = model.time;
        this->systems = model.systems;
        this->flows = model.flows;
    }
    return *this; //retorna o modelo
}

//IMPLEMENTAÇÃO metodos da fabrica
//criar Model
Model* Model::createModel(std::string name, double time) {
    Model* m = new ModelImpl(name, time);
    Model::addModel(m);
    return m;
}

//Criar system
System* ModelImpl:: createSystem(std::string name, double value){
    //instancia
    System* sys = new SystemImpl(name, value);
    //adiciona systema ao modelo
    this->add(sys);
    return sys;
}

//create flow ja implementadp pois é metodo template

//metodos delete
void Model::deleteModel(Model* model){
    if(!model){
        return;
    }
    delete model;
}

void ModelImpl::deleteSystem(System* sys) {
    if (!sys) return;
    this->remove(sys); // Tira do vetor
    delete sys;        // Apagar
}

void ModelImpl::deleteFlow(Flow* flow) {
    if (!flow) return;
    this->remove(flow); // Tira do vetor
    delete flow;        // Apagar
}