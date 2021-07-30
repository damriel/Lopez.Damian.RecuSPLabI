#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dam.h"
#include "LinkedList.h"
#include "Controller.h"
#include "bicicleta.h"

int main()
{
    srand(time(NULL));
    int opcion;
    int opcionFiltro;
    int flagFiltro;
    char archivo[20] = " ";
    LinkedList* listaBicicletas = ll_newLinkedList();
    LinkedList* listaConValores = NULL;
    LinkedList* listaFiltrada = NULL;
    LinkedList* listaOrdenada = NULL;

    do
    {
        opcion = dam_menuOpciones();
        switch(opcion)
        {
        case 1:
            printf("Ingrese el nombre del archivo a cargar (bicicletas.csv): ");
            fflush(stdin);
            scanf("%s",archivo);
            if(!controller_loadFromText(archivo,listaBicicletas))
            {
                printf("Bicicletas cargadas con exito!\n\n");
            }
            else
            {
                printf("Ocurrio un error intentando abrir el archivo (no existe, no se pudo abrir o esta corrompido).\n\n");
            }
            break;
        case 2:
            if(ll_isEmpty(listaBicicletas))
            {
                printf("Aun no hay bicicletas cargadas.\n");
            }
            else
            {
                controller_ListarBicicletas(listaBicicletas);
            }
            break;
        case 3:
            if(ll_isEmpty(listaBicicletas))
            {
                printf("Aun no hay bicicletas cargadas.\n");
            }
            else
            {
                listaConValores = ll_map(listaBicicletas,asignarValores);
                controller_ListarBicicletas(listaConValores);
                printf("\n\nTIEMPOS ASIGNADOS EXITOSAMENTE! \n\n");
            }
            break;
        case 4:
            if(listaConValores==NULL || ll_isEmpty(listaConValores))
            {
                printf("Aun no se asignaron los tiempos. Seleccione la opcion 3 y vuelva a intentarlo.\n");
            }
            else
            {
                flagFiltro=0;
                do{
                    opcionFiltro = dam_menuFiltrado();
                    switch(opcionFiltro)
                    {
                    case 1:
                        listaFiltrada = ll_filter(listaConValores, bicicleta_filtradoPorBMX);
                        printf("\nIngrese el nombre para guardar el listado de bicicletas BMX: ");
                        fflush(stdin);
                        scanf("%s",archivo);
                        strcpy(archivo,strcat(archivo,".csv"));
                        if(controller_saveAsText(archivo,listaFiltrada))
                        {
                            printf("Lista filtrada guardada con exito!\n");
                        }
                        else
                        {
                            printf("Hubo un error al intentar guardar la lista filtrada.\n");
                        }
                        flagFiltro=1;
                        break;
                    case 2:
                        listaFiltrada = ll_filter(listaConValores, bicicleta_filtradoPorPlayera);
                        printf("\nIngrese el nombre para guardar el listado de bicicletas Playeras: ");
                        fflush(stdin);
                        scanf("%s",archivo);
                        strcpy(archivo,strcat(archivo,".csv"));
                        if(controller_saveAsText(archivo,listaFiltrada))
                        {
                            printf("Lista filtrada guardada con exito!\n");
                        }
                        else
                        {
                            printf("Hubo un error al intentar guardar la lista filtrada.\n");
                        }
                        flagFiltro=1;
                        break;
                    case 3:
                        listaFiltrada = ll_filter(listaConValores, bicicleta_filtradoPorMTB);
                        printf("\nIngrese el nombre para guardar el listado de bicicletas MTV: ");
                        fflush(stdin);
                        scanf("%s",archivo);
                        strcpy(archivo,strcat(archivo,".csv"));
                        if(controller_saveAsText(archivo,listaFiltrada))
                        {
                            printf("Lista filtrada guardada con exito!\n");
                        }
                        else
                        {
                            printf("Hubo un error al intentar guardar la lista filtrada.\n");
                        }
                        flagFiltro=1;
                        break;
                    case 4:
                        listaFiltrada = ll_filter(listaConValores, bicicleta_filtradoPorPaseo);
                        printf("\nIngrese el nombre para guardar el listado de bicicletas de Paseo: ");
                        fflush(stdin);
                        scanf("%s",archivo);
                        strcpy(archivo,strcat(archivo,".csv"));
                        if(controller_saveAsText(archivo,listaFiltrada))
                        {
                            printf("Lista filtrada guardada con exito!\n");
                        }
                        else
                        {
                            printf("Hubo un error al intentar guardar la lista filtrada.\n");
                        }
                        flagFiltro=1;
                        break;
                    }
                }while(flagFiltro==0);
            }
            break;
        case 5:
            if(listaConValores==NULL || ll_isEmpty(listaConValores))
            {
                printf("Aun no se asignaron los tiempos. Seleccione la opcion 3 y vuelva a intentarlo.\n");
            }
            else
            {
                listaOrdenada = listaConValores;
                controller_sortBicicletas(listaOrdenada);
                controller_ListarBicicletas(listaOrdenada);
            }
            break;
        case 6:
            if(listaConValores==NULL || ll_isEmpty(listaConValores))
            {
                printf("Aun no se asignaron los tiempos. Seleccione la opcion 3 y vuelva a intentarlo.\n");
            }
            else
            {
                printf("\nIngrese el nombre para guardar el listado de posiciones: ");
                fflush(stdin);
                scanf("%s",archivo);
                strcpy(archivo,strcat(archivo,".csv"));
                controller_saveAsText(archivo,listaOrdenada);
            }
            break;
        }
    system("pause");
    system("cls");
    }while(opcion!=7);

    free(listaBicicletas);

    if(listaConValores!=NULL)
    {
        free(listaConValores);
    }

    if(listaFiltrada!=NULL)
    {
        free(listaFiltrada);
    }

    return 0;
}
