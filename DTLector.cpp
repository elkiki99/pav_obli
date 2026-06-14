#include "DTLector.h"

DTLector::DTLector(int id, string nombre, string pass, DTFecha fechaRegistro)
	: id(id), nombre(nombre), pass(pass), fechaRegistro(fechaRegistro) {}

int DTLector::getId() { 
	return id; 
}

string DTLector::getNombre() { 
	return nombre; 
}

string DTLector::getPass() { 
	return pass; 
}

DTFecha DTLector::getFechaRegistro() { 
	return fechaRegistro; 
}
