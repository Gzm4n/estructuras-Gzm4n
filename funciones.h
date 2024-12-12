struct Libro{
   char title[100];
   char author[50];
   int year;
   char status[10];
   int id;
};

void flush();
int menu();
void registrarLibros(struct Libro libros[20], int i);
void mostrarLibros(struct Libro libros[20], int c);
void buscarLibroId(struct Libro libros[20], int i, int id);
