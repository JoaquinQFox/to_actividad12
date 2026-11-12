#include <iostream>
#include <memory>
#include "Computadora.h"
#include "director/ComputadoraDirector.h"
#include "builders/ComputadoraGamerBuilder.h"
#include "builders/ComputadoraOficinaBuilder.h"

int main() {
    // Construir Computadora Gamer
    auto gamerBuilder = std::make_shared<ComputadoraGamerBuilder>();
    ComputadoraDirector director(gamerBuilder);

    std::shared_ptr<Computadora> pcGamer =
        director.construirComputadora();

    std::cout << "--- COMPUTADORA GAMER ---" << std::endl;
    pcGamer->mostrarEspecificaciones();

    std::cout << "\n";

    // Construir Computadora de Oficina
    auto oficinaBuilder = std::make_shared<ComputadoraOficinaBuilder>();
    director.setBuilder(oficinaBuilder);

    std::shared_ptr<Computadora> pcOficina =
        director.construirComputadora();

    std::cout << "--- COMPUTADORA DE OFICINA ---" << std::endl;
    pcOficina->mostrarEspecificaciones();

    return 0;
}