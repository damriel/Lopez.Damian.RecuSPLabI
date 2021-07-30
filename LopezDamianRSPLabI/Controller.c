#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "bicicleta.h"
#include "parser.h"
#include "dam.h"

/** \brief Carga los datos desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListBici LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListBici)
{
    int retorno=-1;
    FILE* pFile=NULL;
    if(path!=NULL && pArrayListBici!=NULL)
    {
        pFile = fopen(path,"r");
        if(pFile != NULL)
        {
            parser_biciFromText(pFile, pArrayListBici);
            retorno=0;
            fclose(pFile);
        }
    }

    return retorno;
}

/** \brief Carga los datos desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 *
int controller_loadFromBinary(char* path , LinkedList* pArrayListPais)
{
    int retorno = -1;
    FILE* pFile=NULL;
    if(path!=NULL && pArrayListPais!=NULL)
    {
        pFile = fopen(path,"rb");
        if(pFile!=NULL)
        {
            if(parser_PaisFromBinary(pFile, pArrayListPais))
            {
                retorno = 0;
            }
            fclose(pFile);
        }
    }
    return retorno;
}*/

/** \brief Listar bicicletas
 *
 * \param path char*
 * \param pArrayListBici LinkedList*
 * \return int
 *
 */
int controller_ListarBicicletas(LinkedList* pArrayListBici)
{
    int retorno = -1;
    int tam;
    eBicicleta* aux=NULL;

    if(pArrayListBici!=NULL)
    {
        tam=ll_len(pArrayListBici);
        retorno=0;
        printf("\n====================================================\n");
        printf("             LISTADO DE PAISES\n");
        printf("====================================================\n");
        printf("  ID          Nombre            Tipo   Tiempo\n");
        for(int i=0; i<tam; i++)
        {
            aux = (eBicicleta*)ll_get(pArrayListBici, i);
            bicicleta_mostrarUnaBici(aux);
        }
        printf("\n");
    }
    return retorno;
}



/** \brief Ordena una lista de paises por cantidad de vacunados con primera dosis
 *
 * \param pArrayListPais LinkedList*
 * \return int
 *
 *
int controller_sortPaises(LinkedList* pArrayListPais)
{
	int retorno = 1;

    printf("Ordenando...\n");
    if(ll_sort(pArrayListPais, pais_compareByVacunados1dosis, 0)!=0)
    {
        retorno=-1;
    }

    return retorno;
}*/

/** \brief muestra el o los nombres de los paises con mayor porcentaje de no vacunados
 *
 * \param pArrayListPais LinkedList*
 * \return int
 *
 *
int controller_mostrarMasCastigado(LinkedList* pArrayListPais)
{
    int retorno=1;
    int tam;
    int mayorSinVac=0;
    int bufferSinVac=0;
    char paisMasCastigado[51];
    ePais* auxPais = NULL;

    if(pArrayListPais!=NULL)
    {
        tam=ll_len(pArrayListPais);
        for(int i=0; i<tam; i++)
        {
            auxPais=ll_get(pArrayListPais,i);
            if(auxPais!=NULL &&
               pais_getSinVacunar(auxPais,&bufferSinVac) &&
               (i==0 || bufferSinVac>mayorSinVac))
            {
                mayorSinVac=bufferSinVac;
                retorno=0;
            }
        }
        printf("Pais/es con menos personas vacunadas:\n");
        for(int i=0; i<tam; i++)
        {
            auxPais=ll_get(pArrayListPais,i);
            if(auxPais!=NULL &&
               pais_getSinVacunar(auxPais,&bufferSinVac) &&
               bufferSinVac==mayorSinVac)
            {
                pais_getNombre(auxPais,paisMasCastigado);
                printf("Nombre: %s - Porcentaje de no vacunados: %d\n",paisMasCastigado,bufferSinVac);
            }
        }
    }
    return retorno;
}*/

/** \brief Guarda los datos en el archivo .csv (modo texto).
 *
 * \param path char*
 * \param pArrayListBici LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListBici)
{
	int retorno=-1;
	int id;
	int tiempo;
	char nombre[128];
	char tipo[128];
	eBicicleta* auxBici=NULL;
	FILE* pFile=NULL;
	if(path!=NULL && pArrayListBici!=NULL)
    {
        pFile = fopen(path, "w");
        if(pFile==NULL)
        {
            retorno = 0;
        }
        else
        {
            fprintf(pFile, "id_bike,nombre,tipo,tiempo\n");
            for(int i=0; i<ll_len(pArrayListBici); i++)
            {
                auxBici = (eBicicleta*) ll_get(pArrayListBici, i);
                if(auxBici!=NULL &&
                   bicicleta_getId(auxBici, &id) &&
                   bicicleta_getNombre(auxBici, nombre) &&
                   bicicleta_getTipo(auxBici, tipo) &&
                   bicicleta_getTiempo(auxBici, &tiempo))
                {
                       fprintf(pFile, "%d,%s,%s,%d\n", id,nombre,tipo,tiempo);
                }
            }
            retorno = 1;
            fclose(pFile);
        }
    }
	return retorno;
}

/** \brief Ordena una lista de bicicletas por tipo
 *
 * \param pArrayListBici LinkedList*
 * \return int
 *
 */
int controller_sortBicicletas(LinkedList* pArrayListBici)
{
	int retorno = 1;

    printf("Ordenando...\n");
    if(ll_sort(pArrayListBici, bicicleta_compareByTipoTiempo, 0)!=0)
    {
        retorno=-1;
    }

    return retorno;
}
