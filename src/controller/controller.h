#ifndef controller_h
#define controller_h

// Funciones de Lectura
void Lectura_Cliente();
void Lectura_Vehiculo();
void Lectura_Repuesto();

// Funciones de QuickSort para cada estructura
void QuickSortVehiculos(int left, int right);
void QuickSortClientes(int left, int right);
void QuickSortRepuestos(int left, int right);

// Funciones de partición para QuickSort
int PartitionVehiculos(int left, int right);
int PartitionClientes(int left, int right);
int PartitionRepuestos(int left, int right);

// Funciones de Consulta
void Consulta_Cliente();
void Consulta_Vehiculo();
void Consulta_Repuesto();

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
