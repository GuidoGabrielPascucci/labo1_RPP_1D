

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Estadia.h"
#include "Nexo.h"
#include "Inputs.h"





/**
 * @fn void sEstadiaDiaria_inicializarEstadias(sEstadiaDiaria*, int)
 * @brief [sEstadiaDiaria_ INICIALIZAR ESTADIAS - Pone a todos los campos 'espacioVacio' de la estructura Estadias en TRUE[1]]
 *
 * @param listaEstadias
 * @param lengthEstadias
 */
void sEstadiaDiaria_inicializarEstadias(sEstadiaDiaria* listaEstadias, int lengthEstadias)
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
 * @fn int sEstadiaDiaria_buscarEspacioLibre(sEstadiaDiaria*, int)
 * @brief [sEstadiaDiaria BUSCAR ESPACIO LIBRE - Busca el espacio vacio en el campo 'espacioVacio' del array de estadias]
 *
 * @param listaEstadias
 * @param lengthEstadias
 * @return Retorna un NUMERO ENTERO, que es el INDEX del primer espacio vacio que encuentra en el array de estadias
 */
int sEstadiaDiaria_buscarEspacioLibre(sEstadiaDiaria* listaEstadias, int lengthEstadias)
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
 * @fn void sEstadiaDiaria_pedirFecha(sEstadiaDiaria*, int)
 * @brief [sEstadiaDiaria PEDIR FECHA - Pide el dia, mes y anio de la estadia al usuario para cargarla en sistema]
 *
 * @param listaEstadias
 * @param index
 */
void sEstadiaDiaria_pedirFecha(sEstadiaDiaria* listaEstadias, int index)
{

	listaEstadias[index].fecha.dia = getIntInMinMaxRange("\nIngrese el dia de estadia: ", "ERROR ! Fecha no valida. Por favor reingrese el dia de estadia: ", 1, 31);
	listaEstadias[index].fecha.mes = getIntInMinMaxRange("Ingrese el mes de estadia: ", "ERROR ! Mes no valido. Por favor reingrese el mes de estadia: ", 1, 12);
	listaEstadias[index].fecha.anio = getIntInMinMaxRange("Ingrese el anio de estadia: ", "ERROR ! Anio no valido. Por favor reingrese el anio de estadia: ", 2021, 2030);

}





/**
 * @fn void sEstadiaDiaria_removerEstadia(sEstadiaDiaria*, int, int)
 * @brief [sEstadiaDiaria REMOVER ESTADIA - Realiza la baja logica de la estadia poniendo en TRUE[1] un determinado subindice del campo 'espacioVacio' del array de estadias]
 *
 * @param listaEstadias
 * @param lengthEstadias
 * @param id
 */
void sEstadiaDiaria_removerEstadia(sEstadiaDiaria* listaEstadias, int lengthEstadias, int id)
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
 * @fn int sEstadiaDiaria_buscarEstadiaPorId(sEstadiaDiaria*, int, int)
 * @brief [sEstadiaDiaria BUSCAR ESTADIA POR ID - Realiza una busqueda de la estadia que contenga el ID ingresado por el usuario]
 *
 * @param listaEstadias
 * @param lengthEstadias
 * @param id
 * @return Retorna un NUMERO ENTERO: [-1] si hubo un error / index [x] si encontro la posicion en el array del ID
 */
int sEstadiaDiaria_buscarEstadiaPorId(sEstadiaDiaria* listaEstadias, int lengthEstadias, int id)
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





/**
 * @fn void sEstadiaDiaria_ordenarFechas(sEstadiaDiaria*, int)
 * @brief [sEstadiaDiaria ORDENAR FECHAS - Realiza un swap de las fechas del array de estadias]
 *
 * @param listaEstadias
 * @param indexEstadia
 */
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





/**
 * @fn void sEstadiaDiaria_ordenarIDs(sEstadiaDiaria*, int)
 * @brief [sEstadiaDiaria ORDENAR IDs - Realiza un swap de los IDs de estadias del array de estadias]
 *
 * @param listaEstadias
 * @param indexEstadia
 */
void sEstadiaDiaria_ordenarIDs(sEstadiaDiaria* listaEstadias, int indexEstadia)
{
	int auxID;

	auxID = listaEstadias[indexEstadia].id;
	listaEstadias[indexEstadia].id = listaEstadias[indexEstadia+1].id;
	listaEstadias[indexEstadia+1].id = auxID;
}





/**
 * @fn void sEstadiaDiaria_ordenarIDsPerros(sEstadiaDiaria*, int)
 * @brief [sEstadiaDiaria ORDENAR IDs PERROS - Realiza un swap de los IDs de perros del array de estadias]
 *
 * @param listaEstadias
 * @param indexEstadia
 */
void sEstadiaDiaria_ordenarIDsPerros(sEstadiaDiaria* listaEstadias, int indexEstadia)
{
	int auxIDPerro;

	auxIDPerro = listaEstadias[indexEstadia].idPerro;
	listaEstadias[indexEstadia].idPerro = listaEstadias[indexEstadia+1].idPerro;
	listaEstadias[indexEstadia+1].idPerro = auxIDPerro;
}





/**
 * @fn void sEstadiaDiaria_ordenarIDsDuenios(sEstadiaDiaria*, int)
 * @brief [sEstadiaDiaria ORDENAR IDs DUENIOS - Realiza un swap de los IDs de duenios del array de estadias]
 *
 * @param listaEstadias
 * @param indexEstadia
 */
void sEstadiaDiaria_ordenarIDsDuenios(sEstadiaDiaria* listaEstadias, int indexEstadia)
{
	int auxIDDuenio;

	auxIDDuenio = listaEstadias[indexEstadia].idDuenio;
	listaEstadias[indexEstadia].idDuenio = listaEstadias[indexEstadia+1].idDuenio;
	listaEstadias[indexEstadia+1].idDuenio = auxIDDuenio;
}












