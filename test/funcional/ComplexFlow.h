#ifndef COMPLEXFLOW_H
#define COMPLEXFLOW_H

#include "../../src/FlowImpl.h"

/*!
 * @brief This Class represents a complex flow in the General Systems Theory implemented in this code.
 */
class ComplexFlow : public FlowImpl {
public:
    // Construtor padrao
    /*!
     * @brief This is the default constructor for the ComplexFlow Class.
     * @return ComplexFlow - a ComplexFlow Class object.
     */
    ComplexFlow();
    // Construtor parametrizado
    /*!
     * @brief This is the parameterized constructor for the ComplexFlow Class.
     * @param name the name of the ComplexFlow.
     * @param source a pointer to the source System.
     * @param target a pointer to the target System.
     */
    ComplexFlow(std::string name, System* source, System* target);
    // Destrutor virtual
    /*!
     * @brief This is the default destructor for the ComplexFlow Class.
     */
    virtual ~ComplexFlow();

    // Sobrescrita do metodo execute
    /*!
     * @brief Executes the complex equation to calculate the flow's value.
     * @return double - the calculated value for the transfer.
     */
    virtual double execute() override;

    // Construtor de copia
    /*!
     * @brief This is the copy constructor for the ComplexFlow Class.
     * @param flow the ComplexFlow that is going to be cloned.
     */
    ComplexFlow(const ComplexFlow& flow);
    // Operador de atribuicao
    /*!
     * @brief This is the overloaded assignment operator for the ComplexFlow Class.
     * @param flow the ComplexFlow that is going to be cloned.
     * @return ComplexFlow& - a reference to the updated ComplexFlow Class object.
     */
    ComplexFlow& operator=(const ComplexFlow& flow);
};

#endif
