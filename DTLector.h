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
        DTLector(int id, string nombre, string pass, DTFecha fechaRegistro);

        int getId();

        string getNombre();

        string getPass();

        DTFecha getFechaRegistro();
};

#endif
