#ifndef FLOW_H
#define FLOW_H
#include "System.h"
#include <string>


/*!
 * @brief This class represents a flow in the General Systems Theory implemented in this code.
 * * It connects a source system to a target system and defines the equation for resource transfer.
 */
class Flow{
    private:
        /*! This attribute contains a name for the flow. */
        std::string name;
        /*! This pointer points to the source System of the flow. */
        System* source;
        /*! This pointer points to the target System of the flow. */
        System* target;
    public:
        // construtores e destrutor
        /*!
         * @brief This is the default constructor for the Flow Class.
         */
        Flow();
        /*!
         * @brief This is the parameterized constructor for the Flow Class.
         * * @param name the name of the Flow.
         * @param source pointer to the source System.
         * @param target pointer to the target System.
         */
        Flow(std::string name, System* source, System* target);

        /*!
         * @brief This is the default destructor for the Flow Class.
         */
        virtual ~Flow();

        //metodo virtual puro
        /*!
         * @brief Pure virtual method to execute the flow equation.
         * * Must be implemented by subclasses to define specific behaviors.
         * @return double - the calculated value to be transferred between systems.
         */
        virtual double execute()=0; 

        //getters e setters
        /*!
         * @brief Sets the name attribute in the Flow Class.
         * * @param name which will be set to the current flow.
         */
        void setName(std::string name);
        /*!
         * @brief Returns the name attribute in the Flow Class.
         * * @return string - the content name attribute.
         */
        std::string getName()const;

        /*!
         * @brief Sets the source system pointer in the Flow Class.
         * * @param source pointer to the system that will be the source.
         */
        void setSource(System* source);
        /*!
         * @brief Returns the source system pointer in the Flow Class.
         * * @return System* - pointer to the source system.
         */
        System* getSource()const;

        /*!
         * @brief Sets the target system pointer in the Flow Class.
         * * @param target pointer to the system that will be the target.
         */
        void setTarget(System* target);
        /*!
         * @brief Returns the target system pointer in the Flow Class.
         * * @return System* - pointer to the target system.
         */
        System* getTarget()const;

        //construtor copia
        /*!
         * @brief This is the copy constructor for the Flow Class.
         * * @param flow the flow that is going to be cloned.
         */
        Flow(const Flow& flow);

        //atribuição pelo operador =
        /*!
         * @brief This is the overloaded assignment operator for the Flow Class.
         * * @param flow the flow that is going to be cloned.
         * @return Flow& - a reference to the updated Flow Class object.
         */
        Flow& operator=(const Flow& flow);
};

#endif