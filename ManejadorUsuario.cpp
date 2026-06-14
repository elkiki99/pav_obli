#include "ManejadorUsuario.h"

ManejadorUsuarios* ManejadorUsuarios::instancia = nullptr;

ManejadorUsuarios::ManejadorUsuarios() {}

ManejadorUsuarios* ManejadorUsuarios::getInstancia() {
    if (instancia == nullptr)
        instancia = new ManejadorUsuarios();

    return instancia;
}

bool ManejadorUsuarios::existeUsuario(int id) {
    map<int, Usuario*>::iterator it = this->usuarios.find(id);

    return (it != this->usuarios.end());
}

Usuario* ManejadorUsuarios::buscarUsuario(int id) {
    map<int, Usuario*>::iterator it = this->usuarios.find(id);

    if (it != this->usuarios.end())
        return it->second;

    return nullptr;
}

void ManejadorUsuarios::agregarUsuario(Usuario* usuario) {
    usuarios.insert(pair<int, Usuario*>(usuario->getId(), usuario));
}

ManejadorUsuarios::~ManejadorUsuarios() {
    map<int, Usuario*>::iterator it;

    for (it = usuarios.begin(); it != usuarios.end(); ++it)
        delete it->second;

    usuarios.clear();
}