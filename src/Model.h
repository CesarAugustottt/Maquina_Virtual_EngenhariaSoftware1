#ifndef MODEL_H
#define MODEL_H

#include <string>

class Flow;
class System;

/*!
 * @brief This class represents the interface of a model in the General Systems Theory implemented in this code.
 * * It acts as a container for systems and flows, controlling the execution of the simulation.
 */
class Model {
public:
    /*!
    * @brief This is the default destructor for the Model Class
    */
    virtual ~Model() {}

    /*!
    * @brief Executes the simulation by updating systems based on the flows equations over a period of time.
    * * @param start the starting time of the simulation.
    * @param final the ending time of the simulation.
    * @param increment the time step increment for each iteration.
    */
    virtual void execute(double, double, double) = 0;
    /*!
    * @brief Adds a System pointer to the internal container of the model.
    * * @param sys the System pointer to be added.
    */
    virtual void add(System*) = 0;
    /*!
    * @brief Adds a Flow pointer to the internal container of the model.
    * * @param flow the Flow pointer to be added.
    */
    virtual void add(Flow*) = 0;
    /*!
    * @brief Removes a System pointer from the internal container of the model.
    * * @param sys the System pointer to be removed.
    */
    virtual void remove(System*) = 0;
    /*!
    * @brief Removes a Flow pointer from the internal container of the model.
    * * @param flow the Flow pointer to be removed.
    */
    virtual void remove(Flow*) = 0;
    /*!
    * @brief Sets the name attribute in the Model Class
    * * @param name which will be set to the current model.
    */
    virtual void setName(std::string) = 0;
    /*!
    * @brief Returns the name attribute in the Model Class.
    * * @return string - the content name attribute.
    */
    virtual std::string getName() const = 0;
    /*!
    * @brief Sets the time attribute in the Model Class.
    * * @param time which will be set to the current model.
    */
    virtual void setTime(double) = 0;
    /*!
    * @brief Returns the time attribute in the Model Class.
    * * @return double - the content time attribute.
    */
    virtual double getTime() const = 0;
    /*!
    * @brief Increments the simulation time by a specific value.
    * * @param increment the value to be added to the current time.
    */
    virtual void incrementTime(double) = 0;
};

#endif
