#ifndef controller_h
#define controller_h

#include "../model/model.h"

// Funciones de Consulta
bool Consultar_Vehiculo(const string& placa, Vehiculos& resultado);
bool Consultar_Cliente(int cedula, Cliente& resultado);
bool Consultar_Repuesto(int modelo, Repuestos& resultado);

// Funciones de Actualizacion
bool Actualizar_Vehiculo(const Vehiculos& nuevoVehiculo, char confirmar);
bool Actualizar_Cliente(const Cliente& nuevoCliente, char confirmar);
bool Actualizar_Repuesto(const Repuestos& nuevoRepuesto, char confirmar);

// Funciones de Borrado
bool Eliminar_Vehiculo(const string& placa, char confirmar);
bool Eliminar_Cliente(int cedula, char confirmar);
bool Eliminar_Repuesto(int modelo, char confirmar);

// Funciones de Insercion
bool Agregar_Vehiculo(const Vehiculos& vehiculo);
bool Agregar_Cliente(const Cliente& cliente);
bool Agregar_Repuesto(const Repuestos& repuesto);
#endif
