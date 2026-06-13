#include "Prestamo.h"

Prestamo::Prestamo(DTFecha fechaPrestamo, int cantDiasDev, int puntuacion, Material* material)
    : fechaPrestamo(fechaPrestamo), cantDiasDev(cantDiasDev), puntuacion(puntuacion), material(material)
{
}

DTFecha Prestamo::getFechaPrestamo() {
    return fechaPrestamo;
}

void Prestamo::setFechaPrestamo(DTFecha fechaPrestamo) {
    this->fechaPrestamo = fechaPrestamo;
}

int Prestamo::getCantDiasDev() {
    return cantDiasDev;
}

void Prestamo::setCantDiasDev(int cantDiasDev) {
    this->cantDiasDev = cantDiasDev;
}

int Prestamo::getPuntuacion() {
    return puntuacion;
}

void Prestamo::setPuntuacion(int puntuacion) {
    this->puntuacion = puntuacion;
}

Material* Prestamo::getMaterial() {
    return material;
}

void Prestamo::setMaterial(Material* material) {
    this->material = material;
}

Prestamo::~Prestamo() {
}
