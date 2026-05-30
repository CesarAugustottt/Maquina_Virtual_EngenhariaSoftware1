#include "FlowImpl.h"

FlowImpl::FlowImpl(){
    this->name= "";
    this->source= nullptr;
    this->target= nullptr;
}

FlowImpl::FlowImpl(std::string name, System* source, System* target): name(name), 
    source(source), target(target){}

FlowImpl::~FlowImpl(){} //fica vazio, pois o flow aponta para sistemas, mas não pode excluir eles

//metodo execute é virtual puro.

void FlowImpl::setName(std::string name){
    this->name = name;
}
std::string FlowImpl::getName()const{
    return this->name;
}

void FlowImpl::setSource(System* source){
    this->source = source;
}
System* FlowImpl::getSource()const{
    return this->source;
}

void FlowImpl::setTarget(System* target){
    this->target= target;
}
System* FlowImpl::getTarget()const{
    return this->target;
}

//construtor de copia
FlowImpl::FlowImpl(const FlowImpl& flow){
    this->name = flow.name;
    this->source = flow.source;
    this->target = flow.target;
}

//Atribuição por =
FlowImpl& FlowImpl::operator=(const FlowImpl& flow){
    if(&flow == this){
        return *this; //são iguais
    }
    this->name = flow.name;
    this->source = flow.source;
    this->target = flow.target;
    return *this;
}