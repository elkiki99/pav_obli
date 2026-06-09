#ifndef REVISTA_H
#define REVISTA_H

#include "Material.h"

class Revista : public Material {
    private:
        int numEdicion;
        bool esMensual;

    public:
        Revista(int id, string titulo, int anioPublicacion, int numEdicion, bool esMensual);

        string getTipo() override;
};

#endif
