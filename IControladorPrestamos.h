#ifndef ICONTROLADORCPRESTAMOS_H
#define ICONTROLADORCPRESTAMOS_H

#include <set>
#include <string>

using namespace std;

class DTLector;
class DTMaterial;
class DTFecha;
class DTPrestamo;

class IControladorPrestamos {
public:
    virtual ~IControladorPrestamos() {}

    virtual DTLector* ingresarIdLector(int id) = 0;

    virtual DTMaterial* ingresarCodMaterial(int id) = 0;

    virtual void ingresarFechaYCantDias(DTFecha& fecha, int cantDias) = 0;

    virtual void registrarPrestamo() = 0;

    virtual void cancelarRegistroPrestamo() = 0;

    virtual set<DTPrestamo> mostrarPrestamosAsociados(int id) = 0;
};

#endif
