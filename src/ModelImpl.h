#ifndef MODELIMPL_H
#define MODELIMPL_H

#include "Model.h"
#include <vector>
#include <string>
#include <algorithm>

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

public:
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
    virtual ~ModelImpl();

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
};

#endif
