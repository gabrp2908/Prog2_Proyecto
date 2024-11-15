#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Vehiculos{
    string modelo, marca, placa, color, motor, fecha_de_entrega;
    int year, kilometraje, ced_cliente;
    float precio_renta;
    bool rentado;
}vehiculo;

struct Cliente{
    string nombre, apellido, email, direccion;
    int cedula, cantidad_vehiculos_rentados;
    bool activo;
}cliente;

struct Repuestos{
    string modelo, marca, nombre, modelo_carro;
    int year_carro, existencias;
    float precio;
} repuestos;

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

void Lectura_Cliente();
void Lectura_Vehiculo();
void Lectura_Repuesto();

void Lectura_Cliente() {

    ifstream lectura_cliente("DATOS_CLIENTES.csv", ios::in);
    string line;

    getline(lectura_cliente, line);

    while(getline(lectura_cliente, line)) {

        istringstream ss(line);

        ss >> cliente.cedula;
        ss.ignore();
        getline(ss, cliente.nombre, ',');
        getline(ss, cliente.apellido, ',');
        getline(ss, cliente.email, ',');
        ss >> cliente.cantidad_vehiculos_rentados;
        ss.ignore();
        getline(ss, cliente.direccion, ',');
        ss >> cliente.activo;
    }
}

void Lectura_Vehiculo() {

    ifstream lectura_vehiculo("DATOS_VEHICULOS.csv", ios::in);
    string line;

    getline(lectura_vehiculo, line);

    while(getline(lectura_vehiculo, line)) {

        istringstream ss(line);

        getline(ss, vehiculo.modelo, ',');
        getline(ss, vehiculo.marca, ',');
        getline(ss, vehiculo.placa, ',');
        getline(ss, vehiculo.color, ',');
        ss >> vehiculo.year;
        ss.ignore();
        ss >> vehiculo.kilometraje;
        ss.ignore();
        ss >> vehiculo.rentado;
        ss.ignore();
        getline(ss, vehiculo.motor, ',');
        ss >> vehiculo.precio_renta;
        ss.ignore();
        ss >> vehiculo.ced_cliente;
        ss.ignore();
        getline(ss, vehiculo.fecha_de_entrega);
    }
}

void Lectura_Repuesto() {

    ifstream lectura_repuesto("DATOS_REPUESTOS.csv", ios::in);
    string line;

    getline(lectura_repuesto, line);

    while(getline(lectura_repuesto, line)) {

        istringstream ss(line);

        getline(ss, repuestos.modelo, ',');
        getline(ss, repuestos.marca, ',');
        getline(ss, repuestos.nombre, ',');
        getline(ss, repuestos.modelo_carro, ',');
        ss >> repuestos.year_carro;
        ss.ignore();
        ss >> repuestos.precio;
        ss.ignore();
        ss >> repuestos.existencias;
    }
}

int main() {
    MenuPrincipal();
    return 0;
    }
