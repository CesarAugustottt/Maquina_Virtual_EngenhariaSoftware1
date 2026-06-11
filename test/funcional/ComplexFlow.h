#ifndef COMPLEXFLOW_H
#define COMPLEXFLOW_H

#include "../../src/Flow.h"

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
public:
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

    //getters e setters
    void setName(std::string name) override;
    std::string getName()const override;
    void setSource(System* source) override;
    System* getSource()const override;
    void setTarget(System* target) override;
    System* getTarget()const override;

    //permite que o template createFloe de Model instacie os fluxos
    friend class Model;
};

#endif
