/*
 * Censista.c
 *
 *  Created on: 19 may. 2022
 *      Author: Joel Barrera
 */

#include "Censista.h"

static int incrementarLegajo();
static int incrementarLegajo()
{
	static int legajoIncremental = 100;
	return legajoIncremental++;
}


void eCensista_listarUno(eCensista censista)
{
	printf("%-10d %-10s %-6d %s\n",censista.legajoCensista,censista.nombre,censista.edad,censista.telefono);
}

int eCensista_listarTodos(eCensista* aCensistas, int limite)
{
	int retorno = -1;
	int i;

	if(aCensistas != NULL && limite > 0)
	{
		printf("\n----------------------------------------");
		printf("\n******** LISTADO DE CENSISTAS **********");
		printf("\n----------------------------------------\n");
		printf("LEGAJO    NOMBRE     EDAD    TELEFONO");
		printf("\n----------------------------------------\n");
		for(i = 0; i < limite; i++)
		{
			eCensista_listarUno((*(aCensistas+i)));
		}
		retorno = 0;
	}
	return retorno;
}


int eCensista_inicializarArray(eCensista* aCensistas, int limite)
{
	int retorno = -1;
	int i;

	if(aCensistas != NULL && limite > 0)
	{
		for(i = 0; i < limite; i++)
		{
			(*(aCensistas+i)).isEmpty = LIBRE;
		}
		retorno = 0;
	}
	return retorno;
}

int eCensista_getIndiceEspacioLibre(eCensista* aCensistas, int limite)
{
	int retorno = -1;
	int i;

	if(aCensistas != NULL && limite > 0)
	{
		for(i = 0; i < limite; i++)
		{
			if((*(aCensistas+i)).isEmpty == LIBRE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int eCensista_getIndicePorLegajo(eCensista* aCensistas, int limite, int legajoBuscado)
{
	int retorno = -1;
	int i;

	if(aCensistas != NULL && limite > 0 && legajoBuscado >= 100)
	{
		for(i = 0; i < limite; i++)
		{
			if((*(aCensistas+i)).isEmpty == OCUPADO && (*(aCensistas+i)).legajoCensista == legajoBuscado)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int eCensista_alta(eCensista* aCensistas, int limite)
{
	int retorno = -1;
	int indiceLibre;
	eCensista auxiliar;

	if(aCensistas != NULL && limite > 0)
	{
		indiceLibre = eCensista_getIndiceEspacioLibre(aCensistas, limite);

		if(indiceLibre >= 0)
		{
			if(utn_getNombre(auxiliar.nombre, "\nIngrese el nombre: ", "\nEl nombre ingresado no es valido\n", 4, MAX_NOMBRE, 3) == 1)
			{
				if(utn_getNumeroEntero(&auxiliar.edad, "\nIngrese la edad: ", "\nLa edad ingresada no es valida\n", 16, 90, 3) == 1)
				{
					if(utn_getTelefono(auxiliar.telefono, MAX_TELEFONO, "\nIngrese el telefono: ", "\nEl telefono ingresado no es valido\n", 3) == 1)
					{
						auxiliar.legajoCensista = incrementarLegajo();
						auxiliar.isEmpty = OCUPADO;
						(*(aCensistas+indiceLibre)) = auxiliar;
						retorno = 0;
					}
				}
			}
		}
	}
	return retorno;
}

int eCensista_modificar(eCensista* aCensistas, int limite)
{
	int retorno = -1;
	int legajoIngresado;
	int indiceLegajo;

	if(aCensistas != NULL && limite > 0)
	{
		eCensista_listarTodos(aCensistas, limite);
		if(utn_getNumeroEntero(&legajoIngresado, "\nIngrese el legajo del censista a modificar: ", "\nEl legajo ingresado no es valido\n", 100, 103, 3) == 1)
		{
			indiceLegajo = eCensista_getIndicePorLegajo(aCensistas, limite, legajoIngresado);
			if(indiceLegajo >= 0)
			{
//				do
//				{
//
//				}while();
			}
		}
	}

	return retorno;
}









