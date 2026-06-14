#ifndef CONTROLADORPRESTAMOS_H
#define CONTROLADORPRESTAMOS_H

#include "IControladorPrestamos.h"
#include <set>
#include <map>

class DTLector;
class DTMaterial;
class DTFecha;
class DTPrestamo;
class Prestamo;
class Lector;

class ControladorPrestamos : public IControladorPrestamos {
private:
    DTLector* dtLector = nullptr;
    DTMaterial* dtMaterial = nullptr;
    DTFecha* dtFecha = nullptr;
    int cantDias = 0;

public:
    DTLector* ingresarIdLector(int id);

    DTMaterial* ingresarCodMaterial(int id);

    void ingresarFechaYCantDias(DTFecha& fecha, int cantDias);

    void registrarPrestamo();

    void cancelarRegistroPrestamo();

    set<DTPrestamo> mostrarPrestamosAsociados(int id);
    
};

#endif
