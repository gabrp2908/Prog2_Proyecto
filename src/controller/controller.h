#ifndef controller_h
#define controller_h

#include "../model/model.h"

// Funciones de Consulta
bool Consultar_Vehiculo(const string& placa, Vehiculos& resultado);
bool Consultar_Cliente(int cedula, Cliente& resultado);
bool Consultar_Repuesto(int modelo, Repuestos& resultado);

// Funciones de Insercion
void Agregar_Cliente();
void Agregar_Vehiculo();
void Agregar_Repuesto();

// Funciones de Borrado
void Eliminar_Cliente();
void Eliminar_Vehiculo();
void Eliminar_Repuesto();

// Funciones de Actulizacion
void Actualizar_Cliente();
void Actualizar_Vehiculo();
void Actualizar_Repuesto();

#endif
