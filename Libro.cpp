#include "Libro.h"

Libro::Libro() {}

Libro::Libro(int id, string titulo, int anioPublicacion, string autor, int cantidadPaginas) : 
       Material(id, titulo, anioPublicacion)
{
    this->autor = autor;
    this->cantidadPaginas = cantidadPaginas;
}

string Libro::getAutor() {
    return autor;
}

void Libro::setAutor(string autor) {
    this->autor = autor;
}

int Libro::getCantidadPaginas() {
    return cantidadPaginas;
}

void Libro::setCantidadPaginas(int cantidadPaginas) {
    this->cantidadPaginas = cantidadPaginas;
}

string Libro::getTipo() {
    return "Libro";
}

// Libro::~Libro() {}