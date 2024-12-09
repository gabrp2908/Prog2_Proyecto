#ifndef view_h
#define view_h
#include "../model/model.h"

// Funciones de Menu
void MenuConsultar();
void MenuActualizar();
void MenuBorrar();
void MenuAgregar();
void Backup();

// Funciones de Menu por Rol
void MenuPorRol(const Usuario& usuario);
void MenuAdmin();
void MenuManager();
void MenuEmpleado();

// Funciones de Consulta en View
void Consultar_Vehiculo_View();
void Consultar_Cliente_View();
void Consultar_Repuesto_View();

// Funciones de Actualizar en View
void Actualizar_Vehiculo_View();
void Actualizar_Cliente_View();
void Actualizar_Repuesto_View();

// Funciones de Eliminar en View
void Eliminar_Vehiculo_View();
void Eliminar_Cliente_View();
void Eliminar_Repuesto_View();

// Funciones de Agregar en View
void Agregar_Vehiculo_View();
void Agregar_Cliente_View();
void Agregar_Repuesto_View();

#endif