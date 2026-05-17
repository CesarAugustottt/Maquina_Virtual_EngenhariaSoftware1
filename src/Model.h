#ifndef MODEL_H
#define MODEL_H

#include"System.h"
#include"Flow.h"
#include<vector>
#include<string>

class Model{
    private:
        std::string name;
        double time;
        std::vector <System*> systems;
        std::vector <Flow*> flows;
    public:
        //construtor
        Model();
        Model(std::string name, double time);
        //destrutor
        virtual ~Model();

        //metodo para rodar a simulação, o mais importante
        void execute (double start, double final, double increment);
        //Adicionar elemento ao modelo
        void add(System* sys);
        void add(Flow* flow);
        //Remover elemento do modelo
        void remove(System* sys);
        void remove(Flow* flow);
        //gettrs e setters
        void setName (std::string name);
        std::string getName() const;
        void setTime(double time);
        double getTime()const;
        //mettodo para incrementaro tempo
        void incrementTime (double increment);
        
        //construtor de copia (forma canonica)
        Model(const Model& model);
        //operador igual de atribuição (forma canonica)
        Model& operator=(const Model& model);

};
#endif