#ifndef ICONTROLADORREGISTRO_H
#define ICONTROLADORREGISTRO_H

#include <string>

using namespace std;

class DTLector;
class DTFecha;
class DTFuncionario;

class IControladorRegistro {
    public:
        virtual bool ingresarDatos(int id, string pass) = 0;

        virtual void confirmarInicioSesion() = 0;
        virtual void cancelarInicioSesion() = 0;

        virtual void cerrarSesion() = 0;

        virtual DTLector* ingresarLector(int id, string nombre, string pass, DTFecha fechaR) = 0;
        virtual void registrarLector() = 0;
        
        virtual DTFuncionario* ingresarFuncionario(int id, string nombre, string pass, int numEmpleado) = 0;
        virtual void registrarFuncionario() = 0;

        virtual void cancelarRegistro() = 0;
};

#endif