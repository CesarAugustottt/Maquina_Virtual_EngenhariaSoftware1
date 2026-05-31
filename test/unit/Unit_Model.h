#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

#include "../../src/ModelImpl.h"

/*!
 * @brief A class containing static unit tests for the Model class.
 */

class Unit_Model{
public:
    /*!
     * @brief Tests the default constructor of ModelImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool construtor_default(void);

    /*!
     * @brief Tests the parameterized constructor of ModelImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool construtor(void);

    /*!
     * @brief Tests the destructor of ModelImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool destrutor(void);

    /*!
     * @brief Tests the execution method of ModelImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool execute(void);

    /*!
     * @brief Tests the time incrementation method of ModelImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool increment(void);

    /*!
     * @brief Tests the addition of Systems and Flows into ModelImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool add(void);

    /*!
     * @brief Tests the removal of Systems and Flows from ModelImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool remove(void);

    /*!
     * @brief Tests the getName method of ModelImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool getName(void);

    /*!
     * @brief Tests the setName method of ModelImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool setName(void);

    /*!
     * @brief Tests the getTime method of ModelImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool getTime(void);

    /*!
     * @brief Tests the setTime method of ModelImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool setTime(void);

    /*!
     * @brief Tests the assignment operator (=) of ModelImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool atribuicao(void);

    /*!
     * @brief Tests the copy constructor of ModelImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool construtorCopia(void);

    //função global chamada pela main
    /*!
     * @brief Runs all the unit tests for the Model class (Regression Testing).
     * @return true if all tests pass, false otherwise.
     */
    static bool regressiveTest(void);
};


#endif 