#include "ComputadoraDirector.h"

ComputadoraDirector::ComputadoraDirector(
    std::shared_ptr<ComputadoraBuilder> builder
) {
    this->builder = builder;
}

void ComputadoraDirector::setBuilder(
    std::shared_ptr<ComputadoraBuilder> builder
) {
    this->builder = builder;
}

std::shared_ptr<Computadora>
ComputadoraDirector::construirComputadora() {

    builder->construirProcesador();
    builder->construirRAM();
    builder->construirAlmacenamiento();
    builder->construirTarjetaGrafica();

    return builder->getComputadora();
}