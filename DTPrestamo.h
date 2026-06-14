#ifndef DTPRESTAMO_H
#define DTPRESTAMO_H

#include <string>
#include "DTFecha.h"

using namespace std;

class DTPrestamo {
    private:
        int codigoMaterial;
        string titulo;
        DTFecha fechaPrestamo;
        int cantDias;

    public:
        DTPrestamo(int codigoMaterial, string titulo, DTFecha fechaPrestamo, int cantDias);

        int getCodigoMaterial() const;
        string getTitulo() const; 
        DTFecha getFechaPrestamo() const; 
        int getCantDias() const; 

        bool operator<(const DTPrestamo& other) const;
};

#endif
