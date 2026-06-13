#ifndef ICONTROLADORREGISTRO_H
#define ICONTROLADORREGISTRO_H

#include <string>

using namespace std;

class IControladorRegistro {
    public:
        virtual bool ingresarDatos(int id, string pass) = 0;
        virtual void confirmarInicioSesion() = 0;
        virtual void cancelarInicioSesion() = 0;

        virtual void cerrarSesion() = 0;
};

#endif