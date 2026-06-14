#ifndef DTMATERIAL_H
#define DTMATERIAL_H

#include <string>

using namespace std;

class DTMaterial {
protected:
    int id;
    string titulo;
    int anioPublicacion;
    string tipo;

public:
    DTMaterial(int id, string titulo, int anioPublicacion, string tipo);
    virtual ~DTMaterial();

    int getId();
    string getTitulo();
    int getAnioPublicacion();

    virtual string getTipo();
};

#endif
