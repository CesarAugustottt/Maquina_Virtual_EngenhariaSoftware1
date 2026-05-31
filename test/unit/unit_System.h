#ifndef UNIT_SYSTEM_H
#define UNIT_SYSTEM_H

/*!
 * @brief A class containing static unit tests for the System class.
 */

class Unit_System {
public:
    /*!
     * @brief Tests the default constructor of SystemImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool defaultConstructor(void);

    /*!
     * @brief Tests the parameterized constructor of SystemImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool constructor(void);

    /*!
     * @brief Tests the destructor of SystemImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool destructor(void);

    /*!
     * @brief Tests the getName method of SystemImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool getName(void);

    /*!
     * @brief Tests the setName method of SystemImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool setName(void);

    /*!
     * @brief Tests the getValue method of SystemImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool getValue(void);

    /*!
     * @brief Tests the setValue method of SystemImpl.
     * @return true if the test passed, false otherwise.
     */
    static bool setValue(void);

    //funcao chamada pela main
    /*!
     * @brief Runs all the unit tests for the System class (Regression Testing).
     * @return true if all tests pass, false otherwise.
     */
    static bool regressiveTest(void);
};

#endif
