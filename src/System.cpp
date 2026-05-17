#include "System.h"

System::System() {
    this->name = "";
    this->value = 0.0;
}

System::System(std::string name, double value) : name(name), value(value) {}

System::~System() {}

void System::setName(std::string name) {
    this->name = name;
}

std::string System::getName() const {
    return this->name;
}

void System::setValue(double value) {
    this->value = value;
}

double System::getValue() const {
    return this->value;
}

System::System(const System& sys) {
    this->name = sys.name;
    this->value = sys.value;
}

System& System::operator=(const System& sys) {
    if (&sys == this) {
        return *this;
    }
    this->name = sys.name;
    this->value = sys.value;
    return *this;
}
