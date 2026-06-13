#include "Revista.h"

Revista::Revista() {}

Revista::Revista(int id, string titulo, int anioPublicacion, int numeroEdicion, bool publicacionMensual) : 
         Material(id, titulo, anioPublicacion)
{
    this->numeroEdicion = numeroEdicion;
    this->publicacionMensual = publicacionMensual;
}

int Revista::getNumeroEdicion() {
    return numeroEdicion;
}

void Revista::setNumeroEdicion(int numeroEdicion) {
    this->numeroEdicion = numeroEdicion;
}

bool Revista::getPublicacionMensual() {
    return publicacionMensual;
}

void Revista::setPublicacionMensual(bool publicacionMensual) {
    this->publicacionMensual = publicacionMensual;
}

string Revista::getTipo() {
    return "Revista";
}

// Revista::~Revista() {}


