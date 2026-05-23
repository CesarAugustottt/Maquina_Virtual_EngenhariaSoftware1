#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

/*!
 * @brief This Class represents a system in the General Systems Theory implemented in this code.
 */
class System {
private:
    /*! This attribute contains a name for the system. */
    std::string name;
    /*! This attribute contains the actual value of the system. */
    double value;

public:
    // Construtores e Destrutor
    /*!
     * @brief This is the default constructor for the System Class.
     * * @return System - a System Class object.
     */
    System();
    /*!
     * @brief This is the parameterized constructor for the System Class.
     * * @param name the name of the System.
     * @param value the initial value of the System.
     */
    System(std::string name, double value);
    /*!
     * @brief This is the default destructor for the System Class.
     */
    virtual ~System();

    // Setters e Getters
    /*!
     * @brief Sets the name attribute in the System Class.
     * * @param name which will be set to the current system.
     */
    void setName(std::string name);
    /*!
     * @brief Returns the name attribute in the System Class.
     * * @return string - the content name attribute.
     */
    std::string getName() const;
    /*!
     * @brief Sets the value attribute in the System Class.
     * * @param value which will be set to the current system.
     */
    void setValue(double value);
    /*!
     * @brief Returns the value attribute in the System Class.
     * * @return double - the content value attribute.
     */
    double getValue() const;

    // Construtor de copia e Operador de atribuicao
    /*!
     * @brief This is the copy constructor for the System Class.
     * * @param sys the system that is going to be cloned.
     */
    System(const System& sys);
    /*!
     * @brief This is the overloaded assignment operator for the System Class.
     * * @param sys the system that is going to be cloned.
     * @return System& - a reference to the updated System Class object.
     */
    System& operator=(const System& sys);
};

#endif
