
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Perro.h"
#include "Inputs.h"





/**
 * @fn void sPerro_inicializarPerritos(sPerro*, int)
 * @brief [sPerro INICIALIZAR PERRITOS - Pone todos los campos 'espacioVacio' de la estructura sPerro en TRUE(1)]
 *
 * @param listaPerros
 * @param lengthPerros
 */
void sPerro_inicializarPerritos(sPerro* listaPerros, int lengthPerros)
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
 * @fn void sPerro_hardcodearPerros(sPerro*, int)
 * @brief [sPerro HARDCODEAR PERROS - Ingreso los datos de 3 perros con sus respectivos datos (ID; Nombre; Raza; Edad) y los carga en el sistema]
 *
 * @param listaPerros
 * @param lengthPerros
 */
void sPerro_hardcodearPerros(sPerro* listaPerros, int lengthPerros)
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
 * @fn void sPerro_mostrarPerro(sPerro*, int)
 * @brief [sPerro MOSTRAR PERRO - Muestra la carga individual de un perrito en particular]
 *
 * @param listaPerros
 * @param index
 */
void sPerro_mostrarPerro(sPerro* listaPerros, int index)
{

	printf("%-20d %-25s %-30s %-20d\n", listaPerros[index].id,
										listaPerros[index].nombre,
										listaPerros[index].raza,
										listaPerros[index].edad);

}





/**
 * @fn void sPerro_mostrarListaPerros(sPerro*, int)
 * @brief [sPerro MOSTRAR LISTA PERROS - Muestra el total de perritos cargados en el sistema]
 *
 * @param listaPerros
 * @param lengthPerros
 */
void sPerro_mostrarListaPerros(sPerro* listaPerros, int lengthPerros)
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
					sPerro_mostrarPerro(listaPerros, i);
				}
			}

			printf("\n\n\n");
		}

}





/**
 * @fn void sPerro_listarPerros(sPerro*, int, int)
 * @brief [sPerro LISTAR PERROS - Si el contador de estadias/altas es mayor a cero, permite mostrar la lista completa de perritos cargados en sistema]
 *
 * @param listaPerros
 * @param lengthPerros
 * @param contadorAltas
 */
void sPerro_listarPerros(sPerro* listaPerros, int lengthPerros, int contadorAltas)
{

	if (contadorAltas > 0)
	{

		if (listaPerros != NULL && lengthPerros > -1)
		{
			sPerro_mostrarListaPerros(listaPerros, lengthPerros);
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
 * @fn int sPerro_cargarPerritoPorId(sPerro*, int, int)
 * @brief [sPerro CARGAR PERRITO POR ID - Muestra primero la lista de perritos para que el usuario seleccione mediante identificador ID que perrito quiere cargar en su estadia]
 *
 * @param listaPerritos
 * @param length
 * @param index
 * @return Retorna un NUMERO ENTERO que es la ID del perrito.
 */
int sPerro_cargarPerritoPorId(sPerro* listaPerros, int lengthPerros, int index)
{
	sPerro_mostrarListaPerros(listaPerros, lengthPerros);

	int idDelPerrito = getIntInMinMaxRange("Ingrese el numero de ID del perrito que quiera cargar en la estadia: ",
									   	   "ERROR ! ID invalida\nPor favor reingrese un numero de ID valido de un perrito que desee cargar en la estadia: ", 7000, 7002);


	return idDelPerrito;
}






/**
 * @fn int sPerro_calcularPromedioEdadPerros(sPerro*, int, int)
 * @brief [sPerro CALCULAR PROMEDIO EDAD PERROS - Realiza el calculo del promedio de edad de todos los perritos cargados en el sistema]
 *
 * @param listaPerros
 * @param lengthPerros
 * @param contadorAltas
 * @return Retorna un NUMERO ENTERO: [-1] si hubo un error / [0] si se pudo realizar la operacion
 */
int sPerro_calcularPromedioEdadPerros(sPerro* listaPerros, int lengthPerros, int contadorAltas)
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












