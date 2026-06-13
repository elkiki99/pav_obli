#ifndef FABRICAREGISTRO_H
#define FABRICAREGISTRO_H

#include "IControladorRegistro.h"

class FabricaRegistro {
private:
    static FabricaRegistro* instancia;

    FabricaRegistro();

public:
    static FabricaRegistro* getInstancia();

    IControladorRegistro* getIControladorRegistro();

    ~FabricaRegistro();
};

#endif