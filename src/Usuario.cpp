#include "Usuario.h"

Usuario::Usuario(int id, string nombre, string pass) {
    this->id = id;
    this->nombre = nombre;
    this->pass = pass;
}

Usuario::~Usuario() {}

int Usuario::getId() {
    return id;
}

string Usuario::getNombre() {
    return nombre;
}

string Usuario::getPass() {
    return pass;
}
