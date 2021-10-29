
#ifndef ESTADIA_H_
#define ESTADIA_H_

#include "Fecha.h"



typedef struct {
	int id;
	int idPerro;
	sFecha fecha;
	int idDuenio;
	int espacioVacio;
} sEstadiaDiaria;





void sEstadiaDiaria_inicializarEstadias(sEstadiaDiaria* listaEstadias, int lengthEstadias);
int sEstadiaDiaria_buscarEspacioLibre(sEstadiaDiaria* listaEstadias, int lengthEstadias);
void sEstadiaDiaria_pedirFecha(sEstadiaDiaria* listaEstadias, int index);
void sEstadiaDiaria_removerEstadia(sEstadiaDiaria* listaEstadias, int lengthEstadias, int id);
int sEstadiaDiaria_buscarEstadiaPorId(sEstadiaDiaria* listaEstadias, int lengthEstadias, int id);
void sEstadiaDiaria_ordenarFechas(sEstadiaDiaria* listaEstadias, int indexEstadia);
void sEstadiaDiaria_ordenarIDs(sEstadiaDiaria* listaEstadias, int indexEstadia);
void sEstadiaDiaria_ordenarIDsPerros(sEstadiaDiaria* listaEstadias, int indexEstadia);
void sEstadiaDiaria_ordenarIDsDuenios(sEstadiaDiaria* listaEstadias, int indexEstadia);







#endif
