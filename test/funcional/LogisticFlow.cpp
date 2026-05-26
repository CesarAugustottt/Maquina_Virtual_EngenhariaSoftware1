#include"LogisticFlow.h"

LogisticFlow::LogisticFlow():Flow(){}

LogisticFlow::LogisticFlow(std::string name, System* source, System* target)
    : Flow(name, source, target){}

LogisticFlow::~LogisticFlow(){} //devido ao virtual da classe mae, o ~Flow sera chamdo em seguida

double LogisticFlow::execute(){
    if(this->getTarget()==nullptr){ //se não tiver sitesma de destino
        return 0.0;
    }
    double valueTarget = getTarget()->getValue();
    return 0.01 * valueTarget * (1 - valueTarget/70);
}
//constrtor de copia
LogisticFlow::LogisticFlow(const LogisticFlow& flow)
    : Flow(flow){} //chamar o contrutor de copia da base
//atribuição por =
LogisticFlow& LogisticFlow::operator=(const LogisticFlow& flow){
    if (&flow != this){ //se for diferente, faz a atribuição
        Flow::operator=(flow); //chama o operador = da base para a atribuição
    }
    return *this; //retorna o conteúdo
}