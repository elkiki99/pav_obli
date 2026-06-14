#ifndef CONTROLADORMATERIALES_H
#define CONTROLADORMATERIALES_H

#include "IControladorMateriales.h"
#include "Material.h"
#include <string>
#include <set>

using namespace std;

class ManejadorMaterial;
class DTMaterial;
class DTRevista;
class DTLibro;

class ControladorMateriales : public IControladorMateriales {
private:
    DTMaterial* dtMaterial = nullptr;

    string autor = "";
    int cantidadPaginas = 0;
    int numeroEdicion = 0;
    bool publicacionMensual = false;

public:
    DTMaterial* ingresarMaterial(int id, string titulo, int anioPublicacion, string tipo) override;
    void registrarMaterial() override;

    void ingresarDatosExtraLibro(string autor, int cantidadPaginas) override;
    void ingresarDatosExtraRevista(int numeroEdicion, bool publicacionMensual) override;

    void confirmarRegistroMaterial() override;
    void cancelarRegistroMaterial() override;

    set<DTMaterial*> listarMateriales() override;
    DTMaterial* verInformacionMaterial(int id) override;
};

#endif

