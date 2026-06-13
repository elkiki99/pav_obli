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
        Usuario();
        Usuario(int id, string nombre, string pass);
        
        int getId();
        void setId(int id);

        string getNombre();
        void setNombre(string nombre);

        string getPass();
        void setPass(string pass);
        
        virtual string getTipo() = 0;
        virtual ~Usuario();
};

#endif
