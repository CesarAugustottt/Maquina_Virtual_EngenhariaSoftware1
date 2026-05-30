#ifndef FLOWIMPL_H
#define FLOWIMPL_H
#include "Flow.h" //interface
#include "System.h"
#include <string>

class FlowImpl: public Flow{
protected:
    /*! This attribute contains a name for the flow. */
    std::string name;
    /*! This pointer points to the source System of the flow. */
    System* source;
    /*! This pointer points to the target System of the flow. */
    System* target;
public:
    // construtores e destrutor
    /*!
     * @brief This is the default constructor for the FlowImpl Class.
     */
    FlowImpl();
    /*!
     * @brief This is the parameterized constructor for the FlowImpl Class.
     * * @param name the name of the Flow.
     * @param source pointer to the source System.
     * @param target pointer to the target System.
     */
    FlowImpl(std::string name, System* source, System* target);

    /*!
     * @brief This is the default destructor for the FlowImpl Class.
     */
    virtual ~FlowImpl();

    //metodo virtual puro
    virtual double execute()=0; 

    //getters e setters
    void setName(std::string name);
    std::string getName()const;
    void setSource(System* source);
    System* getSource()const;
    void setTarget(System* target);
    System* getTarget()const;

    //construtor copia
    /*!
     * @brief This is the copy constructor for the FlowImpl Class.
     * * @param flow the flow that is going to be cloned.
     */
    FlowImpl(const FlowImpl& flow);

    //atribuição pelo operador =
    /*!
     * @brief This is the overloaded assignment operator for the FlowImpl Class.
     * * @param flow the flow that is going to be cloned.
     * @return FlowImpl& - a reference to the updated FlowImpl Class object.
     */
    FlowImpl& operator=(const FlowImpl& flow);
};

#endif