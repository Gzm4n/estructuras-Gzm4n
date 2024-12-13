#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main (int argc, char *argv[]) {

    struct Libro libros[20];
    int opc;
    int i=0;
    char titulo[100]="";
    do{
        opc = menu();
        switch (opc)
        {
            case 1:
                registrarLibros(libros, i);
                i++;
                break;
            case 2:
                mostrarLibros(libros, i);
                break; 
            case 3:
                int id;
                printf("Ingrese el id del libro a buscar: ");
                scanf("%d", &id);
                flush();
                buscarLibroId(libros, i, id);
                break;
            case 4:
                printf("Ingrese el titulo del libro a buscar: ");
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = '\0';
                buscarLibroTitulo(libros, i, titulo);
                titulo[0]='\0';
                break;
            case 5:
                printf("Ingrese el titulo del libro cuyo estado se va a modificar: ");
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = '\0';
                actualizarEstado(libros, i, titulo);
                titulo[0]='\0';
                break;
            case 6:
                printf("Ingrese el titulo del libro a eliminar: ");
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = '\0';
                eliminarLibro(libros, i, titulo);
                titulo[0]='\0';
                break;
            case 7:
                printf("Programa detenido\n");
                break;
            default:
                printf("Opcion no valida. Ingrese de nuevo\n");
                break;
        }
    }while(opc != 7);


    return 0;
}
