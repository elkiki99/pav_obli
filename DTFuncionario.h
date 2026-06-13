#ifndef DTFUNCIONARIO_H
#define DTFUNCIONARIO_H

#include <string>

using namespace std;

class DTFuncionario {
    private:
        int id;
        string nombre;
        string pass;
        int numEmpleado;

    public:
        DTFuncionario(int id, string nombre, string pass, int numEmpleado)
            : id(id), nombre(nombre), pass(pass), numEmpleado(numEmpleado) {}

        int getId() const { return id; }
        string getNombre() const { return nombre; }
        string getPass() const { return pass; }
        int getNumEmpleado() const { return numEmpleado; }
};

#endif
