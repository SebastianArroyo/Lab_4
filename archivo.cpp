#include "archivo.h"

red leer_archivo(red net)
{
    ifstream archivo_entrada("red.txt");;
    string linea;
    enrutador router;
    char nombre,num,valor;
    while(getline(archivo_entrada, linea))
    {
        int numero_int=0,mul=1,dig=0;
        string numero="";
        int tam=linea.length();
        for(int c=0;c!=tam;c++)
        {
            if(c==0)
            {
                nombre=linea[c];
            }
            else if(c==2)
            {
                valor=linea[c];
            }
            else if(c>=4)
            {
                if(linea[c]=='-')
                {
                    numero_int=-1;
                }
                else
                {
                    num=linea[c];
                    numero.push_back(num);
                }
            }
        }

        if(numero_int!=-1)
        {
            for (int o=numero.length()-1;o>=0;o--)
            {
                numero_int+=(int(numero[o])-48)*mul;
                dig++;
                mul*=10;
            }
        }
        router.agregar_enlace(valor,numero_int);
        net.agregar_ruta(nombre,valor,numero_int);
    }
    //net.imprimir_todo();
    return net;
}
