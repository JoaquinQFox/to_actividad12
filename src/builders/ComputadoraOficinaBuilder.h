#ifndef COMPUTADORAOFICINABUILDER_H
#define COMPUTADORAOFICINABUILDER_H

#include "ComputadoraBuilder.h"

class ComputadoraOficinaBuilder : public ComputadoraBuilder {
private:
    std::shared_ptr<Computadora> computadora;

public:
    ComputadoraOficinaBuilder();

    void construirProcesador() override;
    void construirRAM() override;
    void construirAlmacenamiento() override;
    void construirTarjetaGrafica() override;

    std::shared_ptr<Computadora> getComputadora() override;
};

#endif