#ifndef FLOWIMPL_H
#define FLOWIMPL_H
#include "Flow.h" //interface
#include "handleBody.h"
#include "System.h"
#include <string>

/*!
 * @class FlowBody
 * @brief This class represents the concrete implementation of a Flow.
 */
class FlowBody : public Body {
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
    FlowBody();

    /*!
     * @brief This is the default destructor for the FlowImpl Class.
     */
    virtual ~FlowBody();

    //metodo virtual puro
    virtual double execute()=0; 

    //getters e setters
    void setName(std::string name);
    std::string getName()const;
    void setSource(System* source);
    System* getSource()const;
    void setTarget(System* target);
    System* getTarget()const;


    // Permite que a classe de teste faça testes unitário a cada método
    friend class Unit_Flow;
    //permite que o template createFloe de Model instacie os fluxos
    friend class Model;
};

/*!
 * @class FlowHandle
 * @brief This class represents the handle of a Flow.
 */
class FlowHandle : public Flow, public Handle<FlowBody> {
protected:
    // construtores e destrutor
    /*!
     * @brief This is the default constructor for the FlowImpl Class.
     */
    FlowHandle();
    /*!
     * @brief This is the parameterized constructor for the FlowImpl Class.
     * * @param name the name of the Flow.
     * @param source pointer to the source System.
     * @param target pointer to the target System.
     */
    FlowHandle(std::string name, System* source, System* target);

public:
    /*!
     * @brief This is the default destructor for the FlowImpl Class.
     */
    virtual ~FlowHandle();

    //metodo virtual puro
    virtual double execute()=0; 

    //getters e setters
    void setName(std::string name) override;
    std::string getName()const override;
    void setSource(System* source) override;
    System* getSource()const override;
    void setTarget(System* target) override;
    System* getTarget()const override;

    // Permite que a classe de teste faça testes unitário a cada método
    friend class Unit_Flow;
    //permite que o template createFloe de Model instacie os fluxos
    friend class Model;
};

#endif
