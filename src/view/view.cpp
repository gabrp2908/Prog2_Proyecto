#include <iostream>
#include "view.h"
#include "../controller/controller.h"
using namespace std;

void MenuPrincipal(){
    int opcion;
    do{
        cout << endl << "MENU PRINCIPAL" << endl;
        cout << "1. Consultar" << endl;
        cout << "2. Actualizar" << endl;
        cout << "3. Borrar" << endl;
        cout << "4. Agregar" << endl;
        cout << "5. Salir del programa" << endl << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion){
        case 1:
            MenuConsultar();
            break;
        case 2:
            MenuActualizar();
            break;
        case 3:
            MenuBorrar();
            break;
        case 4:
            MenuAgregar();
            break;
        case 5:
            cout << "Saliendo del programa . . ." << endl;
            break;
        default:
            cout << "Opcion invalida" << endl
                 << endl;
        }
    } while (opcion != 5);
}

void MenuConsultar(){
    int opcion_consulta;
    do{
        cout << endl << "MENU DE CONSULTA DE REGISTROS" << endl;
        cout << "Indique el tipo de consulta que desea realizar:" << endl;
        cout << "1. Vehiculo" << endl;
        cout << "2. Cliente" << endl;
        cout << "3. Repuesto" << endl;
        cout << "4. Regresar al Menu Principal" << endl << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion_consulta;

        switch (opcion_consulta){
        case 1:
            Consulta_Vehiculo_View();
            break;
        case 2:
            Consulta_Cliente_View();
            break;
        case 3:
            Consulta_Repuesto_View();
            break;
        case 4: // Retorno a Menu Principal
            return;
            break;
        default:
            cout << "Opcion Invalida" << endl << endl;
        }
    } while (opcion_consulta != 5);
}

void MenuActualizar(){
    int opcion_actualizar;
    do{
        cout << endl << "MENU DE ACTUALIZACION DE REGISTROS" << endl;
        cout << "Indique el tipo de registro que desea actualizar:" << endl;
        cout << "1. Vehiculo " << endl;
        cout << "2. Cliente" << endl;
        cout << "3. Repuesto" << endl;
        cout << "4. Regresar al Menu Principal" << endl << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion_actualizar;

        switch (opcion_actualizar){
        case 1:
            Actualizar_Vehiculo();
            break;
        case 2:
            Actualizar_Cliente();
            break;
        case 3:
            Actualizar_Repuesto();
            break;
        case 4: // Retorno a Menu Principal
            return;
            break;
        default:
            cout << "Opcion Invalida" << endl
                 << endl;
        }
    } while (opcion_actualizar != 4);
}

void MenuBorrar(){
    int opcion_borrar;
    do{
        cout << endl << "MENU DE ELIMINACION DE REGISTROS" << endl;
        cout << "Indique el tipo de registro que desea eliminar:" << endl;
        cout << "1. Vehiculo " << endl;
        cout << "2. Cliente" << endl;
        cout << "3. Repuesto" << endl;
        cout << "4. Regresar al Menu Principal" << endl << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion_borrar;

        switch (opcion_borrar){
        case 1:
            Eliminar_Vehiculo();
            break;
        case 2:
            Eliminar_Cliente();
            break;
        case 3:
            Eliminar_Repuesto();
            break;
        case 4: // Retorno a Menu Principal
            return;
            break;
        default:
            cout << "Opcion Invalida" << endl
                 << endl;
        }
    } while (opcion_borrar != 4);
}

void MenuAgregar(){
    int opcion_agregar;
    do{
        cout << endl << "MENU DE ACTUALIZACION DE REGISTROS" << endl;
        cout << "Indique el tipo de registro que desea agregar:" << endl;
        cout << "1. Vehiculo " << endl;
        cout << "2. Cliente" << endl;
        cout << "3. Repuesto" << endl;
        cout << "4. Regresar al Menu Principal" << endl << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion_agregar;

        switch (opcion_agregar){
        case 1:
            Agregar_Vehiculo();
            break;
        case 2:
            Agregar_Cliente();
            break;
        case 3:
            Agregar_Repuesto();
            break;
        case 4: // Retorno a Menu Principal
            return;
            break;
        default:
            cout << "Opcion Invalida" << endl;
        }
    } while (opcion_agregar != 4);
}

void Consulta_Vehiculo_View() {
    string placa;
    cout << endl << "Ingrese la placa del vehiculo que desea consultar: ";
    cin >> placa;

    Vehiculos vehiculo;
    if (Consultar_Vehiculo(placa, vehiculo)) {
        cout << " Modelo: " << vehiculo.modelo << endl;
        cout << " Marca: " << vehiculo.marca << endl;
        cout << " Placa: " << vehiculo.placa << endl;
        cout << " Year: " << vehiculo.year << endl;
        cout << " Rentado: " << (vehiculo.rentado ? "Si" : "No") << endl;
        cout << " Motor: " << vehiculo.motor << endl;
        cout << " Precio de renta: " << vehiculo.precio_renta << " $/hr" << endl;
        if (vehiculo.rentado == 0){
            cout << " Cedula del cliente: N/A" << endl;
            cout << " Fecha de entrega: N/A" << endl;
        } else {
            cout << " Cedula del cliente: " << vehiculo.ced_cliente << endl;
            cout << " Fecha de entrega: " << vehiculo.fecha_de_entrega << endl;
        }
    } else {
        cout << "La placa " << placa << " no ha sido encontrada en los registros." << endl;
    }
}

void Consulta_Cliente_View() {
    int cedula;
    cout << endl << "Ingrese la cedula del cliente que desea consultar: ";
    cin >> cedula;

    Cliente cliente;
    if (Consultar_Cliente(cedula, cliente)) {
        cout << " Cedula: " << cliente.cedula << endl;
        cout << " Nombre: " << cliente.nombre << endl;
        cout << " Apellido: " << cliente.apellido << endl;
        cout << " Correo: " << cliente.email << endl;
        cout << " Vehiculos rentados: " << cliente.cantidad_vehiculos_rentados << endl;
        cout << " Direccion: " << cliente.direccion << endl;
        cout << " Activo: " << (cliente.activo ? "Si" : "No") << endl;
    } else {
        cout << "La cedula " << cedula << " no ha sido encontrada en los registros." << endl;
    }
}

void Consulta_Repuesto_View() {
    int modelo;
    cout << endl << "Ingrese el modelo del repuesto que desea consultar: ";
    cin >> modelo;

    Repuestos repuesto;
    if (Consultar_Repuesto(modelo, repuesto)) {
        cout << " Modelo: " << repuesto.modelo << endl;
        cout << " Marca: " << repuesto.marca << endl;
        cout << " Nombre: " << repuesto.nombre << endl;
        cout << " Modelo del carro: " << repuesto.modelo_carro << endl;
        cout << " Year del carro: " << repuesto.year_carro << endl;
        cout << " Precio: " << repuesto.precio << " $" << endl;
        cout << " Existencias: " << repuesto.existencias << endl;
    } else {
        cout << "El modelo " << modelo << " no ha sido encontrado en los registros." << endl;
    }
}