#include "Lector.h"
#include "DTLector.h"

Lector::Lector(int id, string nombre, string pass, DTFecha fechaRegistro) 
    : Usuario(id, nombre, pass), fechaRegistro(fechaRegistro) {}

DTFecha Lector::getFechaRegistro() {
    return fechaRegistro;
}

void Lector::setFechaRegistro(DTFecha fechaRegistro) {
    this->fechaRegistro = fechaRegistro;
}

set<Prestamo*>& Lector::getPrestamos() {
    return prestamos;
}

void Lector::agregarPrestamo(Prestamo* prestamo) {
    prestamos.insert(prestamo);
}

string Lector::getTipo() {
    return "Lector";
}

DTLector* Lector::toDT() {
    return new DTLector(getId(), getNombre(), getPass(), fechaRegistro);
}

Lector::~Lector() {
    for (Prestamo* prestamo : prestamos) {
        delete prestamo;
    }
}
