
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Perro.h"
#include "Inputs.h"





/**
 * @fn void inicializarPerritos(sPerro*, int)
 * @brief [Inicializar Perritos -Pone a todos los campos 'espacio vacio' de la estructura Perro en VERDADERO(1)]
 *
 * @param perritos
 * @param length
 */
void inicializarPerritos(sPerro* listaPerros, int lengthPerros)
{

	if (listaPerros != NULL && lengthPerros > -1)
	{

		for (int i = 0; i < lengthPerros; ++i)
		{
			listaPerros[i].espacioVacio = TRUE;
		}

	}
	else
	{
		printf("ERROR !\nInvalid length or null pointer\n\n");
		system("pause");
	}

}





/**
 * @fn void sPerro_hardcodeo(sPerro*, int)
 * @brief [sPerro Hardcodeo - Ingreso de datos a priori de 3 perritos con sus respectivos datos (ID; Nombre; Raza; Edad)]
 *
 * @param perritos
 * @param length
 */
void sPerro_hardcodeo(sPerro* listaPerros, int lengthPerros)
{
	int ids[] = {7000, 7001, 7002};
	char nombres[][MAX_NOMBRE] = {"Lobo", "Sheila", "Reina"};
	char razas[][MAX_NOMBRE] = {"Sharpei", "Golden", "Galgo"};
	int edades[] = {2, 12, 13};

	for (int i = 0; i < lengthPerros-7; ++i)
	{
		listaPerros[i].id = ids[i];
		strcpy(listaPerros[i].nombre, nombres[i]);
		strcpy(listaPerros[i].raza, razas[i]);
		listaPerros[i].edad = edades[i];
		listaPerros[i].espacioVacio = FALSE;
	}

}





/**
 * @fn void mostrarPerro(sPerro*, int)
 * @brief [Mostrar Perro - Muestra la carga individual de un perrito en particular]
 *
 * @param perritos
 * @param index
 */
void mostrarPerro(sPerro* listaPerros, int index)
{

	printf("%-20d %-25s %-30s %-20d\n", listaPerros[index].id,
										listaPerros[index].nombre,
										listaPerros[index].raza,
										listaPerros[index].edad);

}





/**
 * @fn void mostrarListaPerros(sPerro*, int)
 * @brief [Mostrar Lista Perros - Muestra el total de perritos cargados en el sistema]
 *
 * @param perritos
 * @param length
 */
void mostrarListaPerros(sPerro* listaPerros, int lengthPerros)
{

		if (listaPerros != NULL && lengthPerros > -1)
		{
			printf("\n\n---------------------------------------------------------------------------------------------------------------------------------\n"
					"Listado de perritos\n"
					"---------------------------------------------------------------------------------------------------------------------------------\n"
					"%-20s %-25s %-30s %-20s", "ID", "Nombre", "Raza", "Edad\n"
					"---------------------------------------------------------------------------------------------------------------------------------\n");

			for (int i = 0; i < lengthPerros; ++i)
			{
				if (listaPerros[i].espacioVacio == FALSE)
				{
					mostrarPerro(listaPerros, i);
				}
			}

			printf("\n\n\n");
		}

}





/**
 * @fn void listarPerros(sPerro*, int, int)
 * @brief [Listar Perros - Si el contador de estadias/altas es mayor a cero, permite mostrar la lista completa de perritos cargados en sistema]
 *
 * @param listaPerros
 * @param length
 * @param contadorAltas
 */
void listarPerros(sPerro* listaPerros, int lengthPerros, int contadorAltas)
{

	if (contadorAltas > 0)
	{

		if (listaPerros != NULL && lengthPerros > -1)
		{
			mostrarListaPerros(listaPerros, lengthPerros);
		}
		else
		{
			printf("\nERROR ! Los datos ingresados son incorrectos. Intentelo nuevamente\n\n\n");
		}

	}
	else
	{
		printf("\nERROR ! No hay datos cargados en el sistema.\n\n");
	}

	system("pause");
}






/**
 * @fn int cargarPerritoPorId(sPerro*, int, int)
 * @brief [Cargar Perrito Por ID - Muestra primero la lista de perritos para que el usuario seleccione mediante identificador ID que perrito quiere cargar en su estadia]
 *
 * @param listaPerritos
 * @param length
 * @param index
 * @return Retorna un NUMERO ENTERO que es la ID del perrito.
 */
int cargarPerritoPorId(sPerro* listaPerros, int lengthPerros, int index)
{
	mostrarListaPerros(listaPerros, lengthPerros);

	int idDelPerrito = getIntInMinMaxRange("Ingrese el numero de ID del perrito que quiera cargar en la estadia: ",
									   	   "ERROR ! ID invalida\nPor favor reingrese un numero de ID valido de un perrito que desee cargar en la estadia: ", 7000, 7002);


	return idDelPerrito;
}






/**
 * @fn int calcularPromedioEdadPerros(sPerro*, int, int)
 * @brief [Calcular Promedio Edad Perros - Realiza el calculo del promedio de edad de todos los perritos cargados en el sistema]
 *
 * @param perritos
 * @param length
 * @param contadorAltas
 * @return Retorna un NUMERO ENTERO: [-1] si hubo un error / [0] si se pudo realizar la operacion
 */
int calcularPromedioEdadPerros(sPerro* listaPerros, int lengthPerros, int contadorAltas)
{
	int value = -1;
	int acumuladorEdad = 0;
	int contadorPerritos = 0;
	float promedioEdad;

	if (contadorAltas > 0)
	{
		if (listaPerros != NULL && lengthPerros > -1)
		{
			for (int i = 0; i < lengthPerros; ++i)
			{
				if (listaPerros[i].espacioVacio == FALSE)
				{
					acumuladorEdad = acumuladorEdad + listaPerros[i].edad;
					contadorPerritos++;
				}
			}

			promedioEdad = (float)acumuladorEdad / contadorPerritos;
			printf("\nPROMEDIO DE EDAD DE LOS PERRITOS: %.2f\n\n\n\n", promedioEdad);


		}
		else
		{
			printf("ERROR !\nDatos invalidos. Intente nuevamente\n\n\n");
		}

	}
	else
	{
		printf("\nERROR !\nNo se puede sacar el promedio porque no hay datos cargados\n\n\n");
	}

	system("pause");

	return value;
}
























