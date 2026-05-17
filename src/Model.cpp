#include "Model.h"

Model::Model(){
    this->name = "";
    this->time = 0.0;
}

Model::Model(std::string name, double time): name(name), time(time){}

Model::~Model(){
    //limpar os apenas os vetires, sem destruir os sistemas e fluxos
    systems.clear();
    flows.clear();
}

void Model::execute(double start, double end, double increment){
    this->time = start;
    while(this->time < end){
        std::vector<double>valueFlow; //vetor com os valores de cada fluxo
        //calcular a equação de cada fluxo
        for (auto f : flows){
            valueFlow.push_back(f->execute());
        }

        //atualizar os sistemas com valores novos
        for(size_t i = 0; i< flows.size(); i++){
            System* source = flows[i]->getSource();
            System* target = flows[i]->getTarget();

            //realizar o fluxo
            if(source){ //diminui o valor da origem
                source->setValue(source->getValue() - valueFlow[i]);
            }
            if(target){//aumenta valor do destino
                target->setValue(target->getValue() + valueFlow[i]);
            }
        }
        //incrementar o tempo (time)
        this->incrementTime(increment);
    }
}

void Model::add(System* sys){
    systems.push_back(sys);
}

void Model::add(Flow* flow){
    flows.push_back(flow);
}

void Model::remove(System* sys){
    //deve procurar o ponteiro sys no vetor
    auto it = std::find(systems.begin(), systems.end(), sys);

    //se ele for diferente do fim o ponteiro foi encontrado e deve remover
    if(it != systems.end()){
        systems.erase(it); //remove  o sistema do vetor.
    }
}

void Model::remove(Flow* flow){
    //deve procurar o ponteiro flow no vetor
    auto it = std::find(flows.begin(), flows.end(), flow);

    //se ele for diferente do fim o ponteiro foi encontrado e deve remover
    //se for igual ao fim é uma posição inválida.
    if(it != flows.end()){
        flows.erase(it); //remove o fluxo do vetor.
    }
}

void Model::setName(std::string name){
    this->name = name;
}

std::string Model::getName()const{
    return this->name;
}

void Model::setTime(double time){
    this->time = time;
}

double Model::getTime()const{
    return this->time;
}

void Model::incrementTime(double increment){
    this->time += increment;
}

//construtor de copia
Model::Model (const Model& model){
    this->name = model.name;
    this->time = model.time;
    this->systems = model.systems; //copia os ponterios
    this->flows = model.flows;
}

//operador = de atribuição
Model& Model::operator=(const Model& model){
    if (&model != this){
        this->name = model.name;
        this->time = model.time;
        this->systems = model.systems;
        this->flows = model.flows;
    }
    return *this; //retorna o modelo
}
