/*
 ============================================================================
 Name        : Primer Parcial
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Vivienda.h"
#include "Censista.h"
#include "input-UTN.h"

#define MAX_VIVIENDAS 3
#define MAX_TIPOS 4
#define MAX_CENSISTAS 3

int main(void)
{
	setbuf(stdout, NULL);

	eVivienda listaViviendas[MAX_VIVIENDAS];
	tipoVivienda listaTipos[MAX_TIPOS] = {{1,"CASA"},{2,"DEPARTAMENTO"},{3,"CASILLA"},{4,"RANCHO"}};
	eCensista listaCensistas[MAX_CENSISTAS] = {{100,"Ana",34,"1203-2345"},
											   {101,"Juan",24,"4301-5467"},
											   {102,"Sol",47,"5902-3748"}};

	char opcionMenu;
	int contAltas = 0;
	int flagAlta = 0;

	eVivienda_inicializarArray(listaViviendas, MAX_VIVIENDAS);
	do
	{
		if(utn_getCaracter(&opcionMenu, "\n\n***** MENU DE OPCIONES *****"
										"\nA. ALTA VIVIENDA"
										"\nB. MODIFICAR VIVIENDA"
										"\nC. BAJA VIVIENDA"
										"\nD. LISTAR VIVIENDAS"
										"\nE. LISTAR CENSISTAS"
										"\nIngrese una opcion: ","\nLa opcion ingresada no es valida\n",'A','E',3) == 1)
		{
			switch(opcionMenu)
			{
				case 'A':
					if(contAltas < MAX_VIVIENDAS)
					{
						if(eVivienda_alta(listaViviendas, MAX_VIVIENDAS) == 0)
						{
							printf("\n*** La carga se realizo con exito ***\n");
							contAltas++;
							flagAlta = 1;
						}
					}
					else
					{
						printf("\n*** Ya no hay mas espacio para guardar datos ***\n");
					}
					break;
				case 'B':
					if(flagAlta == 1 && contAltas > 0)
					{
						if(eVivienda_modificar(listaViviendas, MAX_VIVIENDAS, listaTipos, MAX_TIPOS, contAltas) == 0)
						{
							printf("\n*** Las modificaciones se realizaron con exito ***\n");
						}
					}
					else
					{
						printf("\n*** Debe ingresar por lo menos una vivienda ***\n");
					}
					break;
				case 'C':
					if(flagAlta == 1 && contAltas > 0)
					{
						if(eVivienda_baja(listaViviendas, MAX_VIVIENDAS, listaTipos, MAX_TIPOS, contAltas) == 0)
						{
							printf("\n*** La baja se realizo con exito ***\n");
							contAltas--;
						}
					}
					else
					{
						printf("\n*** Debe ingresar por lo menos una vivienda ***\n");
					}
					break;
				case 'D':
					if(flagAlta == 1 && contAltas > 0)
					{
						eVivienda_ordenador(listaViviendas, MAX_VIVIENDAS);
						eVivienda_listarTodos(listaViviendas, MAX_VIVIENDAS, listaTipos, MAX_TIPOS);
					}
					else
					{
						printf("\n*** Debe ingresar por lo menos una vivienda ***\n");
					}
					break;
				case 'E':
					eCensista_listarTodos(listaCensistas, MAX_CENSISTAS);
					break;
				default:
					break;
			}
		}
	}while(opcionMenu != 'F');

	return EXIT_SUCCESS;
}
