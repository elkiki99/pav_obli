#ifndef MANEJADORUSUARIOS_H
#define MANEJADORUSUARIOS_H

#include <map>
#include "Usuario.h"

class ManejadorUsuarios {
private:
    static ManejadorUsuarios* instancia;

    std::map<int, Usuario*> usuarios;

    ManejadorUsuarios();

public:
    static ManejadorUsuarios* getInstancia();

    bool existeUsuario(int id);
    Usuario* buscarUsuario(int id);

    void agregarUsuario(Usuario* usuario);

    ~ManejadorUsuarios();
};

#endif