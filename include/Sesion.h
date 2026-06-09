#ifndef SESION_H
#define SESION_H

#include <string>

using namespace std;

class Sesion {
private:
    static Sesion* instancia;
    Sesion();
    ~Sesion();
    string usuarioActual;
    bool estaLogueado;

public:
    // Eliminar constructores de copia y asignación para evitar duplicados
    Sesion(const Sesion&) = delete;
    void operator = (Sesion&) = delete;

    // Punto de acceso global
    static Sesion* getInstancia();

    void iniciarSesion(const string& usuario);
    void cerrarSesion();
    string getUsuario() const;
    bool isLogueado() const;
};

#endif // SESION_H
