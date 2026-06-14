#include "SystemImpl.h"

SystemBody::SystemBody() {
    this->name = "";
    this->value = 0.0;
}

SystemBody::SystemBody(std::string name, double value) : name(name), value(value) {}

SystemBody::~SystemBody() {}

void SystemBody::setName(std::string name) {
    this->name = name;
}

std::string SystemBody::getName() const {
    return this->name;
}

void SystemBody::setValue(double value) {
    this->value = value;
}

double SystemBody::getValue() const {
    return this->value;
}

//Implementação do SystemHandle
SystemHandle::SystemHandle() : Handle<SystemBody>() {}

SystemHandle::SystemHandle(std::string name, double value) {
        delete pImpl_; 
        pImpl_ = new SystemBody(name, value);
        pImpl_->attach();
    }

SystemHandle::~SystemHandle(){}

double SystemHandle::getValue() const { 
    return pImpl_->getValue(); 
}

std::string SystemHandle::getName() const{ 
    return pImpl_->getName(); 
}

void SystemHandle::setValue(double value){ 
    pImpl_->setValue(value); 
}

void SystemHandle::setName(std::string name){ 
    pImpl_->setName(name); 
}