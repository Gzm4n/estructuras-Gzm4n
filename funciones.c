#include <stdio.h>
#include <string.h>
#include "funciones.h"

void flush(){
    while(getchar()!='\n');
}


int menu(){
    int opc;
    do{
        printf ("Ingrese el numero correspondiente a una de las siguientes opciones:?\n"
                "1. Registrar libro\n"
                "2. Mostrar libros\n"
                "3. Buscar libro por ID\n"
                "4. Buscar libro por titulo\n"
                "5. Actualizar el estado de un libro\n"
                "6. Eliminar un libro\n"
                "7. Detener el programa\n");
        scanf("%d", &opc);
        while (getchar() != '\n');
        if (opc<8 && opc>0){
            return opc;
            break;
        }
        else printf ("El valor ingresado no se encuentra en el listado. Ingrese de nuevo.\n");
    }while (opc>8 || opc<0);
}



void registrarLibros(struct Libro libros[20], int i){
    int statusIndex;
    
    printf(" Libro %d\n", i+1);
    printf("Ingrese el nombre del libro: ");
    fgets(libros[i].title, sizeof(libros[i].title), stdin);
    libros[i].title[strcspn(libros[i].title, "\n")] = '\0';

    printf("Ingrese el autor del libro: ");
    fgets(libros[i].author, sizeof(libros[i].author), stdin);
    libros[i].author[strcspn(libros[i].author, "\n")] = '\0';

    printf("Ingrese el año de publicacion: ");
    scanf("&d", &libros[i].year);
    flush();

    do{
        printf("Ingrese el numero correspondiente al estado del libro\n"
                "1 para disponible, o 0 para prestado: ");
        scanf("%d", &statusIndex);
        flush();
        if (statusIndex==0) strcpy(libros[i].status, "Ocupado");
        else if (statusIndex==1) strcpy(libros[i].status, "Disponible");
        else printf("Opcion no valida. Ingrese de nuevo");
    }while (statusIndex!=0 && statusIndex!=1);

    libros[i].id = i+1;
}

void mostrarLibros(struct Libro libros[20], int c){
    printf("+-------+------------+------------+-----------------+--------------+\n");
    printf ("| %-5s | %-10s | %-10s | %-15s | %-12s |\n", "ID", "Titulo", "Autor", "Año de publicacion", "Estado"); //2 tabs
    for (int i=0; i<c; i++){
        printf("+-------+------------+------------+-----------------+--------------+\n");
        printf("| %-5d | %-10s | %-10s | %-15d | %-12s |\n", libros[i].id, libros[i].title, libros[i].author, libros[i].year, libros[i].status);
    }
}

void buscarLibroId(struct Libro libros[20], int c, int id){
    for (int i=0; i<c; i++){
        
    }
}
