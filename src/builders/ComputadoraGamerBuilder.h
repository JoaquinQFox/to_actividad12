#ifndef COMPUTADORAGAMERBUILDER_H
#define COMPUTADORAGAMERBUILDER_H

#include "ComputadoraBuilder.h"

class ComputadoraGamerBuilder : public ComputadoraBuilder {
private:
    std::shared_ptr<Computadora> computadora;

public:
    ComputadoraGamerBuilder();

    void construirProcesador() override;
    void construirRAM() override;
    void construirAlmacenamiento() override;
    void construirTarjetaGrafica() override;

    std::shared_ptr<Computadora> getComputadora() override;
};

#endif