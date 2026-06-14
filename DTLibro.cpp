#include "DTLibro.h"

DTLibro::DTLibro(int id, string titulo, int anioPublicacion, string autor, int cantidadPaginas)
    : DTMaterial(id, titulo, anioPublicacion, "Libro"), autor(autor), cantidadPaginas(cantidadPaginas) {}

DTLibro::~DTLibro() {}

string DTLibro::getAutor() { 
    return autor; 
}

int DTLibro::getCantidadPaginas() { 
    return cantidadPaginas; 
}

string DTLibro::getTipo() { 
    return "Libro";
}