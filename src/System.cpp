#include "SystemImpl.h"

SystemImpl::SystemImpl() {
    this->name = "";
    this->value = 0.0;
}

SystemImpl::SystemImpl(std::string name, double value) : name(name), value(value) {}

SystemImpl::~SystemImpl() {}

void SystemImpl::setName(std::string name) {
    this->name = name;
}

std::string SystemImpl::getName() const {
    return this->name;
}

void SystemImpl::setValue(double value) {
    this->value = value;
}

double SystemImpl::getValue() const {
    return this->value;
}

SystemImpl::SystemImpl(const SystemImpl& sys) {
    this->name = sys.name;
    this->value = sys.value;
}

SystemImpl& SystemImpl::operator=(const SystemImpl& sys) {
    if (&sys == this) {
        return *this;
    }
    this->name = sys.name;
    this->value = sys.value;
    return *this;
}
