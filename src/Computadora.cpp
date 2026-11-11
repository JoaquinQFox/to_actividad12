#include "Computadora.h"
#include <iostream>

void Computadora::setProcesador(const std::string& procesador) {
    this->procesador = procesador;
}

void Computadora::setRam(const std::string& ram) {
    this->ram = ram;
}

void Computadora::setAlmacenamiento(const std::string& almacenamiento) {
    this->almacenamiento = almacenamiento;
}

void Computadora::setTarjetaGrafica(const std::string& tarjetaGrafica) {
    this->tarjetaGrafica = tarjetaGrafica;
}

void Computadora::mostrarEspecificaciones() const {
    std::cout << "Procesador: " << procesador << std::endl;
    std::cout << "RAM: " << ram << std::endl;
    std::cout << "Almacenamiento: " << almacenamiento << std::endl;
    std::cout << "Tarjeta Gráfica: " << tarjetaGrafica << std::endl;
}
