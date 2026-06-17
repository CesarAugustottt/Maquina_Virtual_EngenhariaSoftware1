#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H

#include "System.h" //interface
#include "handleBody.h"
#include <string>

/*!
 * @class SystemBody
 * @brief This class represents the concrete implementation of a System.
 */
class SystemBody : public Body {
protected:
    /*! This attribute contains a name for the system. */
    std::string name;
    /*! This attribute contains the actual value of the system. */
    double value;
    
public:
    /*!
     * @brief This is the default constructor for the SystemBody Class.
     */
    SystemBody();

    /**
     * @brief Destructor for SystemBody.
     */
    virtual ~SystemBody();

    void setName(std::string name);
    std::string getName() const;
    void setValue(double value);
    double getValue() const;

    //acesso a classes de testes unitarios
    friend class Unit_System;
    friend class SystemHandle;
};


/**
 * @class SystemHandle
 * @brief This class represents the handle of a system.
 */
class SystemHandle : public System, public Handle<SystemBody> {
protected:
    /**
     * @brief Default constructor for SystemHandle.
     */
    SystemHandle();

    /**
     * @brief This is the Parameterized constructor for SystemHandle.
     * @param name The name of the System.
     * @param value The initial value of the System.
     */
    SystemHandle(std::string name, double value);
public:

    /**
     * @brief Destructor for SystemHandle.
     */
    virtual ~SystemHandle();

    double getValue() const override;
    std::string getName() const override;
    void setValue(double value) override;
    void setName(std::string name) override;
    
    //classe amiga para testes unitários
    friend class Unit_System;
    friend class ModelBody;
};

#endif