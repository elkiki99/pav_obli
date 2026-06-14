#ifndef FABRICAMATERIALES_H
#define FABRICAMATERIALES_H

#include "IControladorMateriales.h"

class FabricaMateriales {
private:
    static FabricaMateriales* instancia;
    
    FabricaMateriales();

public:
    static FabricaMateriales* getInstancia();

    IControladorMateriales* getIControladorMateriales();

    ~FabricaMateriales();
};

#endif
