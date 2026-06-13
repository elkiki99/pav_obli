#ifndef CONTROLADORREGISTRO_H
#define CONTROLADORREGISTRO_H

#include "IControladorRegistro.h"

// forward declarations to avoid circular includes
class Usuario;
class Sesion;

class ControladorRegistro : public IControladorRegistro {
private:
    Usuario* usuarioPendiente = nullptr;
    DTLector* dtLector = nullptr;

public:
    // Iniciar Sesión (1er caso de uso)
    bool ingresarDatos(int id, string pass);

    // Cancelar Inicio de Sesión (2do caso de uso)
    void cancelarInicioSesion();
    void confirmarInicioSesion();

    // Cerrar Sesión (3er caso de uso)
    void cerrarSesion();

    // Registrar Lector (4to caso de uso)
    DTLector* ingresarLector(int id, string nombre, string pass, DTFecha fechaR);
    void registrarLector();

    // Cancelar Registro (5to caso de uso)
    void cancelarRegistro();

    bool existeUsuario(int id);
    
};

#endif