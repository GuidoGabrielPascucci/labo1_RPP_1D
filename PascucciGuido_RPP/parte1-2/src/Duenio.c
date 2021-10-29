

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Duenio.h"
#include "Nexo.h"
#include "Inputs.h"





/**
 * @fn int sDuenio_inicializarDuenios(sDuenio*, int)
 * @brief [sDuenio INICIALIZAR DUENIOS - Inicializa todas las posiciones del campo espacioVacio perteneciente a la estructura sDuenio en TRUE [1]]
 *
 * @param listaDuenios
 * @param lengthDuenios
 * @return Retorna [-1] si hay error / [0] si OK
 */
int sDuenio_inicializarDuenios(sDuenio* listaDuenios, int lengthDuenios) {

	int functionValue = -1;

	if (listaDuenios != NULL && lengthDuenios > -1)
	{

		for (int i = 0; i < lengthDuenios; ++i)
		{
			listaDuenios[i].espacioVacio = TRUE;
		}

		functionValue = 0;

	}
	else
	{
		printf("ERROR <<Invalid length or NULL pointer>>");
	}


	return functionValue;
}





/**
 * @fn void sDuenio_hardcodearDuenios(sDuenio*, int)
 * @brief [sDuenio HARDCODEAR DUENIOS - Ingresa los datos de 5 duenios con sus respectivos nombres, telefonos y IDs, y los carga en el sistema]
 *
 * @param listaDuenios
 * @param lengthDuenios
 */
void sDuenio_hardcodearDuenios(sDuenio* listaDuenios, int lengthDuenios) {

	int ids[] = {30000, 30001, 30002, 30003, 30004};
	char nombres[][MAXLENGTH] = {"Juan", "Jose", "Diego", "Armando", "Lionel"};
	int telefonos[] = {42101350, 1550238146, 1125478012, 43291541, 35271250};


	for (int i = 0; i < lengthDuenios; ++i)
	{
		listaDuenios[i].id = ids[i];
		strcpy(listaDuenios[i].nombre, nombres[i]);
		listaDuenios[i].telefono = telefonos[i];
		listaDuenios[i].espacioVacio = FALSE;
	}

}





/**
 * @fn int duenio_cargarId(sDuenio*, int)
 * @brief [sDuenio CARGAR ID - Muestra la lista de duenios y pide al usuario ingresar el ID correspondiente a uno de los duenios]
 *
 * @param listaDuenios
 * @param lengthDuenios
 * @return Retorna el ID de uno de los duenios cargados en sistema
 */
int sDuenio_cargarId(sDuenio* listaDuenios, int lengthDuenios)
{
	sDuenio_mostrarTodos(listaDuenios, lengthDuenios);
	int idDuenio = getIntInMinMaxRange("Ingrese ID del duenio que desee: ",
									   "ERROR. Ingrese nuevamente el ID del duenio que desee: ", 30000, 30004);


	return idDuenio;
}





/**
 * @fn void sDuenio_mostrarTodos(sDuenio*, int)
 * @brief [sDuenio MOSTRAR TODOS - Muestra en pantalla todos los duenios cargados en sistema]
 *
 * @param listaDuenios
 * @param lengthDuenios
 */
void sDuenio_mostrarTodos(sDuenio* listaDuenios, int lengthDuenios)
{

	if (listaDuenios != NULL && lengthDuenios > -1)
	{
		printf("\n\n---------------------------------------------------------------------------------------------------------------------------------\n"
				"LISTADO DUENIOS\n"
				"---------------------------------------------------------------------------------------------------------------------------------\n"
				"%-20s %-20s %-20s", "ID", "Nombre", "Telefono\n"
				"---------------------------------------------------------------------------------------------------------------------------------\n");

		for (int i = 0; i < lengthDuenios; ++i)
		{
			sDuenio_mostrarUno(listaDuenios, i);
		}

		printf("\n\n\n\n");
	}
	else
	{
		printf("\n\nERROR <<Invalid length or NULL pointer>>\n\n\n");
	}

}





/**
 * @fn void sDuenio_mostrarUno(sDuenio*, int)
 * @brief [sDuenio MOSTRAR UNO - Muestra en pantalla un duenio con su respectivo nombre, telefono y ID, en una posicion especifica del array de Duenios dependiendo del index que le llegue por parametro]
 *
 * @param listaDuenios
 * @param index
 */
void sDuenio_mostrarUno(sDuenio* listaDuenios, int index)
{

	printf("%-20d %-20s %-20d\n", listaDuenios[index].id,
								  listaDuenios[index].nombre,
								  listaDuenios[index].telefono);

}









