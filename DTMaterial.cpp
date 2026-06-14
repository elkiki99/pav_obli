#include "DTMaterial.h"

DTMaterial::DTMaterial(int id, string titulo, int anioPublicacion, string tipo)
    : id(id), titulo(titulo), anioPublicacion(anioPublicacion), tipo(tipo) {}

DTMaterial::~DTMaterial() {}

int DTMaterial::getId() { 
    return id; 
}

string DTMaterial::getTitulo() { 
    return titulo; 
}

int DTMaterial::getAnioPublicacion() { 
    return anioPublicacion; 
}

string DTMaterial::getTipo() {
    return tipo;
}

