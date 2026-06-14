#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>

class Flow;
class System;
class ModelImpl;

/*!
 * @brief This class represents the interface of a model in the General Systems Theory implemented in this code.
 * * It acts as a container for systems and flows, controlling the execution of the simulation.
 */
class Model {
private:
    /*! @brief Static container for storing all models created by the factory.*/
    static std::vector<Model*> models;
    
    /*!
     * @brief Adds a Model instance within the static global vector.
     * * @param Pointer to the instance of the model to be added.
     */
    static void addModel(Model*);

    friend class ModelBody;
    friend class ModelHandle;
protected:
    /*!
    * @brief Adds a System pointer to the internal container of the model.
    * * @param sys the System pointer to be added.
    */
    virtual void add(System*) = 0;
    /*!
    * @brief Adds a Flow pointer to the internal container of the model.
    * * @param flow the Flow pointer to be added.
    */
    virtual void add(Flow*) = 0;
public:
    /*!
    * @brief This is the default destructor for the Model Class
    */
    virtual ~Model() {}

    /*!
    * @brief Executes the simulation by updating systems based on the flows equations over a period of time.
    * * @param start the starting time of the simulation.
    * @param final the ending time of the simulation.
    * @param increment the time step increment for each iteration.
    */
    virtual void execute(double, double, double) = 0;
    /*!
    * @brief Removes a System pointer from the internal container of the model.
    * * @param sys the System pointer to be removed.
    */
    virtual void remove(System*) = 0;
    /*!
    * @brief Removes a Flow pointer from the internal container of the model.
    * * @param flow the Flow pointer to be removed.
    */
    virtual void remove(Flow*) = 0;
    /*!
    * @brief Sets the name attribute in the Model Class
    * * @param name which will be set to the current model.
    */
    virtual void setName(std::string) = 0;
    /*!
    * @brief Returns the name attribute in the Model Class.
    * * @return string - the content name attribute.
    */
    virtual std::string getName() const = 0;
    /*!
    * @brief Sets the time attribute in the Model Class.
    * * @param time which will be set to the current model.
    */
    virtual void setTime(double) = 0;
    /*!
    * @brief Returns the time attribute in the Model Class.
    * * @return double - the content time attribute.
    */
    virtual double getTime() const = 0;
    /*!
    * @brief Increments the simulation time by a specific value.
    * * @param increment the value to be added to the current time.
    */
    virtual void incrementTime(double) = 0;

    //METODOS frabrica
    //metodos de criação
    /*!
    * @brief Static method that acts as a factory to create a Model instance.
    * @param name the name of the model.
    * @param time the initial time of the model.
    * @return Model* - pointer to the created model interface.
    */
    static Model* createModel(std::string name = "", double time = 0.0);

    /*!
    * @brief Factory method to create a System inside this model.
    * @param name the name of the system.
    * @param value the initial value of the system.
    * @return System* - pointer to the created system.
    */
    virtual System* createSystem(std::string name = "", double value = 0.0) = 0;


    /*!
    * @brief Template factory method to create any type of Flow inside this model.
    * @tparam T the concrete subclass of Flow.
    * @param name the name of the flow.
    * @param source pointer to the source system.
    * @param target pointer to the target system.
    * @return Flow* - pointer to the created flow.
    */
    template <typename T>
    Flow* createFlow(std::string name = "", System* source = nullptr, System* target = nullptr) { //metodo template não pode ser virtual
        Flow* flow = new T(name, source, target);
        this->add(flow); // Já adiciona automaticamente ao modelo
        return flow;
    }

    //metodos para deletar
    /*!
     * @brief Static method that acts as a factory to delete a Model instance.
     * * @param model Pointer to the Model instance to be deleted.
     */
    static void deleteModel(Model*);

    /*!
     * @brief Factory method to delete a System instance from this model.
     * * @param sys Pointer to the System instance to be deleted.
     */
    virtual void deleteSystem(System*) = 0;

    /*!
     * @brief Factory method to delete a Flow instance from this model.
     * * @param flow Pointer to the Flow instance to be deleted.
     */
    virtual void deleteFlow(Flow*) = 0;
    friend class Unit_Model;
};

#endif
