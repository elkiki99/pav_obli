#ifndef FABRICAPRESTAMOS_H
#define FABRICAPRESTAMOS_H

#include "IControladorPrestamos.h"

class FabricaPrestamos {
private:
    static FabricaPrestamos* instancia;
    
    FabricaPrestamos();

public:
    static FabricaPrestamos* getInstancia();

    IControladorPrestamos* getIControladorPrestamos();

    ~FabricaPrestamos();
};

#endif
