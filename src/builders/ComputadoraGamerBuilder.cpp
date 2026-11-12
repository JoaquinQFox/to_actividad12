#include "ComputadoraGamerBuilder.h"

ComputadoraGamerBuilder::ComputadoraGamerBuilder() {
    computadora = std::make_shared<Computadora>();
}

void ComputadoraGamerBuilder::construirProcesador() {
    computadora->setProcesador("Intel Core i9");
}

void ComputadoraGamerBuilder::construirRAM() {
    computadora->setRam("32 GB DDR5");
}

void ComputadoraGamerBuilder::construirAlmacenamiento() {
    computadora->setAlmacenamiento("SSD NVMe 2 TB");
}

void ComputadoraGamerBuilder::construirTarjetaGrafica() {
    computadora->setTarjetaGrafica("NVIDIA GeForce RTX 4080");
}

std::shared_ptr<Computadora> ComputadoraGamerBuilder::getComputadora() {
    return computadora;
}