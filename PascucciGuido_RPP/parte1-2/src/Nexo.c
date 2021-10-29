

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Nexo.h"
#include "Inputs.h"
#include "Validations.h"





/**
 * @fn void mainMenu(sEstadiaDiaria*, sPerro*, sDuenio*, int, int, int)
 * @brief [MAIN MENU - Donde se pueden realizar las acciones correspondientes o finalizar el programa]
 *
 * @param listaEstadias
 * @param listaPerros
 * @param listaDuenios
 * @param lengthPerros
 * @param lengthEstadias
 * @param lengthDuenios
 */
void mainMenu(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, sDuenio* listaDuenios, int lengthPerros, int lengthEstadias, int lengthDuenios)
{
	int contadorId = 0;
	int contadorAltas = 0;
	int option;

	do
		{
			option = getIntInMinMaxRange("\n_________________________________________________________________________________________________________________________________\n\n\n"
										 "MENU\n\n"
										 "_________________________________________________________________________________________________________________________________\n\n"
										 "Ingrese una opcion:\n"
										 "---------------------------------------------------------------------------------------------------------------------------------\n\n"
										 "1. Reservar Estadia\n"
										 "2. Modificar Estadia\n"
										 "3. Cancelar Estadia\n"
										 "4. Listar Estadias\n"
										 "5. Listar Perros\n"
										 "6. Promedio De Edad De Los Perros\n"
										 "7. Mostrar Perro Con Mas Estadias Reservadas\n"
										 "8. Listado De Perros Con Sus Estadías Diarias Reservadas.\n\n"
										 "9. EXIT\n\n\n"
										 "_________________________________________________________________________________________________________________________________\n\n",

										 "\nError - motivo: [Entrada invalida]. Ingrese nuevamente una opcion:\n"
										 "_________________________________________________________________________________________________________________________________\n\n"
										 "1. Reservar Estadia\n"
										 "2. Modificar Estadia\n"
										 "3. Cancelar Estadia\n"
										 "4. Listar Estadias\n"
										 "5. Listar Perros\n"
										 "6. Promedio De Edad De Los Perros\n\n"
										 "7. perro con mas estadias reservadas\n"
										 "8. listado de perros con sus estadias diarias reservadas\n\n"
										 "9. EXIT\n\n\n", 1, 9);


			switch (option)
			{
				case 1:
					agregarEstadia(listaEstadias, listaPerros, listaDuenios, lengthEstadias, lengthPerros, lengthDuenios, &contadorId, &contadorAltas);
					break;

				case 2:
					modificarEstadia(listaEstadias, listaPerros, listaDuenios, lengthEstadias, lengthPerros, lengthDuenios, contadorId, contadorAltas);
					break;

				case 3:
					cancelarEstadia(listaEstadias, listaPerros, listaDuenios, lengthEstadias, lengthPerros, lengthDuenios, &contadorAltas);
					break;

				case 4:
					listarEstadias(listaEstadias, listaPerros, listaDuenios, lengthEstadias, lengthPerros, lengthDuenios, contadorAltas);
					break;

				case 5:
					sPerro_listarPerros(listaPerros, lengthPerros, contadorAltas);
					break;

				case 6:
					sPerro_calcularPromedioEdadPerros(listaPerros, lengthPerros, contadorAltas);
					break;

				case 7:
					calcularYMostrarPerroConMasEstadias(listaPerros, listaEstadias, listaDuenios, lengthEstadias, lengthPerros, lengthDuenios, contadorAltas);
					break;

				case 8:
					mostrarPerroConSusEstadias(listaPerros, listaEstadias, listaDuenios, lengthEstadias, lengthPerros, lengthDuenios, contadorAltas);
					break;

				case 9:
					// Exit
					printf("\n\n\t\t\t\tGracias por utilizar nuestros servicios. Nos vemos!\n\n");
					break;
			}


		} while (option != 9);

}





/**
 * @fn void agregarEstadia(sEstadiaDiaria*, sPerro*, sDuenio*, int, int, int, int*, int*)
 * @brief [AGREGAR ESTADIA - Busca el espacio libre e invoca a la funcion para cargar los datos de la estadia;
 * ademas incrementa el contador de estadias y el contador de ID's]
 *
 * @param listaEstadias
 * @param listaPerros
 * @param listaDuenios
 * @param lengthEstadias
 * @param lengthPerros
 * @param lengthDuenios
 * @param contadorId
 * @param contadorAltas
 */
void agregarEstadia(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, sDuenio* listaDuenios, int lengthEstadias, int lengthPerros, int lengthDuenios, int* contadorId, int* contadorAltas)
{
	int index;

	if ( (listaEstadias != NULL && listaPerros != NULL && listaPerros != NULL) && (lengthPerros > -1 && lengthEstadias > -1 && lengthDuenios > -1) )
	{

		index = sEstadiaDiaria_buscarEspacioLibre(listaEstadias, lengthPerros);

		if ( (index != -1) && (!cargarDatosDeEstadia(listaEstadias, listaPerros, listaDuenios, lengthPerros, lengthEstadias, lengthDuenios, index, contadorId)) )
		{
			(*contadorId)++;
			(*contadorAltas)++;

			system("pause");
		}
		else
		{
			printf("\n\nERROR !\nNo hay espacio disponible para agregar perros.\n\n\n");
			system("pause");
		}

	}
	else
	{
		printf("\nERROR !\nDatos invalidos. Por favor intente nuevamente\n\n\n\n");
		system("pause");
	}

}





/**
 * @fn int cargarDatosDeEstadia(sEstadiaDiaria*, sPerro*, sDuenio*, int, int, int, int, int*)
 * @brief [CARGAR DATOS DE ESTADIA - Carga los datos de la estadia que el usuario ingresa en el sistema]
 *
 * @param listaEstadias
 * @param listaPerros
 * @param listaDuenios
 * @param lengthEstadias
 * @param lengthPerros
 * @param lengthDuenios
 * @param index
 * @param contadorId
 * @return
 */
int cargarDatosDeEstadia(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, sDuenio* listaDuenios, int lengthEstadias, int lengthPerros, int lengthDuenios, int index, int* contadorId)
{
	int value = -1;


	printf("\n\n---------------------------------------------------------------------------------------------------------------------------------\n"
			"Por favor complete los siguientes datos:\n"
			"---------------------------------------------------------------------------------------------------------------------------------\n");

	sEstadiaDiaria_pedirFecha(listaEstadias, index);

	listaEstadias[index].id = generarId(*contadorId);
	listaEstadias[index].idDuenio = sDuenio_cargarId(listaDuenios, lengthDuenios);
	listaEstadias[index].idPerro = sPerro_cargarPerritoPorId(listaPerros, lengthPerros, index);

	listaEstadias[index].espacioVacio = FALSE;


	value = 0;


	printf("\n\n********************************************************************************************************************************************\n\n"
			"Estadia agregada exitosamente !\n\n"
			"********************************************************************************************************************************************\n\n");


	return value;
}





/**
 * @fn void modificarEstadia(sEstadiaDiaria*, sPerro*, sDuenio*, int, int, int, int, int)
 * @brief [MODIFICAR ESTADIA - Si el contador de estadias/altas es mayor a cero, permite la modificacion de los datos de la estadia]
 *
 * @param listaEstadias
 * @param listaPerros
 * @param listaDuenios
 * @param lengthEstadias
 * @param lengthPerros
 * @param lengthDuenios
 * @param contadorId
 * @param contadorAltas
 */
void modificarEstadia(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, sDuenio* listaDuenios, int lengthEstadias, int lengthPerros, int lengthDuenios, int contadorId, int contadorAltas)
{
	int id;
	int indexDelId;
	int option;


	if (contadorAltas > 0)
	{
		if ( (listaEstadias != NULL && listaPerros != NULL && listaDuenios != NULL) && (lengthEstadias > -1 && lengthPerros > -1 && lengthDuenios > -1) )
		{

			do
			{
				mostrarListaEstadias(listaEstadias, listaPerros, listaDuenios, lengthEstadias, lengthPerros, lengthDuenios);

				id = getNumeroMayorQueMinimo("Ingrese el ID de la estadia que desea modificar: ", "ERROR! El ID no existe. Por favor reingrese un ID valido: ", ID);
				indexDelId = sEstadiaDiaria_buscarEstadiaPorId(listaEstadias, lengthEstadias, id);

				if (indexDelId != -1)
				{
					modificarEstadiaMenu(listaEstadias, listaPerros, listaDuenios, lengthEstadias, lengthPerros, lengthDuenios, indexDelId);

					option = getIntInMinMaxRange("Desea seguir realizando modificaciones?\n"
												 "---------------------------------------------------------------------------------------------------------------------------------\n"
												 "1. Ingresar otro ID para modificar\n"
												 "2. Volver al menu principal\n\n\n",

												 "ERROR! <<Opcion Invalida>> Reingrese una opcion valida...\n"
												 "Desea seguir realizando modificaciones?\n"
												 "---------------------------------------------------------------------------------------------------------------------------------\n"
												 "1. Ingresar otro ID para modificar\n"
												 "2. Volver al menu principal\n\n\n", 1, 2);

				}
				else
				{
					printf("ERROR ! El ID ingresado no pertenece a ninguna estadia cargada en el sistema.\n"
							"Por favor vuelva a ingresar otro ID...\n\n\n\n");
				}


			} while(option != 2);


		}
		else
		{
			printf("ERROR! <<Invalid length or NULL pointer>>\n\n\n");
			system("pause");
		}

	}
	else
	{
		printf("\nERROR! <<No hay datos cargados en el sistema>>\n\n\n");
		system("pause");
	}

}





/**
 * @fn void modificarEstadiaMenu(sEstadiaDiaria*, sPerro*, sDuenio*, int, int, int, int)
 * @brief [MODIFICAR ESTADIA MENU - Despliega un menu de opciones para modificar telefono de contacto, modificar perro, o volver al menu anterior]
 *
 * @param listaEstadias
 * @param listaPerros
 * @param listaDuenios
 * @param lengthEstadias
 * @param lengthPerros
 * @param lengthDuenios
 * @param index
 */
void modificarEstadiaMenu(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, sDuenio* listaDuenios, int lengthEstadias, int lengthPerros, int lengthDuenios, int index)
{
	int option;

	option = getIntInMinMaxRange("\n\n---------------------------------------------------------------------------------------------------------------------------------\n"
								 "Que desea modificar?\n"
								 "---------------------------------------------------------------------------------------------------------------------------------\n"
								 "1. Telefono de contacto\n"
								 "2. Perro\n\n"
								 "3. Volver\n\n\n",

								 "---------------------------------------------------------------------------------------------------------------------------------\n"
								 "ERROR! Opcion invalida\n"
								 "Que desea modificar?\n"
								 "---------------------------------------------------------------------------------------------------------------------------------\n"
								 "1. Telefono de contacto\n"
								 "2. Perro\n\n"
								 "3. Volver al menu\n\n\n", 1, 3);


	switch(option)
	{
		case 1:
			modificarTelefonoDeContacto(listaEstadias, listaDuenios, lengthEstadias, lengthDuenios, index);
			break;

		case 2:
			modificarPerro(listaPerros, listaEstadias, index);
			break;
	}

}





/**
 * @fn void modificarTelefonoDeContacto(sEstadiaDiaria*, sDuenio*, int, int, int)
 * @brief [MODIFICAR TELEFONO DE CONTACTO - Modificacion de los datos de telefono de la estadia reservada con opcion de telefono de linea o celular posterior carga de la misma en el sistema]
 *
 * @param listaEstadias
 * @param listaDuenios
 * @param lengthEstadias
 * @param lengthDuenios
 * @param index
 */
void modificarTelefonoDeContacto(sEstadiaDiaria* listaEstadias, sDuenio* listaDuenios, int lengthEstadias, int lengthDuenios, int index)
{
	int auxTelefono;
	int option = getIntInMinMaxRange("Ingrese la opcion correspondiente\n"
									 "---------------------------------------------------------------------------------------------------------------------------------\n"
									 "1. Telefono de linea\n"
									 "2. Celular\n\n\n",

									 "ERROR! <<La opcion ingresada no es valida. Reingrese la opcion correspondiente\n"
									 "---------------------------------------------------------------------------------------------------------------------------------\n"
									 "1. Telefono de linea\n"
									 "2. Celular\n\n\n", 1, 2);



	if (option == 1)
	{
		for (int i = 0; i < lengthEstadias; ++i)
		{
			if (i == index)
			{

				for (int j = 0; j < lengthDuenios; ++j)
				{
					if (listaEstadias[i].idDuenio == listaDuenios[j].id)
					{
						auxTelefono = getIntInMinMaxRange("Ingrese telefono de linea (8 digitos): ", "ERROR !\nPor favor reingrese telefono de linea (Debe tener 8 digitos): ", 10000000, 99999999);

						if (verificarModificacionDeEstadia() == 1)
						{
							listaDuenios[j].telefono = auxTelefono;

							printf("\n********************************************************************************************************************************************\n\n"
								   "Has cambiado el telefono de contacto!\n\n"
								   "********************************************************************************************************************************************\n\n\n");
						}
						else
						{
							printf("\n********************************************************************************************************************************************\n\n"
									"No has hecho cambios en las estadias\n\n"
									"********************************************************************************************************************************************\n\n\n");
						}

						break;
					}
				}

				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < lengthEstadias; ++i)
		{
			if (i == index)
			{

				for (int j = 0; j < lengthDuenios; ++j)
				{
					if (listaEstadias[i].idDuenio == listaDuenios[j].id)
					{
						auxTelefono = getIntInMinMaxRange("Ingrese celular (10 digitos): ", "ERROR !\nPor favor reingrese celular (Debe tener 10 digitos): ", 1000000000, 1999999999);

						if (verificarModificacionDeEstadia() == 1)
						{
							listaDuenios[j].telefono = auxTelefono;

							printf("\n********************************************************************************************************************************************\n\n"
								   "Has cambiado el telefono de contacto!\n\n"
								   "********************************************************************************************************************************************\n\n\n");
						}
						else
						{
							printf("\n********************************************************************************************************************************************\n\n"
									"No has hecho cambios en las estadias\n\n"
									"********************************************************************************************************************************************\n\n\n");
						}

						break;
					}
				}

				break;
			}
		}
	}





	system("pause");

}





/**
 * @fn void modificarPerro(sPerro*, sEstadiaDiaria*, int)
 * @brief [MODIFICAR PERRO - Menu de modificacion del perro de la estadia segun opcion elegida por el usuario y posterior carga de la misma en el sistema]
 *
 * @param listaPerros
 * @param listaEstadias
 * @param index
 */
void modificarPerro(sPerro* listaPerros, sEstadiaDiaria* listaEstadias, int index)
{

	int perroSeleccionado = getIntInMinMaxRange("\nCual es el perro que desea registrar en esta estadia?\n"
												"1. Lobo\n"
												"2. Sheila\n"
												"3. Reina\n\n\n",

												"ERROR ! opcion invalida. Por favor reingrese el perro que desea registrar en esta estadia:\n"
												"1. Lobo\n"
												"2. Sheila\n"
												"3. Reina\n\n\n", 1, 3);


	if (verificarModificacionDeEstadia() == 1)
	{
		switch (perroSeleccionado)
		{
			case 1:
				listaEstadias[index].idPerro = listaPerros[0].id;
				break;

			case 2:
				listaEstadias[index].idPerro = listaPerros[1].id;
				break;

			case 3:
				listaEstadias[index].idPerro = listaPerros[2].id;
				break;
		}


		printf("\n********************************************************************************************************************************************\n\n"
				"Has cambiado el perro de la estadia!\n\n"
				"********************************************************************************************************************************************\n\n\n");
	}
	else
	{
		printf("\n********************************************************************************************************************************************\n\n"
				"No has hecho cambios en las estadias\n\n"
				"********************************************************************************************************************************************\n\n\n");

	}


	system("pause");
}





/**
 * @fn void cancelarEstadia(sEstadiaDiaria*, sPerro*, sDuenio*, int, int, int, int*)
 * @brief [CANCELAR ESTADIA - Si el contador de estadias/altas es mayor a cero, permite la eliminacion de una estadia cargada en el sistema. Posee su propio submenu]
 *
 * @param listaEstadias
 * @param listaPerros
 * @param listaDuenios
 * @param lengthEstadias
 * @param lengthPerros
 * @param lengthDuenios
 * @param contadorAltas
 */
void cancelarEstadia(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, sDuenio* listaDuenios, int lengthEstadias, int lengthPerros, int lengthDuenios, int* contadorAltas)
{
	int id;
	int indexDelId;
	int opcion;


	if ( (listaEstadias != NULL && listaPerros != NULL && listaDuenios != NULL) && (lengthEstadias > -1 && lengthPerros > -1 && lengthDuenios > -1) )
	{
		do
		{
			if (*contadorAltas > 0)
			{
				mostrarListaEstadias(listaEstadias, listaPerros, listaDuenios, lengthEstadias, lengthPerros, lengthDuenios);
				id = getNumeroMayorQueMinimo("Ingrese el ID de la estadia que desea cancelar: ", "ERROR! El ID no es valido... Por favor reingrese un ID valido: ", ID);
				indexDelId = sEstadiaDiaria_buscarEstadiaPorId(listaEstadias, lengthEstadias, id);

				if (indexDelId != -1)
				{
					if (verificarCancelacionDeEstadia() == 1)
					{
						sEstadiaDiaria_removerEstadia(listaEstadias, lengthEstadias, id);
						(*contadorAltas)--;

						printf("\n\n********************************************************************************************************************************************\n\n"
								"Has cancelado la estadia !\n\n"
								"********************************************************************************************************************************************\n\n\n");

						system("pause");

					}
					else
					{
						printf("\n********************************************************************************************************************************************\n\n"
								"No has hecho cambios en las estadias\n\n"
								"********************************************************************************************************************************************\n\n\n");

						system("pause");
					}


					opcion = getIntInMinMaxRange("Que desea hacer?\n"
												 "---------------------------------------------------------------------------------------------------------------------------------\n"
												 "1. Seguir cancelando estadias\n"
												 "2. Volver al Menu Principal\n\n",

												 "ERROR! <<Opcion Invalida>> Reingrese una opcion valida...\n"
												 "---------------------------------------------------------------------------------------------------------------------------------\n"
												 "1. Seguir cancelando estadias\n"
												 "2. Volver al Menu Principal\n", 1, 2);

				}
				else
				{
					printf("\n\n\nERROR! <<No existe esa ID o no corresponde a ninguna estadia en el sistema>>\n\n\n");

					opcion = getIntInMinMaxRange("Desea ingresar otro ID?\n"
												 "---------------------------------------------------------------------------------------------------------------------------------\n"
												 "1. Si, ingresar otro ID\n"
												 "2. Volver al Menu Principal\n",

												 "ERROR! El ID no es valido. Desea ingresar otra ID?\n"
												 "---------------------------------------------------------------------------------------------------------------------------------\n"
												 "1. Si, ingresar otro ID\n"
												 "2. Volver al Menu Principal\n", 1, 2);
				}

			}
			else
			{
				printf("\nERROR! <<No hay datos cargados en el sistema>>\n\n\n");
				system("pause");
				break;
			}

		} while(opcion == 1);

	}
	else
	{
		printf("\nERROR! <<Invalid length or NULL pointer>>\n\n\n");
		system("pause");
	}


}





/**
 * @fn void mostrarEstadia(sEstadiaDiaria*, sPerro*, sDuenio*, int, int, int, int, int, int)
 * @brief [MOSTRAR ESTADIA - Muestra la carga individual de una estadia en particular segun subindices de los arrays de cada estructura]
 *
 * @param listaEstadias
 * @param listaPerros
 * @param listaDuenios
 * @param lengthEstadias
 * @param lengthPerros
 * @param lengthDuenios
 * @param indexEstadias
 * @param indexPerros
 * @param indexDuenios
 */
void mostrarEstadia(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, sDuenio* listaDuenios, int lengthEstadias, int lengthPerros, int lengthDuenios, int indexEstadias, int indexPerros, int indexDuenios)
{

	printf("%-20d %-25s %-30d %-20s %d/%d/%d\n", 	listaEstadias[indexEstadias].id,

													listaDuenios[indexDuenios].nombre,
													listaDuenios[indexDuenios].telefono,

													listaPerros[indexPerros].nombre,

													listaEstadias[indexEstadias].fecha.dia,
													listaEstadias[indexEstadias].fecha.mes,
													listaEstadias[indexEstadias].fecha.anio);

}





/**
 * @fn void mostrarListaEstadias(sEstadiaDiaria*, sPerro*, sDuenio*, int, int, int)
 * @brief [MOSTRAR LISTA ESTADIAS - Muestra el total de estadias cargadas en el sistema]
 *
 * @param listaEstadias
 * @param listaPerros
 * @param listaDuenios
 * @param lengthEstadias
 * @param lengthPerros
 * @param lengthDuenios
 */
void mostrarListaEstadias(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, sDuenio* listaDuenios, int lengthEstadias, int lengthPerros, int lengthDuenios)
{

	if ( (listaEstadias != NULL && listaPerros != NULL && listaDuenios != NULL) && (lengthEstadias > -1 && lengthPerros > -1 && lengthDuenios > -1) )
	{

		printf("\n\n---------------------------------------------------------------------------------------------------------------------------------\n"
				"Listado de estadias\n"
				"---------------------------------------------------------------------------------------------------------------------------------\n"
				"%-20s %-25s %-30s %-20s %-20s", "ID", "Nombre Duenio", "Telefono de contacto", "Perro", "Fecha\n"
				"---------------------------------------------------------------------------------------------------------------------------------\n");


		for (int i = 0; i < lengthEstadias; ++i)
		{
			if (listaEstadias[i].espacioVacio == FALSE)
			{
				for (int j = 0; j < lengthPerros; ++j)
				{
					if (listaEstadias[i].idPerro == listaPerros[j].id)
					{

						for (int k = 0; k < lengthDuenios; ++k)
						{
							if (listaEstadias[i].idDuenio == listaDuenios[k].id)
							{
								mostrarEstadia(listaEstadias, listaPerros, listaDuenios, lengthEstadias, lengthPerros, lengthDuenios, i, j, k);
								break;
							}
						}

						break;
					}
				}
			}
		}


	}

	printf("\n\n\n");
}





/**
 * @fn void listarEstadias(sEstadiaDiaria*, sPerro*, sDuenio*, int, int, int, int)
 * @brief [LISTAR ESTADIAS - Si el contador de estadias/altas es mayor que cero, ofrece el listado de las estadias ordenado]
 *
 * @param listaEstadias
 * @param listaPerros
 * @param listaDuenios
 * @param lengthEstadias
 * @param lengthPerros
 * @param lengthDuenios
 * @param contadorAltas
 */
void listarEstadias(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, sDuenio* listaDuenios, int lengthEstadias, int lengthPerros, int lengthDuenios, int contadorAltas)
{

	if (contadorAltas > 0)
	{

		if ( (listaEstadias != NULL && listaPerros != NULL && listaDuenios != NULL) && (lengthEstadias > -1 && lengthPerros > -1 && lengthDuenios > -1) )
		{

			listarEstadiasPorFechaDescendente(listaEstadias, listaDuenios, lengthEstadias, lengthDuenios);
			mostrarListaEstadias(listaEstadias, listaPerros, listaDuenios, lengthEstadias, lengthPerros, lengthDuenios);

		}
		else
		{
			printf("\nERROR! <<Invalid length or NULL pointer>>\n\n\n");
		}

	}
	else
	{
		printf("\nERROR! <<No hay datos cargados en el sistema>>\n\n\n");
	}


	system("pause");
}





/**
 * @fn void listarEstadiasPorFechaDescendente(sEstadiaDiaria*, sDuenio*, int, int)
 * @brief [LISTAR ESTADIAS POR FECHA DESCENDENTE - Ordenamiento de los datos de las estadias reservadas, por orden de fechas descendente y por nombre del duenio en caso de misma fecha]
 *
 * @param listaEstadias
 * @param listaDuenios
 * @param lengthEstadias
 * @param lengthDuenios
 */
void listarEstadiasPorFechaDescendente(sEstadiaDiaria* listaEstadias, sDuenio* listaDuenios, int lengthEstadias, int lengthDuenios)
{
	int limite = lengthEstadias - 1;
	int flagSwap;

	do
	{
		flagSwap = 0;

		for (int i = 0; i < limite; ++i)
		{

			if ( (listaEstadias[i].espacioVacio == FALSE && listaEstadias[i+1].espacioVacio == FALSE) )
			{

				if ( (listaEstadias[i].fecha.anio < listaEstadias[i+1].fecha.anio) )
				{
					sEstadiaDiaria_ordenarFechas(listaEstadias, i);
					sEstadiaDiaria_ordenarIDs(listaEstadias, i);
					sEstadiaDiaria_ordenarIDsPerros(listaEstadias, i);
					sEstadiaDiaria_ordenarIDsDuenios(listaEstadias, i);

					flagSwap = 1;
				}

				else
				{

					if ( (listaEstadias[i].fecha.anio == listaEstadias[i+1].fecha.anio && listaEstadias[i].fecha.mes < listaEstadias[i+1].fecha.mes) )
					{
						sEstadiaDiaria_ordenarFechas(listaEstadias, i);
						sEstadiaDiaria_ordenarIDs(listaEstadias, i);
						sEstadiaDiaria_ordenarIDsPerros(listaEstadias, i);
						sEstadiaDiaria_ordenarIDsDuenios(listaEstadias, i);

						flagSwap = 1;
					}

					else
					{

						if ( (listaEstadias[i].fecha.anio == listaEstadias[i+1].fecha.anio) && (listaEstadias[i].fecha.mes == listaEstadias[i+1].fecha.mes) && (listaEstadias[i].fecha.dia < listaEstadias[i+1].fecha.dia) )

						{
							sEstadiaDiaria_ordenarFechas(listaEstadias, i);
							sEstadiaDiaria_ordenarIDs(listaEstadias, i);
							sEstadiaDiaria_ordenarIDsPerros(listaEstadias, i);
							sEstadiaDiaria_ordenarIDsDuenios(listaEstadias, i);

							flagSwap = 1;
						}

						else
						{

							if ( (listaEstadias[i].fecha.anio == listaEstadias[i+1].fecha.anio) && (listaEstadias[i].fecha.mes == listaEstadias[i+1].fecha.mes) && (listaEstadias[i].fecha.dia == listaEstadias[i+1].fecha.dia) )
							{

								for (int j = 0; j < lengthDuenios; ++j)
								{
									if (listaEstadias[i].idDuenio == listaDuenios[j].id)
									{
										for (int k = 0; k < lengthDuenios; ++k)
										{
											if (listaEstadias[i+1].idDuenio == listaDuenios[k].id)
											{
												if (strcmp(listaDuenios[j].nombre , listaDuenios[k].nombre) == -1)
												{
													sEstadiaDiaria_ordenarIDs(listaEstadias, i);
													sEstadiaDiaria_ordenarIDsPerros(listaEstadias, i);
													sEstadiaDiaria_ordenarIDsDuenios(listaEstadias, i);
													break;
												}
											}
										}

										break;
									}
								}

								flagSwap = 1;
							}

						}

					}

				}

			}

		}

		limite--;

	} while (flagSwap);

}





/**
 * @fn void calcularYMostrarPerroConMasEstadias(sPerro*, sEstadiaDiaria*, sDuenio*, int, int, int, int)
 * @brief [CALCULAR Y MOSTRAR PERRO CON MAS ESTADIAS - Determina cual de los perros es el que tiene mas estadias reservadas en el sistema para luego mostrarlo]
 *
 * @param listaPerros
 * @param listaEstadias
 * @param listaDuenios
 * @param lengthPerros
 * @param lengthEstadias
 * @param lengthDuenios
 * @param contadorAltas
 */
void calcularYMostrarPerroConMasEstadias(sPerro* listaPerros, sEstadiaDiaria* listaEstadias, sDuenio* listaDuenios, int lengthPerros, int lengthEstadias, int lengthDuenios, int contadorAltas)
{
	int contadorEstadiasLobo = 0;
	int contadorEstadiasSheila = 0;
	int contadorEstadiasReina = 0;


	if (contadorAltas > 0)
	{

		if ( (listaPerros != NULL && listaEstadias != NULL && listaDuenios != NULL) && (lengthPerros > -1 && lengthEstadias > -1 && lengthDuenios > -1) )
		{

			for (int i = 0; i < lengthPerros; ++i)
			{
				for (int j = 0; j < lengthEstadias; ++j)
				{
					if (listaPerros[i].id == listaEstadias[j].idPerro)
					{
						switch(i)
						{
							case 0:
								contadorEstadiasLobo++;
								break;

							case 1:
								contadorEstadiasSheila++;
								break;

							case 2:
								contadorEstadiasReina++;
								break;
						}
					}
				}
			}


			if (contadorEstadiasLobo > contadorEstadiasSheila && contadorEstadiasLobo > contadorEstadiasReina)
			{
				mostrarPerroConMasEstadias(listaPerros, listaEstadias, listaDuenios, lengthEstadias, lengthPerros, lengthDuenios, 0);
			}
			else
			{
				if (contadorEstadiasSheila > contadorEstadiasReina)
				{
					mostrarPerroConMasEstadias(listaPerros, listaEstadias, listaDuenios, lengthEstadias, lengthPerros, lengthDuenios, 1);
				}
				else
				{
					mostrarPerroConMasEstadias(listaPerros, listaEstadias, listaDuenios, lengthEstadias, lengthPerros, lengthDuenios, 2);
				}
			}

		}
		else
		{
			printf("ERROR! <<Invalid length or NULL pointer>>\n\n\n");
		}

	}
	else
	{
		printf("ERROR! <<No hay datos cargados en el sistema>>");
	}

	printf("\n\n\n");
	system("pause");
}





/**
 * @fn void mostrarPerroConMasEstadias(sPerro*, sEstadiaDiaria*, sDuenio*, int, int, int, int)
 * @brief [MOSTRAR PERRO CON MAS ESTADIAS - Muestra el perro que tenga mas estadias reservadas cargadas en el sistema]
 *
 * @param listaPerros
 * @param listaEstadias
 * @param listaDuenios
 * @param lengthPerros
 * @param lengthEstadias
 * @param lengthDuenios
 * @param indexPerro
 */
void mostrarPerroConMasEstadias(sPerro* listaPerros, sEstadiaDiaria* listaEstadias, sDuenio* listaDuenios, int lengthPerros, int lengthEstadias, int lengthDuenios, int indexPerro)
{

	printf("\n\nEstadias de %s:\n"
			"---------------------------------------------------------------------------------------------------------------------------------\n", listaPerros[indexPerro].nombre);

	printf("%-20s %-20s %-20s", "Duenio", "Telefono", "Fecha\n"
			"---------------------------------------------------------------------------------------------------------------------------------\n");


	for (int i = 0; i < lengthEstadias; ++i)
	{
		if ( (listaEstadias[i].espacioVacio == FALSE) && (listaEstadias[i].idPerro == listaPerros[indexPerro].id) )
		{
			for (int j = 0; j < lengthDuenios; ++j)
			{
				if (listaEstadias[i].idDuenio == listaDuenios[j].id)
				{

					printf("%-20s %-20d %d/%d/%d\n", listaDuenios[j].nombre,
												     listaDuenios[j].telefono,
												     listaEstadias[i].fecha.dia,
												     listaEstadias[i].fecha.mes,
												     listaEstadias[i].fecha.anio);

				}
			}
		}
	}

}





/**
 * @fn void mostrarPerroConSusEstadias(sPerro*, sEstadiaDiaria*, sDuenio*, int, int, int, int)
 * @brief [MOSTRAR PERRO CON SUS ESTADIAS - Muestra todos los perros con todas sus estadias reservadas cargadas en el sistema]
 *
 * @param listaPerros
 * @param listaEstadias
 * @param listaDuenios
 * @param lengthPerros
 * @param lengthEstadias
 * @param lengthDuenios
 * @param contadorAltas
 */
void mostrarPerroConSusEstadias(sPerro* listaPerros, sEstadiaDiaria* listaEstadias, sDuenio* listaDuenios, int lengthPerros, int lengthEstadias, int lengthDuenios, int contadorAltas)
{

	if (contadorAltas > 0)
	{

		if ( (listaPerros != NULL && listaEstadias != NULL && listaDuenios != NULL) && (lengthPerros > -1 && lengthEstadias > -1 && lengthDuenios > -1) )
		{

			for (int i = 0; i < lengthPerros; ++i)
			{
				if (listaPerros[i].espacioVacio == FALSE)
				{

					printf("\n\nEstadias de %s:\n"
							"---------------------------------------------------------------------------------------------------------------------------------\n", listaPerros[i].nombre);

					printf("%-20s %-20s %-20s", "Duenio", "Telefono", "Fecha\n"
							"---------------------------------------------------------------------------------------------------------------------------------\n");

					for (int j = 0; j < lengthEstadias; ++j)
					{
						if (listaPerros[i].id == listaEstadias[j].idPerro)
						{

							for (int k = 0; k < lengthDuenios; ++k)
							{
								if (listaEstadias[j].idDuenio == listaDuenios[k].id)
								{
									printf("%-20s %-20d %d/%d/%d\n", listaDuenios[k].nombre,
																	 listaDuenios[k].telefono,
																	 listaEstadias[j].fecha.dia,
																	 listaEstadias[j].fecha.mes,
																	 listaEstadias[j].fecha.anio);
								}
							}

						}
					}
				}
			}

		}
		else
		{
			printf("ERROR! <<Invalid length or NULL pointer>>\n\n\n");
		}

	}
	else
	{
		printf("ERROR! <<No hay datos cargados en el sistema>>");
	}


	printf("\n\n\n");
	system("pause");
}





/**
 * @fn int generarId(int)
 * @brief [GENERAR ID - Genera un ID a partir del DEFINE ID y de la cantidad de ID's registrados]
 *
 * @param contadorId
 * @return
 */
int generarId(int contadorId)
{
	int generatedId;

	if (contadorId == 0)
	{
		generatedId = ID;
	}
	else
	{
		generatedId = ID + contadorId;
	}

	return generatedId;
}












