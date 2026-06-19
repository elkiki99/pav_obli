#include "ControladorMateriales.h"
#include "ManejadorMaterial.h"
#include "DTMaterial.h"
#include "DTRevista.h"
#include "Revista.h"
#include "DTLibro.h"
#include "Libro.h"

DTMaterial* ControladorMateriales::ingresarMaterial(int id, string titulo, int anioPublicacion, string tipo) {
    ManejadorMaterial* mm = ManejadorMaterial::getInstancia();

    if (mm->existeMaterial(id)) {
        return nullptr;
    }

    this->dtMaterial = new DTMaterial(id, titulo, anioPublicacion, tipo);
    return dtMaterial;
}

void ControladorMateriales::ingresarDatosExtraLibro(string autor, int cantidadPaginas) {
    if (dtMaterial == nullptr || dtMaterial->getTipo() != "Libro") {
        return;
    }
    this->autor = autor;
    this->cantidadPaginas = cantidadPaginas;
}

void ControladorMateriales::ingresarDatosExtraRevista(int numeroEdicion, bool publicacionMensual) {
    if (dtMaterial == nullptr || dtMaterial->getTipo() != "Revista") {
        return;
    }
    this->numeroEdicion = numeroEdicion;
    this->publicacionMensual = publicacionMensual;
}

void ControladorMateriales::registrarMaterial() {
    if (dtMaterial == nullptr) return;

    ManejadorMaterial* mm = ManejadorMaterial::getInstancia();
    Material* material = nullptr;

    if (dtMaterial->getTipo() == "Libro") {
        material = new Libro(dtMaterial->getId(), dtMaterial->getTitulo(),
                             dtMaterial->getAnioPublicacion(), autor, cantidadPaginas);
        this->autor = "";
        this->cantidadPaginas = 0;

    } else if (dtMaterial->getTipo() == "Revista") {
        material = new Revista(dtMaterial->getId(), dtMaterial->getTitulo(),
                               dtMaterial->getAnioPublicacion(), numeroEdicion, publicacionMensual);
        this->numeroEdicion = 0;
        this->publicacionMensual = false;
    }

    if (material != nullptr) {
        mm->agregarMaterial(material);
    }

    delete this->dtMaterial;
    this->dtMaterial = nullptr;
}

void ControladorMateriales::confirmarRegistroMaterial() {
    this->registrarMaterial();
}

void ControladorMateriales::cancelarRegistroMaterial() {
    if (dtMaterial == nullptr) return;

    this->autor = "";
    this->cantidadPaginas = 0;
    this->numeroEdicion = 0;
    this->publicacionMensual = false;

    delete this->dtMaterial;
    this->dtMaterial = nullptr;
}

set<DTMaterial*> ControladorMateriales::listarMateriales() {
    set<DTMaterial*> resultado;
    ManejadorMaterial* mm = ManejadorMaterial::getInstancia();

    for (auto& item : mm->getMateriales()) {
        DTMaterial* dt = item.second->toDT();
        if (dt != nullptr) {
            resultado.insert(dt);
        }
    }

    return resultado;
}

DTMaterial* ControladorMateriales::verInformacionMaterial(int id) {
    ManejadorMaterial* mm = ManejadorMaterial::getInstancia();
    Material* material = mm->buscarMaterial(id);

    if (material == nullptr) {
        return nullptr;
    }

    return material->toDT();
}
