#ifndef USUARIO_H
#define USUARIO_H

#include <string>

using namespace std;

class Usuario {
    protected:
        int id;
        string nombre;
        string pass;

    public:
        Usuario(int id, string nombre, string pass);
        virtual ~Usuario();

        int getId();
        string getNombre();
        string getPass();

        virtual string getTipo() = 0;
};

#endif
