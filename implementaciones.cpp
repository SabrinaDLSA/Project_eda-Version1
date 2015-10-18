#include <iostream>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include "header.h"
#define N 60

using namespace std;
char ingreso_usuario[N];
char cadena2[N];
char parametros[N];

void Retorno_Funcion(int retorno)
{
    switch(retorno)
    {
    case 0:
        cout<<"Resultado OK";
        break;
    case 1:
        cout<<"Resultado ERROR";
        break;
    case 2:
        cout<<"Resultado No_Implementada";
        break;
    }
}
Archivo CrearArchivo(char *nombre)
{
    Archivo nuevoarchivo;
    nuevoarchivo = new archivo;
    nuevoarchivo->nombre = nombre;
    if(comienzo == NULL )
    {
        nuevoarchivo->Linea=NULL;
        nuevoarchivo->Nro_Linea=0;
        nuevoarchivo->siguiente=NULL;
        nuevoarchivo->anterior=NULL;
        comienzo = nuevoarchivo;
        cout<< "Archivo creado con comienzo vacio"<<endl;
    }
    else
    {
        nuevoarchivo->Linea=NULL;
        nuevoarchivo->Nro_Linea=0;
        nuevoarchivo->siguiente=comienzo->siguiente;
        nuevoarchivo->anterior=NULL;
        comienzo->siguiente = nuevoarchivo;
        cout<< "Archivo creado"<<endl;
    }
    return comienzo;

}
 TipoRet BorrarArchivo(Archivo *a)
{
    return OK;
}

void selector_funcion(char ingresado[N])
{
    char cadena1, *comando_cortado;
    cadena1 = '(';
    int p=0;
    p = encuentro(cadena1, ingresado, 0); //Busco el caracter que indica que el comando termina alli dado por (
        if( p == -1 )
        {
            error_funcion( 1 ); //Si no lo encuentro damos error de sintaxis
        }
        else{
           comando_cortado = busco_comando(ingresado, p);    //Si lo encuentro se lo doy a comando junto con su posicion
            busco_funcion( comando_cortado , p );
        }                                  // Esre se encarga guardar el comando para enviarlo a la funcion que
                                        // comparara y encontrara cual fue la funcion llamada
}

int encuentro( char busco, char search_place[N], int position) //Funcion que busca caracteres en cadena
{                                                             // El primer parametro indica lo que se busca
                                                             // El segundo parametro donde y el tercedo desde
        while ( search_place[position] != '\0' && position < N )
        {
             if ( search_place[position] == busco )
             {
                 return position;
             }
             ++position;    //Retornamos la posicion en la cual se encuentra el caracter
        }
    position = 0;
    return -1;

}
char *busco_comando( char search_place[N], int position ){  // Funcion que busca que comando se ingreso
     cout<<"Ingreso"<<search_place<<endl;                                                    // El primer parametro es la cadena ingresada
    int start = 0;                                      // Por el usuario y la segunda la posicion del
    char command[N], *comando_cortado;                                   // caracter de terminación que indica que el comando
    command[N] = {'\0'};                             // termina, hemos usado ( puesto que al tener un
    command[0]= { '-' };                             // Parentesis quiere decir que comienzan los parametros
       for ( start=0; start < position; start++)
    {
        command[start] = search_place[start];
    }
    cout <<"My comand busco"<<command<< "My position busco"<<position<<endl;
    comando_cortado = command;
    return comando_cortado;
}

void busco_funcion(char command[N], int position )
{
    char comando[N], *param;
    strcpy(comando, command);
    cout <<"My comandooo para comparar"<<comando<<"My position"<< position<<endl;
            if(strncmp(comando, "CrearArchivo", position)==0)
        {
             param = busco_parametro( command , position );
             if( param == false )
             return;
             else
             comienzo = CrearArchivo( param );

        }
        else
        {
            if (strcmp (comando,"BorrarArchivo")==0)
            {
//               ret = BorrarArchivo(parametros);
            }
            else
            {

                if (strncmp (comando, "InsertarLinea", position )==0 )
                {
                  cout << "Insertart linea!!"<<endl;

                  param = busco_parametro( command , position );

                }
                else
                {
                    if (strcmp(comando, "BorrarLinea")==0)
                    {
                        //BorrarLinea(parametros);
                       // Retorno_Funcion(retorno);
                    }
                    else
                    {
                        if (strcmp(comando, "MostrarTexto")==0)
                        {
                           // MostrarTexto(parametros);
                            // Retorno_Funcion(retorno);
                        }
                        else
                        {
                            cout << "La función que ha ingresado no existe"<<endl;
                        }
                    }
                }
            }
        }

}


void error_funcion(int error_num){ // Funcion que emite los errores

    switch( error_num )
    {

        case 1:
        cout << "Error  de sintaxis esperando ( para mas informacion utilice --help"<<endl;
        return;
        break;
        case 2:
        cout << "Error  de sintaxis esperando ) para mas informacion utilice --help"<<endl;
        return;
        break;
        case 3:
        cout << "Error  funcion vacia, por favor revise la sintaxis"<<endl;
        return;
        break;
        case 4:
        cout << "Error parametro vacia, por favor revise la sintaxis"<<endl;
        return;
        break;
        case 5:
        cout << "Error debe separar los parametros con ,"<<endl;
        return;
        break;
    }
}


char *busco_parametro( char command[N] , int position){
    parametros[0] = { '-' };
    char busco = ')';
        int pos_fin_comando = 0, pos = position +1, start=0;
        pos_fin_comando = encuentro( busco , ingreso_usuario, position);
        if( pos_fin_comando == -1 )
        {
            error_funcion( 2 );// Si no me devuelve final de la funcion doy error de sintaxis
        }
        else
        {
            if ( strncmp(command, "CrearArchivo", position)== 0)
            {
                   for ( pos; pos < pos_fin_comando; ++pos)
                    {
                        parametros[start] = ingreso_usuario[pos];
                        start++;
                    }
                if(parametros[0] == '-')
                {
                        error_funcion(4); // Si al final me devuelven parametros vacios tiro error de sintaxis
                        return false;
                }
            }
            else
            {
                cout <<" comando Insertar line< "<<endl;
                cout << command << endl;
                    if( strncmp( command, "InsertarLinea", position )== 0)
                    {
                    cout <<" comando Insertar line< "<<endl;
                    cout << command << endl;
                        char coma_parametro = ',';
                        int corte_comando = encuentro( coma_parametro , ingreso_usuario, position);
                        if ( corte_comando == -1 ){
                        error_funcion( 5 ); // si no encuentro , separador de parametros retorno error.
                            return;
                        }
                        for ( pos; pos < corte_comando; ++pos)
                        {
                            parametros[start] = ingreso_usuario[pos];
                            start++;
                        }
                    }
            }
        }
        return parametros; // de lo contrario retorno el parametro
}

char *vaciar_string( char string_vacio[N] )
{
    int pos;
    pos = 0;
    while(string_vacio != '\0')
    {
        string_vacio[pos] = ' ';
        pos ++;
    }
    return string_vacio;
}

Archivo busco_archivo( char *nombre )
{
    Archivo auxiliar = new archivo;

    auxiliar = comienzo;

    while( auxiliar->siguiente != NULL )
    {
        if( auxiliar->nombre == nombre )
        {
            return auxiliar;
        }
        auxiliar = auxiliar->siguiente;
    }
   return false;
}










