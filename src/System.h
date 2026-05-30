#ifndef SYSTEM_H
#define SYSTEM_H
#include <string>

/*!
 * @brief This Class represents a system in the General Systems Theory implemented in this code.
 */
class System {
public:
    /*!
     * @brief This is the default destructor for the System Class.
     */
    virtual ~System() {}

    // Setters e Getters
    /*!
     * @brief Sets the name attribute in the System Class.
     * * @param name which will be set to the current system.
     */
    virtual void setName(std::string) = 0;
    /*!
     * @brief Returns the name attribute in the System Class.
     * * @return string - the content name attribute.
     */
    virtual std::string getName() const = 0;
    /*!
     * @brief Sets the value attribute in the System Class.
     * * @param value which will be set to the current system.
     */
    virtual void setValue(double) = 0;
    /*!
     * @brief Returns the value attribute in the System Class.
     * * @return double - the content value attribute.
     */
    virtual double getValue() const = 0;
};

#endif
