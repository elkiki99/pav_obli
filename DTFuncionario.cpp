#include "DTFuncionario.h"

DTFuncionario::DTFuncionario(int id, string nombre, string pass, int numEmpleado)
	: id(id), nombre(nombre), pass(pass), numEmpleado(numEmpleado) {}

int DTFuncionario::getId() { 
	return id; 
}

string DTFuncionario::getNombre() { 
	return nombre; 
}

string DTFuncionario::getPass() { 
	return pass; 
}

int DTFuncionario::getNumEmpleado() { 
	return numEmpleado; 
}
