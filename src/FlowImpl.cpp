#include "FlowImpl.h"

// FlowBody

FlowBody::FlowBody(){
    this->name= "";
    this->source= nullptr;
    this->target= nullptr;
}

FlowBody::FlowBody(std::string name, System* source, System* target): name(name), 
    source(source), target(target){}

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

// FlowHandle

FlowHandle::FlowHandle() : Handle<FlowBody>() {}

FlowHandle::FlowHandle(std::string name, System* source, System* target) : Handle<FlowBody>() {
    FlowBody* newBody = new FlowBody(name, source, target);
    pImpl_->detach();
    pImpl_ = newBody;
    pImpl_->attach();
}

FlowHandle::~FlowHandle(){} //fica vazio, pois o flow aponta para sistemas, mas não pode excluir eles

//metodo execute é virtual puro.

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
