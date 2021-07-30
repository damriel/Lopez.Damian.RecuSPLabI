#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"

/** \brief setea el campo indicado de la estructura pasada como primer parametro con el valor indicado como segundo parametro
 *
 * \param this eBicicleta* estructura a la que se le desea asignar un valor en el campo determinado
 * \param id int valor a ser asignado en el campo
 * \return int retorna (0) si this es NULL o si el valor a asignar no es valido
 *                     (1) si se pudo asignar el valor.
 *
 */
int bicicleta_setId(eBicicleta* this, int id)
{
    int retorno=0;
    if(this!=NULL && id>0)
    {
        this->id_bike=id;
        retorno=1;
    }
    return retorno;
}

/** \brief obtiene el valor del campo indicado de la estructura pasada como primer parametro y lo devuelve por referencia a la direccion de memoria pasada como segundo parametro.
 *
 * \param this eBicicleta* estructura de la que se desea obtener el valor del campo determinado.
 * \param id int* direccion de memoria donde se almacenara el valor obtenido.
 * \return int retorna (0) si this es NULL o (1) si se obtuvo el valor.
 *
 */
int bicicleta_getId(eBicicleta* this, int* id)
{
    int retorno=0;
    if(this!=NULL)
    {
        *id = this->id_bike;
        retorno=1;
    }
    return retorno;
}

/** \brief setea el campo indicado de la estructura pasada como primer parametro con el valor indicado como segundo parametro
 *
 * \param this eBicicleta* estructura a la que se le desea asignar un valor en el campo determinado
 * \param nombre char* valor a ser asignado en el campo
 * \return int retorna (0) si this es NULL o si el valor a asignar no es valido
 *                     (1) si se pudo asignar el valor.
 *
 */
int bicicleta_setNombre(eBicicleta* this, char* nombre)
{
    int retorno=0;
    if(this!=NULL && nombre!=NULL && strlen(nombre)>1 && strlen(nombre)<=30)
    {
        strcpy(this->nombre,nombre);
        retorno=1;
    }
    return retorno;
}

/** \brief obtiene el valor del campo indicado de la estructura pasada como primer parametro y lo devuelve por referencia a la direccion de memoria pasada como segundo parametro.
 *
 * \param this eBicicleta* estructura de la que se desea obtener el valor del campo determinado.
 * \param nombre char* direccion de memoria donde se almacenara el valor obtenido.
 * \return int retorna (0) si this es NULL o (1) si se obtuvo el valor.
 *
 */
int bicicleta_getNombre(eBicicleta* this, char* nombre)
{
    int retorno=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=1;
    }
    return retorno;
}

/** \brief setea el campo indicado de la estructura pasada como primer parametro con el valor indicado como segundo parametro
 *
 * \param this eBicicleta* estructura a la que se le desea asignar un valor en el campo determinado
 * \param tipo char* valor a ser asignado en el campo
 * \return int retorna (0) si this es NULL o si el valor a asignar no es valido
 *                     (1) si se pudo asignar el valor.
 *
 */
int bicicleta_setTipo(eBicicleta* this, char* tipo)
{
    int retorno=0;
    if(this!=NULL && tipo!=NULL && strlen(tipo)>1 && strlen(tipo)<=30)
    {
        strcpy(this->tipo,tipo);
        retorno=1;
    }
    return retorno;
}

/** \brief obtiene el valor del campo indicado de la estructura pasada como primer parametro y lo devuelve por referencia a la direccion de memoria pasada como segundo parametro.
 *
 * \param this eBicicleta* estructura de la que se desea obtener el valor del campo determinado.
 * \param tipo char* direccion de memoria donde se almacenara el valor obtenido.
 * \return int retorna (0) si this es NULL o (1) si se obtuvo el valor.
 *
 */
int bicicleta_getTipo(eBicicleta* this, char* tipo)
{
    int retorno=0;
    if(this!=NULL && tipo!=NULL)
    {
        strcpy(tipo,this->tipo);
        retorno=1;
    }
    return retorno;
}

/** \brief setea el campo indicado de la estructura pasada como primer parametro con el valor indicado como segundo parametro
 *
 * \param this eBicicleta* estructura a la que se le desea asignar un valor en el campo determinado
 * \param id int valor a ser asignado en el campo
 * \return int retorna (0) si this es NULL o si el valor a asignar no es valido
 *                     (1) si se pudo asignar el valor.
 *
 */
int bicicleta_setTiempo(eBicicleta* this, int tiempo)
{
    int retorno=0;
    if(this!=NULL && tiempo>0)
    {
        this->tiempo=tiempo;
        retorno=1;
    }
    return retorno;
}

/** \brief obtiene el valor del campo indicado de la estructura pasada como primer parametro y lo devuelve por referencia a la direccion de memoria pasada como segundo parametro.
 *
 * \param this eBicicleta* estructura de la que se desea obtener el valor del campo determinado.
 * \param id int* direccion de memoria donde se almacenara el valor obtenido.
 * \return int retorna (0) si this es NULL o (1) si se obtuvo el valor.
 *
 */
int bicicleta_getTiempo(eBicicleta* this, int* tiempo)
{
    int retorno=0;
    if(this!=NULL)
    {
        *tiempo = this->tiempo;
        retorno=1;
    }
    return retorno;
}

/** \brief Solicita espacio en memoria suficiente para una nueva estructura, seteando sus valores "por defecto".
 *
 * \return ePais* retorna la direccion de memoria del espacio asignado.
 *
 */
eBicicleta* bicicleta_new()
{
    eBicicleta* nuevaBici = (eBicicleta*)malloc(sizeof(eBicicleta));
    if(nuevaBici!=NULL)
    {
        nuevaBici->id_bike=0;
        strcpy(nuevaBici->nombre,"");
        strcpy(nuevaBici->tipo,"");
        nuevaBici->tiempo=0;
    }
    return nuevaBici;
}

/** \brief Solicita espacio en memoria suficiente para una nueva estructura, recibiendo los valores de cada campo como cadenas de caracteres y haciendo
 *         las conversiones a cada tipo de dato segun corresponda.
 *
 * \param idStr char* valor para el campo ID.
 * \param nombreStr char* valor para el campo Nombre.
 * \param tipoStr char* valor para el campo Tipo.
 * \param tiempostr char* valor para el campo Tiempo.
 * \return eBicicleta* retorna la direccion de memoria del espacio asignado.
 *
 */
eBicicleta* bici_newParametros(char* idStr, char* nombreStr, char* tipoStr, char* tiempoStr)
{
    eBicicleta* nuevaBici = bicicleta_new();
    if(nuevaBici!=NULL)
    {
        bicicleta_setId(nuevaBici, atoi(idStr));
        bicicleta_setNombre(nuevaBici, nombreStr);
        bicicleta_setTipo(nuevaBici, tipoStr);
        bicicleta_setTiempo(nuevaBici, atoi(tiempoStr));
    }
    return nuevaBici;
}

/** \brief Imprime por pantalla un elemento del tipo eBicicleta.
 *
 * \param this eBicicleta* direccion de memoria del elemento que se desea imprimir.
 * \return int retorna (0) si this es NULL o si falla cualquiera de los getters.
 *                     (1) si pudo imprimir el elemento.
 *
 */
int bicicleta_mostrarUnaBici(eBicicleta* this)
{
    int retorno = 0;
    int id;
    char nombre[32];
    char tipo[32];
    int tiempo;
    if(this!=NULL &&
       bicicleta_getId(this, &id) &&
       bicicleta_getNombre(this, nombre) &&
       bicicleta_getTipo(this, tipo) &&
       bicicleta_getTiempo(this, &tiempo))
    {
        printf(" %4d   %14s       %8s  %4d\n",id,nombre,tipo,tiempo);
        retorno=1;
    }
    return retorno;
}

int bicicleta_filtradoPorBMX(void* p)
{
    int retorno=0;
    eBicicleta* unaBici = NULL;
    if(p!=NULL)
    {
        unaBici = (eBicicleta*)p;
        if(strcmp(unaBici->tipo, "BMX")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int bicicleta_filtradoPorPlayera(void* p)
{
    int retorno=0;
    eBicicleta* unaBici = NULL;
    if(p!=NULL)
    {
        unaBici = (eBicicleta*)p;
        if(strcmp(unaBici->tipo, "PLAYERA")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int bicicleta_filtradoPorMTB(void* p)
{
    int retorno=0;
    eBicicleta* unaBici = NULL;
    if(p!=NULL)
    {
        unaBici = (eBicicleta*)p;
        if(strcmp(unaBici->tipo, "MTB")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int bicicleta_filtradoPorPaseo(void* p)
{
    int retorno=0;
    eBicicleta* unaBici = NULL;
    if(p!=NULL)
    {
        unaBici = (eBicicleta*)p;
        if(strcmp(unaBici->tipo, "PASEO")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

/** \brief Compara el campo vac1dosis de dos elementos y retorna 0 o 1 segun cual sea mayor
 *
 * \param bici1 void* direccion de memoria del primer elemento
 * \param bici2 void* direccion de memoria del segundo elemento
 * \return int retorna (-1) si no debe swapear
 *                     (1) si debe swapear
 *                     (0)
 *
 */
int bicicleta_compareByTipoTiempo(void* bici1, void* bici2)
{
	int retorno;

	if(bici1!=NULL && bici2!=NULL)
    {
        if(((strcmp(((eBicicleta*)bici1)->tipo, ((eBicicleta*)bici2)->tipo)<0) ||
            ((strcmp(((eBicicleta*)bici1)->tipo, ((eBicicleta*)bici2)->tipo)==0) && (((eBicicleta*)bici1)->tiempo >= ((eBicicleta*)bici2)->tiempo))))
        {
            retorno=1;
        }
        else if((strcmp(((eBicicleta*)bici1)->tipo, ((eBicicleta*)bici2)->tipo)>0))
        {
            retorno=-1;
        }
        else
        {
            retorno=0;
        }
    }

	return retorno;
}
