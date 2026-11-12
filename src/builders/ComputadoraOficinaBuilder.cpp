#include "ComputadoraOficinaBuilder.h"

ComputadoraOficinaBuilder::ComputadoraOficinaBuilder() {
    computadora = std::make_shared<Computadora>();
}

void ComputadoraOficinaBuilder::construirProcesador() {
    computadora->setProcesador("Intel Core i5");
}

void ComputadoraOficinaBuilder::construirRAM() {
    computadora->setRam("16 GB DDR4");
}

void ComputadoraOficinaBuilder::construirAlmacenamiento() {
    computadora->setAlmacenamiento("SSD 512 GB");
}

void ComputadoraOficinaBuilder::construirTarjetaGrafica() {
    computadora->setTarjetaGrafica("Intel UHD Graphics");
}

std::shared_ptr<Computadora> ComputadoraOficinaBuilder::getComputadora() {
    return computadora;
}