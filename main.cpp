#include <iostream>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include "implementaciones.cpp"

using namespace std;

int main()
{
comienzo = NULL;
    do
    {
        ingreso_usuario[N] = { ' ' };
        cout << ">";
        cin.getline(ingreso_usuario, N, '\n');
        if(strcmp(ingreso_usuario , "quit") == 0)
        {
            return 0;
        }
        selector_funcion( ingreso_usuario );
    }while( strcmp(ingreso_usuario , "quit") != 0 );
    return 0;
}

