#ifndef REVISTA_H
#define REVISTA_H

#include "Material.h"

class DTMaterial;

class Revista : public Material {
    private:
        int numeroEdicion;
        bool publicacionMensual;

    public:
        Revista();
        Revista(int id, string titulo, int anioPublicacion, int numEdicion, bool esMensual);

        int getNumeroEdicion();
        void setNumeroEdicion(int numeroEdicion);

        bool getPublicacionMensual();
        void setPublicacionMensual(bool publicacionMensual);

        string getTipo() override;
        DTMaterial* toDT() override;
        // ~Revista();
};

#endif
