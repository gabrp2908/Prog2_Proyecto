#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../model/model.h"
using namespace std;

int numVehiculos = 0, numClientes = 0, numRepuestos = 0;

// Implementacion de QuickSort para Vehiculos
void QuickSortVehiculos(int left, int right){
    if (left < right){
        int pivotIndex = PartitionVehiculos(left, right);
        QuickSortVehiculos(left, pivotIndex - 1);
        QuickSortVehiculos(pivotIndex + 1, right);
    }
}

int PartitionVehiculos(int left, int right){
    int pivot = vehiculos[right].ced_cliente;
    int i = left - 1;

    for (int j = left; j < right; j++){
        if (vehiculos[j].ced_cliente < pivot){
            i++;
            swap(vehiculos[i], vehiculos[j]);
        }
    }
    swap(vehiculos[i + 1], vehiculos[right]);
    return i + 1;
}

// Implementacion de QuickSort para Clientes
void QuickSortClientes(int left, int right){
    if (left < right){
        int pivotIndex = PartitionClientes(left, right);
        QuickSortClientes(left, pivotIndex - 1);
        QuickSortClientes(pivotIndex + 1, right);
    }
}

int PartitionClientes(int left, int right){
    int pivot = cliente[right].cedula;
    int i = left - 1;

    for (int j = left; j < right; j++){
        if (cliente[j].cedula < pivot){
            i++;
            swap(cliente[i], cliente[j]);
        }
    }
    swap(cliente[i + 1], cliente[right]);
    return i + 1;
}

// Implementacion de QuickSort para Repuestos
void QuickSortRepuestos(int left, int right){
    if (left < right){
        int pivotIndex = PartitionRepuestos(left, right);
        QuickSortRepuestos(left, pivotIndex - 1);
        QuickSortRepuestos(pivotIndex + 1, right);
    }
}

int PartitionRepuestos(int left, int right){
    int pivot = repuesto[right].modelo;
    int i = left - 1;

    for (int j = left; j < right; j++){
        if (repuesto[j].modelo < pivot){
            i++;
            swap(repuesto[i], repuesto[j]);
        }
    }
    swap(repuesto[i + 1], repuesto[right]);
    return i + 1;
}

// Lectura de archivos
void Lectura_Cliente(){
    ifstream lectura_cliente("DATOS_CLIENTES.csv", ios::in);
    string line;

    while (getline(lectura_cliente, line) && numClientes < MAX_CLIENTES){
        istringstream ss(line);

        ss >> cliente->cedula;
        ss.ignore();
        getline(ss, cliente->nombre, ',');
        getline(ss, cliente->apellido, ',');
        getline(ss, cliente->email, ',');
        ss >> cliente->cantidad_vehiculos_rentados;
        ss.ignore();
        getline(ss, cliente->direccion, ',');
        ss >> cliente->activo;

        cliente[numClientes++] = cliente;
    }
    lectura_cliente.close();

    QuickSortClientes(0, numClientes - 1);
}

void Lectura_Vehiculo(){
    ifstream lectura_vehiculo("DATOS_VEHICULOS.csv");
    string line;

    while (getline(lectura_vehiculo, line) && numVehiculos < MAX_VEHICULOS){
        istringstream ss(line);

        getline(ss, vehiculos->modelo, ',');
        getline(ss, vehiculos->marca, ',');
        getline(ss, vehiculos->placa, ',');
        getline(ss, vehiculos->color, ',');
        ss >> vehiculos->year;
        ss.ignore();
        ss >> vehiculos->kilometraje;
        ss.ignore();
        ss >> vehiculos->rentado;
        ss.ignore();
        getline(ss, vehiculos->motor, ',');
        ss >> vehiculos->precio_renta;
        ss.ignore();
        ss >> vehiculos->ced_cliente;
        ss.ignore();
        getline(ss, vehiculos->fecha_de_entrega);

        vehiculos[numVehiculos++] = vehiculos;
    }
    lectura_vehiculos->close();

    QuickSortVehiculos(0, numVehiculos - 1);
}

void Lectura_Repuesto(){
    ifstream lectura_repuesto("DATOS_REPUESTOS.csv", ios::in);
    string line;

    while (getline(lectura_repuesto, line) && numRepuestos < MAX_REPUESTOS){
        istringstream ss(line);

        ss >> repuesto->modelo;
        ss.ignore();
        getline(ss, repuesto->marca, ',');
        getline(ss, repuesto->nombre, ',');
        getline(ss, repuesto->modelo_carro, ',');
        ss >> repuesto->year_carro;
        ss.ignore();
        ss >> repuesto->precio;
        ss.ignore();
        ss >> repuesto->existencias;

        repuesto[numRepuestos++] = repuesto;
    }
    lectura_repuesto.close();

    QuickSortRepuestos(0, numRepuestos - 1);
}