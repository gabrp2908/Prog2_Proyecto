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