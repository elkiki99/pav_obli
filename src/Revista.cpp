#include "Revista.h"

Revista::Revista(int id, string titulo, int anioPublicacion, int numeroEdicion, bool publicacionMensual) : Material(id, titulo, anioPublicacion)
{
    this->numeroEdicion = numeroEdicion;
    this->publicacionMensual = publicacionMensual;
}

int Revista::getNumeroEdicion() {
    return numeroEdicion;
}

bool Revista::getPublicacionMensual() {
    return publicacionMensual;
}

string Revista::getTipo() {
    return "Revista";
}
