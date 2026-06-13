#include "Sesion.h"

Sesion* Sesion::instancia = nullptr;

Sesion::Sesion() : usuarioLogueado(nullptr) {}

Sesion::~Sesion() {}

Sesion* Sesion::getInstancia() {
    if (instancia == nullptr) {
        instancia = new Sesion();
    }

    return instancia;
}

void Sesion::login(Usuario* u) {
    usuarioLogueado = u;
}

void Sesion::logout() {
    usuarioLogueado = nullptr;
}

Usuario* Sesion::getUsuarioLogueado() {
    return usuarioLogueado;
}