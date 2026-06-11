#include "ComplexFlow.h"
#include "../../src/System.h"

// Invoca o construtor padrao da classe base
ComplexFlow::ComplexFlow(){
    this->name= "";
    this->source= nullptr;
    this->target= nullptr;
}

// Repassa os parametros para o construtor da classe base
ComplexFlow::ComplexFlow(std::string name, System* source, System* target) 
    : name(name), source(source), target(target){}

ComplexFlow::~ComplexFlow() {} // Vazio devido ao virtual da classe mae

void ComplexFlow::setName(std::string name){
    this->name = name;
}
std::string ComplexFlow::getName()const{
    return this->name;
}

void ComplexFlow::setSource(System* source){
    this->source = source;
}
System* ComplexFlow::getSource()const{
    return this->source;
}

void ComplexFlow::setTarget(System* target){
    this->target= target;
}
System* ComplexFlow::getTarget()const{
    return this->target;
}

// Implementacao do calculo
double ComplexFlow::execute() {
    if (this->getSource() != nullptr) { // se tiver sistema de origem
        return 0.01 * this->getSource()->getValue(); 
    }
    return 0.0;
}

// Invoca o construtor de copia da classe base
ComplexFlow::ComplexFlow(const ComplexFlow& flow){
    this->name = flow.name;
    this->source = flow.source;
    this->target = flow.target;
}

// Atribuicao por =
ComplexFlow& ComplexFlow::operator=(const ComplexFlow& flow) {
    if(&flow == this){
        return *this; //são iguais
    }
    this->name = flow.name;
    this->source = flow.source;
    this->target = flow.target;
    return *this;
}
