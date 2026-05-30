#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H

#include "System.h" //interface
#include <string>

class SystemImpl : public System {
protected:
    /*! This attribute contains a name for the system. */
    std::string name;
    /*! This attribute contains the actual value of the system. */
    double value;
public:
    // Construtores e Destrutor
    /*!
     * @brief This is the default constructor for the SystemImpl Class.
     */
    SystemImpl();
    /*!
     * @brief This is the parameterized constructor for the SystemImpl Class.
     * * @param name the name of the System.
     * @param value the initial value of the System.
     */
    SystemImpl(std::string name, double value);
    ///destrutor
    virtual ~SystemImpl();
    // Setters e Getters
    void setName(std::string name);
    std::string getName() const;
    void setValue(double value);
    double getValue() const;

    // Construtor de copia e Operador de atribuicao
    /*!
     * @brief This is the copy constructor for the SystemImpl Class.
     * * @param sys the system that is going to be cloned.
     */
    SystemImpl(const SystemImpl& sys);
    /*!
     * @brief This is the overloaded assignment operator for the SystemImpl Class.
     * * @param sys the system that is going to be cloned.
     * @return SystemImpl& - a reference to the updated SystemImpl Class object.
     */
    SystemImpl& operator=(const SystemImpl& sys);
};

#endif
