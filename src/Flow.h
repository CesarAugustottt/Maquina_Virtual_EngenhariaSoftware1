#ifndef FLOW_H
#define FLOW_H
#include "System.h"
#include <string>

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

#endif