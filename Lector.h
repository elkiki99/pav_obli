#ifndef LECTOR_H
#define LECTOR_H

#include <set>
#include "Usuario.h"
#include "Prestamo.h"
#include "DTFecha.h"

class Lector : public Usuario {
    private:
        // int fechaRegistro;
        DTFecha fechaRegistro;

        set<Prestamo*> prestamos;

    public:
        Lector();
        Lector(int id, string nombre, string pass, DTFecha fechaRegistro);

        DTFecha getFechaRegistro();
        void setFechaRegistro(DTFecha fechaRegistro);
        
        set<Prestamo*>& getPrestamos();
        void agregarPrestamo(Prestamo* prestamo);

        DTLector* toDT() override;
        string getTipo() override;
        
        ~Lector();
};

#endif
