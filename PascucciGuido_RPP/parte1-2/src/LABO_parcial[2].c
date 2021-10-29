
/*
 ============================================================================
 Name        : LABO_parcial[2].c
 Author      : Pascucci, Guido Gabriel
 Description : Parcial Laboratorio - Parte II
 ============================================================================
*/


#include <stdio.h>
#include <stdlib.h>

#include "Perro.h"
#include "Estadia.h"
#include "Nexo.h"
#include "Duenio.h"



int main(void) {
	setbuf(stdout, NULL);

	printf("\n\t\t\t\t\tGuarderia de Perritos\n\t\t\t\t\t     Bienvenidxs!\n");

	sPerro perritos[MAX_PERROS];
	sEstadiaDiaria estadias[MAX_ESTADIAS];
	sDuenio duenios[MAXDUENIOS];

	sPerro_inicializarPerritos(perritos, MAX_PERROS);
	sEstadiaDiaria_inicializarEstadias(estadias, MAX_PERROS);
	sDuenio_inicializarDuenios(duenios, MAXDUENIOS);

	sPerro_hardcodearPerros(perritos, MAX_PERROS);
	sDuenio_hardcodearDuenios(duenios, MAXDUENIOS);


	mainMenu(estadias, perritos, duenios, MAX_ESTADIAS, MAX_PERROS, MAXDUENIOS);


	return EXIT_SUCCESS;
}












