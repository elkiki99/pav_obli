#include "DTPrestamo.h"

DTPrestamo::DTPrestamo(int codigoMaterial, string titulo, DTFecha fechaPrestamo, int cantDias)
    : codigoMaterial(codigoMaterial), titulo(titulo), fechaPrestamo(fechaPrestamo), cantDias(cantDias) {}

int DTPrestamo::getCodigoMaterial() const { 
    return codigoMaterial; 
}

string DTPrestamo::getTitulo() const { 
    return titulo; 
}

DTFecha DTPrestamo::getFechaPrestamo() const { 
    return fechaPrestamo; 
}

int DTPrestamo::getCantDias() const { 
    return cantDias; 
}

bool DTPrestamo::operator<(const DTPrestamo& other) const {
    return codigoMaterial < other.codigoMaterial;
}