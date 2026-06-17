#include "FlowImpl.h"

FlowBody::FlowBody(){
    this->name= "";
    this->source= nullptr;
    this->target= nullptr;
}

FlowBody::~FlowBody(){} //fica vazio, pois o flow aponta para sistemas, mas não pode excluir eles

void FlowBody::setName(std::string name){
    this->name = name;
}
std::string FlowBody::getName()const{
    return this->name;
}

void FlowBody::setSource(System* source){
    this->source = source;
}
System* FlowBody::getSource()const{
    return this->source;
}

void FlowBody::setTarget(System* target){
    this->target= target;
}
System* FlowBody::getTarget()const{
    return this->target;
}

// Implementação de FlowHandle
FlowHandle::FlowHandle(){}

FlowHandle::FlowHandle(std::string name, System* source, System* target) {
    pImpl_->setName(name);
    pImpl_->setSource(source);
    pImpl_->setTarget(target);
}

FlowHandle::~FlowHandle(){}

void FlowHandle::setName(std::string name){
    pImpl_->setName(name);
}
std::string FlowHandle::getName()const{
    return pImpl_->getName();
}

void FlowHandle::setSource(System* source){
    pImpl_->setSource(source);
}

System* FlowHandle::getSource()const{
    return pImpl_->getSource();
}

void FlowHandle::setTarget(System* target){
    pImpl_->setTarget(target);
}
System* FlowHandle::getTarget()const{
    return pImpl_->getTarget();
}
