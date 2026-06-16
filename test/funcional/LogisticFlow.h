#ifndef LOGISTICFLOW_H
#define LOGISTICFLOW_H

#include "../../src/FlowImpl.h"

/*!
 * @brief This class represents a logistic flow in the General Systems Theory implemented in this code.
 * * It implements the execute method using a logistic equation for resource transfer.
 */
class LogisticFlow : public FlowHandle {
protected:
    // construtor e destrutor 
    /*!
     * @brief This is the default constructor for the LogisticFlow Class.
     */
    LogisticFlow();
    
    /*!
     * @brief This is the parameterized constructor for the LogisticFlow Class.
     * * @param name the name of the LogisticFlow.
     * @param source pointer to the source System.
     * @param target pointer to the target System.
     */
    LogisticFlow(std::string name, System* source, System* target);

    //construtor copia
    /*!
     * @brief This is the copy constructor for the LogisticFlow Class.
     * * @param flow the logistic flow that is going to be cloned.
     */
    LogisticFlow(const LogisticFlow& flow);

    //operador de atribuição
    /*!
     * @brief This is the overloaded assignment operator for the LogisticFlow Class.
     * * @param flow the logistic flow that is going to be cloned.
     * @return LogisticFlow& - a reference to the updated LogisticFlow Class object.
     */
    LogisticFlow& operator=(const LogisticFlow& flow);
    
public:
    //destrutor
    /*!
     * @brief This is the default destructor for the LogisticFlow Class.
     */
    virtual ~LogisticFlow();
        
    //metodo sobregarregado
    /*!
     * @brief Executes the specific logistic equation for this flow.
     * * Overrides the pure virtual method from the Flow class.
     * @return double - the calculated value based on the logistic equation.
     */
    virtual double execute() override;

    //permite que o template createFlow de Model instancie os fluxos
    friend class Model;
};

#endif
