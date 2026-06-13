#include "ControladorRegistro.h"
#include "ManejadorUsuario.h"
#include "Sesion.h"
#include "DTFecha.h"
#include "DTLector.h"
#include "Lector.h"
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
}

// 2.2
void ControladorRegistro::confirmarInicioSesion() {
    if (usuarioPendiente != nullptr) {
        Sesion::getInstancia()->login(usuarioPendiente);
        usuarioPendiente = nullptr;
    }
}

// Cerrar Sesión (3er caso de uso)
void ControladorRegistro::cerrarSesion() {
    Sesion::getInstancia()->logout();
}

// Registrar Lector (4to caso de uso) 4.1
DTLector* ControladorRegistro::ingresarLector(int id, string nombre, string pass, DTFecha fechaR) {
    this->dtLector = new DTLector(id, nombre, pass, fechaR);
    return this->dtLector;
}

// 4.2
void ControladorRegistro::registrarLector() {
    ManejadorUsuarios* mjus = ManejadorUsuarios::getInstancia();

    // Convert DTFecha to int representation for Lector
    DTFecha fecha = this->dtLector->getFechaRegistro();
    int fechaInt = fecha.getAnio() * 10000 + fecha.getMes() * 100 + fecha.getDia();

    Usuario* usuario = new Lector(
        this->dtLector->getId(),
        this->dtLector->getNombre(),
        this->dtLector->getPass(),
        fechaInt
    );

    mjus->agregarUsuario(usuario);
}

// Cancelar Registro (5to caso de uso)
void ControladorRegistro::cancelarRegistro() {
    delete this->dtLector;
    this->dtLector = nullptr;
}

// funcion auxiliar para validar que no se registre un nuevo usuario con un ID ya existente
bool ControladorRegistro::existeUsuario(int id) {
    ManejadorUsuarios* mjus = ManejadorUsuarios::getInstancia();
    return mjus->existeUsuario(id);
}