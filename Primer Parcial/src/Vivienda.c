/*
 * Vivienda.c
 *
 *  Created on: 19 may. 2022
 *      Author: Joel Barrera
 */

#include "Vivienda.h"

/**
 * @brief Incrementa el ID de una vivienda de a uno
 *
 * @return Retorna el ID incrementado
 */
 static int incrementarId();
 static int incrementarId()
{
	static int idIncremental = 20000;
	return idIncremental++;
}

int eVivienda_listarUno(eVivienda* aViviendas, int limiteViviendas, tipoVivienda* aTipos, int limiteTipos, int idBuscado)
{
	int retorno = -1;
	int i;
	int j;

	if(aViviendas != NULL && limiteViviendas > 0 && aTipos != NULL && limiteTipos > 0 && idBuscado >= 20000)
	{
		printf("\n\n-----------------------------------------------------------------------------------------\n");
		printf("************************************ DATOS DE LA VIVIENDA ***********************************");
		printf("\n-------------------------------------------------------------------------------------------\n");
		printf("ID            CALLE           CANT.PERSONAS    HABITACIONES   TIPO VIVIENDA   LEGAJO CENSISTA");
		printf("\n-------------------------------------------------------------------------------------------\n");
		for(i = 0; i < limiteViviendas; i++)
		{
			for(j = 0; j < limiteTipos; j++)
			{
				if((*(aViviendas+i)).isEmpty == OCUPADO && (*(aViviendas+i)).idVivienda == idBuscado)
				{
					if((*(aViviendas+i)).tipoVivienda == (*(aTipos+j)).tipoVivienda)
					{
						printf("%-9d"
								"%-10s"
								"%10d"
								"%15d"
								"%15d"
								"%15d\n",(*(aViviendas+i)).idVivienda,(*(aViviendas+i)).calle,(*(aViviendas+i)).cantidadPersonas,(*(aViviendas+i)).cantidadHabitaciones,(*(aViviendas+i)).tipoVivienda,(*(aViviendas+i)).legajoCensista);
						retorno = 0;
						break;
					}
				}
			}
		}
	}
	return retorno;
}

int eVivienda_listarTodos(eVivienda* aViviendas, int limiteViviendas, tipoVivienda* aTipos, int limiteTipos)
{
	int retorno = -1;
	int i;
	int j;

	if(aViviendas != NULL && limiteViviendas > 0 && aTipos != NULL && limiteTipos > 0)
	{
		printf("\n\n------------------------------------------------------------------------------------------\n");
		printf("*********************************** LISTADO DE VIVIENDAS *************************************");
		printf("\n--------------------------------------------------------------------------------------------\n");
		printf("ID            CALLE           CANT.PERSONAS    HABITACIONES   TIPO VIVIENDA   LEGAJO CENSISTA");
		printf("\n--------------------------------------------------------------------------------------------\n");
		for(i = 0; i < limiteViviendas; i++)
		{
			for(j = 0; j < limiteTipos; j++)
			{
				if((*(aViviendas+i)).isEmpty == OCUPADO)
				{
					if((*(aViviendas+i)).tipoVivienda == (*(aTipos+j)).tipoVivienda)
					{
						printf("%-9d"
								"%-10s"
								"%10d"
								"%15d"
								"%15s"
								"%15d\n",(*(aViviendas+i)).idVivienda,(*(aViviendas+i)).calle,(*(aViviendas+i)).cantidadPersonas,(*(aViviendas+i)).cantidadHabitaciones,(*(aTipos+j)).descripcion,(*(aViviendas+i)).legajoCensista);
					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

int eVivienda_inicializarArray(eVivienda* aViviendas, int limite)
{
	int retorno = -1;
	int i;

	if(aViviendas != NULL && limite > 0)
	{
		for(i = 0; i < limite; i++)
		{
			(*(aViviendas+i)).isEmpty = LIBRE;
		}
		retorno = 0;
	}
	return retorno;
}

int eVivienda_getIndiceEspacioLibre(eVivienda* aViviendas, int limite)
{
	int retorno = -1;
	int i;

	if(aViviendas != NULL && limite > 0)
	{
		for(i = 0; i < limite; i++)
		{
			if((*(aViviendas+i)).isEmpty == LIBRE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int eVivienda_getIndicePorId(eVivienda* aViviendas, int limite, int idBuscado)
{
	int retorno = -1;
	int i;

	if(aViviendas != NULL && limite > 0 && idBuscado >= 20000)
	{
		for(i = 0; i < limite; i++)
		{
			if((*(aViviendas+i)).isEmpty == OCUPADO && (*(aViviendas+i)).idVivienda == idBuscado)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int eVivienda_alta(eVivienda* aViviendas, int limiteViviendas)
{
	int retorno = -1;
	int indiceLibre;
	eVivienda auxiliar;

	if(aViviendas != NULL && limiteViviendas > 0)
	{
		indiceLibre = eVivienda_getIndiceEspacioLibre(aViviendas, limiteViviendas);

		if(indiceLibre >= 0 && indiceLibre < limiteViviendas)
		{
			if(utn_getCalle(auxiliar.calle,"\nIngrese la calle: ","\nLa calle ingresada no es valida\n",4,MAX_CALLE,3) == 1)
			{
				if(utn_getNumeroEntero(&auxiliar.cantidadPersonas,"\nIngrese la cantidad de personas que habitan el hogar: ","\nLa cantidad ingresada no es valida\n",1,10,3) == 1)
				{
					if(utn_getNumeroEntero(&auxiliar.cantidadHabitaciones,"\nIngrese la cantidad de habitaciones del hogar: ","\nLa cantidad ingresada no es valida\n",1,5,3) == 1)
					{
						if(utn_getNumeroEntero(&auxiliar.tipoVivienda,"\nTIPO DE VIVIENDA\n1.CASA\n2.DEPARTAMENTO\n3.CASILLA\n4.RANCHO\nElija una opcion: ","\nLa opcion ingresada no es valida\n",1,4,3) == 1)
						{
							if(utn_getNumeroEntero(&auxiliar.legajoCensista,"\nIngrese el legajo de censista: ","\nEl legajo ingresado no es valido\n",100,102,3) == 1)
							{
								auxiliar.idVivienda = incrementarId();
								auxiliar.isEmpty = OCUPADO;
								(*(aViviendas+indiceLibre)) = auxiliar;
								retorno = 0;
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}

int eVivienda_modificarUno(eVivienda* pVivienda, int opcionModificar)
{
	int retorno = -1;
	eVivienda auxiliar;

	if(pVivienda != NULL && opcionModificar > 0)
	{
		switch(opcionModificar)
		{
			case 1:
				if(utn_getCalle(auxiliar.calle,"\nIngrese la calle: ","\nLa calle ingresada no es valida\n",4,MAX_CALLE,3) == 1)
				{
					strcpy(pVivienda->calle,auxiliar.calle);
					retorno = 0;
				}
				break;
			case 2:
				if(utn_getNumeroEntero(&auxiliar.cantidadPersonas,"\nIngrese la cantidad de personas del hogar: ","\nLa cantidad ingresada no es valida\n",1,10,3) == 1)
				{
					pVivienda->cantidadPersonas = auxiliar.cantidadPersonas;
					retorno = 0;
				}
				break;
			case 3:
				if(utn_getNumeroEntero(&auxiliar.cantidadHabitaciones,"\nIngrese la cantidad de habitaciones del hogar: ","\nLa cantidad ingresada no es valida\n",1,5,3) == 1)
				{
					pVivienda->cantidadHabitaciones = auxiliar.cantidadHabitaciones;
					retorno = 0;
				}
				break;
			case 4:
				if(utn_getNumeroEntero(&auxiliar.tipoVivienda,"\nTIPO DE VIVIENDA\n1.CASA\n2.DEPARTAMENTO\n3.CASILLA\n4.RANCHO\nIngrese una opcion: ","\nLa opcion ingresada no es valida\n",1,4,3) == 1)
				{
					pVivienda->tipoVivienda = auxiliar.tipoVivienda;
					retorno = 0;
				}
				break;
			case 5:
				break;
			default:
				break;
		}
	}
	return retorno;
}

int eVivienda_modificar(eVivienda* aViviendas, int limiteViviendas, tipoVivienda* aTipos, int limiteTipos, int contAltas)
{
	int retorno = -1;
	int idIngresado;
	int opcionModificacion;
	int indiceId;

	if(aViviendas != NULL && limiteViviendas > 0 && aTipos != NULL && limiteTipos > 0 && contAltas > 0)
	{
		eVivienda_listarTodos(aViviendas, limiteViviendas, aTipos, limiteTipos);
		if(utn_getNumeroEntero(&idIngresado,"\nIngrese el ID de la vivienda a modificar: ","\nEl ID ingresado no es valido\n",20000,19999+contAltas,3) == 1)
		{
			indiceId = eVivienda_getIndicePorId(aViviendas,limiteViviendas,idIngresado);
			if(indiceId >= 0)
			{
				do
				{
					eVivienda_listarUno(aViviendas, limiteViviendas, aTipos, limiteTipos, idIngresado);
					if(utn_getNumeroEntero(&opcionModificacion, "\nMENU DE MODIFICACION"
																"\n1.MODIFICAR CALLE"
																"\n2.MODIFICAR CANTIDAD DE PERSONAS"
																"\n3.MODIFICAR CANTIDAD DE HABITACIONES"
																"\n4.MODIFICAR TIPO DE VIVIENDA"
																"\n5.SALIR"
																"\nIngrese una opcion: ","\nLa opcion ingresada no es valida\n",1,5,3) == 1)
					{
						if(eVivienda_modificarUno((aViviendas+indiceId),opcionModificacion) == 0)
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

int eVivienda_baja(eVivienda* aViviendas, int limiteViviendas, tipoVivienda* aTipos, int limiteTipos, int contAltas)
{
	int retorno = -1;
	int idIngresado;
	int indiceId;
	int confirmacion;


	if(aViviendas != NULL && limiteViviendas > 0 && aTipos != NULL && limiteTipos > 0 && contAltas > 0)
	{
		eVivienda_listarTodos(aViviendas, limiteViviendas, aTipos, limiteTipos);
		if(utn_getNumeroEntero(&idIngresado,"\nIngrese el numero del ID a dar de baja: ","\nEl ID ingresado no es valido\n",20000,19999+contAltas,3) == 1)
		{
			indiceId = eVivienda_getIndicePorId(aViviendas,limiteViviendas,idIngresado);

			if(indiceId >= 0)
			{
				eVivienda_listarUno(aViviendas, limiteViviendas, aTipos, limiteTipos, idIngresado);
				if(utn_getNumeroEntero(&confirmacion,"\nEsta seguro/a que quiere dar de baja la vivienda?\n1.SI\n2.NO\nElija una opcion: ",
													 "\nLa opcion ingresada no es valida\n",1,2,3) == 1)
				{
					if(confirmacion == 1)
					{
						(*(aViviendas+indiceId)).isEmpty = LIBRE;
						retorno = 0;
					}
				}
			}
		}
	}
	return retorno;
}

int eVivienda_ordenador(eVivienda* aViviendas, int limite)
{
	int retorno = -1;
	int i;
	int flagSwap;
	eVivienda auxiliar;

	if(aViviendas != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(i = 0; i < limite-1; i++)
			{
				if((*(aViviendas+i)).isEmpty == LIBRE || (*(aViviendas+i+1)).isEmpty == LIBRE)
				{
					continue;
				}
				if(strncmp((*(aViviendas+i)).calle,(*(aViviendas+i+1)).calle,MAX_CALLE) > 0)
				{
					flagSwap = 1;
					auxiliar = (*(aViviendas+i));
					(*(aViviendas+i)) = (*(aViviendas+i+1));
					(*(aViviendas+i+1)) = auxiliar;
				}
				else if(strncmp((*(aViviendas+i)).calle,(*(aViviendas+i+1)).calle,MAX_CALLE) == 0)
				{
					if((*(aViviendas+i)).cantidadPersonas > (*(aViviendas+i+1)).cantidadPersonas)
					{
						flagSwap = 1;
						auxiliar = (*(aViviendas+i));
						(*(aViviendas+i)) = (*(aViviendas+i+1));
						(*(aViviendas+i+1)) = auxiliar;
					}
				}
			}
			limite--;
		}while(flagSwap == 1);
		retorno = 0;
	}
	return retorno;
}








