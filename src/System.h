#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

class System {
private:
    std::string name;
    double value;

public:
    // Construtores e Destrutor
    System();
    System(std::string name, double value);
    virtual ~System();

    // Setters e Getters
    void setName(std::string name);
    std::string getName() const;
    void setValue(double value);
    double getValue() const;

private:
    // Construtor de copia e Operador de atribuicao
    System(const System& sys);
    System& operator=(const System& sys);
};

#endif
