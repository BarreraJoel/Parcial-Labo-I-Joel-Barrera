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

/**
 * @brief Inicializa el array de censistas en LIBRE[0]
 *
 * @param aCensistas Puntero al array de censistas
 * @param limite Largo del array
 * @return Retorna -1 [Puntero NULL - Largo no valido] - 0 [OK]
 */
int eCensista_inicializarArray(eCensista* aCensistas, int limite);

/**
 * @brief Busca el indice de la primera posicion libre del array y la retorna
 *
 * @param aCensistas Puntero al array de censistas
 * @param limite Largo del array
 * @return Retorna -1 [Puntero NULL - Largo no valido - sin espacio] - Indice [OK]
 */
int eCensista_getIndiceEspacioLibre(eCensista* aCensistas, int limite);

/**
 * @brief Busca la posicion de la vivienda mediante un id ingresado y retorna el indice
 *
 * @param aCensistas Puntero al array de censistas
 * @param limite Largo del array
 * @param legajoBuscado Legajo ingresado
 * @return Retorna -1 [Puntero NULL - Largo no valido - Legajo no encontrado] - Indice [OK]
 */
int eCensista_getIndicePorLegajo(eCensista* aCensistas, int limite, int legajoBuscado);

//ALTA
/**
 * @brief Da de alta a un censista dentro del array de censistas
 *
 * @param aCensistas Puntero al array de censistas
 * @param limite Largo del array
 * @return Retorna -1 [Puntero NULL - Largo no valido - Alta no completada] - 0 [OK]
 */
int eCensista_alta(eCensista* aCensistas, int limite);

//MODIFICAR
/**
 * @brief Modifica un campo seleccionado de la vivienda
 *
 * @param pCensista Puntero a estructura de tipo eCensista
 * @param opcionModificar Opcion ingresada a modificar
 * @return Retorna -1 [Puntero NULL - Opcion no valida - Modificacion no completada] - 0 [OK]
 */
int eCensista_modificarUno(eCensista* pCensista, int opcionModificar);

/**
 * @brief Permite el ingreso del legajo del censista y el campo a modificar
 *
 * @param aCensistas Puntero al array de censistas
 * @param limite Largo del array
 * @return Retorna -1 [Punteros NULL - Largos no validos - Modificacion no completada] - 0 [OK]
 */
int eCensista_modificar(eCensista* aCensistas, int limite);

//BAJA
/**
 * @brief Da de baja a un censista del array mediante el legajo ingresado
 *
 * @param aCensistas Puntero al array de censistas
 * @param limite Largo del array
 * @return Retorna -1 [Punteros NULL - Largos no validos - Baja no completada] - 0 [OK]
 */
int eCensista_baja(eCensista* aCensistas, int limite);

//LISTAR
/**
 * @brief Lista un censista del array
 *
 * @param censista Estructura del tipo eCensista a mostrar
 */
void eCensista_listarUno(eCensista censista);

/**
 * @brief Lista a todos los censistas del array
 *
 * @param aCensistas Puntero al array de censistas
 * @param limite Largo del array
 * @return Retorna -1 [Puntero NULL - Largo no valido] - 0 [OK]
 */
int eCensista_listarTodos(eCensista* aCensistas, int limite);









#endif /* CENSISTA_H_ */
