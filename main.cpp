#include <iostream>
#include "FabricaRegistro.h"
#include "IControladorRegistro.h"
#include "DTFecha.h"
#include "DTLector.h"
#include "DTFuncionario.h"
#include "Sesion.h"

using namespace std;

void iniciarSesion();
void registrarFuncionario();
void registrarLector();
void cerrarSesion();
void cancelarRegistro();
// void registrarMaterial();
// void verInformacionMaterial();

int main() {
    int opcion = -1;

    do {
        Usuario* usuarioLogueado = Sesion::getInstancia()->getUsuarioLogueado();

        cout << "\n=== Sistema de Registro ===\n" << endl;

        if (usuarioLogueado == nullptr) {
            cout << "1. Iniciar Sesión" << endl;
        }
        cout << "2. Registrar Funcionario" << endl;
        cout << "3. Registrar Lector" << endl;

        if (usuarioLogueado != nullptr) {
            cout << "4. Cerrar Sesión" << endl;
        }
        
        if (usuarioLogueado != nullptr && usuarioLogueado->getTipo() == "Funcionario") {
            cout << "5. Registrar Material" << endl;
            cout << "6. Ver Información Material" << endl;
        }

        cout << "9. Salir" << endl;
        cout << "Opción: ";
        
        cin >> opcion;

        switch(opcion) {
            case 1: {
                iniciarSesion();
                break;
            }   
            case 2: {
                registrarFuncionario();
                break;
            }
            case 3: {
                registrarLector();
                break;
            }
            case 4: {
                cerrarSesion();
                break;
            }
            case 5: {
                if (usuarioLogueado != nullptr && usuarioLogueado->getTipo() == "Funcionario") {
                    // registrarMaterial();
                    cout << "\nFuncionalidad de registrar material no implementada aún." << endl;
                } else {
                    cout << "\nOpción inválida. Por favor, seleccione una opción válida." << endl;
                }
                break;
            }
            case 6: {
                if (usuarioLogueado != nullptr && usuarioLogueado->getTipo() == "Funcionario") {
                    // verInformacionMaterial();
                    cout << "\nFuncionalidad de ver información de material no implementada aún." << endl;
                } else {
                    cout << "\nOpción inválida. Por favor, seleccione una opción válida." << endl;
                }
                break;
            }
            case 9: {
                cout << "\nSaliendo del sistema..." << endl;
                break;
            }
            default: {
                cout << "\nOpción inválida. Por favor, seleccione una opción válida." << endl;
                break;
            }
        }
    } while(opcion != 9);

}

void iniciarSesion() {
    if(Sesion::getInstancia()->getUsuarioLogueado() != nullptr) {
        cout << "\nYa hay una sesión activa. Por favor, cierre la sesión actual antes de iniciar una nueva." << endl;
        return;
    }

    int id;
    string pass;

    cout << "\nIngrese ID (cédula): ";
    cin >> id;
    cout << "\nIngrese Contraseña: ";
    cin >> pass;

    IControladorRegistro* ctrlReg = FabricaRegistro::getInstancia()->getIControladorRegistro();

    if (ctrlReg->ingresarDatos(id, pass)) { // devuelve true si son válidos los datos ingresados
        // Mostrar datos del usuario antes de confirmar
        cout << "\n=== Confirmar Inicio de Sesión ===\n" << endl;
        cout << "ID (cédula): " << id << endl;
        
        int opcionConfirmar = -1;

        cout << "\n1. Confirmar Inicio de Sesión" << endl;
        cout << "2. Cancelar Inicio de Sesión" << endl;
        cout << "Opción: ";

        cin >> opcionConfirmar;

        while(opcionConfirmar != 1 && opcionConfirmar != 2) {
            cout << "\nOpción inválida. Por favor, ingrese 1 para confirmar o 2 para cancelar." << endl;
            cout << "Opción: ";
            cin >> opcionConfirmar;
        }
        
        if (opcionConfirmar == 1) {
            ctrlReg->confirmarInicioSesion();
            // cout << "\nInicio de sesión exitoso" << endl;
            cout << "\nBienvenid@, " << Sesion::getInstancia()->getUsuarioLogueado()->getNombre() << "!" << endl;
        } else if(opcionConfirmar == 2) {
            ctrlReg->cancelarInicioSesion();
            cout << "\nInicio de sesión cancelado" << endl;
        }
    } else {
        cout << "\nError al iniciar sesión: Datos incorrectos" << endl;
        ctrlReg->cancelarInicioSesion();
    }
}

void registrarFuncionario() {
    int id, numEmpleado;
    string nombre, pass;

    cout << "\nIngrese ID (cédula): ";
    cin >> id;
    cout << "\nIngrese Nombre: ";
    cin >> nombre;
    cout << "\nIngrese Contraseña: ";
    cin >> pass;
    cout << "\nIngrese Número de Empleado: ";
    cin >> numEmpleado;

    IControladorRegistro* ctrlReg = FabricaRegistro::getInstancia()->getIControladorRegistro();
    DTFuncionario* dtFuncionario = ctrlReg->ingresarFuncionario(id, nombre, pass, numEmpleado);

    if (dtFuncionario == nullptr) {
        cout << "\nError: Ya existe un usuario registrado con ese ID." << endl;
        return;
    }

    // Mostrar datos del funcionario antes de registrar
    cout << "\n=== Confirmar Registro de Funcionario ===\n" << endl;
    cout << "ID (cédula): " << dtFuncionario->getId() << endl;
    cout << "Nombre: " << dtFuncionario->getNombre() << endl;
    cout << "Contraseña: " << dtFuncionario->getPass() << endl;
    cout << "Número de Empleado: " << dtFuncionario->getNumEmpleado() << endl;

    int opcionConfirmar = -1;

    cout << "\n1. Confirmar Registro" << endl;
    cout << "2. Cancelar Registro" << endl;
    cout << "Opción: ";

    cin >> opcionConfirmar;

    while(opcionConfirmar != 1 && opcionConfirmar != 2) {
        cout << "\nOpción inválida. Por favor, ingrese 1 para confirmar o 2 para cancelar." << endl;
        cout << "Opción: ";
        cin >> opcionConfirmar;
    }
    
    if (opcionConfirmar == 1) {
        ctrlReg->registrarFuncionario();
        cout << "\nFuncionario registrado exitosamente" << endl;
    } else if (opcionConfirmar == 2) {
        ctrlReg->cancelarRegistro();
        cout << "\nRegistro cancelado" << endl;
    }
}

void registrarLector() {
    int id, dia, mes, anio;
    string nombre, pass;

    cout << "\nIngrese ID (cédula): ";
    cin >> id;
    cout << "\nIngrese Nombre: ";
    cin >> nombre;
    cout << "\nIngrese Contraseña: ";
    cin >> pass;
    cout << "\nIngrese Fecha de Registro (dd mm aaaa): ";
    cin >> dia >> mes >> anio;

    DTFecha fechaRegistro(dia, mes, anio);

    IControladorRegistro* ctrlReg = FabricaRegistro::getInstancia()->getIControladorRegistro();
    DTLector* dtLector = ctrlReg->ingresarLector(id, nombre, pass, fechaRegistro);
    
    if (dtLector == nullptr) {
        cout << "\nError: Ya existe un usuario registrado con ese ID." << endl;
        return;
    }

    // Mostrar datos del lector antes de registrar
    cout << "\n=== Confirmar Registro de Lector ===\n" << endl;
    cout << "ID (cédula): " << dtLector->getId() << endl;
    cout << "Nombre: " << dtLector->getNombre() << endl;
    cout << "Contraseña: " << dtLector->getPass() << endl;
    DTFecha fecha = dtLector->getFechaRegistro();
    cout << "Fecha de Registro: " << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio() << endl;

    int opcionConfirmar = -1;

    cout << "\n1. Confirmar Registro" << endl;
    cout << "2. Cancelar Registro" << endl;
    cout << "Opción: ";

    cin >> opcionConfirmar;

    while(opcionConfirmar != 1 && opcionConfirmar != 2) {
        cout << "\nOpción inválida. Por favor, ingrese 1 para confirmar o 2 para cancelar." << endl;
        cout << "Opción: ";
        cin >> opcionConfirmar;
    }
    
    if (opcionConfirmar == 1) {
        ctrlReg->registrarLector();
        cout << "\nLector registrado exitosamente" << endl;
    } else if (opcionConfirmar == 2) {
        ctrlReg->cancelarRegistro();
        cout << "\nRegistro cancelado" << endl;
    }
}

void cerrarSesion() {
    if(Sesion::getInstancia()->getUsuarioLogueado() == nullptr) {
        cout << "\nNo hay una sesión activa para cerrar." << endl;
        return;
    }
    IControladorRegistro* ctrlReg = FabricaRegistro::getInstancia()->getIControladorRegistro();
    ctrlReg->cerrarSesion();
    cout << "\nSesión cerrada" << endl;
}

void cancelarRegistro() {
    IControladorRegistro* ctrlReg = FabricaRegistro::getInstancia()->getIControladorRegistro();
    ctrlReg->cancelarRegistro();
    cout << "\nRegistro cancelado" << endl;
}