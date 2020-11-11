#include "enrutador.h"

bool enrutador::agregar_enlace(char nombre, int costo)
{
    bool st=false;
    if (router.find(nombre)==router.end()) {
        router.insert(pair<char,int>(nombre,costo));
        st=true;
    }
    return st;
}

bool enrutador::eliminar_enlace(char nombre)
{
    bool st=false;
    if (router.find(nombre)!=router.end()) {
        router.erase(nombre);
        st=true;
    }
    return st;
}

bool enrutador::modificar_enlace(char nombre, int costo)
{
    bool st=false;
    if (router.find(nombre)!=router.end()) {
        router[nombre]=costo;
        st=true;
    }
    return st;
}

void enrutador::imprimir()
{
    for (it2=router.begin();it2!=router.end();it2++) {
        cout << it2->first << '\t' << it2->second << endl;
    }
}
