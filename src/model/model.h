#ifndef model_h
#define model_h
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

const int MAX_VEHICULOS = 10000;
const int MAX_CLIENTES = 10000;
const int MAX_REPUESTOS = 10000;

class Vehiculos{
    public:
    string modelo, marca, placa, color, motor, fecha_de_entrega;
    int year = 0, kilometraje = 0, ced_cliente = 0;
    float precio_renta = 0.0;
    bool rentado = false;

    static int CargarDesdeArchivo(const string& archivo, Vehiculos* vehiculos, int maxVehiculos) {
        ifstream file(archivo);
        string line;
        int i = 0;
        while (getline(file, line) && i < maxVehiculos) {
            istringstream ss(line);

            getline(ss, vehiculos[i].modelo, ',');
            getline(ss, vehiculos[i].marca, ',');
            getline(ss, vehiculos[i].placa, ',');
            getline(ss, vehiculos[i].color, ',');
            ss >> vehiculos[i].year;
            ss.ignore();
            ss >> vehiculos[i].kilometraje;
            ss.ignore();
            ss >> vehiculos[i].rentado;
            ss.ignore();
            getline(ss, vehiculos[i].motor, ',');
            ss >> vehiculos[i].precio_renta;
            ss.ignore();
            ss >> vehiculos[i].ced_cliente;
            ss.ignore();
            getline(ss, vehiculos[i].fecha_de_entrega);

            i++;
        }

        file.close();
        return i;
    }
};

class Cliente{
    public:
    string nombre, apellido, email, direccion;
    int cedula = 0, cantidad_vehiculos_rentados = 0;
    bool activo = false;

    static int CargarDesdeArchivo(const string& archivo, Cliente* clientes, int maxClientes) {
        ifstream file(archivo);
        string line;
        int i = 0;
        while (getline(file, line) && i < maxClientes) {
            istringstream ss(line);

            ss >> clientes[i].cedula;
            ss.ignore();
            getline(ss, clientes[i].nombre, ',');
            getline(ss, clientes[i].apellido, ',');
            getline(ss, clientes[i].email, ',');
            ss >> clientes[i].cantidad_vehiculos_rentados;
            ss.ignore();
            getline(ss, clientes[i].direccion, ',');
            ss >> clientes[i].activo;

            i++;
        }

        file.close();
        return i;
    }
};

class Repuestos{
    public:
    string marca, nombre, modelo_carro;
    int modelo = 0, year_carro = 0, existencias = 0;
    float precio = 0.0;

    static int CargarDesdeArchivo(const string& archivo, Repuestos* repuestos, int maxRepuestos) {
        ifstream file(archivo);
        string line;
        int i = 0;
        while (getline(file, line) && i < maxRepuestos) {
            istringstream ss(line);

            ss >> repuestos[i].modelo;
            ss.ignore();
            getline(ss, repuestos[i].marca, ',');
            getline(ss, repuestos[i].nombre, ',');
            getline(ss, repuestos[i].modelo_carro, ',');
            ss >> repuestos[i].year_carro;
            ss.ignore();
            ss >> repuestos[i].precio;
            ss.ignore();
            ss >> repuestos[i].existencias;

            i++;
        }

        file.close();
        return i;
    }
};

struct Usuario {
    string username;
    string password;
    string rol;
};

const int MAX_USUARIOS = 100;

extern Usuario UsuariosBase[MAX_USUARIOS];
extern int numUsuarios;

#endif