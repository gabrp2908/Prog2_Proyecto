#ifndef controller_h
#define controller_h
#include <string>
using namespace std;

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

#endif
