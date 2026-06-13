#include "Usuario.h"

Usuario::Usuario() {}

Usuario::Usuario(int id, string nombre, string pass) {
    this->id = id;
    this->nombre = nombre;
    this->pass = pass;
}

int Usuario::getId() {
    return id;
}

void Usuario::setId(int id) {
    this->id = id;
}

string Usuario::getNombre() {
    return nombre;
}

void Usuario::setNombre(string nombre) {
    this->nombre = nombre;
}

string Usuario::getPass() {
    return pass;
}

void Usuario::setPass(string pass) {
    this->pass = pass;
}

Usuario::~Usuario() {}
