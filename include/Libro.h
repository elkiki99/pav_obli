#ifndef LIBRO_H
#define LIBRO_H

#include "Material.h"

class Libro : public Material {
    private:
        string autor;
        int cantPaginas;

    public:
        Libro(int id, string titulo, int anioPublicacion, string autor, int cantPaginas);

        string getTipo() override;
};

#endif
