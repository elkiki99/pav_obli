#include "Lector.h"

Lector:: Lector() {}

Lector::Lector(int id, string nombre, string pass, int fechaRegistro) : Usuario(id, nombre, pass)
{
    this->fechaRegistro = fechaRegistro;
}

int Lector::getFechaRegistro() {
    return fechaRegistro;
}

void Lector::setFechaRegistro(int fechaRegistro) {
    this->fechaRegistro = fechaRegistro;
}

const set<Prestamo*>& Lector::getPrestamos() {
    return prestamos;
}

void Lector::agregarPrestamo(Prestamo* prestamo) {
    prestamos.insert(prestamo);
}

string Lector::getTipo() {
    return "Lector";
}

Lector::~Lector() {
    for (Prestamo* prestamo : prestamos) {
        delete prestamo;
    }
}
