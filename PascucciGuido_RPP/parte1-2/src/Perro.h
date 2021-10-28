
#ifndef PERRO_H_
#define PERRO_H_


#define ID 100000
#define MAX_ESTADIAS 10
#define MAX_PERROS 10
#define MAX_NOMBRE 21
#define TRUE 1
#define FALSE 0




typedef struct
{

 int id;
 char nombre[MAX_NOMBRE];
 char raza[MAX_NOMBRE];
 int edad;
 int espacioVacio;

} sPerro;




void inicializarPerritos(sPerro* listaPerros, int lengthPerros);
void sPerro_hardcodeo(sPerro* listaPerros, int lengthPerros);
void mostrarPerro(sPerro* listaPerros, int index);
void mostrarListaPerros(sPerro* listaPerros, int lengthPerros);
void listarPerros(sPerro* listaPerros, int lengthPerros, int contadorAltas);
int cargarPerritoPorId(sPerro* listaPerros, int lengthPerros, int index);
int calcularPromedioEdadPerros(sPerro* listaPerros, int lengthPerros, int contadorAltas);









#endif




