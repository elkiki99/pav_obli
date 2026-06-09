#include "Sesion.h"

Sesion* Sesion::instancia = nullptr;

Sesion::Sesion() {
    usuarioActual = "";
    estaLogueado = false;
}

Sesion::~Sesion() {}

Sesion* Sesion::getInstancia() {
    if (instancia == nullptr) {
        instancia = new Sesion();
    }
    return instancia;
}

void Sesion::iniciarSesion(string& usuario) {
    // aca hay que crear una función de busqueda, si ok then lo que está abajo else sesión sigue vacía
    usuarioActual = usuario;
    estaLogueado = true;
}

void Sesion::cerrarSesion() {
    usuarioActual = "";
    estaLogueado = false;
}

string Sesion::getUsuario() {
    return usuarioActual;
}

bool Sesion::isLogueado() {
    return estaLogueado;
}
