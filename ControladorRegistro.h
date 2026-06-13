#ifndef CONTROLADORREGISTRO_H
#define CONTROLADORREGISTRO_H

#include "IControladorRegistro.h"

// forward declarations to avoid circular includes
class Usuario;
class Sesion;

class ControladorRegistro : public IControladorRegistro {
private:
    Usuario* usuarioPendiente;

public:
    // Iniciar Sesión (1er caso de uso)
    bool ingresarDatos(int id, string pass);

    // Cancelar Inicio de Sesión (2do caso de uso)
    void cancelarInicioSesion();
    void confirmarInicioSesion();

    // Cerrar Sesión (3er caso de uso)
    void cerrarSesion();

    
};

#endif