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
}repuesto;

void Lectura_Cliente();
void Lectura_Vehiculo();

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

    lectura_cliente.close();
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

    lectura_vehiculo.close();
}

int main() {


    return 0;
    }