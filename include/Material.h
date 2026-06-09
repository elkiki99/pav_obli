#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>

using namespace std;

class Material {
    protected:
        int id;
        string titulo;
        int anioPublicacion;

    public:
        Material(int id, string titulo, int anioPublicacion);
        virtual ~Material();

        int getId();
        string getTitulo();
        int getAnioPublicacion();

        virtual string getTipo() = 0;
};

#endif
