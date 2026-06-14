#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <set>

using namespace std;

class DTLector;
class Prestamo;

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
        virtual DTLector* toDT() = 0;
        virtual set<Prestamo*>& getPrestamos();
        virtual void agregarPrestamo(Prestamo* prestamo);
        
        virtual ~Usuario();
};

#endif
