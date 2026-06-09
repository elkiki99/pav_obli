#ifndef PRESTAMO_H
#define PRESTAMO_H

#include "DTFecha.h"
#include "Material.h"

class Prestamo {
    private:
        DTFecha fechaPrestamo;
        int cantDiasDev;
        int puntuacion;
        Material* material;

    public:
        Prestamo(DTFecha fechaPrestamo, int cantDiasDev, int puntuacion, Material* material);

        DTFecha getFechaPrestamo();
        int getCantDiasDev();
        int getPuntuacion();
        Material* getMaterial();
};

#endif
