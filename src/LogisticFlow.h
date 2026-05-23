#ifndef LOGISTICFLOW_H
#define LOGISTICFLOW_H
#include"Flow.h"

class LogisticFlow: public Flow{
    public:
        LogisticFlow();
        LogisticFlow(std::string name, System* source, System* target);
        virtual ~LogisticFlow();
        double execute() override;
    private:
        LogisticFlow(const LogisticFlow& flow);
        LogisticFlow& operator=(const LogisticFlow& flow);
};
#endif
