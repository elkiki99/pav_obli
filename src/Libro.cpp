#include "Libro.h"

Libro::Libro(int id, string titulo, int anioPublicacion, string autor, int cantidadPaginas) : Material(id, titulo, anioPublicacion)
{
    this->autor = autor;
    this->cantidadPaginas = cantidadPaginas;
}

string Libro::getAutor() {
    return autor;
}

int Libro::getCantidadPaginas() {
    return cantidadPaginas;
}

string Libro::getTipo() {
    return "Libro";
}
