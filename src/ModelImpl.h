#ifndef MODELIMPL_H
#define MODELIMPL_H

#include "Model.h"
#include "System.h"
#include "Flow.h"

#include <vector>
#include <string>
#include <algorithm>

/*!
 * @brief This class represents the concrete implementation of a Model.
 */

class ModelImpl : public Model {
protected:
    /*! This attribute contains a name for the model. */
    std::string name;
    /*! This attribute contains the current time of the simulation. */
    double time;
    /*! This vector contains pointers to all systems registered in the model. */
    std::vector<System*> systems;
    /*! This vector contains pointers to all flows registered in the model. */
    std::vector<Flow*> flows;

    //Construtores protegidos, ninguem fora da fabrica pode usar os contrutores ou fazer copia.
    /*!
    * @brief This is the default constructor for the Model Class.
    */
    ModelImpl();
    /*!
    * @brief This is the parameterized constructor for the Model Class.
    * * @param name the name of the Model.
    * @param time the initial time of the simulation.
    */
    ModelImpl(std::string name, double time);

    /*!
    * @brief This is the copy constructor for the Model Class.
    * * @param model the model that is going to be cloned.
    */
    ModelImpl(const ModelImpl& model);
    /*!
    * @brief This is the overloaded assignment operator for the Model Class.
    * * @param model the model that is going to be cloned.
    * @return Model& - a reference to the updated Model Class object.
    */
    ModelImpl& operator=(const ModelImpl& model);

public:
    virtual ~ModelImpl();
    void execute(double start, double final, double increment) override;
    void add(System* sys) override;
    void add(Flow* flow) override;
    void remove(System* sys) override;
    void remove(Flow* flow) override;
    void setName(std::string name) override;
    std::string getName() const override;
    void setTime(double time) override;
    double getTime() const override;
    void incrementTime(double increment) override;

    //Metodo da fabrica
    System* createSystem(std::string name = "", double value = 0.0) override;

    // Permite que a classe de teste faça testes unitario a cada metodo
    friend class Unit_Model;
    // Permite que o metodo statico da fabrica acesse os construtores protegidos
    friend class Model;
};

#endif
