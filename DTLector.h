#ifndef DTLECTOR_H
#define DTLECTOR_H

#include <string>
#include "DTFecha.h"

using namespace std;

class DTLector {
    private:
        int id;
        string nombre;
        string pass;
        DTFecha fechaRegistro;

    public:
        DTLector(int id, string nombre, string pass, DTFecha fechaRegistro)
            : id(id), nombre(nombre), pass(pass), fechaRegistro(fechaRegistro) {}

        int getId() const { return id; }
        string getNombre() const { return nombre; }
        string getPass() const { return pass; }
        DTFecha getFechaRegistro() const { return fechaRegistro; }
};

#endif
