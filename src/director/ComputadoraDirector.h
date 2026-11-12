#ifndef COMPUTADORADIRECTOR_H
#define COMPUTADORADIRECTOR_H

#include "../builders/ComputadoraBuilder.h"
#include <memory>

class ComputadoraDirector {
private:
    std::shared_ptr<ComputadoraBuilder> builder;

public:
    ComputadoraDirector(
        std::shared_ptr<ComputadoraBuilder> builder
    );

    void setBuilder(
        std::shared_ptr<ComputadoraBuilder> builder
    );

    std::shared_ptr<Computadora> construirComputadora();
};

#endif