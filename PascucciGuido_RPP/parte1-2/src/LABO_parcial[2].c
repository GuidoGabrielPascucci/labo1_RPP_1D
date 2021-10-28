
/*
 ============================================================================
 Name        : LABO_parcial[2].c
 Author      : Pascucci, Guido Gabriel
 Description : Parcial Laboratorio - Parte II
 ============================================================================
*/

/*
			Parte 2 (Refactorizaci�n e Informes)

Para esta instancia del parcial, deber� agregar la siguiente estructura y relacionarla de
manera adecuada con la/s estructura/s de la parte 1. Eliminando de las anteriores los
campos que sobren.

Duenio:
- id (comienza en 30000)
- nombre(m�ximo 41 caracteres)
- telefono (int)

Hardcodear por lo menos 5 due�os.

Nota importante: Deber� impactar este cambio en las funcionalidades solicitadas en la
parte 1. Recordar que al dar de alta una estad�a, se deber� verificar que el due�o ingresado
exista.

Agregar los siguientes informes:
7. El perro que tiene m�s estad�as reservadas.
8. Listado de perros con sus estad�as diarias reservadas.
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


	// INIT
	inicializarPerritos(perritos, MAX_PERROS);
	inicializarEstadias(estadias, MAX_PERROS);
	sDuenio_inicializarDuenios(duenios, MAXDUENIOS);


	// HARDCODE
	sPerro_hardcodeo(perritos, MAX_PERROS);
	sDuenio_hardcodearDuenios(duenios, MAXDUENIOS);


	// MAIN MENU
	mainMenu(estadias, perritos, duenios, MAX_ESTADIAS, MAX_PERROS, MAXDUENIOS);



	return EXIT_SUCCESS;
}












