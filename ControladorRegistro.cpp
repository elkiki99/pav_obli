#include "ControladorRegistro.h"
#include "Sesion.h"
#include "ManejadorUsuario.h"
#include <iostream>

using namespace std;

// Iniciar Sesión (1er caso de uso)
bool ControladorRegistro::ingresarDatos(int id, string pass) {
    Sesion* sesion = Sesion::getInstancia();

    if (sesion->getUsuarioLogueado() != nullptr) { // si hay una sesión activa
        return false;
    }

    ManejadorUsuarios* mjus = ManejadorUsuarios::getInstancia();

    if (!mjus->existeUsuario(id)) { // si el usuario no existe
        return false;
    }

    Usuario* usuario = mjus->buscarUsuario(id);

    if (usuario->getPass() != pass) { // si la contraseña no coincide
        return false;
    }

    usuarioPendiente = usuario;

    return true;
}

// Cancelar Inicio de Sesión (2do caso de uso) 2.1
void ControladorRegistro::cancelarInicioSesion() {
    usuarioPendiente = nullptr;
    cout << "Inicio de sesión cancelado" << endl;
}

// 2.2
void ControladorRegistro::confirmarInicioSesion() {
    Sesion::getInstancia()->login(usuarioPendiente);
    usuarioPendiente = nullptr;
}

// Cerrar Sesión (3er caso de uso)
void ControladorRegistro::cerrarSesion() {
    Sesion::getInstancia()->logout();
}