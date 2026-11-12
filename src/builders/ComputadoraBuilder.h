#ifndef COMPUTADORABUILDER_H
#define COMPUTADORABUILDER_H

#include "../Computadora.h"
#include <memory>

class ComputadoraBuilder {
public:
    virtual ~ComputadoraBuilder() = default;

    // métodos para construir las distintas partes
    virtual void construirProcesador() = 0;
    virtual void construirRAM() = 0;
    virtual void construirAlmacenamiento() = 0;
    virtual void construirTarjetaGrafica() = 0;

    // método para obtener el producto terminado
    virtual std::shared_ptr<Computadora> getComputadora() = 0;
};

#endif
