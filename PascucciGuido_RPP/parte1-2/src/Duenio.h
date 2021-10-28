
#ifndef DUENIO_H_
#define DUENIO_H_


#define MAXLENGTH 41
#define MAXDUENIOS 5


typedef struct{
	int id;
	char nombre[MAXLENGTH];
	int telefono;
	int espacioVacio;
} sDuenio;




int sDuenio_inicializarDuenios(sDuenio* listaDuenios, int lengthDuenios);
void sDuenio_hardcodearDuenios(sDuenio* listaDuenios, int lengthDuenios);

int duenio_cargarId(sDuenio* listaDuenios, int lengthDuenios);

void sDuenio_mostrarUno(sDuenio* listaDuenios, int index);
void sDuenio_mostrarTodos(sDuenio* listaDuenios, int lengthDuenios);



#endif
