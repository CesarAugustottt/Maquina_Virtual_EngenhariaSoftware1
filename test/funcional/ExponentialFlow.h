#ifndef EXPONENTIALFLOW_H
#define EXPONENTIALFLOW_H

#include "../../src/FlowImpl.h" 
#include "../../src/System.h"
#include <string>

/*!
 * @brief This Class represents an exponential flow in the General Systems Theory implemented in this code.
 */
class ExponentialFlow : public FlowHandle {
public:
    /*!
     * @brief This is the default constructor for the ExponentialFlow Class.
     */
    ExponentialFlow();
    
    /*!
     * @brief This is the parameterized constructor for the ExponentialFlow Class.
     * @param name the name of the ExponentialFlow.
     * @param source a pointer to the source System.
     * @param target a pointer to the target System.
     */
    ExponentialFlow(std::string name, System* source, System* target);
    
    /*!
     * @brief This is the default destructor for the ExponentialFlow Class.
     */
    virtual ~ExponentialFlow();
    
    /*!
     * @brief Executes the exponential equation to calculate the flow's value.
     */
    virtual double execute() override;
};

#endif
