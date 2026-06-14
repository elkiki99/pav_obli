#ifndef ICONTROlADORMATERIALES_H
#define ICONTROlADORMATERIALES_H

#include <string>
#include <set>

using namespace std;

class Material;
class DTMaterial;

class IControladorMateriales {
    public:
        virtual DTMaterial* ingresarMaterial(int id, string titulo, int anioPublicacion, string tipo) = 0;
        virtual void registrarMaterial() = 0;

        virtual void ingresarDatosExtraLibro(string autor, int cantidadPaginas) = 0;
        virtual void ingresarDatosExtraRevista(int numeroEdicion, bool publicacionMensual) = 0;

        virtual void confirmarRegistroMaterial() = 0;
        virtual void cancelarRegistroMaterial() = 0;

        virtual set<DTMaterial*> listarMateriales() = 0;
        virtual DTMaterial* verInformacionMaterial(int id) = 0;

        virtual ~IControladorMateriales() {}
};

#endif
