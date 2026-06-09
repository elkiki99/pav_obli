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
        Lector(int id, string nombre, string pass, int fechaRegistro);

        int getFechaRegistro();

        set<Prestamo*> getPrestamos();

        void agregarPrestamo(Prestamo* prestamo);

        string getTipo() override;
};

#endif
