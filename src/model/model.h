#ifndef model_h
#define model_h
#include <string>
using namespace std;

const int MAX_VEHICULOS = 10000;
const int MAX_CLIENTES = 10000;
const int MAX_REPUESTOS = 10000;

class Vehiculos{
    public:
    string modelo, marca, placa, color, motor, fecha_de_entrega;
    int year, kilometraje, ced_cliente;
    float precio_renta;
    bool rentado;
}*vehiculos;

class Cliente{
    public:
    string nombre, apellido, email, direccion;
    int cedula, cantidad_vehiculos_rentados;
    bool activo;
}*cliente;

class Repuestos{
    public:
    string marca, nombre, modelo_carro;
    int modelo, year_carro, existencias;
    float precio;
}*repuesto;

#endif