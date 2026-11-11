#ifndef COMPUTADORA_H
#define COMPUTADORA_H

#include <string>

class Computadora {
private:
    std::string procesador;
    std::string ram;
    std::string almacenamiento;
    std::string tarjetaGrafica;

public:
    void setProcesador(const std::string& procesador);
    void setRam(const std::string& ram);
    void setAlmacenamiento(const std::string& almacenamiento);
    void setTarjetaGrafica(const std::string& tarjetaGrafica);

    void mostrarEspecificaciones() const;
};

#endif
