#include "ControladorPrestamos.h"
#include "ManejadorUsuario.h"
#include "ManejadorMaterial.h"
#include "DTLector.h"
#include "DTMaterial.h"
#include "DTFecha.h"
#include "DTPrestamo.h"
#include "Prestamo.h"
#include "Lector.h"
#include "Material.h"
#include <iostream>

using namespace std;

DTLector* ControladorPrestamos::ingresarIdLector(int id) {
    ManejadorUsuarios* mu = ManejadorUsuarios::getInstancia();

    if (!mu->existeUsuario(id)) {
        return nullptr;
    }

    Usuario* usuario = mu->buscarUsuario(id);

    if (usuario == nullptr || usuario->getTipo() != "Lector") {
        return nullptr;
    }

    this->dtLector = usuario->toDT();
    return dtLector;
}

DTMaterial* ControladorPrestamos::ingresarCodMaterial(int id) {
    ManejadorMaterial* mm = ManejadorMaterial::getInstancia();
    
    if (!mm->existeMaterial(id)) {
        return nullptr;
    }
    
    Material* material = mm->buscarMaterial(id);

    this->dtMaterial = material->toDT();
    
    return dtMaterial;
}

void ControladorPrestamos::ingresarFechaYCantDias(DTFecha& fechaPrestamo, int cantDias) {
    this->dtFecha = new DTFecha(fechaPrestamo.getDia(), fechaPrestamo.getMes(), fechaPrestamo.getAnio());
    this->cantDias = cantDias;
}

void ControladorPrestamos::registrarPrestamo() {
    ManejadorUsuarios* mu = ManejadorUsuarios::getInstancia();
    ManejadorMaterial* mm = ManejadorMaterial::getInstancia();
    
    Usuario* usuario = mu->buscarUsuario(this->dtLector->getId());
    Material* material = mm->buscarMaterial(dtMaterial->getId());
    
    Prestamo* prestamo = new Prestamo(*dtFecha, cantDias, 0, material);
    usuario->agregarPrestamo(prestamo);  // virtual, llama al de Lector
    
    delete this->dtLector;
    this->dtLector = nullptr;
    this->dtMaterial = nullptr;
    this->dtFecha = nullptr;
    this->cantDias = 0;
} 

void ControladorPrestamos::cancelarRegistroPrestamo() {
    if (this->dtLector != nullptr) {
        delete dtLector;
        dtLector = nullptr;
    }
    
    if (this->dtMaterial != nullptr) {
        dtMaterial = nullptr;
    }
    
    if (this->dtFecha != nullptr) {
        delete dtFecha;
        dtFecha = nullptr;
    }
    
    this->cantDias = 0;
}

set<DTPrestamo> ControladorPrestamos::mostrarPrestamosAsociados(int id) {
    set<DTPrestamo> resultado;
    ManejadorUsuarios* mu = ManejadorUsuarios::getInstancia();
    
    if (!mu->existeUsuario(id)) {
        return resultado;
    }
    
    Usuario* usuario = mu->buscarUsuario(id);

    if (usuario == nullptr || usuario->getTipo() != "Lector") {
        return resultado;
    }

    for (Prestamo* prestamo : usuario->getPrestamos()) {  // virtual, llama al de Lector
        Material* material = prestamo->getMaterial();
        DTMaterial* dtmat = material->toDT();
        
        DTPrestamo dtprestamo(dtmat->getId(), dtmat->getTitulo(), 
                               prestamo->getFechaPrestamo(), prestamo->getCantDiasDev());
        resultado.insert(dtprestamo);
        delete dtmat;
    }
    
    return resultado;
}