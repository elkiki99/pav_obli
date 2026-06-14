#ifndef DTLIBRO_H
#define DTLIBRO_H

#include "DTMaterial.h"
#include <string>

using namespace std;

class DTLibro : public DTMaterial {
private:
    string autor;
    int cantidadPaginas;

public:
    DTLibro(int id, string titulo, int anioPublicacion, string autor, int cantidadPaginas);
    ~DTLibro();

    string getAutor();
    int getCantidadPaginas();
    string getTipo();
};

#endif
