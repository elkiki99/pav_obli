#ifndef MANEJADORMATERIAL_H
#define MANEJADORMATERIAL_H

#include <map>
#include "Material.h"

class ManejadorMaterial {
private:
    static ManejadorMaterial* instancia;

    map<int, Material*> materiales;

    ManejadorMaterial();

public:
    static ManejadorMaterial* getInstancia();

    bool existeMaterial(int id);
    Material* buscarMaterial(int id);
    const map<int, Material*>& getMateriales() const;

    void agregarMaterial(Material* material);

    ~ManejadorMaterial();
};

#endif