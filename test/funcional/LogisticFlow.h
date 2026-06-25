#ifndef LOGISTICFLOW_H
#define LOGISTICFLOW_H

#include "../../src/FlowImpl.h"
#include "../../src/System.h"
#include <string>

/*!
 * @brief This class represents a logistic flow in the General Systems Theory implemented in this code.
 * * It implements the execute method using a logistic equation for resource transfer.
 */
class LogisticFlow : public FlowHandle {
public:
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
    
    /*!
     * @brief This is the default destructor for the LogisticFlow Class.
     */
    virtual ~LogisticFlow();
        
    /*!
     * @brief Executes the specific logistic equation for this flow.
     * * Overrides the pure virtual method from the Flow class.
     * @return double - the calculated value based on the logistic equation.
     */
    virtual double execute() override;
};

#endif
