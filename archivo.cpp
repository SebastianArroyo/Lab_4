#include "archivo.h"

void leer_archivo()
{
    ifstream archivo("red.txt");
    if(!archivo.is_open())
    {
        cout<<"El archivo no existe "<<endl;
    }
    else
    {
        char letra;
        while(!archivo.eof())
        {
            letra=archivo.get();
        }
    }
    archivo.close();
}
