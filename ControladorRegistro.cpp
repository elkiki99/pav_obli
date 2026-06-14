#include "ControladorRegistro.h"
#include "ManejadorUsuario.h"
#include "Sesion.h"
#include "DTFecha.h"
#include "DTLector.h"
#include "Lector.h"
#include "DTFuncionario.h"
#include "Funcionario.h"
#include <iostream>

using namespace std;

bool ControladorRegistro::ingresarDatos(int id, string pass) {
    Sesion* sesion = Sesion::getInstancia();

    if (sesion->getUsuarioLogueado() != nullptr) {
        return false;
    }

    ManejadorUsuarios* mjus = ManejadorUsuarios::getInstancia();

    if (!mjus->existeUsuario(id)) {
        return false;
    }

    Usuario* usuario = mjus->buscarUsuario(id);

    if (usuario->getPass() != pass) {
        return false;
    }

    usuarioPendiente = usuario;

    return true;
}

void ControladorRegistro::cancelarInicioSesion() {
    usuarioPendiente = nullptr;
}

void ControladorRegistro::confirmarInicioSesion() {
    if (usuarioPendiente != nullptr) {
        Sesion::getInstancia()->login(usuarioPendiente);
        usuarioPendiente = nullptr;
    }
}

void ControladorRegistro::cerrarSesion() {
    Sesion::getInstancia()->logout();
}

DTLector* ControladorRegistro::ingresarLector(int id, string nombre, string pass, DTFecha fechaR) {
    ManejadorUsuarios* mu = ManejadorUsuarios::getInstancia();
    
    if (mu->existeUsuario(id))
        return nullptr;

    this->dtLector = new DTLector(id, nombre, pass, fechaR);

    return this->dtLector;
}

DTFuncionario* ControladorRegistro::ingresarFuncionario(int id, string nombre, string pass, int numEmpleado) {
    ManejadorUsuarios* mu = ManejadorUsuarios::getInstancia();

    if (mu->existeUsuario(id))
        return nullptr;

    this->dtFuncionario = new DTFuncionario(id, nombre, pass, numEmpleado);
    return this->dtFuncionario;
}

void ControladorRegistro::registrarFuncionario() {
    ManejadorUsuarios* mjus = ManejadorUsuarios::getInstancia();

    Usuario* usuario = new Funcionario(
        this->dtFuncionario->getId(),
        this->dtFuncionario->getNombre(),
        this->dtFuncionario->getPass(),
        this->dtFuncionario->getNumEmpleado()
    );

    mjus->agregarUsuario(usuario);

    delete this->dtFuncionario;
    this->dtFuncionario = nullptr;
}

void ControladorRegistro::registrarLector() {
    ManejadorUsuarios* mjus = ManejadorUsuarios::getInstancia();

    Usuario* usuario = new Lector(
        this->dtLector->getId(),
        this->dtLector->getNombre(),
        this->dtLector->getPass(),
        this->dtLector->getFechaRegistro()  // DTFecha directamente
    );

    mjus->agregarUsuario(usuario);
    
    delete this->dtLector;
    this->dtLector = nullptr;
}

void ControladorRegistro::cancelarRegistro() {
    if (this->dtLector != nullptr) {
        delete this->dtLector;
        this->dtLector = nullptr;
    }
    if (this->dtFuncionario != nullptr) {
        delete this->dtFuncionario;
        this->dtFuncionario = nullptr;
    }
}