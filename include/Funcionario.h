#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Usuario.h"

class Funcionario : public Usuario {
    private:
        int numEmpleado;

    public:
        Funcionario(int id, string nombre, string pass, int numEmpleado);

        int getNumEmpleado();

        string getTipo() override;
};

#endif
