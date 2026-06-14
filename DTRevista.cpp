#include "DTRevista.h"

DTRevista::DTRevista(int id, string titulo, int anioPublicacion, int numeroEdicion, bool publicacionMensual)
    : DTMaterial(id, titulo, anioPublicacion, "Revista"), numeroEdicion(numeroEdicion), publicacionMensual(publicacionMensual) {}

DTRevista::~DTRevista() {}

int DTRevista::getNumeroEdicion() { 
    return numeroEdicion; 
}
bool DTRevista::getPublicacionMensual() { 
    return publicacionMensual; 
}
string DTRevista::getTipo() { 
    return "Revista"; 
}
