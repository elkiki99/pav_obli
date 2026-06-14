#include "FabricaMateriales.h"
#include "ControladorMateriales.h"

FabricaMateriales* FabricaMateriales::instancia = nullptr;

FabricaMateriales::FabricaMateriales() {}

FabricaMateriales* FabricaMateriales::getInstancia() {
    if (instancia == nullptr)
        instancia = new FabricaMateriales();

    return instancia;
}

IControladorMateriales* FabricaMateriales::getIControladorMateriales() {
    return new ControladorMateriales();
}

FabricaMateriales::~FabricaMateriales() {}
