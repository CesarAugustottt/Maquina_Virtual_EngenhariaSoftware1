#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

/*!
 * @brief A class containing static unit tests for the Model class.
 */

class Unit_Model{
public:
    /*!
     * @brief Tests the default constructor of ModelImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool defaultConstructor(void); 

    /*!
     * @brief Tests the parameterized constructor of ModelImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool constructor(void);

    /*!
     * @brief Tests the destructor of ModelImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool destructor(void);

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
     * @brief Tests the addition of Systems into ModelImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool addSystem(void);

    /*!
     * @brief Tests the addition of Flows into ModelImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool addFlow(void);

    /*!
     * @brief Tests the private static method addModel.
     * @return true if the test passed, false otherwise.
     */
    static bool addModel(void);

    /*!
     * @brief Tests the removal of Systems from ModelImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool removeSystem(void);

    /*!
     * @brief Tests the removal of Flows from ModelImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool removeFlow(void);

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
    static bool assignmentOperator(void);

    /*!
     * @brief Tests the copy constructor of ModelImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool copyConstructor(void);

    //metodos da fabrica de criação
    /*!
     * @brief Tests the static factory method createModel.
     * @return true if the test passed, false otherwise.
     */
    static bool createModel(void);

    /*!
     * @brief Tests the factory method createSystem.
     * @return true if the test passed, false otherwise.
     */
    static bool createSystem(void);

    /*!
     * @brief Tests the template factory method createFlow.
     * @return true if the test passed, false otherwise.
     */
    static bool createFlow(void);

    //metodos da fabrica de destruição
    /*!
     * @brief Tests the static factory method deleteModel.
     * @return true if the test passed, false otherwise.
     */
    static bool deleteModel(void);

    /*!
     * @brief Tests the factory method deleteSystem.
     * @return true if the test passed, false otherwise.
     */
    static bool deleteSystem(void);

    /*!
     * @brief Tests the factory method deleteFlow.
     * @return true if the test passed, false otherwise.
     */
    static bool deleteFlow(void);

    //função global chamada pela main
    /*!
     * @brief Runs all the unit tests for the Model class (Regression Testing).
     * @return true if all tests pass, false otherwise.
     */
    static bool regressiveTest(void);
};


#endif 