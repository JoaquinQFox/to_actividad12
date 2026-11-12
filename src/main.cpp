#include <iostream>
#include <memory>
#include "Computadora.h"
#include "builders/ComputadoraBuilder.h"

class PruebaBuilder : public ComputadoraBuilder {
private:
    std::shared_ptr<Computadora> computadora;

public:
    PruebaBuilder() {
        computadora = std::make_shared<Computadora>();
    }

    void construirProcesador() override {
        computadora->setProcesador("Intel Core i5-12400F");
    }

    void construirRAM() override {
        computadora->setRam("16 GB DDR4");
    }

    void construirAlmacenamiento() override {
        computadora->setAlmacenamiento("SSD 512 GB NVMe");
    }

    void construirTarjetaGrafica() override {
        computadora->setTarjetaGrafica("NVIDIA GTX 1650");
    }

    std::shared_ptr<Computadora> getComputadora() override {
        return computadora;
    }
};

int main() {
    std::cout << "=== PRUEBA DE LA INTERFAZ COMPUTADORABUILDER ===" << std::endl;

    std::unique_ptr<ComputadoraBuilder> builder = std::make_unique<PruebaBuilder>();

    builder->construirProcesador();
    builder->construirRAM();
    builder->construirAlmacenamiento();
    builder->construirTarjetaGrafica();

    std::shared_ptr<Computadora> pc = builder->getComputadora();
    pc->mostrarEspecificaciones();

    return 0;
}
