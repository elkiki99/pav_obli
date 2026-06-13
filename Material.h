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
        Material();
        Material(int id, string titulo, int anioPublicacion);
        
        int getId();
        void setId(int id);

        string getTitulo();
        void setTitulo(string titulo);

        int getAnioPublicacion();
        void setAnioPublicacion(int anioPublicacion);

        virtual string getTipo() = 0;
        virtual ~Material();
    };

#endif
