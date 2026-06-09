#include "Prestamo.h"

Prestamo::Prestamo(DTFecha fechaPrestamo, int cantDiasDev, int puntuacion, Material* material)
{
    this->fechaPrestamo = fechaPrestamo;
    this->cantDiasDev = cantDiasDev;
    this->puntuacion = puntuacion;
    this->material = material;
}

DTFecha Prestamo::getFechaPrestamo() {
    return fechaPrestamo;
}

int Prestamo::getCantDiasDev() {
    return cantDiasDev;
}

int Prestamo::getPuntuacion() {
    return puntuacion;
}

Material* Prestamo::getMaterial() {
    return material;
}
