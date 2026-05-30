#ifndef MODELIMPL_H
#define MODELIMPL_H

#include "Model.h"
#include <vector>
#include <string>
#include <algorithm>

class ModelImpl : public Model {
protected:
    std::string name;
    double time;
    std::vector<System*> systems;
    std::vector<Flow*> flows;

public:
    ModelImpl();
    ModelImpl(std::string name, double time);
    virtual ~ModelImpl();

    ModelImpl(const ModelImpl& model);
    ModelImpl& operator=(const ModelImpl& model);

    void execute(double start, double final, double increment) override;
    void add(System* sys) override;
    void add(Flow* flow) override;
    void remove(System* sys) override;
    void remove(Flow* flow) override;
    void setName(std::string name) override;
    std::string getName() const override;
    void setTime(double time) override;
    double getTime() const override;
    void incrementTime(double increment) override;
};

#endif
