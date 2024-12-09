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
        cout << "5. Crear copias de seguridad" << endl;
        cout << "6. Salir del programa" << endl << endl;
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
            Backup();
            break;
        case 6:
            cout << "Saliendo del programa . . ." << endl;
            break;
        default:
            cout << "Opcion invalida" << endl
                 << endl;
        }
    } while (opcion != 6);
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
            Consultar_Vehiculo_View();
            break;
        case 2:
            Consultar_Cliente_View();
            break;
        case 3:
            Consultar_Repuesto_View();
            break;
        case 4: // Retorno a Menu Principal
            return;
            break;
        default:
            cout << "Opcion Invalida" << endl << endl;
        }
    } while (opcion_consulta != 4);
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
            Actualizar_Vehiculo_View();
            break;
        case 2:
            Actualizar_Cliente_View();
            break;
        case 3:
            Actualizar_Repuesto_View();
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
            Eliminar_Vehiculo_View();
            break;
        case 2:
            Eliminar_Cliente_View();
            break;
        case 3:
            Eliminar_Repuesto_View();
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
            Agregar_Vehiculo_View();
            break;
        case 2:
            Agregar_Cliente_View();
            break;
        case 3:
            Agregar_Repuesto_View();
            break;
        case 4: // Retorno a Menu Principal
            return;
            break;
        default:
            cout << "Opcion Invalida" << endl;
        }
    } while (opcion_agregar != 4);
}

void Consultar_Vehiculo_View() {
    string placa;
    cout << endl << "Ingrese la placa del vehiculo que desea consultar: ";
    cin >> placa;

    Vehiculos vehiculo;
    if (Consultar_Vehiculo(placa, vehiculo)) {
        cout << " Modelo: " << vehiculo.modelo << endl;
        cout << " Marca: " << vehiculo.marca << endl;
        cout << " Placa: " << vehiculo.placa << endl;
        cout << " Color: " << vehiculo.color << endl;
        cout << " Year: " << vehiculo.year << endl;
        cout << " Kilometraje: " << vehiculo.kilometraje << endl;
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

void Consultar_Cliente_View() {
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

void Consultar_Repuesto_View() {
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

void Actualizar_Vehiculo_View() {
    Vehiculos nuevoVehiculo;
    cout << endl << "Ingrese la Placa del Vehiculo que desea actualizar: ";
    cin >> nuevoVehiculo.placa;

    cout << "Introduzca los nuevos datos del vehiculo: " << endl;
    cout << " Modelo: ";
    cin >> nuevoVehiculo.modelo;
    cout << " Marca: ";
    cin >> nuevoVehiculo.marca;
    cout << " Color: ";
    cin >> nuevoVehiculo.color;
    cout << " Year: ";
    cin >> nuevoVehiculo.year;
    cout << " Kilometraje: ";
    cin >> nuevoVehiculo.kilometraje;
    cout << " Rentado (Si = 1, No = 0): ";
    cin >> nuevoVehiculo.rentado;
    cout << " Motor: ";
    cin >> nuevoVehiculo.motor;
    cout << " Precio de renta: ";
    cin >> nuevoVehiculo.precio_renta;
    cout << " Cedula del cliente: ";
    cin >> nuevoVehiculo.ced_cliente;
    cout << " Fecha de entrega (dd/mm/aaaa): ";
    cin >> nuevoVehiculo.fecha_de_entrega;

    char confirmar;
    cout << "Desea confirmar los cambios realizados? (Y/N): ";
    cin >> confirmar;
    if (Actualizar_Vehiculo(nuevoVehiculo, confirmar)) {
        cout << "El Vehiculo ha sido actualizado correctamente." << endl;
    } else {
        cout << "El cambio ha sido descartado o el Vehiculo con Placa " << nuevoVehiculo.placa << " no existe en los registros." << endl;
    }
}

void Actualizar_Cliente_View() {
    Cliente nuevoCliente;
    cout << endl << "Ingrese la Cedula del Cliente que desea actualizar: ";
    cin >> nuevoCliente.cedula;

    cout << "Introduzca los nuevos datos del cliente: " << endl;
    cout << " Nombre: ";
    cin >> nuevoCliente.nombre;
    cout << " Apellido: ";
    cin >> nuevoCliente.apellido;
    cout << " Correo: ";
    cin >> nuevoCliente.email;
    cout << " Vehiculos rentados: ";
    cin >> nuevoCliente.cantidad_vehiculos_rentados;
    cout << " Direccion: ";
    cin.ignore();
    getline(cin, nuevoCliente.direccion);
    cout << " Activo (Si = 1, No = 0): ";
    cin >> nuevoCliente.activo;

    char confirmar;
    cout << "Desea confirmar los cambios realizados? (Y/N): ";
    cin >> confirmar;
    if (Actualizar_Cliente(nuevoCliente, confirmar)) {
        cout << "El Cliente ha sido actualizado correctamente." << endl;
    } else {
        cout << "El cambio ha sido descartado o el Cliente con Cedula " << nuevoCliente.cedula << " no existe en los registros." << endl;
    }
}

void Actualizar_Repuesto_View() {
    Repuestos nuevoRepuesto;
    cout << endl << "Ingrese el Modelo del Repuesto que desea actualizar: ";
    cin >> nuevoRepuesto.modelo;

    cout << "Introduzca los nuevos datos del repuesto: " << endl;
    cout << " Marca: ";
    cin >> nuevoRepuesto.marca;
    cout << " Nombre: ";
    cin.ignore();
    getline(cin, nuevoRepuesto.nombre);
    cout << " Modelo del carro: ";
    cin >> nuevoRepuesto.modelo_carro;
    cout << " Year del carro: ";
    cin >> nuevoRepuesto.year_carro;
    cout << " Precio: ";
    cin >> nuevoRepuesto.precio;
    cout << " Existencias: ";
    cin >> nuevoRepuesto.existencias;

    char confirmar;
    cout << "Desea confirmar los cambios realizados? (Y/N): ";
    cin >> confirmar;
    if (Actualizar_Repuesto(nuevoRepuesto, confirmar)) {
        cout << "El Repuesto ha sido actualizado correctamente." << endl;
    } else {
        cout << "El cambio ha sido descartado o el Repuesto con Modelo " << nuevoRepuesto.modelo << " no existe en los registros." << endl;
    }
}

void Eliminar_Vehiculo_View() {
    string placa;
    cout << endl << "Ingrese la Placa del Vehiculo que desea eliminar: ";
    cin >> placa;

    char confirmar;
    cout << "Desea confirmar los cambios realizados? (Y/N): ";
    cin >> confirmar;
    if (Eliminar_Vehiculo(placa, confirmar)){
        cout << "El Vehiculo fue eliminado correctamente." << endl;
    }
    else{
        cout << "El cambio ha sido descartado o el Vehiculo con Placa " << placa << " no existe en los registros." << endl;
    }
}

void Eliminar_Cliente_View(){
    int cedula;
    cout << endl << "Ingrese la Cedula del Cliente que desea eliminar: ";
    cin >> cedula;

    char confirmar;
    cout << "Desea confirmar los cambios realizados? (Y/N): ";
    cin >> confirmar;
    if (Eliminar_Cliente(cedula, confirmar)) {
        cout << "El Cliente fue eliminado correctamente." << endl;
    } else {
        cout << "El cambio ha sido descartado o el Cliente con Cedula " << cedula << " no existe en los registros." << endl;
    }
}

void Eliminar_Repuesto_View() {
    int modelo;
    cout << endl << "Ingrese el Modelo del Repuesto que desea eliminar: ";
    cin >> modelo;

    char confirmar;
    cout << "Desea confirmar los cambios realizados? (Y/N): ";
    cin >> confirmar;
    if (Eliminar_Repuesto(modelo, confirmar)) {
        cout << "El Repuesto fue eliminado correctamente." << endl;
    } else {
        cout << "El cambio ha sido descartado o el Repuesto con Modelo " << modelo << " no existe en los registros." << endl;
    }
}

void Agregar_Vehiculo_View(){
    Vehiculos vehiculo;
    cout << endl << "Introduzca los datos del Vehiculo que desea agregar: " << endl;

    cout << " Modelo: ";
    cin >> vehiculo.modelo;
    cout << " Marca: ";
    cin >> vehiculo.marca;
    cout << " Placa: ";
    cin >> vehiculo.placa;
    cout << " Color: ";
    cin >> vehiculo.color;
    cout << " Año: ";
    cin >> vehiculo.year;
    cout << " Kilometraje: ";
    cin >> vehiculo.kilometraje;
    cout << " Rentado (Si = 1, No = 0): ";
    cin >> vehiculo.rentado;
    cout << " Motor: ";
    cin >> vehiculo.motor;
    cout << " Precio de renta: ";
    cin >> vehiculo.precio_renta;
    cout << " Cedula del cliente: ";
    cin >> vehiculo.ced_cliente;
    cout << " Fecha de entrega (dd/mm/aaaa): ";
    cin >> vehiculo.fecha_de_entrega;

    char confirmar;
    cout << "Desea confirmar los cambios realizados? (Y/N): ";
    cin >> confirmar;

    if (confirmar == 'y' || confirmar == 'Y'){
        if (Agregar_Vehiculo(vehiculo)){
            cout << "El Vehiculo " << vehiculo.modelo << " " << vehiculo.marca << " ha sido agregado exitosamente." << endl;
        }
    }
    else{
        cout << "El cambio ha sido descartado." << endl;
    }
}

void Agregar_Cliente_View() {
    Cliente cliente;
    cout << endl << "Introduzca los datos del Cliente que desea agregar: " << endl;

    cout << " Cedula: ";
    cin >> cliente.cedula;
    cout << " Nombre: ";
    cin >> cliente.nombre;
    cout << " Apellido: ";
    cin >> cliente.apellido;
    cout << " Correo: ";
    cin >> cliente.email;
    cout << " Vehiculos rentados: ";
    cin >> cliente.cantidad_vehiculos_rentados;
    cout << " Direccion: ";
    cin.ignore();
    getline(cin, cliente.direccion);
    cout << " Activo (Si = 1, No = 0): ";
    cin >> cliente.activo;

    char confirmar;
    cout << "Desea confirmar los cambios realizados? (Y/N): ";
    cin >> confirmar;

    if (confirmar == 'y' || confirmar == 'Y') {
        if (Agregar_Cliente(cliente)) {
            cout << "El Cliente " << cliente.nombre << " " << cliente.apellido << " ha sido agregado exitosamente." << endl;
        }
    } else {
        cout << "El cambio ha sido descartado." << endl;
    }
}

void Agregar_Repuesto_View() {
    Repuestos repuesto;
    cout << endl << "Introduzca los datos del Repuesto que desea agregar: " << endl;

    cout << " Modelo: ";
    cin >> repuesto.modelo;
    cout << " Marca: ";
    cin >> repuesto.marca;
    cout << " Nombre: ";
    cin.ignore();
    getline(cin, repuesto.nombre);
    cout << " Modelo del carro: ";
    cin >> repuesto.modelo_carro;
    cout << " Year del carro: ";
    cin >> repuesto.year_carro;
    cout << " Precio: ";
    cin >> repuesto.precio;
    cout << " Existencias: ";
    cin >> repuesto.existencias;

    char confirmar;
    cout << "Desea confirmar los cambios realizados? (Y/N): ";
    cin >> confirmar;

    if (confirmar == 'y' || confirmar == 'Y') {
        if (Agregar_Repuesto(repuesto)) {
            cout << "El Repuesto " << repuesto.modelo << " " << repuesto.marca << " ha sido agregado exitosamente." << endl;
        }
    } else {
        cout << "El cambio ha sido descartado." << endl;
    }
}

void Backup(){
    if (CrearBackup()){
        cout << "Copia de seguridad completada." << endl;
    }
    else{
        cout << "No se pudo completar la copia de seguridad." << endl;
    }
}