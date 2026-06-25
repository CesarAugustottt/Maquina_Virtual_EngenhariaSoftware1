#ifndef COMPOSITESYSTEM_H
#define COMPOSITESYSTEM_H

#include "System.h"
#include "handleBody.h"
#include <string>
#include <vector>
#include <algorithm>

/*!
 * @class CompositeSystemBody
 * @brief Concrete Body for a Composite System node.
 */
class CompositeSystemBody : public Body {
protected:
    /*! Local name for this composite node. */
    std::string name;
    /*! Value for this composite node. */
    double value;
    /*! Children Systems that compose this node. */
    std::vector<System*> systemChildrens;

public:
    CompositeSystemBody();
    virtual ~CompositeSystemBody();

    void setName(std::string name);
    std::string getName() const;
    void   setValue(double value);
    double getValue() const;

    void add (System* systemChildren);
    void remove(System* systemChildren);

    friend class CompositeSystemHandle;
    friend class Unit_System;
};


/*!
 * @class CompositeSystemHandle
 * @brief Handle for System.
 */
class CompositeSystemHandle : public System, public Handle<CompositeSystemBody> {
protected:
    CompositeSystemHandle();

    /*!
     * @brief Parameterized constructor.
     * @param name The label for this composite system.
     */
    CompositeSystemHandle(std::string name);

public:
    virtual ~CompositeSystemHandle();

    void setName(std::string name) override;
    std::string getName() const override;
    void setValue(double value) override;
    double getValue() const override;

    void add (System* systemChildren);
    void remove (System* systemChildren);

    friend class Unit_System;
    friend class ModelBody;
    friend class ModelHandle;
};

#endif