#include <iostream>
#include "view.h"
#include "../controller/controller.h"
using namespace std;

void MenuPrincipal(){
    int opcion;
    do{
        cout << endl << "MENU PRINCIPAL" << endl;
        cout << "1. Consultar" << endl;
        cout << "2. Actualizar" << endl;
        cout << "3. Borrar" << endl;
        cout << "4. Agregar" << endl;
        cout << "5. Salir del programa" << endl << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion){
        case 1:
            MenuConsultar();
            break;
        case 2:
            MenuActualizar();
            break;
        case 3:
            MenuBorrar();
            break;
        case 4:
            MenuAgregar();
            break;
        case 5:
            cout << "Saliendo del programa . . ." << endl;
            break;
        default:
            cout << "Opcion invalida" << endl
                 << endl;
        }
    } while (opcion != 5);
}

void MenuConsultar(){
    int opcion_consulta;
    do{
        cout << endl << "MENU DE CONSULTA DE REGISTROS" << endl;
        cout << "Indique el tipo de consulta que desea realizar:" << endl;
        cout << "1. Vehiculo" << endl;
        cout << "2. Cliente" << endl;
        cout << "3. Repuesto" << endl;
        cout << "4. Regresar al Menu Principal" << endl << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion_consulta;

        switch (opcion_consulta){
        case 1:
            Consulta_Vehiculo();
            break;
        case 2:
            Consulta_Cliente();
            break;
        case 3:
            Consulta_Repuesto();
            break;
        case 4: // Retorno a Menu Principal
            return;
            break;
        default:
            cout << "Opcion Invalida" << endl << endl;
        }
    } while (opcion_consulta != 5);
}

void MenuActualizar(){
    int opcion_actualizar;
    do{
        cout << endl << "MENU DE ACTUALIZACION DE REGISTROS" << endl;
        cout << "Indique el tipo de registro que desea actualizar:" << endl;
        cout << "1. Vehiculo " << endl;
        cout << "2. Cliente" << endl;
        cout << "3. Repuesto" << endl;
        cout << "4. Regresar al Menu Principal" << endl << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion_actualizar;

        switch (opcion_actualizar){
        case 1:
            Actualizar_Vehiculo();
            break;
        case 2:
            Actualizar_Cliente();
            break;
        case 3:
            Actualizar_Repuesto();
            break;
        case 4: // Retorno a Menu Principal
            return;
            break;
        default:
            cout << "Opcion Invalida" << endl
                 << endl;
        }
    } while (opcion_actualizar != 4);
}

void MenuBorrar(){
    int opcion_borrar;
    do{
        cout << endl << "MENU DE ELIMINACION DE REGISTROS" << endl;
        cout << "Indique el tipo de registro que desea eliminar:" << endl;
        cout << "1. Vehiculo " << endl;
        cout << "2. Cliente" << endl;
        cout << "3. Repuesto" << endl;
        cout << "4. Regresar al Menu Principal" << endl << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion_borrar;

        switch (opcion_borrar){
        case 1:
            Eliminar_Vehiculo();
            break;
        case 2:
            Eliminar_Cliente();
            break;
        case 3:
            Eliminar_Repuesto();
            break;
        case 4: // Retorno a Menu Principal
            return;
            break;
        default:
            cout << "Opcion Invalida" << endl
                 << endl;
        }
    } while (opcion_borrar != 4);
}

void MenuAgregar(){
    int opcion_agregar;
    do{
        cout << endl << "MENU DE ACTUALIZACION DE REGISTROS" << endl;
        cout << "Indique el tipo de registro que desea agregar:" << endl;
        cout << "1. Vehiculo " << endl;
        cout << "2. Cliente" << endl;
        cout << "3. Repuesto" << endl;
        cout << "4. Regresar al Menu Principal" << endl << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion_agregar;

        switch (opcion_agregar){
        case 1:
            Agregar_Vehiculo();
            break;
        case 2:
            Agregar_Cliente();
            break;
        case 3:
            Agregar_Repuesto();
            break;
        case 4: // Retorno a Menu Principal
            return;
            break;
        default:
            cout << "Opcion Invalida" << endl;
        }
    } while (opcion_agregar != 4);
}