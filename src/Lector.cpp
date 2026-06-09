#include "Lector.h"

Lector::Lector(int id, string nombre, string pass, int fechaRegistro) : Usuario(id, nombre, pass)
{
    this->fechaRegistro = fechaRegistro;
}

int Lector::getFechaRegistro() {
    return fechaRegistro;
}

set<Prestamo*> Lector::getPrestamos() {
    return prestamos;
}

void Lector::agregarPrestamo(Prestamo* prestamo) {
    prestamos.insert(prestamo);
}

string Lector::getTipo() {
    return "Lector";
}
