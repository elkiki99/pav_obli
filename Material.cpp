#include "Material.h"

Material::Material() {}

Material::Material(int id, string titulo, int anioPublicacion) {
    this->id = id;
    this->titulo = titulo;
    this->anioPublicacion = anioPublicacion;
}

int Material::getId() {
    return id;
}

void Material::setId(int id) {
    this->id = id;
}

string Material::getTitulo() {
    return titulo;
}

void Material::setTitulo(string titulo) {
    this->titulo = titulo;
}

int Material::getAnioPublicacion() {
    return anioPublicacion;
}

void Material::setAnioPublicacion(int anioPublicacion) {
    this->anioPublicacion = anioPublicacion;
}

Material::~Material() {}