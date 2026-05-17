#include "Flow.h"

Flow::Flow(){
    this->name= "";
    this->source= nullptr;
    this->target= nullptr;
}

Flow::Flow(std::string name, System* source, System* target): name(name), 
    source(source), target(target){}

Flow::~Flow(){} //fica vazio, pois o flow aponta para sistemas, mas não pode excluir eles

//metodo execute é virtual puro.

void Flow::setName(std::string name){
    this->name = name;
}
std::string Flow::getName()const{
    return this->name;
}

void Flow::setSource(System* source){
    this->source = source;
}
System* Flow::getSource()const{
    return this->source;
}

void Flow::setTarget(System* target){
    this->target= target;
}
System* Flow::getTarget()const{
    return this->target;
}

//construtor de copia
Flow::Flow(const Flow& flow){
    this->name = flow.name;
    this->source = flow.source;
    this->target = flow.target;
}

//Atribuição por =
Flow& Flow::operator=(const Flow& flow){
    if(&flow == this){
        return *this; //são iguais
    }
    this->name = flow.name;
    this->source = flow.source;
    this->target = flow.target;
    return *this;
}