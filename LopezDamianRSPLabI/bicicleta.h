#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct
{
    int id_bike;
    char nombre[30];
    char tipo[30];
    int tiempo;
}eBicicleta;

int bicicleta_setId(eBicicleta* this, int id);
int bicicleta_getId(eBicicleta* this, int* id);
int bicicleta_setNombre(eBicicleta* this, char* nombre);
int bicicleta_getNombre(eBicicleta* this, char* nombre);
int bicicleta_setTipo(eBicicleta* this, char* tipo);
int bicicleta_getTipo(eBicicleta* this, char* tipo);
int bicicleta_setTiempo(eBicicleta* this, int tiempo);
int bicicleta_getTiempo(eBicicleta* this, int* tiempo);
eBicicleta* bicicleta_new();
eBicicleta* bici_newParametros(char* idStr, char* nombreStr, char* tipoStr, char* tiempoStr);
int bicicleta_mostrarUnaBici(eBicicleta* this);
int bicicleta_filtradoPorBMX(void* p);
int bicicleta_filtradoPorPlayera(void* p);
int bicicleta_filtradoPorMTB(void* p);
int bicicleta_filtradoPorPaseo(void* p);
int bicicleta_compareByTipoTiempo(void* bici1, void* bici2);


#endif // BICICLETA_H_INCLUDED
