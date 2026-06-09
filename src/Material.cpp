#include "Material.h"

Material::Material(int id, string titulo, int anioPublicacion) {
    this->id = id;
    this->titulo = titulo;
    this->anioPublicacion = anioPublicacion;
}

Material::~Material() {}

int Material::getId() {
    return id;
}

string Material::getTitulo() {
    return titulo;
}

int Material::getAnioPublicacion() {
    return anioPublicacion;
}
