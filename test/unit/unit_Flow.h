#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H

/*!
 * @brief A class containing static unit tests for the Flow class.
 */

class Unit_Flow {
public:
    /*!
     * @brief Tests the default constructor of FlowImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool defaultConstructor(void);

    /*!
     * @brief Tests the parameterized constructor of FlowImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool constructor(void);

    /*!
     * @brief Tests the destructor of FlowImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool destructor(void);

    /*!
     * @brief Tests the getName method of FlowImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool getName(void);

    /*!
     * @brief Tests the setName method of FlowImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool setName(void);

    /*!
     * @brief Tests the getSource method of FlowImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool getSource(void);

    /*!
     * @brief Tests the setSource method of FlowImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool setSource(void);

    /*!
     * @brief Tests the getTarget method of FlowImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool getTarget(void);

    /*!
     * @brief Tests the setTarget method of FlowImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool setTarget(void);

    /*!
     * @brief Tests the copy constructor of FlowImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool copyConstructor(void);

    /*!
     * @brief Tests the assignment operator (=) of FlowImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool assignmentOperator(void);

    /*!
     * @brief Runs all the unit tests for the Flow class (Regression Testing).
     * @return true if all tests pass, false otherwise.
     */
    static bool regressiveTest(void);
};

#endif
