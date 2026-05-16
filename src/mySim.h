#ifndef MYSIM_H
#define MYSIM_H

#include <vector> 
#include <string>

//Esqueleto
//Classe System
class System{
    private:
        std::string name;
        double value;
    public:
        //construtor
        System();
        System(std::string name, double value);
        virtual ~System();
        //setters e gettres
        void setName(std::string name);
        std::string getName()const;
        void setValue(double value);
        double getValue()const;
        //construtor copia
        System(const System& sys);
        System& operator=(const System& sys);
};

//Class Flow
class Flow{
    private:
        std::string name;
        System* source;
        System* target;
    public:
        Flow();
        Flow(std::string name, System* source, System* target);
        virtual ~Flow();
        virtual double execute()=0; //metodo virtual puro
        //getters e setters
        void setName(std::string name);
        std::string getName()const;
        void setSource(System* source);
        System* getSource()const;
        void setTarget(System* target);
        System* getTarget()const;
        //construtor copia
        Flow(const Flow& flow);
        //atribuição pelo operador =
        Flow& operator=(const Flow& flow);
};

//Class ExponentialFlow
class ExponentialFlow: public Flow{
    public:
        ExponentialFlow(std::string name, System* source, System* target);
        virtual ~ExponentialFlow();
        double execute() override;
};

//Class LogicFlow
class LogisticFlow: public Flow{
    public:
        LogisticFlow();
        LogisticFlow(std::string name, System* source, System* target);
        virtual ~LogisticFlow();
        double execute() override;
        LogisticFlow(const LogisticFlow& flow);
        LogisticFlow& operator=(const LogisticFlow& flow);
};

//Class ComplexFlow
class ComplexFlow: public Flow{
    public:
        ComplexFlow(std::string name, System* source, System* target);
        virtual ~ComplexFlow();
        double execute() override;
};

//Classe MOdel
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