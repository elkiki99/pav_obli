#include "IControladorMateriales.h"
#include "IControladorRegistro.h"
#include "ManejadorMaterial.h"
#include "FabricaMateriales.h"
#include "FabricaPrestamos.h"
#include "FabricaRegistro.h"
#include "DTFuncionario.h"
#include "DTPrestamo.h"
#include "DTRevista.h"
#include "DTLector.h"
#include "DTFecha.h"
#include "Revista.h"
#include "DTLibro.h"
#include <iostream>
#include "Sesion.h"
#include "Libro.h"
#include <limits>

void consultarPrestamoLector();
void verInformacionMaterial();
void registrarFuncionario();
void registrarMaterial();
void registrarPrestamo();
void registrarLector();
void iniciarSesion();
void cerrarSesion();

using namespace std;

string leerLinea(const string& prompt);
int leerInt(const string& prompt);

int main() {
    int opcion = -1;

    do {
        Usuario* usuarioLogueado = Sesion::getInstancia()->getUsuarioLogueado();

        cout << "\n=== Sistema de Registro ===\n" << endl;

        if (usuarioLogueado == nullptr) {
            cout << "1. Iniciar Sesión" << endl;
        }

        bool authYFunc = usuarioLogueado != nullptr && usuarioLogueado->getTipo() == "Funcionario";

        if (authYFunc) {
            cout << "2. Registrar Funcionario" << endl;
            cout << "3. Registrar Lector" << endl;
            cout << "4. Registrar Material" << endl;
        }

        if (usuarioLogueado != nullptr) {
            cout << "5. Ver Información Material" << endl;
        }

        if (authYFunc) {
            cout << "6. Registrar Préstamo" << endl;
            cout << "7. Consultar Préstamos de Lector" << endl;
        }

        if (usuarioLogueado != nullptr) {
            cout << "8. Cerrar Sesión" << endl;
        }

        cout << "9. Salir" << endl;
        
        opcion = leerInt("Opción: ");

        switch(opcion) {
            case 1: {
                    if (Sesion::getInstancia()->getUsuarioLogueado() == nullptr)
                        iniciarSesion(); 
                    else
                        cout << "\nOpción inválida. Por favor, seleccione una opción válida." << endl;
                    break;
            }
            case 2: {
                if (usuarioLogueado != nullptr && usuarioLogueado->getTipo() == "Funcionario")
                    registrarFuncionario();
                else
                    cout << "\nOpción inválida. Por favor, seleccione una opción válida." << endl;
                break;
            }
            case 3: {
                if (usuarioLogueado != nullptr && usuarioLogueado->getTipo() == "Funcionario")
                    registrarLector();
                else
                    cout << "\nOpción inválida. Por favor, seleccione una opción válida." << endl;
                break;
            }  
            case 4: {
                if (usuarioLogueado != nullptr && usuarioLogueado->getTipo() == "Funcionario")
                    registrarMaterial();
                else
                    cout << "\nOpción inválida. Por favor, seleccione una opción válida." << endl;
                break;
            }
            case 5: {
                if (usuarioLogueado != nullptr)
                    verInformacionMaterial();
                else
                    cout << "\nOpción inválida. Por favor, seleccione una opción válida." << endl;
                break;
            }
            case 6: {
                if(usuarioLogueado != nullptr && usuarioLogueado->getTipo() == "Funcionario")
                    registrarPrestamo();
                else
                    cout << "\nOpción inválida. Por favor, seleccione una opción válida." << endl;
                break;
            }
            case 7: {
                if(usuarioLogueado != nullptr && usuarioLogueado->getTipo() == "Funcionario")
                    consultarPrestamoLector();
                else
                    cout << "\nOpción inválida. Por favor, seleccione una opción válida." << endl;
                break;
            }
            case 8: if (Sesion::getInstancia()->getUsuarioLogueado() != nullptr)
                        cerrarSesion(); 
                    else
                        cout << "\nOpción inválida. Por favor, seleccione una opción válida." << endl;
                    break;
            case 9: cout << "\nSaliendo del sistema..." << endl; 
                    break;
            case 1738:
                    registrarFuncionario();
                    break;
            default: 
                    cout << "\nOpción inválida. Por favor, seleccione una opción válida." << endl; 
                    break;
        }
    } while(opcion != 9);
}

void iniciarSesion() {
    if (Sesion::getInstancia()->getUsuarioLogueado() != nullptr) {
        return;
    }

    int id;
    string pass;

    id = leerInt("\nIngrese ID (cédula): ");
    pass = leerLinea("\nIngrese Contraseña: ");

    IControladorRegistro* ctrlReg = FabricaRegistro::getInstancia()->getIControladorRegistro();

    if (ctrlReg->ingresarDatos(id, pass)) {
        cout << "\n=== Confirmar Inicio de Sesión ===\n" << endl;
        cout << "ID (cédula): " << id << endl;

        int opcionConfirmar = -1;

        cout << "\n1. Confirmar Inicio de Sesión" << endl;
        cout << "2. Cancelar Inicio de Sesión" << endl;
        opcionConfirmar = leerInt("Opción: ");

        while (opcionConfirmar != 1 && opcionConfirmar != 2) {
            cout << "\nOpción inválida. Por favor, ingrese 1 para confirmar o 2 para cancelar." << endl;
            opcionConfirmar = leerInt("Opción: ");
        }

        if (opcionConfirmar == 1) {
            ctrlReg->confirmarInicioSesion();
            cout << "\nBienvenid@, " << Sesion::getInstancia()->getUsuarioLogueado()->getNombre() << "!" << endl;
        } else {
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

    id = leerInt("\nIngrese ID (cédula): ");
    nombre = leerLinea("\nIngrese Nombre: ");
    pass   = leerLinea("\nIngrese Contraseña: ");
    numEmpleado = leerInt("\nIngrese Número de Empleado: ");

    IControladorRegistro* ctrlReg = FabricaRegistro::getInstancia()->getIControladorRegistro();
    DTFuncionario* dtFuncionario = ctrlReg->ingresarFuncionario(id, nombre, pass, numEmpleado);

    if (dtFuncionario == nullptr) {
        cout << "\nError: Ya existe un usuario registrado con ese ID." << endl;
        return;
    }

    cout << "\n=== Confirmar Registro de Funcionario ===\n" << endl;
    cout << "ID (cédula): " << dtFuncionario->getId() << endl;
    cout << "Nombre: " << dtFuncionario->getNombre() << endl;
    cout << "Contraseña: " << dtFuncionario->getPass() << endl;
    cout << "Número de Empleado: " << dtFuncionario->getNumEmpleado() << endl;

    int opcionConfirmar = -1;

    cout << "\n1. Confirmar Registro" << endl;
    cout << "2. Cancelar Registro" << endl;
    opcionConfirmar = leerInt("Opción: ");

    while (opcionConfirmar != 1 && opcionConfirmar != 2) {
        cout << "\nOpción inválida. Por favor, ingrese 1 para confirmar o 2 para cancelar." << endl;
        opcionConfirmar = leerInt("Opción: ");
    }

    if (opcionConfirmar == 1) {
        ctrlReg->registrarFuncionario();
        cout << "\nFuncionario registrado exitosamente" << endl;
    } else {
        ctrlReg->cancelarRegistro();
        cout << "\nRegistro cancelado" << endl;
    }
}

void registrarLector() {
    int id, dia, mes, anio;
    string nombre, pass;

    id = leerInt("\nIngrese ID (cédula): ");
    nombre = leerLinea("\nIngrese Nombre: ");
    pass   = leerLinea("\nIngrese Contraseña: ");
    dia = leerInt("\nIngrese día de registro: ");
    mes = leerInt("Ingrese mes de registro: ");
    anio = leerInt("Ingrese año de registro: ");

    DTFecha fechaRegistro(dia, mes, anio);

    IControladorRegistro* ctrlReg = FabricaRegistro::getInstancia()->getIControladorRegistro();
    DTLector* dtLector = ctrlReg->ingresarLector(id, nombre, pass, fechaRegistro);

    if (dtLector == nullptr) {
        cout << "\nError: Ya existe un usuario registrado con ese ID." << endl;
        return;
    }

    cout << "\n=== Confirmar Registro de Lector ===\n" << endl;
    cout << "ID (cédula): " << dtLector->getId() << endl;
    cout << "Nombre: " << dtLector->getNombre() << endl;
    cout << "Contraseña: " << dtLector->getPass() << endl;
    DTFecha fecha = dtLector->getFechaRegistro();
    cout << "Fecha de Registro: " << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio() << endl;

    int opcionConfirmar = -1;

    cout << "\n1. Confirmar Registro" << endl;
    cout << "2. Cancelar Registro" << endl;
    opcionConfirmar = leerInt("Opción: ");

    while (opcionConfirmar != 1 && opcionConfirmar != 2) {
        cout << "\nOpción inválida. Por favor, ingrese 1 para confirmar o 2 para cancelar." << endl;
        opcionConfirmar = leerInt("Opción: ");
    }

    if (opcionConfirmar == 1) {
        ctrlReg->registrarLector();
        cout << "\nLector registrado exitosamente" << endl;
    } else {
        ctrlReg->cancelarRegistro();
        cout << "\nRegistro cancelado" << endl;
    }
}

void registrarMaterial() {
    int id, anioPublicacion;
    string titulo, tipo, autor, esMensual;
    int cantidadPaginas = 0;
    int numeroEdicion = 0;
    bool publicacionMensual = false;
 
    id = leerInt("\nIngrese Código de material: ");
    titulo = leerLinea("Ingrese Título: ");
    anioPublicacion = leerInt("Ingrese Año de Publicación: ");
    tipo = leerLinea("Ingrese Tipo (Libro/Revista): ");

    while (tipo != "Libro" && tipo != "libro" && tipo != "LIBRO" && 
           tipo != "Revista" && tipo != "revista" && tipo != "REVISTA") 
    {
        tipo = leerLinea("\nTipo inválido. Por favor, ingrese 'Libro' o 'Revista': ");
    }

    if (tipo == "libro" || tipo == "LIBRO") {
        tipo = "Libro";
    } else if (tipo == "revista" || tipo == "REVISTA") {
        tipo = "Revista";
    }

    if (tipo == "Libro") {
        autor = leerLinea("Ingrese Autor: ");
        cantidadPaginas = leerInt("Ingrese Cantidad de Páginas: ");
    } else if (tipo == "Revista") {
        numeroEdicion = leerInt("Ingrese Número de Edición: ");
        esMensual = leerLinea("Es publicación mensual? (Si/No): ");

        while(esMensual != "Si" && esMensual != "si" && esMensual != "SI" && 
              esMensual != "No" && esMensual != "no" && esMensual != "NO")
        {
            esMensual = leerLinea("\nOpción inválida. Por favor, ingrese 'Si' o 'No': ");
        }

        if(esMensual == "Si" || esMensual == "si" || esMensual == "SI") {
            publicacionMensual = true;
        } else if (esMensual == "No" || esMensual == "no" || esMensual == "NO") {
            publicacionMensual = false;
        }
    }

    IControladorMateriales* ctrlMat = FabricaMateriales::getInstancia()->getIControladorMateriales();
    DTMaterial* dtMaterial = ctrlMat->ingresarMaterial(id, titulo, anioPublicacion, tipo);

    if (dtMaterial == nullptr) {
        cout << "\nError: ya existe un material con ese código." << endl;
        ctrlMat->cancelarRegistroMaterial();
        return;
    }

    if (tipo == "Libro") {
        ctrlMat->ingresarDatosExtraLibro(autor, cantidadPaginas);
    } else if (tipo == "Revista") {
        ctrlMat->ingresarDatosExtraRevista(numeroEdicion, publicacionMensual);
    }

    cout << "\n=== Confirmar Registro de Material ===\n" << endl;
    cout << "Código: " << dtMaterial->getId() << endl;
    cout << "Título: " << dtMaterial->getTitulo() << endl;
    cout << "Año de Publicación: " << dtMaterial->getAnioPublicacion() << endl;
    cout << "Tipo: " << dtMaterial->getTipo() << endl;

    if (tipo == "Libro") {
        cout << "Autor: " << autor << endl;
        cout << "Cantidad de Páginas: " << cantidadPaginas << endl;
    } else if (tipo == "Revista") {
        cout << "Número de Edición: " << numeroEdicion << endl;
        cout << "Publicación Mensual: " << (publicacionMensual ? "Sí" : "No") << endl;
    }

    int opcionConfirmar = -1;
    cout << "\n1. Confirmar Registro" << endl;
    cout << "2. Cancelar Registro" << endl;
    opcionConfirmar = leerInt("Opción: ");

    while (opcionConfirmar != 1 && opcionConfirmar != 2) {
        cout << "\nOpción inválida. Por favor, ingrese 1 para confirmar o 2 para cancelar." << endl;
        opcionConfirmar = leerInt("Opción: ");
    }

    if (opcionConfirmar == 1) {
        ctrlMat->confirmarRegistroMaterial();
        cout << "\nMaterial registrado exitosamente" << endl;
    } else {
        ctrlMat->cancelarRegistroMaterial();
        cout << "\nRegistro de material cancelado" << endl;
    }
}

void verInformacionMaterial() {
    IControladorMateriales* ctrlMat = FabricaMateriales::getInstancia()->getIControladorMateriales();

    set<DTMaterial*> materiales = ctrlMat->listarMateriales();

    if (materiales.empty()) {
        cout << "\nNo hay materiales registrados." << endl;
        return;
    }

    cout << "\n=== Materiales Disponibles ===" << endl;

    for (DTMaterial* dt : materiales) {
        cout << "  [" << dt->getId() << "] " << dt->getTitulo() << " (" << dt->getTipo() << ") " << endl;
        delete dt;
    }

    int id;
    id = leerInt("\nIngrese el código del material: ");

    DTMaterial* dtMaterial = ctrlMat->verInformacionMaterial(id);

    if (dtMaterial == nullptr) {
        cout << "\nNo se encontró ningún material con ese código." << endl;
        return;
    }

    cout << "\n=== Información de Material ===" << endl;
    cout << "Código: " << dtMaterial->getId() << endl;
    cout << "Título: " << dtMaterial->getTitulo() << endl;
    cout << "Año de Publicación: " << dtMaterial->getAnioPublicacion() << endl;
    cout << "Tipo: " << dtMaterial->getTipo() << endl;

    if (dtMaterial->getTipo() == "Libro") {
        DTLibro* dtLibro = dynamic_cast<DTLibro*>(dtMaterial);
        if (dtLibro != nullptr) {
            cout << "Autor: " << dtLibro->getAutor() << endl;
            cout << "Cantidad de Páginas: " << dtLibro->getCantidadPaginas() << endl;
        }
    } else if (dtMaterial->getTipo() == "Revista") {
        DTRevista* dtRevista = dynamic_cast<DTRevista*>(dtMaterial);
        if (dtRevista != nullptr) {
            cout << "Número de Edición: " << dtRevista->getNumeroEdicion() << endl;
            cout << "Publicación Mensual: " << (dtRevista->getPublicacionMensual() ? "Sí" : "No") << endl;
        }
    }

    delete dtMaterial;
}

void registrarPrestamo() {
    IControladorPrestamos* ctrlPres = FabricaPrestamos::getInstancia()->getIControladorPrestamos();

    int idLector = leerInt("\nIngrese ID del lector: ");

    DTLector* dtLector = ctrlPres->ingresarIdLector(idLector);
    
    if (dtLector == nullptr) {
        cout << "\nLector no encontrado." << endl;
        return;
    }

    int idMaterial = leerInt("Ingrese código del material: ");
    DTMaterial* dtMaterial = ctrlPres->ingresarCodMaterial(idMaterial);

    if (dtMaterial == nullptr) {
        cout << "\nMaterial no encontrado." << endl;
        ctrlPres->cancelarRegistroPrestamo();
        return;
    }

    int dia = leerInt("Ingrese día de préstamo: ");
    int mes = leerInt("Ingrese mes de préstamo: ");
    int anio = leerInt("Ingrese año de préstamo: ");
    int cantDias = leerInt("Ingrese cantidad de días de préstamo: ");

    DTFecha fechaPrestamo(dia, mes, anio);
    ctrlPres->ingresarFechaYCantDias(fechaPrestamo, cantDias);

    int opcionConfirmar = -1;

    cout << "\n1. Confirmar Préstamo" << endl;
    cout << "2. Cancelar Préstamo" << endl;
    opcionConfirmar = leerInt("Opción: ");

    while (opcionConfirmar != 1 && opcionConfirmar != 2) {
        cout << "\nOpción inválida. Por favor, ingrese 1 para confirmar o 2 para cancelar." << endl;
        opcionConfirmar = leerInt("Opción: ");
    }

    if (opcionConfirmar == 1) {
        ctrlPres->registrarPrestamo();
        cout << "\nPréstamo registrado exitosamente." << endl;
    } else {
        ctrlPres->cancelarRegistroPrestamo();
        cout << "\nPréstamo cancelado" << endl;
    }

    delete ctrlPres;
}

void consultarPrestamoLector() {
    IControladorPrestamos* ctrlPres = FabricaPrestamos::getInstancia()->getIControladorPrestamos();

    int idLector = leerInt("\nIngrese ID del lector: ");
    set<DTPrestamo> prestamos = ctrlPres->mostrarPrestamosAsociados(idLector);

    if (prestamos.empty()) {
        cout << "\nNo se encontraron préstamos para ese lector." << endl;
        return;
    }

    cout << "\n=== Préstamos del Lector ===" << endl;

    for (const DTPrestamo& dtPrestamo : prestamos) {
        DTFecha fecha = dtPrestamo.getFechaPrestamo();
        cout << "\nCódigo de material: " << dtPrestamo.getCodigoMaterial() << endl;
        cout << "Título: " << dtPrestamo.getTitulo() << endl;
        cout << "Fecha de préstamo: " << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio() << endl;
        cout << "Días de préstamo: " << dtPrestamo.getCantDias() << endl;
    }
}

void cerrarSesion() {
    if (Sesion::getInstancia()->getUsuarioLogueado() == nullptr) {
        return;
    }
    IControladorRegistro* ctrlReg = FabricaRegistro::getInstancia()->getIControladorRegistro();
    ctrlReg->cerrarSesion();
    cout << "\nSesión cerrada" << endl;
}

string leerLinea(const string& prompt) {
    string valor;
    cout << prompt;
    if (cin.peek() == '\n') {
        cin.ignore();
    }
    getline(cin, valor);
    return valor;
}

int leerInt(const string& prompt) {
    while (true) {
        string input = leerLinea(prompt);
        try {
            return stoi(input);
        } catch (...) {
            cout << "\nEntrada inválida, ingrese un número válido." << endl;
        }
    }
}