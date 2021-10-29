
/*
 ============================================================================
 Name        : LABO_parcial[3].c
 Author      : Pascucci, Guido Gabriel
 Description : Parcial Laboratorio - Parte III
 ============================================================================
*/

/*
		Parte 3 (Refactorización e Informes)
Agregar las siguientes opciones al menú anterior:
9. ALTA DE PERRO: Con id autoincremental (comienza en 7002 por los 3 perritos que ya
estaban hardcodeados).
10. La cantidad de dueños que se llaman Alan y que, a su vez, tienen al menos una
estadía reservada.
11. Listado de estadías realizadas por dueñas que se llaman Lucia y cuya fecha de
reserva es durante la segunda quincena de noviembre 2021.

Nota importante: La nueva opción de ALTA DE PERRO influirá en algunas de las
funcionalidades solicitadas en las partes 1 y 2, REVISAR CON CUIDADO (ejemplo: si al dar
de alta estadía, el perrito se seleccionaba a través de un menú de opciones, ahora lo tienen
que hacer por id).
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



















