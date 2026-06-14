#include "Funcionario.h"

Funcionario::Funcionario() {}

Funcionario::Funcionario(int id, string nombre, string pass, int numEmpleado) : Usuario(id, nombre, pass)
{
    this->numEmpleado = numEmpleado;
}

int Funcionario::getNumEmpleado() {
    return numEmpleado;
}

void Funcionario::setNumEmpleado(int numEmpleado) {
    this->numEmpleado = numEmpleado;
}

string Funcionario::getTipo() {
    return "Funcionario";
}

// DTUsuario* Funcionario::toDT() {
//     return new DTFuncionario(getId(), getNombre(), getPass(), getNumEmpleado());
// }

// Funcionario::~Funcionario() {}
