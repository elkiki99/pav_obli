#ifndef CONTROLADORREGISTRO_H
#define CONTROLADORREGISTRO_H

#include "IControladorRegistro.h"

class Usuario;
class Sesion;
class DTFuncionario;

class ControladorRegistro : public IControladorRegistro {
private:
    Usuario* usuarioPendiente = nullptr;
    DTLector* dtLector = nullptr;
    DTFuncionario* dtFuncionario = nullptr;

public:
    bool ingresarDatos(int id, string pass);
    
    void cancelarInicioSesion();
    void confirmarInicioSesion();

    void cerrarSesion();

    DTLector* ingresarLector(int id, string nombre, string pass, DTFecha fechaR);
    void registrarLector();
    
    DTFuncionario* ingresarFuncionario(int id, string nombre, string pass, int numEmpleado);
    void registrarFuncionario();

    void cancelarRegistro();
};

#endif