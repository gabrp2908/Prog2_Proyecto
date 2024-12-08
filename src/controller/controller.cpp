#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../model/model.h"
#include "../view/view.h"
#include "controller.h"

using namespace std;

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

// Actualizar Vehiculo
bool Actualizar_Vehiculo(const Vehiculos& nuevoVehiculo, char confirmar) {
    ifstream lectura_vehiculo("../bin/DATOS_VEHICULOS.csv");
    ofstream escritura_vehiculo_Temp("../bin/DATOS_VEHICULOS_TEMP.csv");
    string line, placaActual;
    Vehiculos vehiculoActual;
    bool encontrado = false;

    while (getline(lectura_vehiculo, line)) {
        istringstream ss(line);

        getline(ss, vehiculoActual.modelo, ',');
        getline(ss, vehiculoActual.marca, ',');
        getline(ss, vehiculoActual.placa, ',');
        placaActual = vehiculoActual.placa;
        getline(ss, vehiculoActual.color, ',');
        ss >> vehiculoActual.year;
        ss.ignore();
        ss >> vehiculoActual.kilometraje;
        ss.ignore();
        ss >> vehiculoActual.rentado;
        ss.ignore();
        getline(ss, vehiculoActual.motor, ',');
        ss >> vehiculoActual.precio_renta;
        ss.ignore();
        ss >> vehiculoActual.ced_cliente;
        ss.ignore();
        getline(ss, vehiculoActual.fecha_de_entrega);

        if (placaActual == nuevoVehiculo.placa) {
            encontrado = true;
            escritura_vehiculo_Temp << nuevoVehiculo.modelo << ',' << nuevoVehiculo.marca << ',' << nuevoVehiculo.placa << ',' 
                                    << nuevoVehiculo.color << ',' << nuevoVehiculo.year << ',' << nuevoVehiculo.kilometraje << ',' 
                                    << nuevoVehiculo.rentado << ',' << nuevoVehiculo.motor << ',' << nuevoVehiculo.precio_renta << ',' 
                                    << nuevoVehiculo.ced_cliente << ',' << nuevoVehiculo.fecha_de_entrega << endl;
        } else {
            escritura_vehiculo_Temp << vehiculoActual.modelo << ',' << vehiculoActual.marca << ',' << vehiculoActual.placa << ',' 
                                    << vehiculoActual.color << ',' << vehiculoActual.year << ',' << vehiculoActual.kilometraje << ',' 
                                    << vehiculoActual.rentado << ',' << vehiculoActual.motor << ',' << vehiculoActual.precio_renta << ',' 
                                    << vehiculoActual.ced_cliente << ',' << vehiculoActual.fecha_de_entrega << endl;
        }
    }

    lectura_vehiculo.close();
    escritura_vehiculo_Temp.close();

    if (encontrado && confirmar) {
        if (confirmar == 'y' || confirmar == 'Y'){
            remove("../bin/DATOS_VEHICULOS.csv");
            rename("../bin/DATOS_VEHICULOS_TEMP.csv", "../bin/DATOS_VEHICULOS.csv");
        } else {
        remove("../bin/DATOS_VEHICULOS_TEMP.csv");
        }
    }

    return encontrado;
}

// Actualizar Cliente
bool Actualizar_Cliente(const Cliente& nuevoCliente, char confirmar) {
    ifstream lectura_cliente("../bin/DATOS_CLIENTES.csv");
    ofstream escritura_cliente_Temp("../bin/DATOS_CLIENTES_TEMP.csv");
    string line;
    Cliente clienteActual;
    bool encontrado = false;

    while (getline(lectura_cliente, line)) {
        istringstream ss(line);

        ss >> clienteActual.cedula;
        ss.ignore();
        getline(ss, clienteActual.nombre, ',');
        getline(ss, clienteActual.apellido, ',');
        getline(ss, clienteActual.email, ',');
        ss >> clienteActual.cantidad_vehiculos_rentados;
        ss.ignore();
        getline(ss, clienteActual.direccion, ',');
        ss >> clienteActual.activo;

        if (clienteActual.cedula == nuevoCliente.cedula) {
            encontrado = true;
            escritura_cliente_Temp << nuevoCliente.cedula << ',' << nuevoCliente.nombre << ',' 
                                   << nuevoCliente.apellido << ',' << nuevoCliente.email << ',' 
                                   << nuevoCliente.cantidad_vehiculos_rentados << ',' << nuevoCliente.direccion 
                                   << ',' << nuevoCliente.activo << endl;
        } else {
            escritura_cliente_Temp << clienteActual.cedula << ',' << clienteActual.nombre << ',' 
                                   << clienteActual.apellido << ',' << clienteActual.email << ',' 
                                   << clienteActual.cantidad_vehiculos_rentados << ',' << clienteActual.direccion 
                                   << ',' << clienteActual.activo << endl;
        }
    }

    lectura_cliente.close();
    escritura_cliente_Temp.close();

    if (encontrado && confirmar) {
        if (confirmar == 'y' || confirmar == 'Y'){
            remove("../bin/DATOS_CLIENTES.csv");
            rename("../bin/DATOS_CLIENTES_TEMP.csv", "../bin/DATOS_CLIENTES.csv");
        }
    } else {
        remove("../bin/DATOS_CLIENTES_TEMP.csv");
    }

    return encontrado;
}

// Actualizar Repuesto
bool Actualizar_Repuesto(const Repuestos& nuevoRepuesto, char confirmar) {
    ifstream lectura_repuesto("../bin/DATOS_REPUESTOS.csv");
    ofstream escritura_repuesto_Temp("../bin/DATOS_REPUESTOS_TEMP.csv");
    string line;
    Repuestos repuestoActual;
    bool encontrado = false;

    while (getline(lectura_repuesto, line)) {
        istringstream ss(line);

        ss >> repuestoActual.modelo;
        ss.ignore();
        getline(ss, repuestoActual.marca, ',');
        getline(ss, repuestoActual.nombre, ',');
        getline(ss, repuestoActual.modelo_carro, ',');
        ss >> repuestoActual.year_carro;
        ss.ignore();
        ss >> repuestoActual.precio;
        ss.ignore();
        ss >> repuestoActual.existencias;

        if (repuestoActual.modelo == nuevoRepuesto.modelo) {
            encontrado = true;
            escritura_repuesto_Temp << nuevoRepuesto.modelo << ',' << nuevoRepuesto.marca << ',' 
                                    << nuevoRepuesto.nombre << ',' << nuevoRepuesto.modelo_carro << ',' 
                                    << nuevoRepuesto.year_carro << ',' << nuevoRepuesto.precio << ',' 
                                    << nuevoRepuesto.existencias << endl;
        } else {
            escritura_repuesto_Temp << repuestoActual.modelo << ',' << repuestoActual.marca << ',' 
                                    << repuestoActual.nombre << ',' << repuestoActual.modelo_carro << ',' 
                                    << repuestoActual.year_carro << ',' << repuestoActual.precio << ',' 
                                    << repuestoActual.existencias << endl;
        }
    }

    lectura_repuesto.close();
    escritura_repuesto_Temp.close();

    if (encontrado && confirmar) {
        if (confirmar == 'y' || confirmar == 'Y'){
        remove("../bin/DATOS_REPUESTOS.csv");
        rename("../bin/DATOS_REPUESTOS_TEMP.csv", "../bin/DATOS_REPUESTOS.csv");
        }
    } else {
        remove("../bin/DATOS_REPUESTOS_TEMP.csv");
    }

    return encontrado;
}

// Eliminar Vehiculo
bool Eliminar_Vehiculo(const string& placa, char confirmar) {
    ifstream lectura_vehiculo("../bin/DATOS_VEHICULOS.csv");
    ofstream escritura_vehiculo_Temp("../bin/DATOS_VEHICULOS_TEMP.csv");
    string line, placa_actual;
    Vehiculos vehiculo;
    bool encontrado = false;

    while (getline(lectura_vehiculo, line)) {
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

        if (placa_actual == placa) {
            encontrado = true;
        } else {
            escritura_vehiculo_Temp << vehiculo.modelo << ',' << vehiculo.marca << ',' << vehiculo.placa << ',' 
                                    << vehiculo.color << ',' << vehiculo.year << ',' << vehiculo.kilometraje << ',' 
                                    << vehiculo.rentado << ',' << vehiculo.motor << ',' << vehiculo.precio_renta << ',' 
                                    << vehiculo.ced_cliente << ',' << vehiculo.fecha_de_entrega << endl;
        }
    }

    lectura_vehiculo.close();
    escritura_vehiculo_Temp.close();

    if (encontrado && confirmar) {
        if (confirmar == 'y' || confirmar == 'Y'){
        remove("../bin/DATOS_VEHICULOS.csv");
        rename("../bin/DATOS_VEHICULOS_TEMP.csv", "../bin/DATOS_VEHICULOS.csv");
        }
    } else {
        remove("../bin/DATOS_VEHICULOS_TEMP.csv");
    }

    return encontrado;
}

// Eliminar Cliente
bool Eliminar_Cliente(int cedula, char confirmar) {
    ifstream lectura_cliente("../bin/DATOS_CLIENTES.csv");
    ofstream escritura_cliente_Temp("../bin/DATOS_CLIENTES_TEMP.csv");
    string line;
    Cliente cliente;
    bool encontrado = false;

    while (getline(lectura_cliente, line)) {
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

        if (cliente.cedula == cedula) {
            encontrado = true;
        } else {
            escritura_cliente_Temp << cliente.cedula << ',' << cliente.nombre << ',' 
                                   << cliente.apellido << ',' << cliente.email << ',' 
                                   << cliente.cantidad_vehiculos_rentados << ',' << cliente.direccion 
                                   << ',' << cliente.activo << endl;
        }
    }

    lectura_cliente.close();
    escritura_cliente_Temp.close();

    if (encontrado && confirmar) {
        if (confirmar == 'y' || confirmar == 'Y'){
        remove("../bin/DATOS_CLIENTES.csv");
        rename("../bin/DATOS_CLIENTES_TEMP.csv", "../bin/DATOS_CLIENTES.csv");
        }
    } else {
        remove("../bin/DATOS_CLIENTES_TEMP.csv");
    }

    return encontrado;
}

// Eliminar Repuesto
bool Eliminar_Repuesto(int modelo, char confirmar) {
    ifstream lectura_repuesto("../bin/DATOS_REPUESTOS.csv");
    ofstream escritura_repuesto_Temp("../bin/DATOS_REPUESTOS_TEMP.csv");
    string line;
    Repuestos repuesto;
    bool encontrado = false;

    while (getline(lectura_repuesto, line)) {
        istringstream ss(line);

        ss >> repuesto.modelo;
        ss.ignore();
        getline(ss, repuesto.marca, ',');
        getline(ss, repuesto.nombre, ',');
        getline(ss, repuesto.modelo_carro, ',');
        ss >> repuesto.year_carro;
        ss.ignore();
        ss >> repuesto.precio;
        ss.ignore();
        ss >> repuesto.existencias;

        if (repuesto.modelo == modelo) {
            encontrado = true;
        } else {
            escritura_repuesto_Temp << repuesto.modelo << ',' << repuesto.marca << ',' 
                                    << repuesto.nombre << ',' << repuesto.modelo_carro << ',' 
                                    << repuesto.year_carro << ',' << repuesto.precio << ',' 
                                    << repuesto.existencias << endl;
        }
    }

    lectura_repuesto.close();
    escritura_repuesto_Temp.close();

    if (encontrado && confirmar) {
        if (confirmar == 'y' || confirmar == 'Y'){
        remove("../bin/DATOS_REPUESTOS.csv");
        rename("../bin/DATOS_REPUESTOS_TEMP.csv", "../bin/DATOS_REPUESTOS.csv");
        }
    } else {
        remove("../bin/DATOS_REPUESTOS_TEMP.csv");
    }

    return encontrado;
}

// Agregar Vehiculo al archivo
bool Agregar_Vehiculo(const Vehiculos& vehiculo) {
    ofstream escritura_vehiculo("../bin/DATOS_VEHICULOS.csv", ios::app);

    escritura_vehiculo << vehiculo.modelo << ',' << vehiculo.marca << ',' << vehiculo.placa << ',' 
                        << vehiculo.color << ',' << vehiculo.year << ',' << vehiculo.kilometraje << ',' 
                        << vehiculo.rentado << ',' << vehiculo.motor << ',' << vehiculo.precio_renta << ',' 
                        << vehiculo.ced_cliente << ',' << vehiculo.fecha_de_entrega << endl;

    escritura_vehiculo.close();
    return true;
}

// Agregar Cliente al archivo
bool Agregar_Cliente(const Cliente& cliente) {
    ofstream escritura_cliente("../bin/DATOS_CLIENTES.csv", ios::app);

    escritura_cliente << cliente.cedula << ',' << cliente.nombre << ',' << cliente.apellido << ',' 
                      << cliente.email << ',' << cliente.cantidad_vehiculos_rentados << ',' 
                      << cliente.direccion << ',' << cliente.activo << endl;

    escritura_cliente.close();
    return true;
}

// Agregar Repuesto al archivo
bool Agregar_Repuesto(const Repuestos& repuesto) {
    ofstream escritura_repuesto("../bin/DATOS_REPUESTOS.csv", ios::app);

    escritura_repuesto << repuesto.modelo << ',' << repuesto.marca << ',' << repuesto.nombre << ',' 
                       << repuesto.modelo_carro << ',' << repuesto.year_carro << ',' 
                       << repuesto.precio << ',' << repuesto.existencias << endl;

    escritura_repuesto.close();
    return true;
}