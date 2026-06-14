#include "ManejadorMaterial.h"

ManejadorMaterial* ManejadorMaterial::instancia = nullptr;

ManejadorMaterial::ManejadorMaterial() {}

ManejadorMaterial* ManejadorMaterial::getInstancia() {
    if (instancia == nullptr)
        instancia = new ManejadorMaterial();

    return instancia;
}

bool ManejadorMaterial::existeMaterial(int id) {
    map<int, Material*>::iterator it = this->materiales.find(id);

    return (it != this->materiales.end());
}

Material* ManejadorMaterial::buscarMaterial(int id) {
    map<int, Material*>::iterator it = this->materiales.find(id);

    if (it != this->materiales.end())
        return it->second;

    return nullptr;
}

void ManejadorMaterial::agregarMaterial(Material* material) {
    materiales.insert(pair<int, Material*>(material->getId(), material));
}

const std::map<int, Material*>& ManejadorMaterial::getMateriales() const {
    return materiales;
}

ManejadorMaterial::~ManejadorMaterial() {
    map<int, Material*>::iterator it;

    for (it = materiales.begin(); it != materiales.end(); ++it)
        delete it->second;

    materiales.clear();
}