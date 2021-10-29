

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Inputs.h"





/**
 * @fn int verificarCancelacionDeEstadia(void)
 * @brief [VERIFICAR CANCELACION DE ESTADIA - Validacion de seguridad para confirmar la cancelacion de la estadia o para deshacer los cambios]
 *
 * @return Retorna un NUMERO ENTERO: [1] si se confirma la cancelacion / [2] si no se cancela la estadia
 */
int verificarCancelacionDeEstadia(void)
{
	int option = getIntInMinMaxRange("\n\n---------------------------------------------------------------------------------------------------------------------------------\n"
									 "Verificacion de seguridad\n"
									 "Confirmas que quieres cancelar esta estadia?\n"
									 "---------------------------------------------------------------------------------------------------------------------------------\n"
									 "1. SI, confirmar la cancelacion de la estadia\n"
									 "2. NO, quiero mantener esta estadia\n\n\n",

									 "\n\n---------------------------------------------------------------------------------------------------------------------------------\n"
									 "ERROR! <<La opcion ingresada no es valida>> Por favor reingrese una opcion...\n"
									 "Verificacion de seguridad\n"
									 "Confirmas que quieres cancelar esta estadia?\n"
									 "---------------------------------------------------------------------------------------------------------------------------------\n"
									 "1. SI, confirmar la cancelacion de la estadia\n"
									 "2. NO, quiero mantener esta estadia\n\n\n", 1, 2);


	return option;
}





/**
 * @fn int verificarModificacionDeEstadia(void)
 * @brief [VERIFICAR MODIFICACION DE ESTADIA - Validacion de seguridad para confirmar la modificacion del perro en una estadia]
 *
 * @return Retorna un NUMERO ENTERO: [1] si se realiza la modificacion / [2] si no se realiza la modificacion
 */
int verificarModificacionDeEstadia(void)
{
	int verificacion;

	verificacion = getIntInMinMaxRange("\n---------------------------------------------------------------------------------------------------------------------------------\n"
									   "Verificacion de seguridad:\n"
									   "Confirmas que quieres realizar la modificacion?\n"
									   "---------------------------------------------------------------------------------------------------------------------------------\n"
									   "1. SI, deseo realizar la modificacion y guardar los cambios\n"
									   "2. NO, deshacer los cambios y volver atras\n\n\n",

									   "ERROR! <<La opcion ingresada no es valida>> Por favor reingrese una opcion...\n"
									   "Confirmas que quieres realizar la modificacion?\n"
									   "---------------------------------------------------------------------------------------------------------------------------------\n"
									   "1. SI, confirmar la modificacion y guardar los cambios\n"
									   "2. NO, cancelar\n\n\n", 1, 2);

	return verificacion;
}





/**
 * @fn int validacionNumerica(int)
 * @brief [VALIDACION NUMERICA - Valida que solo se puedan ingresar numeros]
 *
 * @param number
 * @return Retorna un NUMERO ENTERO: [-1] si hay error / [0] si el numero ingresado es un digito del 0 al 9
 */
int validacionNumerica(int number)
{
	int value = -1;

	if (!isdigit(number))
	{
		value = 0;
	}


	return value;
}





/**
 * @fn int stringValidation(char*, int)
 * @brief [STRING VALIDATION - Valida que la cadena de caracteres contenga solo letras del alfabeto, y no contenga simbolos ni numeros]
 *
 * @param string
 * @param length
 * @return Retorna un NUMERO ENTERO: [-1] si hubo un error / [0] si la cadena ingresada son letras.
 */
int stringValidation(char* string, int length)
{
	int functionValue = 0;


	for (int i = 0; i < length; ++i)
	{
		if ( (isdigit(string[i])) || string[i] < 32 || (string[i] > 32 && string[i] < 65) || (string[i] > 90 && string[i] < 97) || string[i] > 122 )
		{
			functionValue = -1;
			break;
		}
	}


	if (functionValue != -1)
	{
		for (int i = 0; i < length; ++i)
		{
			if (i == 0)
			{
				string[i] = toupper(string[i]);
			}
			else
			{
				string[i] = tolower(string[i]);
			}
		}
	}


	return functionValue;
}









