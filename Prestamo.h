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
        Prestamo();
        Prestamo(DTFecha fechaPrestamo, int cantDiasDev, int puntuacion, Material* material);

        DTFecha getFechaPrestamo();
        void setFechaPrestamo(DTFecha fechaPrestamo);

        int getCantDiasDev();
        void setCantDiasDev(int cantDiasDev);

        int getPuntuacion();
        void setPuntuacion(int puntuacion);

        Material* getMaterial();
        void setMaterial(Material* material);
        ~Prestamo();
};

#endif
