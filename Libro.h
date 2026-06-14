#ifndef LIBRO_H
#define LIBRO_H

#include "Material.h"

class DTMaterial;

class Libro : public Material {
    private:
        string autor;
        int cantidadPaginas;

    public:
        Libro();
        Libro(int id, string titulo, int anioPublicacion, string autor, int cantidadPaginas);

        string getAutor();
        void setAutor(string autor);

        int getCantidadPaginas();
        void setCantidadPaginas(int cantidadPaginas);

        string getTipo() override;
        DTMaterial* toDT() override;
        // ~Libro();
        
};

#endif
