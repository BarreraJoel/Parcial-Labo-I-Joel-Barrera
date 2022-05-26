/*
 * Censista.c
 *
 *  Created on: 19 may. 2022
 *      Author: Joel Barrera
 */

#include "Censista.h"

/**
 * @brief Incrementa el legajo del censista en uno
 *
 * @return Retorna el ID incrementado
 */
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
			if(utn_getNombre(auxiliar.nombre,"\nIngrese el nombre: ","\nEl nombre ingresado no es valido\n",4,MAX_NOMBRE,3) == 1)
			{
				if(utn_getNumeroEntero(&auxiliar.edad,"\nIngrese la edad: ","\nLa edad ingresada no es valida\n",18,90,3) == 1)
				{
					if(utn_getTelefono(auxiliar.telefono,MAX_TELEFONO,"\nIngrese el telefono: ","\nEl telefono ingresado no es valido\n",3) == 1)
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

int eCensista_modificarUno(eCensista* pCensista, int opcionModificar)
{
	int retorno = -1;
	eCensista auxiliar;

	if(pCensista != NULL && opcionModificar > 0)
	{
		switch(opcionModificar)
		{
			case 1:
				if(utn_getNombre(auxiliar.nombre,"\nIngrese el nombre: ","\nEl nombre ingresado no es valido\n",4,MAX_NOMBRE,3) == 1)
				{
					strcpy(pCensista->nombre,auxiliar.nombre);
					retorno = 0;
				}
				break;
			case 2:
				if(utn_getNumeroEntero(&auxiliar.edad,"\nIngrese la edad: ","\nLa edad ingresada no es valida\n",18,90,3) == 1)
				{
					pCensista->edad = auxiliar.edad;
					retorno = 0;
				}
				break;
			case 3:
				if(utn_getTelefono(auxiliar.telefono,MAX_TELEFONO,"\nIngrese el telefono: ","\nEl telefono ingresado no es valido\n",3) == 1)
				{
					strcpy(pCensista->telefono,auxiliar.telefono);
					retorno = 0;
				}
				break;
			case 4:
				break;
			default:
				break;
		}
	}
	return retorno;
}

int eCensista_modificar(eCensista* aCensistas, int limite)
{
	int retorno = -1;
	int legajoIngresado;
	int indiceLegajo;
	int opcionModificacion;

	if(aCensistas != NULL && limite > 0)
	{
		eCensista_listarTodos(aCensistas, limite);
		if(utn_getNumeroEntero(&legajoIngresado,"\nIngrese el legajo del censista a modificar: ","\nEl legajo ingresado no es valido\n",100,103,3) == 1)
		{
			indiceLegajo = eCensista_getIndicePorLegajo(aCensistas, limite, legajoIngresado);
			if(indiceLegajo >= 0)
			{
				do
				{
					eCensista_listarUno((*(aCensistas+indiceLegajo)));
					if(utn_getNumeroEntero(&opcionModificacion, "\nMENU DE MODIFICACION"
																"\n1.MODIFICAR NOMBRE"
																"\n2.MODIFICAR EDAD"
																"\n3.MODIFICAR TELEFONO"
																"\n4.SALIR"
																"\nIngrese una opcion: ","\nLa opcion ingresada no es valida\n",1,4,3) == 1)
					{
						if(eCensista_modificarUno((aCensistas+indiceLegajo),opcionModificacion) == 0)
						{
							printf("\n*** La modificacion se realizo con exito ***\n");
							retorno = 0;
						}
					}
				}while(opcionModificacion != 5);

			}
		}
	}
	return retorno;
}

int eCensista_baja(eCensista* aCensistas, int limite)
{
	int retorno = -1;
	int legajoIngresado;
	int indiceLegajo;
	int confirmacion;

	if(aCensistas != NULL && limite > 0)
	{
		eCensista_listarTodos(aCensistas, limite);
		if(utn_getNumeroEntero(&legajoIngresado,"\nIngrese el numero del ID a dar de baja: ","\nEl ID ingresado no es valido\n",100,102,3) == 1)
		{
			indiceLegajo = eCensista_getIndicePorLegajo(aCensistas,limite,legajoIngresado);

			if(indiceLegajo >= 0)
			{
				eCensista_listarUno((*(aCensistas+indiceLegajo)));
				if(utn_getNumeroEntero(&confirmacion,"\nEsta seguro/a que quiere dar de baja al censista?\n1.SI\n2.NO\nElija una opcion: ",
													 "\nLa opcion ingresada no es valida\n",1,2,3) == 1)
				{
					if(confirmacion == 1)
					{
						(*(aCensistas+indiceLegajo)).isEmpty = LIBRE;
						retorno = 0;
					}
				}
			}
		}
	}
	return retorno;

}










