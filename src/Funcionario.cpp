#include "Funcionario.h"

Funcionario::Funcionario(int id, string nombre, string pass, int numEmpleado) : Usuario(id, nombre, pass)
{
    this->numEmpleado = numEmpleado;
}

int Funcionario::getNumEmpleado() {
    return numEmpleado;
}

string Funcionario::getTipo() {
    return "Funcionario";
}
