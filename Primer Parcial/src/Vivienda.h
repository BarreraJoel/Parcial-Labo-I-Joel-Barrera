/*
 * Vivienda.h
 *
 *  Created on: 19 may. 2022
 *      Author: Joel Barrera
 */

#ifndef VIVIENDA_H_
#define VIVIENDA_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "input-UTN.h"
#include "Censista.h"

#define LIBRE 0
#define OCUPADO 1
#define MAX_CALLE 25
#define MAX_DESCRIPCION 20

typedef struct{
	int tipoVivienda;
	char descripcion[MAX_DESCRIPCION];
}tipoVivienda;

typedef struct{
	int idVivienda;
	char calle[MAX_CALLE];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int legajoCensista;
	int isEmpty;
}eVivienda;

/**
 * @brief Inicializa el array de viviendas en LIBRE[0]
 *
 * @param aViviendas Puntero a un array de viviendas
 * @param limite Largo del array
 * @return Retorna -1 [Puntero NULL - Largo no valido] - 0 [OK]
 */
int eVivienda_inicializarArray(eVivienda* aViviendas, int limite);

/**
 * @brief Busca la primera posicion libre del array y retorna el indice de esa posicion
 *
 * @param aViviendas Puntero a un array de viviendas
 * @param limite Largo del array
 * @return Retorna -1 [Puntero NULL - Largo no valido - sin espacio] - Indice [OK]
 */
int eVivienda_getIndiceEspacioLibre(eVivienda* aViviendas, int limite);

/**
 * @brief Busca la posicion de la vivienda mediante un id ingresado y retorna el indice
 *
 * @param aViviendas Puntero a un array de viviendas
 * @param limite Largo del array
 * @param idBuscado ID ingresado
 * @return Retorna -1 [Puntero NULL - Largo no valido - ID no encontrado] - Indice [OK]
 */
int eVivienda_getIndicePorId(eVivienda* aViviendas, int limite, int idBuscado);

//ALTA
/**
 * @brief Da de alta a una vivienda dentro del array de viviendas
 *
 * @param aViviendas Puntero a un array de viviendas
 * @param limite Largo del array
 * @return Retorna -1 [Puntero NULL - Largo no valido - Alta no completada] - 0 [OK]
 */
int eVivienda_alta(eVivienda* aViviendas, int limite);

//MODIFICAR
/**
 * @brief Modifica un campo seleccionado de la vivienda
 *
 * @param pVivienda Puntero a estructura de tipo eVivienda
 * @param opcionModificar Opcion ingresada a modificar
 * @return Retorna -1 [Puntero NULL - Opcion no valida - Modificacion no completada] - 0 [OK]
 */
int eVivienda_modificarUno(eVivienda* pVivienda, int opcionModificar);

/**
 * @brief Permite el ingreso del ID de la vivienda y el campo a modificar
 *
 * @param aViviendas Puntero a un array de viviendas
 * @param limiteViviendas Largo del array de viviendas
 * @param aTipos Puntero a un array de tipos de viviendas
 * @param limiteTipos Largo del array de tipos de viviendas
 * @param contAltas Contador de altas que determina el maximo de ID
 * @return Retorna -1 [Punteros NULL - Largos no validos - Modificacion no completada] - 0 [OK]
 */
int eVivienda_modificar(eVivienda* aViviendas, int limiteViviendas, tipoVivienda* aTipos, int limiteTipos, int contAltas);

//BAJA
/**
 * @brief Da de baja una vivienda del array mediante un ID ingresado
 *
 * @param aViviendas Puntero a un array de viviendas
 * @param limiteViviendas Largo del array de viviendas
 * @param aTipos Puntero a un array de tipos de viviendas
 * @param limiteTipos Largo del array de tipos de viviendas
 * @param contAltas Contador de altas que determina el maximo de ID
 * @return Retorna -1 [Punteros NULL - Largos no validos - Baja no completada] - 0 [OK]
 */
int eVivienda_baja(eVivienda* aViviendas, int limiteViviendas, tipoVivienda* aTipos, int limiteTipos, int contAltas);

//ORDENAR
/**
 * @brief Ordena el array en base al nombre y la cantidad de personas
 *
 * @param aViviendas Puntero a un array de viviendas
 * @param limite Largo del array de viviendas
 * @return Retorna -1 [Puntero NULL - Largo no valido] - 0 [OK]
 */
int eVivienda_ordenador(eVivienda* aViviendas, int limite);

//LISTAR
/**
 * @brief Lista una vivienda del array
 *
 * @param aViviendas Puntero a un array de viviendas
 * @param limiteViviendas Largo del array de viviendas
 * @param aTipos Puntero a un array de tipos de viviendas
 * @param limiteTipos Largo del array de tipos de viviendas
 * @param idBuscado ID de la vivienda
 * @return Retorna -1 [Punteros NULL - Largos no validos - ID no valido] - 0 [OK]
 */
int eVivienda_listarUno(eVivienda* aViviendas, int limiteViviendas, tipoVivienda* aTipos, int limiteTipos, int idBuscado);

/**
 * @brief Lista el array de viviendas
 *
 * @param aViviendas Puntero a un array de viviendas
 * @param limiteViviendas Largo del array de viviendas
 * @param aTipos Puntero a un array de tipos de viviendas
 * @param limiteTipos Largo del array de tipos de viviendas
 * @return Retorna -1 [Punteros NULL - Largos no validos] - 0 [OK]
 */
int eVivienda_listarTodos(eVivienda* aViviendas, int limiteViviendas, tipoVivienda* aTipos, int limiteTipos);


#endif /* VIVIENDA_H_ */









