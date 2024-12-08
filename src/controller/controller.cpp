#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../model/model.h"
#include "../view/view.h"
#include "controller.h"

using namespace std;

// Consulta de cliente segun su cedula
bool Consultar_Cliente(int cedula, Cliente& resultado){

    Cliente* clientes = new Cliente[MAX_CLIENTES];
    int numClientes = Cliente::CargarDesdeArchivo("../bin/DATOS_CLIENTES.csv", clientes, MAX_CLIENTES);
    
    bool encontrado = false;
    for (int i = 0; i < numClientes; ++i) {
        if (clientes[i].cedula == cedula) {
            resultado = clientes[i];
            encontrado = true;
            break;
        }
    }

    delete[] clientes;
    return encontrado;
}

// Consulta de vehiculo segun su placa
 bool Consulta_Vehiculo(const string& placa, Vehiculos& resultado){

    Vehiculos* vehiculos = new Vehiculos[MAX_VEHICULOS];
    int numVehiculos = Vehiculos::CargarDesdeArchivo("../bin/DATOS_VEHICULOS.csv", vehiculos, MAX_VEHICULOS);
    
    bool encontrado = false;
    for (int i = 0; i < numVehiculos; ++i) {
        if (vehiculos[i].placa == placa) {
            resultado = vehiculos[i];
            encontrado = true;
            break;
        }
    }

    delete[] vehiculos;
    return encontrado;
}

// Consulta de repuesto segun el modelo
bool Consulta_Repuesto(int modelo, Repuestos& resultado){
    
    Repuestos* repuestos = new Repuestos[MAX_REPUESTOS];
    int numRepuestos = Repuestos::CargarDesdeArchivo("../bin/DATOS_REPUESTOS.csv", repuestos, MAX_REPUESTOS);

    bool encontrado = false;
    for (int i = 0; i < numRepuestos; ++i) {
        if (repuestos[i].modelo == modelo) {
            resultado = repuestos[i];
            encontrado = true;
            break;
        }
    }

    delete[] repuestos;
    return encontrado;
}

// Implementacion de funciones de insercion
void Agregar_Cliente(){
    Lectura_Cliente();
    cout << endl
         << "Introduzca los datos del Cliente que desea agregar: " << endl;

    cout << endl<< " Cedula: ";
    cin >> cliente.cedula;
    cout << " Nombre: ";
    cin >> cliente.nombre;
    cout << " Apellido: ";
    cin >> cliente.apellido;
    cout << " Correo: ";
    cin >> cliente.email;
    cout << " Vehiculos rentados: ";
    cin >> cliente.cantidad_vehiculos_rentados;
    cout << " Direccion: ";
    cin.ignore();
    getline(cin, cliente.direccion);
    cout << " Activo (Si = 1, No = 0): ";
    cin >> cliente.activo;

    clientes[numClientes++] = cliente;

    char confirmar;
    cout << "Desea confirmar los cambios realizados? (Y/N): ";
    cin >> confirmar;

    if (confirmar == 'y' || confirmar == 'Y'){
        ofstream escritura_cliente("DATOS_CLIENTES.csv", ios::app);

        escritura_cliente << cliente.cedula << ',' << cliente.nombre << ',' << cliente.apellido << ',' << cliente.email << ',' << cliente.cantidad_vehiculos_rentados << ',' << cliente.direccion << ',' << cliente.activo << endl;

        cout << "El Cliente " << cliente.nombre << " " << cliente.apellido << " ha sido agregado exitosamente." << endl;
        escritura_cliente.close();
    }
    else{
        cout << "El cambio ha sido descartado. " << endl;
    }
}

void Agregar_Vehiculo(){
    cout << endl << "Introduzca los datos del vehiculo que desea agregar: " << endl;

    cout << endl << " Modelo: ";
    cin >> vehiculo.modelo;
    cout << " Marca: ";
    cin >> vehiculo.marca;
    cout << " Placa: ";
    cin >> vehiculo.placa;
    cout << " Color: ";
    cin >> vehiculo.color;
    cout << " Year: ";
    cin >> vehiculo.year;
    cout << " Kilometraje: ";
    cin >> vehiculo.kilometraje;
    cout << " Rentado (Si = 1, No = 0): ";
    cin >> vehiculo.rentado;
    cout << " Motor: ";
    cin >> vehiculo.motor;
    cout << " Precio de renta: ";
    cin >> vehiculo.precio_renta;
    cout << " Cedula del cliente: ";
    cin >> vehiculo.ced_cliente;
    cout << " Fecha de entrega (dd/mm/aaaa): ";
    cin >> vehiculo.fecha_de_entrega;

    vehiculos[numVehiculos++] = vehiculo;

    char confirmar;
    cout << "Desea confirmar los cambios realizados? (Y/N): ";
    cin >> confirmar;

    if (confirmar == 'y' || confirmar == 'Y'){
        ofstream escritura_vehiculo("DATOS_VEHICULOS.csv", ios::app);

        escritura_vehiculo << vehiculo.modelo << ',' << vehiculo.marca << ',' << vehiculo.placa << ',' << vehiculo.color<< ',' << vehiculo.year << ',' << vehiculo.kilometraje << ',' << vehiculo.rentado << ',' << vehiculo.motor << ',' << vehiculo.precio_renta << ',' << vehiculo.ced_cliente << ',' << vehiculo.fecha_de_entrega << endl;

        cout << "El Vehiculo " << vehiculo.modelo << " " << vehiculo.marca << " ha sido agregado exitosamente." << endl;
        escritura_vehiculo.close();
    }
    else{
        cout << "El cambio ha sido descartado. " << endl;
    }
}

void Agregar_Repuesto(){
    Lectura_Repuesto();
    cout << endl << "Introduzca los datos del Repuesto que desea agregar: " << endl;

    cout << endl << " Modelo: ";
    cin >> repuesto.modelo;
    cout << " Marca: ";
    cin >> repuesto.marca;
    cout << " Nombre: ";
    cin.ignore();
    getline(cin, repuesto.nombre);
    cout << " Modelo del carro: ";
    cin >> repuesto.modelo_carro;
    cout << " Year Carro: ";
    cin >> repuesto.year_carro;
    cout << " Precio: ";
    cin >> repuesto.precio;
    cout << " Existencias: ";
    cin >> repuesto.existencias;

    repuestos[numRepuestos++] = repuesto;

    char confirmar;
    cout << "Desea confirmar los cambios realizados? (Y/N): ";
    cin >> confirmar;

    if (confirmar == 'y' || confirmar == 'Y'){
        ofstream escritura_repuesto("DATOS_REPUESTOS.csv", ios::app);

        escritura_repuesto << repuesto.modelo << ',' << repuesto.marca << ',' << repuesto.nombre << ',' << repuesto.modelo_carro<< ',' << repuesto.year_carro << ',' << repuesto.precio << ',' << repuesto.existencias << endl;

        cout << "El Repuesto " << repuesto.modelo << " " << repuesto.marca << " ha sido agregado exitosamente." << endl;
        escritura_repuesto.close();
    }
    else{
        cout << "El cambio ha sido descartado. " << endl;
    }
}

// Implementacion de funciones de borrado
void Eliminar_Cliente(){
    Lectura_Cliente();
    int cedula;
    cout << endl << "Ingrese la Cedula del Cliente que desea eliminar: ";
    cin >> cedula;

    int mid, left = 0, right = numClientes - 1;
    bool encontrado = false;

    while (left <= right){
        mid = left + (right - left) / 2;

        if (clientes[mid].cedula == cedula){
            encontrado = true;
            break;
        }
        if (clientes[mid].cedula < cedula){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    if (cedula == clientes[mid].cedula){
        for (int i = 0; i < numClientes; i++){
            clientes[i] = clientes[i + 1];
        }
        numClientes--;
    }

    if (encontrado){
        char confirmar;
        cout << "Desea confirmar los cambios realizados? (Y/N): ";
        cin >> confirmar;

        if (confirmar == 'y' || confirmar == 'Y'){
            ifstream lectura_cliente("DATOS_CLIENTES.csv");
            ofstream escritura_cliente_Temp("DATOS_CLIENTES_TEMP.csv");
            string line;
            int cedula_actual;

            while (getline(lectura_cliente, line)){
                istringstream ss(line);

                ss >> cliente.cedula;
                ss.ignore();
                cedula_actual = cliente.cedula;
                getline(ss, cliente.nombre, ',');
                getline(ss, cliente.apellido, ',');
                getline(ss, cliente.email, ',');
                ss >> cliente.cantidad_vehiculos_rentados;
                ss.ignore();
                getline(ss, cliente.direccion, ',');
                ss >> cliente.activo;

                if (cedula != cedula_actual){
                    escritura_cliente_Temp << cliente.cedula << ',' << cliente.nombre << ',' << cliente.apellido << ',' << cliente.email
                                           << ',' << cliente.cantidad_vehiculos_rentados << ',' << cliente.direccion << ',' << cliente.activo << endl;
                    continue;
                }
            }
            lectura_cliente.close();
            escritura_cliente_Temp.close();

            remove("DATOS_CLIENTES.csv");
            rename("DATOS_CLIENTES_TEMP.csv", "DATOS_CLIENTES.csv");
            cout << "El Cliente fue eliminado correctamente." << endl;
        }
        else{
            cout << "El cambio ha sido descartado. " << endl;
        }
    }
    else{
        cout << "El Cliente con Cedula " << cedula << " no existe en los registros." << endl;
    }
}

void Eliminar_Vehiculo(){
    string placa;
    cout << endl << "Ingrese la Placa del Vehiculo que desea eliminar: ";
    cin >> placa;

    ifstream lectura_vehiculo("DATOS_VEHICULOS.csv");
    ofstream escritura_vehiculo_Temp("DATOS_VEHICULOS_TEMP.csv");
    bool encontrado = false;
    string line, placa_actual;

    while (getline(lectura_vehiculo, line)){
        istringstream ss(line);

        getline(ss, vehiculo.modelo, ',');
        getline(ss, vehiculo.marca, ',');
        getline(ss, vehiculo.placa, ',');
        placa_actual = vehiculo.placa;
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

        if (placa.compare(placa_actual) == 0)
            encontrado = true;
        else{
            escritura_vehiculo_Temp << vehiculo.modelo << ',' << vehiculo.marca << ',' << vehiculo.placa << ',' << vehiculo.color
                                    << ',' << vehiculo.year << ',' << vehiculo.kilometraje << ',' << vehiculo.rentado << ',' << vehiculo.motor
                                    << ',' << vehiculo.precio_renta << ',' << vehiculo.ced_cliente << ',' << vehiculo.fecha_de_entrega << endl;
        }
    }
    lectura_vehiculo.close();
    escritura_vehiculo_Temp.close();

    if (encontrado){
        char confirmar;
        cout << "Desea confirmar los cambios realizados? (Y/N): ";
        cin >> confirmar;

        if (confirmar == 'y' || confirmar == 'Y'){
            remove("DATOS_VEHICULOS.csv");
            rename("DATOS_VEHICULOS_TEMP.csv", "DATOS_VEHICULOS.csv");
            cout << "El Vehiculo fue eliminado correctamente." << endl;
        }
        else{
            remove("DATOS_VEHICULOS_TEMP.csv");
            cout << "El cambio ha sido descartado. " << endl;
        }
    }
    else{
        cout << "El Vehiculo de placa " << placa << " no existe en los registros." << endl;
        remove("DATOS_VEHICULOS_TEMP.csv");
    }
}

void Eliminar_Repuesto(){
    Lectura_Repuesto();
    int modelo;
    cout << endl << "Ingrese el Modelo del Repuesto que desea eliminar: ";
    cin >> modelo;

    int mid, left = 0, right = numRepuestos - 1;
    bool encontrado = false;

    while (left <= right){
        mid = left + (right - left) / 2;

        if (repuestos[mid].modelo == modelo){
            encontrado = true;
            break;
        }
        if (repuestos[mid].modelo < modelo){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    if (modelo == repuestos[mid].modelo){
        for (int i = 0; i < numRepuestos; i++){
            repuestos[i] = repuestos[i + 1];
        }
        numRepuestos--;
    }

    if (encontrado){
        char confirmar;
        cout << "Desea confirmar los cambios realizados? (Y/N): ";
        cin >> confirmar;

        if (confirmar == 'y' || confirmar == 'Y'){
            ifstream lectura_repuesto("DATOS_REPUESTOS.csv");
            ofstream escritura_repuesto_Temp("DATOS_REPUESTOS_TEMP.csv");
            string line;
            int modelo_actual;

            while (getline(lectura_repuesto, line)){
                istringstream ss(line);

                ss >> repuesto.modelo;
                ss.ignore();
                modelo_actual = repuesto.modelo;
                getline(ss, repuesto.marca, ',');
                getline(ss, repuesto.nombre, ',');
                getline(ss, repuesto.modelo_carro, ',');
                ss >> repuesto.year_carro;
                ss.ignore();
                ss >> repuesto.precio;
                ss.ignore();
                ss >> repuesto.existencias;

                if (modelo != modelo_actual){
                    escritura_repuesto_Temp << repuesto.modelo << ',' << repuesto.marca << ',' << repuesto.nombre << ',' << repuesto.modelo_carro << ',' << repuesto.year_carro << ',' << repuesto.precio << ',' << repuesto.existencias << endl;
                    continue;
                }
            }
            lectura_repuesto.close();
            escritura_repuesto_Temp.close();

            remove("DATOS_REPUESTOS.csv");
            rename("DATOS_REPUESTOS_TEMP.csv", "DATOS_REPUESTOS.csv");
            cout << "El Repuesto fue eliminado correctamente." << endl;
        }
        else{
            cout << "El cambio ha sido descartado." << endl;
        }
    }
    else{
        cout << "El Repuesto de modelo " << modelo << " no existe en los registros." << endl;
    }
}

// Implementacion de funciones de actualizacion
void Actualizar_Cliente(){
    Lectura_Cliente();
    int cedula;
    cout << endl << "Ingrese la Cedula del Cliente que desea actualizar: ";
    cin >> cedula;

    int mid, left = 0, right = numClientes - 1;
    bool encontrado = false;

    while (left <= right){
        mid = left + (right - left) / 2;

        if (clientes[mid].cedula == cedula){
            encontrado = true;
            break;
        }
        if (clientes[mid].cedula < cedula){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    if (encontrado){
        ifstream lectura_cliente("DATOS_CLIENTES.csv");
        ofstream escritura_cliente_Temp("DATOS_CLIENTES_TEMP.csv");
        string line;
        int cedula_actual;

        while (getline(lectura_cliente, line)){
            istringstream ss(line);

            ss >> cliente.cedula;
            ss.ignore();
            cedula_actual = cliente.cedula;
            getline(ss, cliente.nombre, ',');
            getline(ss, cliente.apellido, ',');
            getline(ss, cliente.email, ',');
            ss >> cliente.cantidad_vehiculos_rentados;
            ss.ignore();
            getline(ss, cliente.direccion, ',');
            ss >> cliente.activo;

            if (cedula != cedula_actual){
                escritura_cliente_Temp << cliente.cedula << ',' << cliente.nombre << ',' << cliente.apellido << ',' << cliente.email
                                       << ',' << cliente.cantidad_vehiculos_rentados << ',' << cliente.direccion << ',' << cliente.activo << endl;
            }
            else{
                cout << endl << "Introduzca los datos del nuevo Cliente: " << endl;

                cout << endl << " Cedula: ";
                cin >> cliente.cedula;
                cout << " Nombre: ";
                cin >> cliente.nombre;
                cout << " Apellido: ";
                cin >> cliente.apellido;
                cout << " Correo: ";
                cin >> cliente.email;
                cout << " Vehiculos rentados: ";
                cin >> cliente.cantidad_vehiculos_rentados;
                cout << " Direccion: ";
                cin.ignore();
                getline(cin, cliente.direccion);
                cout << " Activo (Si = 1, No = 0): ";
                cin >> cliente.activo;

                clientes[mid].cedula = cliente.cedula;
                clientes[mid].nombre = cliente.nombre;
                clientes[mid].apellido = cliente.apellido;
                clientes[mid].email = cliente.email;
                clientes[mid].cantidad_vehiculos_rentados = cliente.cantidad_vehiculos_rentados;
                clientes[mid].direccion = cliente.direccion;
                clientes[mid].activo = cliente.activo;

                escritura_cliente_Temp << cliente.cedula << ',' << cliente.nombre << ',' << cliente.apellido << ',' << cliente.email
                                       << ',' << cliente.cantidad_vehiculos_rentados << ',' << cliente.direccion << ',' << cliente.activo << endl;
            }
        }
        lectura_cliente.close();
        escritura_cliente_Temp.close();

        char confirmar;
        cout << "Desea confirmar los cambios realizados? (Y/N): ";
        cin >> confirmar;

        if (confirmar == 'y' || confirmar == 'Y'){
            remove("DATOS_CLIENTES.csv");
            rename("DATOS_CLIENTES_TEMP.csv", "DATOS_CLIENTES.csv");
            cout << "El Cliente ha sido actualizado correctamente." << endl;
        }
        else{
            cout << "La actualizacion ha sido descartada. " << endl;
            remove("DATOS_CLIENTES_TEMP.csv");
        }
    }
    else{
        cout << "El Cliente con Cedula " << cedula << " no existe en los registros." << endl;
    }
}

void Actualizar_Vehiculo(){
    string placa;
    cout << endl << "Ingrese la Placa del Vehiculo que desea actualizar: ";
    cin >> placa;

    ifstream lectura_vehiculo("DATOS_VEHICULOS.csv");
    ofstream escritura_vehiculo_Temp("DATOS_VEHICULOS_TEMP.csv");
    bool encontrado = false;
    string line, placa_actual;

    while (getline(lectura_vehiculo, line)){
        istringstream ss(line);

        getline(ss, vehiculo.modelo, ',');
        getline(ss, vehiculo.marca, ',');
        getline(ss, vehiculo.placa, ',');
        placa_actual = vehiculo.placa;
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

        if (placa.compare(placa_actual) == 0){
            encontrado = true;
            cout << endl << "Introduzca los datos del nuevo vehiculo: " << endl;

            cout << endl << " Modelo: ";
            cin >> vehiculo.modelo;
            cout << " Marca: ";
            cin >> vehiculo.marca;
            cout << " Placa: ";
            cin >> vehiculo.placa;
            cout << " Color: ";
            cin >> vehiculo.color;
            cout << " Year: ";
            cin >> vehiculo.year;
            cout << " Kilometraje: ";
            cin >> vehiculo.kilometraje;
            cout << " Rentado (Si = 1, No = 0):: ";
            cin >> vehiculo.rentado;
            cout << " Motor: ";
            cin >> vehiculo.motor;
            cout << " Precio de renta: ";
            cin >> vehiculo.precio_renta;
            cout << " Cedula del cliente: ";
            cin >> vehiculo.ced_cliente;
            cout << " Fecha de entrega (dd/mm/aaaa): ";
            cin >> vehiculo.fecha_de_entrega;

            escritura_vehiculo_Temp << vehiculo.modelo << ',' << vehiculo.marca << ',' << vehiculo.placa << ',' << vehiculo.color << ',' << vehiculo.year << ',' << vehiculo.kilometraje << ',' << vehiculo.rentado << ',' << vehiculo.motor << ',' << vehiculo.precio_renta << ',' << vehiculo.ced_cliente << ',' << vehiculo.fecha_de_entrega << endl;
        }
        else{
            escritura_vehiculo_Temp << vehiculo.modelo << ',' << vehiculo.marca << ',' << vehiculo.placa << ',' << vehiculo.color << ',' << vehiculo.year << ',' << vehiculo.kilometraje << ',' << vehiculo.rentado << ',' << vehiculo.motor << ',' << vehiculo.precio_renta << ',' << vehiculo.ced_cliente << ',' << vehiculo.fecha_de_entrega << endl;
        }
    }
    lectura_vehiculo.close();
    escritura_vehiculo_Temp.close();

    if (encontrado){
        char confirmar;
        cout << "Desea confirmar los cambios realizados? (Y/N): ";
        cin >> confirmar;

        if (confirmar == 'y' || confirmar == 'Y'){
            remove("DATOS_VEHICULOS.csv");
            rename("DATOS_VEHICULOS_TEMP.csv", "DATOS_VEHICULOS.csv");
            cout << "El Vehiculo ha sido actualizado correctamente." << endl;
        }
        else{
            remove("DATOS_VEHICULOS_TEMP.csv");
            cout << "La actualizacion ha sido descartada. " << endl;
        }
    }
    else{
        cout << "El Vehiculo de placa " << placa << " no existe en los registros." << endl;
        remove("DATOS_VEHICULOS_TEMP.csv");
    }
}

void Actualizar_Repuesto(){
    Lectura_Repuesto();
    int modelo;
    cout << endl << "Ingrese el Modelo del Repuesto que desea actualizar: ";
    cin >> modelo;

    int mid, left = 0, right = numRepuestos - 1;
    bool encontrado = false;

    while (left <= right){
        mid = left + (right - left) / 2;

        if (repuestos[mid].modelo == modelo){
            encontrado = true;
            break;
        }
        if (repuestos[mid].modelo < modelo){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    if (encontrado){
        ifstream lectura_repuesto("DATOS_REPUESTOS.csv");
        ofstream escritura_repuesto_Temp("DATOS_REPUESTOS_TEMP.csv");
        string line;
        int modelo_actual;

        while (getline(lectura_repuesto, line)){
            istringstream ss(line);

            ss >> repuesto.modelo;
            ss.ignore();
            modelo_actual = repuesto.modelo;
            getline(ss, repuesto.marca, ',');
            getline(ss, repuesto.nombre, ',');
            getline(ss, repuesto.modelo_carro, ',');
            ss >> repuesto.year_carro;
            ss.ignore();
            ss >> repuesto.precio;
            ss.ignore();
            ss >> repuesto.existencias;

            if (modelo != modelo_actual){
                escritura_repuesto_Temp << repuesto.modelo << ',' << repuesto.marca << ',' << repuesto.nombre << ',' << repuesto.modelo_carro << ',' << repuesto.year_carro << ',' << repuesto.precio << ',' << repuesto.existencias << endl;
            }
            else{
                cout << endl << "Introduzca los datos del Repuesto que desea agregar: " << endl;

                cout << endl << " Modelo: ";
                cin >> repuesto.modelo;
                cout << " Marca: ";
                cin >> repuesto.marca;
                cout << " Nombre: ";
                cin.ignore();
                getline(cin, repuesto.nombre);
                cout << " Modelo del carro: ";
                cin >> repuesto.modelo_carro;
                cout << " Year Carro: ";
                cin >> repuesto.year_carro;
                cout << " Precio: ";
                cin >> repuesto.precio;
                cout << " Existencias: ";
                cin >> repuesto.existencias;

                repuestos[mid].modelo = repuesto.modelo;
                repuestos[mid].marca = repuesto.marca;
                repuestos[mid].nombre = repuesto.nombre;
                repuestos[mid].modelo_carro = repuesto.modelo_carro;
                repuestos[mid].year_carro = repuesto.year_carro;
                repuestos[mid].precio = repuesto.precio;
                repuestos[mid].existencias = repuesto.existencias;

                escritura_repuesto_Temp << repuesto.modelo << ',' << repuesto.marca << ',' << repuesto.nombre << ',' << repuesto.modelo_carro << ',' << repuesto.year_carro << ',' << repuesto.precio << ',' << repuesto.existencias << endl;
            }
        }
        lectura_repuesto.close();
        escritura_repuesto_Temp.close();

        char confirmar;
        cout << "Desea confirmar los cambios realizados? (Y/N): ";
        cin >> confirmar;
        if (confirmar == 'y' || confirmar == 'Y'){
            remove("DATOS_REPUESTOS.csv");
            rename("DATOS_REPUESTOS_TEMP.csv", "DATOS_REPUESTOS.csv");
            cout << "El Repuesto fue eliminado correctamente." << endl;
        }
        else{
            cout << "El cambio ha sido descartado." << endl;
            remove("DATOS_REPUESTOS_TEMP.csv");
        }
    }
    else{
        cout << "El Repuesto de modelo " << modelo << " no existe en los registros." << endl;
    }
}