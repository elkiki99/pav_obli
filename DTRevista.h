#ifndef DTREVISTA_H
#define DTREVISTA_H

#include "DTMaterial.h"

class DTRevista : public DTMaterial {
private:
    int numeroEdicion;
    bool publicacionMensual;

public:
    DTRevista(int id, string titulo, int anioPublicacion, int numeroEdicion, bool publicacionMensual);
    ~DTRevista();

    int getNumeroEdicion();
    bool getPublicacionMensual();
    string getTipo();
};

#endif
