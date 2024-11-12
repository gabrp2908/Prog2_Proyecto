#include <iostream>
#include <fstream>

using namespace std;

struct Vehiculos{
    string modelo, marca, placa, color, motor, fecha_de_entrega;
    int year, kilometraje, ced_cliente;
    float precio_renta;
    bool rentado;
};

struct Cliente{
    string nombre, apellido, email, direccion;
    int cedula, cantidad_vehiculos_rentados;
    bool activo;
};

struct Repuestos{
    string modelo, marca, nombre, modelo_carro;
    int year_carro, existencias;
    float precio;
};

void MenuPrincipal();
void MenuConsultar();
void MenuActualizar();
void MenuBorrar();
void MenuAgregar();

void MenuPrincipal(){
    int opcion;
    do{
        cout << "MENU PRINCIPAL" << endl;
        cout << "1. Consultar" << endl;
        cout << "2. Actualizar" << endl;
        cout << "3. Borrar" << endl;
        cout << "4. Agregar" << endl;
        cout << "5. Salir del programa" << endl;
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
    int opcion_leer;
    do{
        cout << "MENU DE CONSULTA DE REGISTROS" << endl;
        cout << "Indique el tipo de consulta que desea realizar:" << endl;
        cout << "1. Vehiculo " << endl;
        cout << "2. Cliente" << endl;
        cout << "3. Repuesto" << endl;
        cout << "4. Regresar al Menu Principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion_leer;

        switch (opcion_leer){
        case 1: //Registro Vehiculo
             break;
        case 2: //Registro Cliente
            break;
        case 3: //Registro Repuesto
            break;
        case 4: //Menu Principal
            MenuPrincipal();
            break;
        default:
            cout << "Opcion Invalida" << endl;
        }
    } while (opcion_leer != 4);
}

void MenuActualizar(){
    int opcion_actualizar;
    do{
        cout << "MENU DE ACTUALIZACION DE REGISTROS" << endl;
        cout << "Indique el tipo de registro que desea actualizar:" << endl;
        cout << "1. Vehiculo " << endl;
        cout << "2. Cliente" << endl;
        cout << "3. Repuesto" << endl;
        cout << "4. Regresar al Menu Principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion_actualizar;

        switch (opcion_actualizar){
        case 1: //Registro Vehiculo
            break;
        case 2: //Registro Cliente
            break;
        case 3: //Registro Repuesto
            break;
        case 4: //Menu
            MenuPrincipal();
            break;
        default:
            cout << "Opcion Invalida" << endl;
        }
     } while (opcion_actualizar!=4);
}

void MenuBorrar()
{
    int opcion_actualizar;
    do{
        cout << "MENU DE ELIMINACION DE REGISTROS" << endl;
        cout << "Indique el tipo de registro que desea eliminar:" << endl;
        cout << "1. Vehiculo " << endl;
        cout << "2. Cliente" << endl;
        cout << "3. Repuesto" << endl;
        cout << "4. Regresar al Menu Principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion_actualizar;

        switch (opcion_actualizar){
        case 1: //Registro Vehiculo
            break;
        case 2: //Registro Cliente
            break;
        case 3: //Registro Repuesto
            break;
        case 4: //Menu Principal
            MenuPrincipal();
            break;
        default:
            cout << "Opcion Invalida" << endl;
        }
    } while (opcion_actualizar != 4);
}

void MenuAgregar()
{
    int opcion_agregar;
    do{
        cout << "MENU DE ACTUALIZACION DE REGISTROS" << endl;
        cout << "Indique el tipo de registro que desea agregar:" << endl;
        cout << "1. Vehiculo " << endl;
        cout << "2. Cliente" << endl;
        cout << "3. Repuesto" << endl;
        cout << "4. Regresar al Menu Principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion_agregar;

        switch (opcion_agregar){
        case 1: //Registro Vehiculo
            break;
        case 2: //Registro Cliente
            break;
        case 3: //Registro Repuesto
            break;
        case 4: //Menu Principal
            MenuPrincipal();
            break;
        default:
            cout << "Opcion Invalida" << endl;
        }
    } while (opcion_agregar != 4);
}

int main(){
    MenuPrincipal();
    return 0;
}