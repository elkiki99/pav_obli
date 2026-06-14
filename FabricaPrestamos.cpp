#include "FabricaPrestamos.h"
#include "ControladorPrestamos.h"

FabricaPrestamos* FabricaPrestamos::instancia = nullptr;

FabricaPrestamos::FabricaPrestamos() {}

FabricaPrestamos* FabricaPrestamos::getInstancia() {
    if (instancia == nullptr)
        instancia = new FabricaPrestamos();

    return instancia;
}

IControladorPrestamos* FabricaPrestamos::getIControladorPrestamos() {
    return new ControladorPrestamos();
}

FabricaPrestamos::~FabricaPrestamos() {}
