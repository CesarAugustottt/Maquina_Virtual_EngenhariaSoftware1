#ifndef MODEL_H
#define MODEL_H
#include"System.h"
#include"Flow.h"
#include <vector> 
#include <string>
#include<iostream>
#include<algorithm>

/*!
 * @brief This class represents a model in the General System Theory implemented in this code.
 * * It acts as a container for systems and flows, controlling the execution of the simulation.
 */

class Model{
    private:
        /*! This attribute contains a name for the model. */
        std::string name;
        /*! This attribute contains the current time of the simulation. */
        double time;
        /*! This vector contains pointers to all systems registered in the model. */
        std::vector <System*> systems;
        /*! This vector contains pointers to all flows registered in the model. */
        std::vector <Flow*> flows;
    public:
        //construtor
        /*!
         * @brief This is the default constructor for the Model Class.
         */
        Model();
        /*!
         * @brief This is the parameterized constructor for the Model Class.
         * * @param name the name of the Model.
         * @param time the initial time of the simulation.
         */
        Model(std::string name, double time);
        //destrutor
        /*!
         * @brief This is the default destructor for the Model Class
         */
        virtual ~Model();

        //metodo para rodar a simulação, o mais importante
        /*!
         * @brief Executes the simulation by updating systems based on the flows equations over a period of time.
         * * @param start the starting time of the simulation.
         * @param final the ending time of the simulation.
         * @param increment the time step increment for each iteration.
         */
        void execute (double start, double final, double increment);

        //Adicionar elemento ao modelo
        /*!
         * @brief Adds a System pointer to the internal container of the model.
         * * @param sys the System pointer to be added.
         */
        void add(System* sys);
        /*!
         * @brief Adds a Flow pointer to the internal container of the model.
         * * @param flow the Flow pointer to be added.
         */
        void add(Flow* flow);

        //Remover elemento do modelo
        /*!
         * @brief Removes a System pointer from the internal container of the model.
         * * @param sys the System pointer to be removed.
         */
        void remove(System* sys);
        /*!
         * @brief Removes a Flow pointer from the internal container of the model.
         * * @param flow the Flow pointer to be removed.
         */
        void remove(Flow* flow);

        //gettrs e setters
        /*!
         * @brief Sets the name attribute in the Model Class
         * * @param name which will be set to the current model.
         */
        void setName (std::string name);
        /*!
         * @brief Returns the name attribute in the Model Class.
         * * @return string - the content name attribute.
         */
        std::string getName() const;

        /*!
         * @brief Sets the time attribute in the Model Class.
         * * @param time which will be set to the current model.
         */
        void setTime(double time);
        /*!
         * @brief Returns the time attribute in the Model Class.
         * * @return double - the content time attribute.
         */
        double getTime()const;

        //mettodo para incrementaro tempo
        /*!
         * @brief Increments the simulation time by a specific value.
         * * @param increment the value to be added to the current time.
         */
        void incrementTime (double increment);
        
        //construtor de copia (forma canonica)
        /*!
         * @brief This is the copy constructor for the Model Class.
         * * @param model the model that is going to be cloned.
         */
        Model(const Model& model);

        //operador igual de atribuição (forma canonica)
        /*!
         * @brief This is the overloaded assignment operator for the Model Class.
         * * @param model the model that is going to be cloned.
         * @return Model& - a reference to the updated Model Class object.
         */
        Model& operator=(const Model& model);

};

#endif