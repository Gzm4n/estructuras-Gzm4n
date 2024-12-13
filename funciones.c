#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define maxYear 2024
#define minYear 868

void flush(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int menu(){
    int opc;
    do{
        printf ("\nIngrese el numero correspondiente a una de las siguientes opciones:\n"
                "1. Registrar libro\n"
                "2. Mostrar libros\n"
                "3. Buscar libro por ID\n"
                "4. Buscar libro por titulo\n"
                "5. Actualizar el estado de un libro\n"
                "6. Eliminar un libro\n"
                "7. Detener el programa\n"
                "\nOpcion: ");
        scanf("%d", &opc);
        flush();
        if (opc<8 && opc>0){
            return opc;
            break;
        }
        else printf ("El valor ingresado no se encuentra en el listado. Ingrese de nuevo.\n");
    }while (opc>8 || opc<0);
}



void registrarLibros(struct Libro libros[20], int i){
    int statusIndex;
    int aux=0;
    
    printf("\nLibro %d\n", i+1);
    printf("\nIngrese el nombre del libro: ");
    fgets(libros[i].title, sizeof(libros[i].title), stdin);
    libros[i].title[strcspn(libros[i].title, "\n")] = '\0';

    printf("Ingrese el autor del libro: ");
    fgets(libros[i].author, sizeof(libros[i].author), stdin);
    libros[i].author[strcspn(libros[i].author, "\n")] = '\0';

    do {
        printf("Ingrese el anio de publicación: ");
        if (scanf("%d", &aux) != 1) {
            printf("Entrada invalida. Por favor, ingrese un numero.\n");
            flush();
            continue;
        }
    
        if (aux >= minYear && aux <= maxYear) {
            libros[i].year = aux;
            printf("Anio guardado correctamente: %d\n", aux);
            break;
        } else {
            printf("Anio no valido. Ingrese de nuevo.\n");
        }
    } while (1);

    do{
        printf("Ingrese el numero correspondiente al estado del libro\n"
                "1 para disponible, 0 para prestado: ");
        scanf("%d", &statusIndex);
        flush();
        if (statusIndex==0) strcpy(libros[i].status, "Ocupado");
        else if (statusIndex==1) strcpy(libros[i].status, "Disponible");
        else printf("Opcion no valida. Ingrese de nuevo\n");
    }while (statusIndex!=0 && statusIndex!=1);

    libros[i].id = i+1;
}

void mostrarLibros(struct Libro libros[20], int c){
    if (c==0) printf("No hay libros registrados\n");
    else{
        printf("+-------+----------------------+----------------------+----------------------+--------------+\n");
        printf ("| %-5s | %-20s | %-20s | %-20s | %-12s |\n", "ID", "Titulo", "Autor", "Anio de publicacion", "Estado"); 
        for (int i=0; i<c; i++){
            printf("+-------+----------------------+----------------------+----------------------+--------------+\n");
            printf("| %-5d | %-20s | %-20s | %-20d | %-12s |\n", libros[i].id, libros[i].title, libros[i].author, libros[i].year, libros[i].status);
        }
        printf("+-------+----------------------+----------------------+----------------------+--------------+\n");
    }
}

void buscarLibroId(struct Libro libros[20], int c, int id){
    for (int i=0; i<c; i++){
        if (libros[i].id == id){
            printf("+-------+----------------------+----------------------+----------------------+--------------+\n");
            printf ("| %-5s | %-20s | %-20s | %-20s | %-12s |\n", "ID", "Titulo", "Autor", "Anio de publicacion", "Estado"); 
            printf("+-------+----------------------+----------------------+----------------------+--------------+\n");
            printf("| %-5d | %-20s | %-20s | %-20d | %-12s |\n", libros[i].id, libros[i].title, libros[i].author, libros[i].year, libros[i].status);
            printf("+-------+----------------------+----------------------+----------------------+--------------+\n");
            break;
        } else if (i==c-1) printf("No se encontro ningun libro con ese ID\n");
    }
}

void buscarLibroTitulo(struct Libro libros[20], int c, char titulo[100]){
    for (int i=0; i<c; i++){
        if (strcmp(libros[i].title, titulo)==0){
            printf("+-------+----------------------+----------------------+----------------------+--------------+\n");
            printf ("| %-5s | %-20s | %-20s | %-20s | %-12s |\n", "ID", "Titulo", "Autor", "Anio de publicacion", "Estado"); 
            printf("+-------+----------------------+----------------------+----------------------+--------------+\n");
            printf("| %-5d | %-20s | %-20s | %-20d | %-12s |\n", libros[i].id, libros[i].title, libros[i].author, libros[i].year, libros[i].status);
            printf("+-------+----------------------+----------------------+----------------------+--------------+\n");
            break;
        } else if (i==19) printf("No se encontro ningun libro con ese titulo\n");
    }
}

void actualizarEstado (struct Libro libros[20], int c, char titulo[100]){
    for (int i=0; i<c; i++){
        if (strcmp(libros[i].title, titulo)==0){
            if (strcmp(libros[i].status, "Disponible")==0) strcpy(libros[i].status, "Ocupado");
            else if (strcmp(libros[i].status, "Ocupado")==0) strcpy(libros[i].status, "Disponible");
            printf ("El estado del libro %s ha sido actualizado a %s\n", libros[i].title, libros[i].status);
            break;
        } else if (i==c-1) printf("No se encontro ningun libro con ese titulo\n");
    }
}

void eliminarLibro (struct Libro libros[20], int c, char titulo[100]){
    for (int i=0; i<c; i++){
        if (strcmp(libros[i].title, titulo)==0){
            for (int j=i; j<c; j++){
                libros[j] = libros[j+1];
            }
            printf("El libro %s ha sido eliminado\n", titulo);
            break;
        } else if (i==c-1) printf("No se encontro ningun libro con ese titulo\n");
    }
}

