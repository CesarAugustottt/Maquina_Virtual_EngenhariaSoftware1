#ifndef COMPLEXFLOW_H
#define COMPLEXFLOW_H

#include "../../src/FlowImpl.h"
#include "../../src/System.h"
#include <string>

/*!
 * @brief This Class represents a complex flow in the General Systems Theory implemented in this code.
 */
class ComplexFlow : public FlowHandle {
public:
    /*!
     * @brief This is the default constructor for the ComplexFlow Class.
     */
    ComplexFlow();
    
    /*!
     * @brief This is the parameterized constructor for the ComplexFlow Class.
     * @param name the name of the ComplexFlow.
     * @param source a pointer to the source System.
     * @param target a pointer to the target System.
     */
    ComplexFlow(std::string name, System* source, System* target);

    /*!
     * @brief This is the default destructor for the ComplexFlow Class.
     */
    virtual ~ComplexFlow();

    /*!
     * @brief Executes the complex equation to calculate the flow's value.
     */
    virtual double execute() override;
};

#endif
