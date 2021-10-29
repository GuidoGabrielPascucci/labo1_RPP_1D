
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Inputs.h"
#include "Validations.h"




/**
 * @fn int getIntInMinMaxRange(char*, char*, int, int)
 * @brief [GET INT IN MIN MAX RANGE - Permite al usuario ingresar un numero entero en un rango de un numero minimo y un numero maximo]
 *
 * @param message
 * @param errorMessage
 * @param min
 * @param max
 * @return Retorna el NUMERO ENTERO luego de pasar por su respectiva validacion
 */
int getIntInMinMaxRange(char* message, char* errorMessage, int min, int max)
{
	int enterIntNumber;

	if (message != NULL && errorMessage != NULL && min < max)
	{
		printf("%s", message);
		fflush(stdin);
		scanf("%d", &enterIntNumber);

		while ( (validacionNumerica(enterIntNumber)) || (enterIntNumber < min || enterIntNumber > max) )
		{
			printf("%s", errorMessage);
			fflush(stdin);
			scanf("%d", &enterIntNumber);
		}

	}

	return enterIntNumber;
}


/**
 * @fn int getNumeroMayorQueMinimo(char*, char*, int)
 * @brief [GET NUMERO MAYOR QUE MINIMO - Permite al usuario ingresar un numero entero que sea mayor a un numero minimo establecido]
 *
 * @param message
 * @param errorMessage
 * @param min
 * @return Retorna el NUMERO ENTERO luego de pasar por su respectiva validacion
 */
int getNumeroMayorQueMinimo(char* message, char* errorMessage, int min)
{
	int enterIntNumber;

	printf("%s", message);
	fflush(stdin);
	scanf("%d", &enterIntNumber);

	while (enterIntNumber < min) {
		printf("%s", errorMessage);
		fflush(stdin);
		scanf("%d", &enterIntNumber);
	}

	return enterIntNumber;
}





/**
 * @fn void getString(char*, char*, char*, int)
 * @brief [GET STRING - Permite al usuario ingresar una cadena de caracteres que no supere la cantidad maxima de caracteres establecida]
 *
 * @param string
 * @param message
 * @param errorMessage
 * @param max
 */
void getString(char* string, char* message, char* errorMessage, int max)
{
	char notValidateString[200];
	int length;

	printf("%s", message);
	fflush(stdin);
	scanf("%[^\n]", notValidateString);
	length = strlen(notValidateString);

	while (length > max || stringValidation(notValidateString, length) )
	{
		printf("%s", errorMessage);
		fflush(stdin);
		scanf("%[^\n]", notValidateString);
		length = strlen(notValidateString);
	}


	strcpy(string, notValidateString);
}












