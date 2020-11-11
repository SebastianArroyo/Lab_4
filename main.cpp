#include "red.h"

int main()
{
    red net;
    int a;
    char name;
    while (true) {
        cout << "          MENU" << endl << endl;
        cout << "1 Agregar enrutador/enlace" << endl;
        cout << "2 Eliminar enrutador" << endl;
        cout << "3 Eliminar enlace" << endl;
        cout << "4 Modificar enlace" << endl;
        cout << "5 Imprimir enrutador" << endl;
        cout << "6 Imprimir red completa" << endl << endl;
        cout << "Ingrese una opcion: "; cin >> a; cout << endl;

        switch (a) {
        case 1:
            cout << "Ingrese el nombre del nuevo enrutador: ";
            cin >> name;
            net.agregar_enrutador(name);
        break;

        case 2:
            cout << "Ingrese el nombre del nodo a eliminar: ";
            cin >> name;
            net.eliminar_enrutador(name);
        break;

        case 3:
            cout << "Ingrese el nombre del primer nodo del enlace a modificar: ";
            cin >> name;
            net.eliminar_enlace_red(name);
        break;

        case 4:
            cout << "Ingrese el nombre del primer nodo del enlace a eliminar: ";
            cin >> name;
            net. modificar_enlace_red(name);
        break;

        case 5:
            cout << "Ingrese el nombre del enrutador a imprimir: ";
            cin >> name;
            net.imprimir_enrutador(name);
        break;

        case 6:
            net.imprimir_todo();
        break;

        default:
            cout << "Debe ingresar un numero valido." << endl << endl;
        break;
        }
    }
    return 0;
}
