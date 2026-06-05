#ifndef EXPONENTIALFLOW_H
#define EXPONENTIALFLOW_H

#include  "../../src/FlowImpl.h"

/*!
 * @brief This Class represents an exponential flow in the General Systems Theory implemented in this code.
 */
class ExponentialFlow : public FlowImpl {
protected:
    // Construtor padrao
    /*!
     * @brief This is the default constructor for the ExponentialFlow Class.
     * * @return ExponentialFlow - an ExponentialFlow Class object.
     */
    ExponentialFlow();
    // Construtor parametrizado
    /*!
     * @brief This is the parameterized constructor for the ExponentialFlow Class.
     * * @param name the name of the ExponentialFlow.
     * @param source a pointer to the source System.
     * @param target a pointer to the target System.
     */
    ExponentialFlow(std::string name, System* source, System* target);
    
    // Construtor de copia
    /*!
     * @brief This is the copy constructor for the ExponentialFlow Class.
     * * @param flow the ExponentialFlow that is going to be cloned.
     */
    ExponentialFlow(const ExponentialFlow& flow);
    // Operador de atribuicao
    /*!
     * @brief This is the overloaded assignment operator for the ExponentialFlow Class.
     * * @param flow the ExponentialFlow that is going to be cloned.
     * @return ExponentialFlow& - a reference to the updated ExponentialFlow Class object.
     */
    ExponentialFlow& operator=(const ExponentialFlow& flow);
public:
    // Destrutor virtual
    /*!
     * @brief This is the default destructor for the ExponentialFlow Class.
     */
    virtual ~ExponentialFlow();
    // Sobrescrita do execute
    /*!
     * @brief Executes the exponential equation to calculate the flow's value.
     * * @return double - the calculated value for the transfer.
     */
    virtual double execute() override;

    //permite que o template createFloe de Model instacie os fluxos
    friend class Model;
};

#endif
