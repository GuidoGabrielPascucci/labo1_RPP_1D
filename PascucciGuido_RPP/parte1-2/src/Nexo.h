
#ifndef NEXO_H_
#define NEXO_H_


#include "Estadia.h"
#include "Perro.h"
#include "Duenio.h"


void mainMenu(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, sDuenio* listaDuenios, int lengthPerros, int lengthEstadias, int lengthDuenios);
void agregarEstadia(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, sDuenio* listaDuenios, int lengthEstadias, int lengthPerros, int lengthDuenios, int* contadorId, int* contadorAltas);
int cargarDatosDeEstadia(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, sDuenio* listaDuenios, int lengthEstadias, int lengthPerros, int lengthDuenios, int index, int* contadorId);
void mostrarEstadia(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, sDuenio* listaDuenios, int lengthEstadias, int lengthPerros, int lengthDuenios, int indexEstadias, int indexPerros, int indexDuenios);
void mostrarListaEstadias(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, sDuenio* listaDuenios, int lengthEstadias, int lengthPerros, int lengthDuenios);



void modificarEstadia(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, sDuenio* listaDuenios, int lengthEstadias, int lengthPerros, int lengthDuenios, int contadorId, int contadorAltas);


void modificarEstadiaMenu(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, sDuenio* listaDuenios, int lengthEstadias, int lengthPerros, int lengthDuenios, int index);


void modificarTelefonoDeContacto(sEstadiaDiaria* listaEstadias, sDuenio* listaDuenios, int lengthEstadias, int lengthDuenios, int index);

void modificarPerro(sPerro* listaPerros, sEstadiaDiaria* listaEstadias, int index);



void cancelarEstadia(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, sDuenio* listaDuenios, int lengthEstadias, int lengthPerros, int lengthDuenios, int* contadorAltas);



void listarEstadias(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, sDuenio* listaDuenios, int lengthEstadias, int lengthPerros, int lengthDuenios, int contadorAltas);


void listarEstadiasPorFechaDescendente(sEstadiaDiaria* listaEstadias, sDuenio* listaDuenios, int lengthEstadias, int lengthDuenios);

int generarId(int contadorId);




void calcularYMostrarPerroConMasEstadias(sPerro* listaPerros, sEstadiaDiaria* listaEstadias, sDuenio* listaDuenios, int lengthPerros, int lengthEstadias, int lengthDuenios, int contadorAltas);


void mostrarPerroConMasEstadias(sPerro* listaPerros, sEstadiaDiaria* listaEstadias, sDuenio* listaDuenios, int lengthPerros, int lengthEstadias, int lengthDuenios, int indexPerro);


void mostrarPerroConSusEstadias(sPerro* listaPerros, sEstadiaDiaria* listaEstadias, sDuenio* listaDuenios, int lengthPerros, int lengthEstadias, int lengthDuenios, int contadorAltas);


#endif
