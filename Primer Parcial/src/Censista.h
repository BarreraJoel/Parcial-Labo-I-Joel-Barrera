/*
 * Censista.h
 *
 *  Created on: 19 may. 2022
 *      Author: Joel Barrera
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_

#include <stdio.h>
#include <stdlib.h>
#include "input-UTN.h"

#define LIBRE 0
#define OCUPADO 1
#define MAX_NOMBRE 20
#define MAX_TELEFONO 10

typedef struct{
	int legajoCensista;
	char nombre[MAX_NOMBRE];
	int edad;
	char telefono[MAX_TELEFONO];
	int isEmpty;
}eCensista;

int eCensista_inicializarArray(eCensista* aCensistas, int limite);
int eCensista_getIndiceEspacioLibre(eCensista* aCensistas, int limite);
int eCensista_getIndicePorLegajo(eCensista* aCensistas, int limite, int legajoBuscado);

//ALTA
int eCensista_alta(eCensista* aCensistas, int limite);

//MODIFICAR
int eCensista_modificar(eCensista* aCensistas, int limite);

//BAJA

//LISTAR
void eCensista_listarUno(eCensista censista);
int eCensista_listarTodos(eCensista* aCensistas, int limite);









#endif /* CENSISTA_H_ */
