# TO ACTIVIDAD 12 - Aplicación del patrón Builder en C++

## 1. Descripción general

Este proyecto implementa el patrón de diseño **Builder** en C++, utilizando como ejemplo la construcción de computadoras con diferentes componentes. El patrón Builder es un patrón creacional que permite crear objetos complejos paso a paso, separando el proceso de construcción de las características específicas de cada instancia.

## 2. Estructura del proyecto

```text
Proyecto/
│
└── src/
    ├── Computadora.h
    ├── Computadora.cpp
    ├── main.cpp
    │
    ├── builders/
    │   ├── ComputadoraBuilder.h
    │   ├── ComputadoraGamerBuilder.h
    │   ├── ComputadoraGamerBuilder.cpp
    │   ├── ComputadoraOficinaBuilder.h
    │   └── ComputadoraOficinaBuilder.cpp
    │
    └── director/
        ├── ComputadoraDirector.h
        └── ComputadoraDirector.cpp
```

## 3. Implementación del patrón Builder

### 3.1. Producto: Computadora

La clase `Computadora` representa el objeto que se desea construir. Contiene los atributos correspondientes al procesador, memoria RAM, almacenamiento y tarjeta gráfica. El cual tiene varios atributos que sería complejo inicializar mediante un constructor, lo cual podria afectar el orden y la legibilidad del código.

**Computadora.h**

```cpp
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
```

**Computadora.cpp**

```cpp
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
```

### 3.2. Builder: ComputadoraBuilder

Es una clase abstracta que define los métodos necesarios para construir cada componente de la computadora y obtener el producto terminado.

**builders/ComputadoraBuilder.h**

```cpp
#ifndef COMPUTADORABUILDER_H
#define COMPUTADORABUILDER_H

#include "../Computadora.h"
#include <memory>

class ComputadoraBuilder {
public:
    virtual ~ComputadoraBuilder() = default;

    virtual void construirProcesador() = 0;
    virtual void construirRAM() = 0;
    virtual void construirAlmacenamiento() = 0;
    virtual void construirTarjetaGrafica() = 0;

    virtual std::shared_ptr<Computadora> getComputadora() = 0;
};

#endif
```

### 3.3. Constructores concretos

Se implementan dos constructores concretos que heredan de `ComputadoraBuilder`. Cada uno establece los componentes correspondientes a su tipo de computadora para poder crear objetos con componentes ya especificados.

**ComputadoraGamerBuilder.h**

```cpp
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
```

**ComputadoraGamerBuilder.cpp**

```cpp
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
```

**ComputadoraOficinaBuilder.h**

```cpp
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
```

**ComputadoraOficinaBuilder.cpp**

```cpp
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
```

### 3.4. Director: ComputadoraDirector

Es el encargado de coordinar el proceso de construcción. Trabaja con la interfaz `ComputadoraBuilder`, por lo que puede utilizar los Builder concretos sin conocer sus implementaciones internas.

**director/ComputadoraDirector.h**

```cpp
#ifndef COMPUTADORADIRECTOR_H
#define COMPUTADORADIRECTOR_H

#include "../builders/ComputadoraBuilder.h"
#include <memory>

class ComputadoraDirector {
private:
    std::shared_ptr<ComputadoraBuilder> builder;

public:
    ComputadoraDirector(
        std::shared_ptr<ComputadoraBuilder> builder
    );

    void setBuilder(
        std::shared_ptr<ComputadoraBuilder> builder
    );

    std::shared_ptr<Computadora> construirComputadora();
};

#endif
```

**director/ComputadoraDirector.cpp**

```cpp
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
```

### 3.5. Programa principal: main.cpp

En el programa principal se demuestra el funcionamiento del patrón Builder mediante la construcción de dos computadoras. Se utiliza el mismo Director, cambiando únicamente el Builder encargado de configurar cada producto.

**main.cpp**

```cpp
#include <iostream>
#include <memory>

#include "Computadora.h"
#include "director/ComputadoraDirector.h"
#include "builders/ComputadoraGamerBuilder.h"
#include "builders/ComputadoraOficinaBuilder.h"

int main() {
    // Construir computadora Gamer
    auto gamerBuilder = std::make_shared<ComputadoraGamerBuilder>();

    ComputadoraDirector director(gamerBuilder);

    std::shared_ptr<Computadora> pcGamer = director.construirComputadora();

    std::cout << "--- COMPUTADORA GAMER ---" << std::endl;
    pcGamer->mostrarEspecificaciones();

    std::cout << "\n";

    // Construir computadora de Oficina
    auto oficinaBuilder = std::make_shared<ComputadoraOficinaBuilder>();

    director.setBuilder(oficinaBuilder);

    std::shared_ptr<Computadora> pcOficina =
        director.construirComputadora();

    std::cout << "--- COMPUTADORA DE OFICINA ---" << std::endl;
    pcOficina->mostrarEspecificaciones();

    return 0;
}
```

## 4. Ejecución del programa

Para compilar y ejecutar el proyecto, se debe abrir una terminal en el directorio principal y ejecutar los siguientes comandos:

**Compilación y ejecución:**

```bash
cd src
g++ main.cpp Computadora.cpp builders/*.cpp director/*.cpp -o main
./main
```

**Salida del programa:**

```bash
--- COMPUTADORA GAMER ---
Procesador: Intel Core i9
RAM: 32 GB DDR5
Almacenamiento: SSD NVMe 2 TB
Tarjeta Gráfica: NVIDIA GeForce RTX 4080

--- COMPUTADORA DE OFICINA ---
Procesador: Intel Core i5
RAM: 16 GB DDR4
Almacenamiento: SSD 512 GB
Tarjeta Gráfica: Intel UHD Graphics
```

La ejecución demuestra la construcción correcta de ambas computadoras, mostrando sus respectivas especificaciones según el Builder seleccionado.