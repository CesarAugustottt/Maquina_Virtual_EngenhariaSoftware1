#ifndef MODELIMPL_H
#define MODELIMPL_H

#include "Model.h"
#include "System.h"
#include "Flow.h"
#include "handleBody.h"

#include <vector>
#include <string>

/**
 * @class ModelBody
 * @brief This class represents the concrete implementation of a Model.
 */
class ModelBody : public Body {
protected:
    /*! This attribute contains a name for the model. */
    std::string name;
    /*! This attribute contains the current time of the simulation. */
    double time;
    /*! This vector contains pointers to all systems registered in the model. */
    std::vector<System*> systems;
    /*! This vector contains pointers to all flows registered in the model. */
    std::vector<Flow*> flows;
  

    void add(System* sys);
    void add(Flow* flow);
public:
    /**
     * @brief This is the default constructor for the Model Class.
     */
    ModelBody();

    /**
     * @brief This is the destructor for ModelBody.
     */
    virtual ~ModelBody();


    void execute(double start, double end, double increment);
    void remove(System* sys);
    void remove(Flow* flow);

    // metodos factory
    System* createSystem(std::string name = "", double value = 0.0);
    void deleteSystem(System* sys);
    void deleteFlow(Flow* flow);

    // Getters e Setters
    void setName(std::string name);
    std::string getName() const;
    void setTime(double time);
    double getTime() const ;
    void incrementTime(double increment);

    //Garante acesso a classe ModelHndle acessar metoodos protegidos
    friend class ModelHandle;
    //acesso aos testes unitarios
    friend class Unit_Model;
};

/**
 * @class ModelHandle
 * @brief This class represents the Handle of a Model.
 */
class ModelHandle : public Model, public Handle<ModelBody> {
protected:
    /**
     * @brief This is the default constructor for ModelHandle.
     */
    ModelHandle();

    /**
     * @brief This is the parameterized constructor for ModelHandle.
     * @param name The name of the Model.
     * @param time The initial time of the simulation.
     */
    ModelHandle(std::string name, double time);

    //metodos de adicionar protegidos
    void add(System* sys) override;
    void add(Flow* flow) override;
public:

    /**
     * @brief This is the destructor for ModelHandle.
     */
    virtual ~ModelHandle();

    void execute(double start, double end, double increment) override;
    void remove(System* sys) override ;
    void remove(Flow* flow) override;

    void setName(std::string name) override;
    std::string getName() const override;
    void setTime(double time) override;
    double getTime() const override;
    void incrementTime(double increment) override;

    System* createSystem(std::string name = "", double value = 0.0) override;
    void deleteSystem(System* sys) override;
    void deleteFlow(Flow* flow) override;

    //Permite que a classe de testes faça testes unitários
    friend class Unit_Model;
    friend class Model;
};

#endif
