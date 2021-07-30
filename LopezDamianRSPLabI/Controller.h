#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path , LinkedList* pArrayListBici);
int controller_ListarBicicletas(LinkedList* pArrayListBici);
int controller_sortBicicletas(LinkedList* pArrayListBici);
int controller_saveAsText(char* path , LinkedList* pArrayListBici);

#endif // CONTROLLER_H_INCLUDED
