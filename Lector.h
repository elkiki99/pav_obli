#ifndef LECTOR_H
#define LECTOR_H

#include <set>
#include "Usuario.h"
#include "Prestamo.h"

class Lector : public Usuario {
    private:
        int fechaRegistro;

        set<Prestamo*> prestamos;

    public:
        Lector();
        Lector(int id, string nombre, string pass, int fechaRegistro);

        int getFechaRegistro();
        void setFechaRegistro(int fechaRegistro);
        
        const set<Prestamo*>& getPrestamos();
        void agregarPrestamo(Prestamo* prestamo);

        string getTipo() override;
        ~Lector();
};

#endif
