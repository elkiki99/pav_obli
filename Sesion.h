#ifndef SESION_H
#define SESION_H

#include "Usuario.h"

class Sesion {
private:
    static Sesion* instancia;

    Usuario* usuarioLogueado;

    Sesion();
    ~Sesion();

public:
    static Sesion* getInstancia();

    void login(Usuario* u);
    void logout();

    Usuario* getUsuarioLogueado();
};

#endif