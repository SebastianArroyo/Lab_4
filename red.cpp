#include "red.h"

void red::agregar_ruta(char nombre, char ruta, int costo)
{
    enrutador router;
    router.agregar_enlace(ruta,costo);
    net.insert(pair<char,enrutador>(nombre,router));
    net[ruta].agregar_enlace(nombre,costo);
}

void red::agregar_enrutador(char nombre)
{
    enrutador router;
    char name;
    int valor=777;
    if (net.find(nombre)==net.end()) {
        router.agregar_enlace(nombre,0);
        for (it=net.begin();it!=net.end();it++) {
            router.agregar_enlace(it->first,-1);
            it->second.agregar_enlace(nombre,-1);
        }
        do {
            cout << "Ingrese el nombre del nodo con el que se va a enlazar el nodo " << nombre << ": ";
            cin >> name; cout << endl;
            if (name==nombre) {
                cout << "No se puede enlazar a si mismo" << endl;
            }
            else if (name!='+') {
                if (!router.modificar_enlace(name,valor)) {
                    cout << "El nodo ingresado no existe." << endl;
                }
                else {
                    cout << "Ingrese el costo del enlace: ";
                    cin >> valor;
                    net[name].modificar_enlace(nombre, valor);
                    router.modificar_enlace(name,valor); //400IQ
                    cout << "Enlazado " << nombre << " con " << name << endl;
                }
            }
        } while (name!='+');
        net.insert(pair<char,enrutador>(nombre,router));
    }
    else {
        cout << "Enrutador ya existe" << endl;
    }
}

void red::eliminar_enrutador(char nombre)
{
    if (net.find(nombre)!=net.end()) {
        net.erase(nombre);
        for(it=net.begin();it!=net.end();it++) {
            it->second.eliminar_enlace(nombre);
        }
        cout << "Borrado exitosamente" << endl;
    }
    else
    {
        cout<<"Nodo no encontrado"<<endl;
    }
}

void red::eliminar_enlace_red(char nombre)
{
    char name;
    bool ban=false, ban1=false;
    for (it=net.begin();it!=net.end();it++) {
        if (it->first==nombre) {
            cout << "Las enlaces de '" << nombre << "' son: " << endl << endl;
            cout << "Precio de " << it->first<< " con: " << endl;
            it->second.imprimir();
            ban=true;
        }
    }
    if (ban==false) {
        cout << "El enrutador '" << nombre << "' no existe" << endl;
    }
    else {
        cout << "Ingrese el nombre del segundo nodo del enlace a eliminar: ";
        cin >> name;
        if (name==nombre) {
            cout << "Usted ha ingresado: ";
            cout << "'" << nombre << "' y '" << name << "'" << endl;
            cout << "Debe ingresar un nombre distinto al primer nodo." << endl << endl;
        }
        else {
            for (it=net.begin();it!=net.end();it++) {
                if (it->first==nombre) {
                    it->second.modificar_enlace(name,-1);
                }
                else if (it->first==name) {
                    it->second.modificar_enlace(nombre,-1);
                    ban1=true;
                }
            }
            if (ban1==false) {
                cout << "El enrutador '" << name << "' no existe" << endl;
            }
            else {
                cout << "Enlace entre '" << nombre << "' y '" << name << "' borrado exitosamente" << endl;
            }
        }
    }
}

void red::modificar_enlace_red(char nombre)
{
    char name;
    int valor;
    bool ban=false, ban1=false;
    for (it=net.begin();it!=net.end();it++) {
        if (it->first==nombre) {
            cout << "Las enlaces de '" << nombre << "' son: " << endl << endl;
            cout << "Precio de " << it->first<< " con: " << endl;
            it->second.imprimir();
            ban=true;
        }
    }
    if (ban==false) {
        cout << "El enrutador '" << nombre << "' no existe" << endl;
    }
    else {
        cout << "Ingrese el nombre del segundo nodo del enlace a modificar: ";
        cin >> name;
        if (name==nombre) {
            cout << "Usted ha ingresado: ";
            cout << "'" << nombre << "' y '" << name << "'" << endl;
            cout << "Debe ingresar un nombre distinto al primer nodo." << endl << endl;
        }
        else {
            cout << "Ingrese nuevo valor para el enlace: "; cin >> valor;
            for (it=net.begin();it!=net.end();it++) {
                if (it->first==nombre) {
                    it->second.modificar_enlace(name,valor);
                }
                else if (it->first==name) {
                    it->second.modificar_enlace(nombre,valor);
                    ban1=true;
                }
            }
            if (ban1==false) {
                cout << "El enrutador '" << name << "' no existe" << endl;
            }
            else {
                cout << "Enlace entre '" << nombre << "' y '" << name << "' modificado exitosamente" << endl;
            }
        }
    }
}

void red::imprimir_todo()
{
    for (it=net.begin();it!=net.end();it++) {
       cout << "Precio de " << it->first<< " con: " << endl;
       it->second.imprimir();
   }
}

void red::imprimir_enrutador(char nombre)
{
    bool ban=false;
    for (it=net.begin();it!=net.end();it++) {
        if (it->first==nombre) {
            cout << "Precio de " << it->first<< " con: " << endl;
            it->second.imprimir();
            ban=true;
        }
    }
    if (ban==false) {
        cout << "El enrutador '" << nombre << "' no exite" << endl;
    }
}
