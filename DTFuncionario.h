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
        DTFuncionario(int id, string nombre, string pass, int numEmpleado);

        int getId();

        string getNombre();

        string getPass();

        int getNumEmpleado();
};

#endif
