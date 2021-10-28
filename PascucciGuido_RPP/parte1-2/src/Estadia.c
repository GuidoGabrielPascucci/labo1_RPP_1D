

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Estadia.h"
#include "Nexo.h"
#include "Inputs.h"





/**
 * @fn void inicializarEstadias(sEstadiaDiaria*, int)
 * @brief [Inicializar Estadias - Pone a todos los campos 'espacio vacio' de la estructura Estadias en VERDADERO(1)]
 *
 * @param listaEstadias
 * @param length
 */
void inicializarEstadias(sEstadiaDiaria* listaEstadias, int lengthEstadias)
{

	if (listaEstadias != NULL && lengthEstadias > -1)
	{

		for (int i = 0; i < lengthEstadias; ++i)
		{
			listaEstadias[i].espacioVacio = TRUE;
		}

	}
	else
	{
		printf("ERROR !\nInvalid length or null pointer\n\n");
		system("pause");
	}

}





/**
 * @fn int buscarEspacioLibre(sEstadiaDiaria*, int)
 * @brief [Buscar Espacio Libre - busca el espacio vacio en el campo 'espacio vacio' del array de estadias]
 *
 * @param listaEstadias
 * @param length
 * @return Retorna el INDEX (NUMERO ENTERO) del primer espacio vacio que encuentra en el array de estadias
 */
int buscarEspacioLibre(sEstadiaDiaria* listaEstadias, int lengthEstadias)
{
	int index = -1;

	for (int i = 0; i < lengthEstadias; ++i)
	{
		if (listaEstadias[i].espacioVacio == TRUE)
		{
			index = i;
			break;
		}
	}

	return index;
}







/**
 * @fn void pedirFecha(sEstadiaDiaria*, int)
 * @brief [Pedir Fecha - Pide el dia, mes y anio de la estadia al usuario para cargarla en sistema]
 *
 * @param listaEstadias
 * @param index
 */
void pedirFecha(sEstadiaDiaria* listaEstadias, int index)
{

	listaEstadias[index].fecha.dia = getIntInMinMaxRange("\nIngrese el dia de estadia: ", "ERROR ! Fecha no valida. Por favor reingrese el dia de estadia: ", 1, 31);
	listaEstadias[index].fecha.mes = getIntInMinMaxRange("Ingrese el mes de estadia: ", "ERROR ! Mes no valido. Por favor reingrese el mes de estadia: ", 1, 12);
	listaEstadias[index].fecha.anio = getIntInMinMaxRange("Ingrese el anio de estadia: ", "ERROR ! Anio no valido. Por favor reingrese el anio de estadia: ", 2021, 2030);

}






/**
 * @fn int removerEstadia(sEstadiaDiaria*, int, int)
 * @brief [Remover Estadia - Realiza la baja logica de la estadia poniendo en VERDADERO(1) un determinado subindice del campo 'espacio vacio' del array de estadias]
 *
 * @param listaEstadias
 * @param length
 * @param id
 * @return Retorna un NUMERO ENTERO: [-1] si hubo un error / [0] si realizo la baja logica
 */
void removerEstadia(sEstadiaDiaria* listaEstadias, int lengthEstadias, int id)
{

	for (int i = 0; i < lengthEstadias; ++i)
	{
		if (id == listaEstadias[i].id)
		{
			listaEstadias[i].espacioVacio = TRUE;
			break;
		}
	}

}



/**
 * @fn int buscarEstadiaPorId(sEstadiaDiaria*, int, int)
 * @brief [Buscar Estadia Por ID - Realiza una busqueda de la estadia que contenga el ID ingresado por el usuario]
 *
 * @param listaEstadias
 * @param length
 * @param id
 * @return Retorna un NUMERO ENTERO: [-1] si hubo un error / index n° [x] si encontro la posicion en el array del ID
 */
int buscarEstadiaPorId(sEstadiaDiaria* listaEstadias, int lengthEstadias, int id)
{
	int index = -1;

	if (listaEstadias != NULL && lengthEstadias > -1)
	{
		for (int i = 0; i < lengthEstadias; ++i)
		{
			if (id == listaEstadias[i].id)
			{
				index = i;
				break;
			}
		}

	}
	else
	{
		printf("ERROR !\nDATOS INVALIDOS.\n\n\n");
	}


	return index;
}






void sEstadiaDiaria_ordenarFechas(sEstadiaDiaria* listaEstadias, int indexEstadia)
{
	int auxFecha;

	auxFecha = listaEstadias[indexEstadia].fecha.anio;
	listaEstadias[indexEstadia].fecha.anio = listaEstadias[indexEstadia+1].fecha.anio;
	listaEstadias[indexEstadia+1].fecha.anio = auxFecha;

	auxFecha = listaEstadias[indexEstadia].fecha.mes;
	listaEstadias[indexEstadia].fecha.mes = listaEstadias[indexEstadia+1].fecha.mes;
	listaEstadias[indexEstadia+1].fecha.mes = auxFecha;

	auxFecha = listaEstadias[indexEstadia].fecha.dia;
	listaEstadias[indexEstadia].fecha.dia = listaEstadias[indexEstadia+1].fecha.dia;
	listaEstadias[indexEstadia+1].fecha.dia = auxFecha;

}



void sEstadiaDiaria_ordenarIDs(sEstadiaDiaria* listaEstadias, int indexEstadia)
{
	int auxID;

	auxID = listaEstadias[indexEstadia].id;
	listaEstadias[indexEstadia].id = listaEstadias[indexEstadia+1].id;
	listaEstadias[indexEstadia+1].id = auxID;
}




void sEstadiaDiaria_ordenarIDsPerros(sEstadiaDiaria* listaEstadias, int indexEstadia)
{
	int auxIDPerro;

	auxIDPerro = listaEstadias[indexEstadia].idPerro;
	listaEstadias[indexEstadia].idPerro = listaEstadias[indexEstadia+1].idPerro;
	listaEstadias[indexEstadia+1].idPerro = auxIDPerro;
}



void sEstadiaDiaria_ordenarIDsDuenios(sEstadiaDiaria* listaEstadias, int indexEstadia)
{
	int auxIDDuenio;

	auxIDDuenio = listaEstadias[indexEstadia].idDuenio;
	listaEstadias[indexEstadia].idDuenio = listaEstadias[indexEstadia+1].idDuenio;
	listaEstadias[indexEstadia+1].idDuenio = auxIDDuenio;
}


































