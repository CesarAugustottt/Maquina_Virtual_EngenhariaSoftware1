#include "CompositeSystem.h"
#include <algorithm>


//  CompositeSystemBody

CompositeSystemBody::CompositeSystemBody()
    : name("") {}

CompositeSystemBody::~CompositeSystemBody() {
    systemChildrens.clear();
}

void CompositeSystemBody::setName(std::string n) {
    this->name = n;
}

std::string CompositeSystemBody::getName() const {
    return this->name;
}


double CompositeSystemBody::getValue() const {
    double total = 0.0;
    for (System* sys : systemChildrens) {
        total += sys->getValue(); //soma os valores de todos os folhos
    }
    return total;
}

void CompositeSystemBody::setValue(double value) {
    //this->value = value;
    //não pode mudar valor
}

void CompositeSystemBody::add(System* systemChildren) {
    if (!systemChildren) 
        return;
    auto it = std::find(systemChildrens.begin(), systemChildrens.end(), systemChildren);
    if (it == systemChildrens.end()) {
        systemChildrens.push_back(systemChildren);
    }
    //assim q adicionar um sistema filho atualizar valor total
    double total = 0.0;
    for (System* sys : systemChildrens) {
        total += sys->getValue(); //soma os valores de todos os folhos
    }
    this->value = total;

}

void CompositeSystemBody::remove(System* systemChildren) {
    auto it = std::find(systemChildrens.begin(), systemChildrens.end(), systemChildren);
    if (it != systemChildrens.end()) {
        systemChildrens.erase(it);
    }

    //assim q remover um sistema filho atualizar valor total
    double total = 0.0;
    for (System* sys : systemChildrens) {
        total += sys->getValue(); //soma os valores de todos os folhos
    }
    this->value = total;
}




//  CompositeSystemHandle

CompositeSystemHandle::CompositeSystemHandle() {}

CompositeSystemHandle::CompositeSystemHandle(std::string name) {
    pImpl_->setName(name);
}

CompositeSystemHandle::~CompositeSystemHandle() {}

void CompositeSystemHandle::setName(std::string name) {
    pImpl_->setName(name);
}

std::string CompositeSystemHandle::getName() const {
    return pImpl_->getName();
}

void CompositeSystemHandle::setValue(double value) {
    pImpl_->setValue(value);
}

double CompositeSystemHandle::getValue() const {
    return pImpl_->getValue();
}

void CompositeSystemHandle::add(System* systemChildren) {
    pImpl_->add(systemChildren);
}

void CompositeSystemHandle::remove(System* systemChildren) {
    pImpl_->remove(systemChildren);
}


