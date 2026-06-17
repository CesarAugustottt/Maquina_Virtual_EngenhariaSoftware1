#ifndef COMPLEXFLOW_H
#define COMPLEXFLOW_H

#include "../../src/Flow.h"
#include "../../src/System.h"
#include <string>

/*!
 * @brief This Class represents a complex flow in the General Systems Theory implemented in this code.
 */
class ComplexFlow : public Flow {
protected:
    /*! This attribute contains a name for the flow. */
    std::string name;
    /*! This pointer points to the source System of the flow. */
    System* source;
    /*! This pointer points to the target System of the flow. */
    System* target;

public:
    /*!
     * @brief This is the default constructor for the ComplexFlow Class.
     * @return ComplexFlow - a ComplexFlow Class object.
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
     * @return double - the calculated value for the transfer.
     */
    virtual double execute() override;

    void setName(std::string name) override;
    std::string getName() const override;
    void setSource(System* source) override;
    System* getSource() const override;
    void setTarget(System* target) override;
    System* getTarget() const override;
};

#endif
