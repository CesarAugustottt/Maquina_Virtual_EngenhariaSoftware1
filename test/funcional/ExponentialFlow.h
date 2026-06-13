#ifndef EXPONENTIALFLOW_H
#define EXPONENTIALFLOW_H

#include "../../src/Flow.h"
#include <string>

/*!
 * @brief This Class represents an exponential flow in the General Systems Theory implemented in this code.
 */
class ExponentialFlow : public Flow {
protected:
    /*! This attribute contains a name for the flow. */
    std::string name;
    /*! This pointer points to the source System of the flow. */
    System* source;
    /*! This pointer points to the target System of the flow. */
    System* target;

    // Construtor padrao
    /*!
     * @brief This is the default constructor for the ExponentialFlow Class.
     * @return ExponentialFlow - an ExponentialFlow Class object.
     */
    ExponentialFlow();
    
    // Construtor parametrizado
    /*!
     * @brief This is the parameterized constructor for the ExponentialFlow Class.
     * @param name the name of the ExponentialFlow.
     * @param source a pointer to the source System.
     * @param target a pointer to the target System.
     */
    ExponentialFlow(std::string name, System* source, System* target);
    
    // Construtor de copia
    /*!
     * @brief This is the copy constructor for the ExponentialFlow Class.
     * @param flow the ExponentialFlow that is going to be cloned.
     */
    ExponentialFlow(const ExponentialFlow& flow);
    
    // Operador de atribuicao
    /*!
     * @brief This is the overloaded assignment operator for the ExponentialFlow Class.
     * @param flow the ExponentialFlow that is going to be cloned.
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
     * @return double - the calculated value for the transfer.
     */
    virtual double execute() override;

    // Getters e setters
    void setName(std::string name) override;
    std::string getName() const override;
    void setSource(System* source) override;
    System* getSource() const override;
    void setTarget(System* target) override;
    System* getTarget() const override;

    // Permite que o template createFlow de Model instancie os fluxos
    friend class Model;
};

#endif
