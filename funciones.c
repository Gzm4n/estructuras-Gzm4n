#include <stdio.h>
#include <string.h>
#include "funciones.h"

void flush(){
    flush();
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
    const *states[]={"Disponible", "Ocupado"};
    
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

    printf("Ingrese el numero correspondiente al estado del libro\n"
            "1 para disponible, o 0 para prestado: ");
    scanf("%d", &libros[i].stateIndex);
    flush();

    char status[10]=states[libros[i].stateIndex];

    libros[i].id = i+1;
}

void mostrarLibros(struct Libro libros[20], int c){
    printf ("N° de libro        ")
    for (int i=0; i<c; i++){
        
    }
}