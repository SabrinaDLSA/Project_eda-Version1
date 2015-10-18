#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define N 60
struct archivo
{
    char *nombre;
    int Nro_Linea;
    struct linea *Linea;
    struct archivo *siguiente;
    struct archivo *anterior;
};
typedef archivo *Archivo;
struct linea
{
    char *valor_linea;
    int Nro_Linea;
    struct linea *siguiente;
    struct linea *anterior;
};
typedef linea *nodo_linea;
enum retorno
{
        OK,ERROR,NO_IMPLEMENTADA
};
typedef enum retorno TipoRet;

Archivo comienzo = new archivo;

char *vaciar_string( char string_vacio[N] );
void selector_funcion(char ingresado[N]);
bool syntax(char ingresado[N]);
Archivo CrearArchivo(char *nombre);
void error_funcion( int num_error );
int encuentro( char busco, char search_place[N], int position);
char *busco_comando( char search_place[N], int position );
void busco_funcion( char command[N], int position);
char *busco_parametro( char command[N], int position);
Archivo busco_archivo( char *nombre );
TipoRet BorrarArchivo(Archivo *a);
TipoRet InsertarLinea(Archivo *a, char *linea, unsigned int  Nro_Linea);
TipoRet BorrarLinea(Archivo *a, unsigned int Nro_Linea);
TipoRet MostrarTexto(Archivo a);


#endif // HEADER_H_INCLUDED
