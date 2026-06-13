#include "FabricaRegistro.h"
#include "ControladorRegistro.h"

FabricaRegistro* FabricaRegistro::instancia = nullptr;

FabricaRegistro::FabricaRegistro() {}

FabricaRegistro* FabricaRegistro::getInstancia() {
    if (instancia == nullptr)
        instancia = new FabricaRegistro();

    return instancia;
}

IControladorRegistro* FabricaRegistro::getIControladorRegistro() {
    return new ControladorRegistro();
}

FabricaRegistro::~FabricaRegistro() {}