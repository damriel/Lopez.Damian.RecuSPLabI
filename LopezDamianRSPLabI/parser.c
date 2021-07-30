#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "bicicleta.h"
#include "parser.h"

/** \brief Parsea los datos los datos desde el archivo .csv (modo texto).
 *
 * \param path char*
 * \param pArrayListBici LinkedList*
 * \return int
 *
 */
int parser_biciFromText(FILE* pFile, LinkedList* pArrayListBici)
{
    int retorno=0;
    char buffer[4][50];
    eBicicleta* auxBici=NULL;

    if(pFile!=NULL && pArrayListBici!=NULL)
    {
        auxBici=bicicleta_new();
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        if(auxBici!=NULL)
        {
            while(!feof(pFile))
            {
                if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3])<4)
                {
                    break;
                }
                else
                {
                    auxBici = bici_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                    ll_add(pArrayListBici, auxBici);
                    retorno = 1;
                }
            }
        }
    }
    return retorno;
}

