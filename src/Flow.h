#ifndef FLOW_H
#define FLOW_H

#include <string>

//Declarar System para não precisar incluir a interface
class System;

/*!
 * @brief This class represents a flow in the General Systems Theory implemented in this code.
 * * It connects a source system to a target system and defines the equation for resource transfer.
 */
class Flow{
public:
    /*!
     * @brief This is the default destructor for the Flow Class.
     */
    virtual ~Flow(){}

    //metodo virtual puro
    /*!
     * @brief Pure virtual method to execute the flow equation.
     * * Must be implemented by subclasses to define specific behaviors.
     * @return double - the calculated value to be transferred between systems.
     */
    virtual double execute() = 0; 

    //getters e setters
    /*!
     * @brief Sets the name attribute in the Flow Class.
     * * @param name which will be set to the current flow.
     */
    virtual void setName(std::string) = 0;
    /*!
     * @brief Returns the name attribute in the Flow Class.
     * * @return string - the content name attribute.
     */
    virtual std::string getName()const = 0;

    /*!
     * @brief Sets the source system pointer in the Flow Class.
     * * @param source pointer to the system that will be the source.
     */
    virtual void setSource(System*) = 0;
    /*!
     * @brief Returns the source system pointer in the Flow Class.
     * * @return System* - pointer to the source system.
     */
    virtual System* getSource()const = 0;

    /*!
     * @brief Sets the target system pointer in the Flow Class.
     * * @param target pointer to the system that will be the target.
     */
    virtual void setTarget(System*) = 0;
    /*!
     * @brief Returns the target system pointer in the Flow Class.
     * * @return System* - pointer to the target system.
     */
     virtual System* getTarget()const = 0;
};

#endif