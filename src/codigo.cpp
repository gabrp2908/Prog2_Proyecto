#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const int MAX_VEHICULOS = 10000;
const int MAX_CLIENTES = 10000;
const int MAX_REPUESTOS = 10000;

struct Vehiculos{
    string modelo, marca, placa, color, motor, fecha_de_entrega;
    int year, kilometraje, ced_cliente;
    float precio_renta;
    bool rentado;
}vehiculo;

struct Cliente{
    string nombre, apellido, email, direccion;
    int cedula, cantidad_vehiculos_rentados;
    bool activo;
}cliente;

struct Repuestos{
    string marca, nombre, modelo_carro;
    int modelo, year_carro, existencias;
    float precio;
}repuesto;

// Arreglos estáticos y contadores
Vehiculos vehiculos[MAX_VEHICULOS];
Cliente clientes[MAX_CLIENTES];
Repuestos repuestos[MAX_REPUESTOS];
int numVehiculos = 0, numClientes = 0, numRepuestos = 0;

//Funciones de Menu
void MenuPrincipal();
void MenuConsultar();
void MenuActualizar();
void MenuBorrar();
void MenuAgregar();

//Funciones de Lectura
void Lectura_Cliente();
void Lectura_Vehiculo();
void Lectura_Repuesto();

//Funciones de QuickSort para cada estructura
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

//Funciones de Insercion
void Agregar_Cliente();
void Agregar_Vehiculo();
void Agregar_Repuesto();

//Funciones de Borrado
void Eliminar_Cliente();
void Eliminar_Vehiculo();
void Eliminar_Repuesto();

//Funciones de Actulizacion
void Actualizar_Cliente();
void Actualizar_Vehiculo();
void Actualizar_Repuesto();

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
            MenuConsultar(); break;
        case 2:
            MenuActualizar(); break;
        case 3:
            MenuBorrar(); break;
        case 4:
            MenuAgregar(); break;
        case 5:
            cout << "Saliendo del programa . . ." << endl; break;
        default:
            cout << "Opcion invalida" << endl << endl;
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
            Consulta_Vehiculo(); break;
        case 2:
            Consulta_Cliente(); break;
        case 3:
            Consulta_Repuesto(); break;
        case 4: //Retorno a Menu Principal
            return; break;
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
        case 1: Actualizar_Vehiculo(); break;
        case 2: Actualizar_Cliente(); break;
        case 3: Actualizar_Repuesto(); break;
        case 4: //Retorno a Menu Principal
            return; break;
        default:
            cout << "Opcion Invalida" << endl << endl;
        }
     } while (opcion_actualizar!=4);
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
            Eliminar_Vehiculo(); break;
        case 2: 
            Eliminar_Cliente(); break;
        case 3: 
            Eliminar_Repuesto();
            break;
        case 4: //Retorno a Menu Principal
            return; break;
        default:
            cout << "Opcion Invalida" << endl << endl;
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
            Agregar_Vehiculo(); break;
        case 2:
            Agregar_Cliente(); break;
        case 3:
            Agregar_Repuesto();
            break;
        case 4: //Retorno a Menu Principal
            return; break;
        default:
            cout << "Opcion Invalida" << endl;
        }
    } while (opcion_agregar != 4);
}

//Implementacion de QuickSort para Vehiculos
void QuickSortVehiculos(int left, int right) {
    if (left < right) {
        int pivotIndex = PartitionVehiculos(left, right);
        QuickSortVehiculos(left, pivotIndex - 1);
        QuickSortVehiculos(pivotIndex + 1, right);
    }
}

int PartitionVehiculos(int left, int right) {
    int pivot = vehiculos[right].ced_cliente;
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (vehiculos[j].ced_cliente < pivot) {
            i++;
            swap(vehiculos[i], vehiculos[j]);
        }
    }
    swap(vehiculos[i + 1], vehiculos[right]);
    return i + 1;
}

// Implementacion de QuickSort para Clientes
void QuickSortClientes(int left, int right) {
    if (left < right) {
        int pivotIndex = PartitionClientes(left, right);
        QuickSortClientes(left, pivotIndex - 1);
        QuickSortClientes(pivotIndex + 1, right);
    }
}

int PartitionClientes(int left, int right) {
    int pivot = clientes[right].cedula;
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (clientes[j].cedula < pivot) {
            i++;
            swap(clientes[i], clientes[j]);
        }
    }
    swap(clientes[i + 1], clientes[right]);
    return i + 1;
}

// Implementacion de QuickSort para Repuestos
void QuickSortRepuestos(int left, int right) {
    if (left < right) {
        int pivotIndex = PartitionRepuestos(left, right);
        QuickSortRepuestos(left, pivotIndex - 1);
        QuickSortRepuestos(pivotIndex + 1, right);
    }
}

int PartitionRepuestos(int left, int right) {
    int pivot = repuestos[right].modelo;
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (repuestos[j].modelo < pivot) {
            i++;
            swap(repuestos[i], repuestos[j]);
        }
    }
    swap(repuestos[i + 1], repuestos[right]);
    return i + 1;
}

//Lectura de archivos
void Lectura_Cliente() {
    ifstream lectura_cliente("DATOS_CLIENTES.csv", ios::in);
    string line;

    while (getline(lectura_cliente, line) && numClientes < MAX_CLIENTES){
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

        clientes[numClientes++] = cliente;
    }
    lectura_cliente.close();

    QuickSortClientes(0, numClientes - 1);
}

void Lectura_Vehiculo() {
    ifstream lectura_vehiculo("DATOS_VEHICULOS.csv");
    string line;

    while (getline(lectura_vehiculo, line) && numVehiculos < MAX_VEHICULOS){
        istringstream ss(line);

        getline(ss, vehiculo.modelo, ',');
        getline(ss, vehiculo.marca, ',');
        getline(ss, vehiculo.placa, ',');
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

        vehiculos[numVehiculos++] = vehiculo;
    }
    lectura_vehiculo.close();

    QuickSortVehiculos(0, numVehiculos - 1);
}

void Lectura_Repuesto() {
    ifstream lectura_repuesto("DATOS_REPUESTOS.csv", ios::in);
    string line;

    while (getline(lectura_repuesto, line) && numRepuestos < MAX_REPUESTOS){
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

        repuestos[numRepuestos++] = repuesto;
    }
    lectura_repuesto.close();

    QuickSortRepuestos(0, numRepuestos - 1);
}

//Consulta de cliente segun su cedula
void Consulta_Cliente() {
    int cedula, cedula_actual;
    cout << endl << "Ingrese la cedula del cliente que desea consultar: "; cin >> cedula;
    bool encontrado = false;

    ifstream lectura_cliente("DATOS_CLIENTES.csv", ios::in);
    string line;

    while (getline(lectura_cliente, line) && numClientes < MAX_CLIENTES){
        istringstream ss(line);

        ss >> cliente.cedula;
        ss.ignore();
        cedula_actual = cliente.cedula;
        getline(ss, cliente.nombre, ',');
        getline(ss, cliente.apellido, ',');
        getline(ss, cliente.email, ',');
        ss >> cliente.cantidad_vehiculos_rentados;
        ss.ignore();
        getline(ss, cliente.direccion, ',');
        ss >> cliente.activo;
        
        if (cedula_actual == cedula) {
		encontrado = true;
            cout << " Cedula: " << cliente.cedula << endl;
            cout << " Nombre: " << cliente.nombre << endl;
            cout << " Apellido: " << cliente.apellido << endl;
            cout << " Correo: " << cliente.email << endl;
            cout << " Vehiculos rentados: " << cliente.cantidad_vehiculos_rentados << endl;
            cout << " Direccion: " << cliente.direccion << endl;
            cout << " Activo: " << (cliente.activo ? "Si" : "No") << endl;
        }
    }
    lectura_cliente.close();
    if (!encontrado) {
        cout << endl << "La Cedula " << cedula << " no ha sido encontrada en los registros." << endl;
    }
}

//Consulta de vehiculo segun su placa
void Consulta_Vehiculo() {
    ifstream lectura_vehiculo("DATOS_VEHICULOS.csv");
	string line, vehiculo_buscar, vehiculo_actual;
	bool existe = false;
	cout << endl << "Ingrese la placa del vehiculo que desea consultar: "; cin >> vehiculo_buscar;
	while (getline(lectura_vehiculo, line)) {
		istringstream ss(line);
		
        getline(ss, vehiculo.modelo, ',');
        getline(ss, vehiculo.marca, ',');
        getline(ss, vehiculo.placa, ',');
        vehiculo_actual = vehiculo.placa;
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

		if (vehiculo_actual.compare(vehiculo_buscar) == 0) {
			existe = true;
			cout << " Modelo:" << vehiculo.modelo << endl;
			cout << " Marca: " << vehiculo.marca << endl;
			cout << " Placa: " << vehiculo.placa << endl;
			cout << " Color: " << vehiculo.color << endl;
            cout << " Year: " << vehiculo.year << endl;
            cout << " Kilometraje: " << vehiculo.kilometraje << " Km" << endl;
            cout << " Rentado: " << (vehiculo.rentado? "Si" : "No")<< endl;
            cout << " Motor: " << vehiculo.motor << endl;
            cout << " Precio de renta: " << vehiculo.precio_renta << " $/hr" << endl;
            if (vehiculo.rentado == 0) {
            cout << " Cedula del cliente: N/A" << endl;
            cout << " Fecha de entrega: N/A" << endl;
            }
		}
	}
	lectura_vehiculo.close();
	if (!existe) {
		cout << endl << "La Placa " << vehiculo_buscar << " no ha sido encontrada en los registros.";
	}
}

//Consulta de repuesto segun el modelo
void Consulta_Repuesto() {
    int modelo, modelo_actual;
	
    cout << endl << "Ingrese el modelo del repuesto que desea consultar: "; cin >> modelo;
    ifstream lectura_repuesto("DATOS_REPUESTOS.csv", ios::in);
    string line;
    bool encontrado = false;

    while (getline(lectura_repuesto, line) && numRepuestos < MAX_REPUESTOS){
        istringstream ss(line);

        ss >> repuesto.modelo;
        ss.ignore();
        modelo_actual = repuesto.modelo;
        getline(ss, repuesto.marca, ',');
        getline(ss, repuesto.nombre, ',');
        getline(ss, repuesto.modelo_carro, ',');
        ss >> repuesto.year_carro;
        ss.ignore();
        ss >> repuesto.precio;
        ss.ignore();
        ss >> repuesto.existencias;

        if (modelo_actual == modelo) {
		    encontrado = true;
			cout << " Modelo: " << repuesto.modelo << endl;
			cout << " Marca: " << repuesto.marca << endl;
			cout << " Nombre: " << repuesto.nombre << endl;
			cout << " Modelo del carro: " << repuesto.modelo_carro << endl;
            cout << " Year Carro: " << repuesto.year_carro << endl;
            cout << " Precio: " << repuesto.precio << " $" << endl;
            cout << " Existencias: " << repuesto.existencias << endl;
            break;
        }
    }
    lectura_repuesto.close();
    if (!encontrado) {
        cout << endl << "El Modelo " << modelo << " no ha sido encontrado en los registros." << endl;
    }
}

//Implementacion de funciones de insercion
void Agregar_Cliente(){
    Lectura_Cliente();
    cout << endl << "Introduzca los datos del Cliente que desea agregar: " << endl;

    cout << endl << " Cedula: ";
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
    cout << " Activo (Si = 1, No = 0): "; cin >> cliente.activo;

    clientes[numClientes++] = cliente;

    char confirmar;
    cout << "Desea confirmar los cambios realizados? (Y/N): ";
    cin >> confirmar;

    if (confirmar == 'y' || confirmar == 'Y'){
        ofstream escritura_cliente("DATOS_CLIENTES.csv", ios::app);

        escritura_cliente << cliente.cedula << ',' << cliente.nombre << ',' << cliente.apellido << ',' << cliente.email
                          << ',' << cliente.cantidad_vehiculos_rentados << ',' << cliente.direccion << ',' << cliente.activo << endl;

        cout << "El Cliente " << cliente.nombre << " " << cliente.apellido << " ha sido agregado exitosamente." << endl;
        escritura_cliente.close();
    }
    else{
        cout << "El cambio ha sido descartado. " << endl;
    }
}

void Agregar_Vehiculo(){
    cout << endl << "Introduzca los datos del vehiculo que desea agregar: " << endl;

    cout << endl << " Modelo: "; cin >> vehiculo.modelo;
    cout << " Marca: "; cin >> vehiculo.marca;
    cout << " Placa: "; cin >> vehiculo.placa;
    cout << " Color: "; cin >> vehiculo.color;
    cout << " Year: "; cin >> vehiculo.year;
    cout << " Kilometraje: "; cin >> vehiculo.kilometraje;
    cout << " Rentado (Si = 1, No = 0): "; cin >> vehiculo.rentado;
    cout << " Motor: "; cin >> vehiculo.motor;
    cout << " Precio de renta: "; cin >> vehiculo.precio_renta;
    cout << " Cedula del cliente: "; cin >> vehiculo.ced_cliente;
    cout << " Fecha de entrega (dd/mm/aaaa): "; cin >> vehiculo.fecha_de_entrega;

    vehiculos[numVehiculos++] = vehiculo;

    char confirmar;
    cout << "Desea confirmar los cambios realizados? (Y/N): ";
    cin >> confirmar;

    if (confirmar == 'y' || confirmar == 'Y'){
        ofstream escritura_vehiculo("DATOS_VEHICULOS.csv", ios::app);

        escritura_vehiculo << vehiculo.modelo << ',' << vehiculo.marca << ',' << vehiculo.placa << ',' << vehiculo.color
                           << ',' << vehiculo.year << ',' << vehiculo.kilometraje << ',' << vehiculo.rentado << ',' << vehiculo.motor
                           << ',' << vehiculo.precio_renta << ',' << vehiculo.ced_cliente << ',' << vehiculo.fecha_de_entrega << endl;

        cout << "El Vehiculo " << vehiculo.modelo << " " << vehiculo.marca << " ha sido agregado exitosamente." << endl;
        escritura_vehiculo.close();
    }
    else{
        cout << "El cambio ha sido descartado. " << endl;
    }
}

void Agregar_Repuesto(){
    Lectura_Repuesto();
    cout << endl << "Introduzca los datos del Repuesto que desea agregar: " << endl;

    cout << endl << " Modelo: "; cin >> repuesto.modelo;
    cout << " Marca: "; cin >> repuesto.marca;
    cout << " Nombre: ";
    cin.ignore();
    getline(cin, repuesto.nombre);
    cout << " Modelo del carro: "; cin >> repuesto.modelo_carro;
    cout << " Year Carro: "; cin >> repuesto.year_carro;
    cout << " Precio: "; cin >> repuesto.precio;
    cout << " Existencias: "; cin >> repuesto.existencias;

    repuestos[numRepuestos++] = repuesto;

    char confirmar;
    cout << "Desea confirmar los cambios realizados? (Y/N): ";
    cin >> confirmar;

    if (confirmar == 'y' || confirmar == 'Y'){
        ofstream escritura_repuesto("DATOS_REPUESTOS.csv", ios::app);

        escritura_repuesto << repuesto.modelo << ',' << repuesto.marca << ',' << repuesto.nombre << ',' << repuesto.modelo_carro
                           << ',' << repuesto.year_carro << ',' << repuesto.precio << ',' << repuesto.existencias << endl;

        cout << "El Repuesto " << repuesto.modelo << " " << repuesto.marca << " ha sido agregado exitosamente." << endl;
        escritura_repuesto.close();
    }
    else{
        cout << "El cambio ha sido descartado. " << endl;
    }
}

//Implementacion de funciones de borrado
void Eliminar_Cliente() {
    Lectura_Cliente();
    int cedula;
    cout << endl << "Ingrese la Cedula del Cliente que desea eliminar: "; cin >> cedula;

    int mid, left = 0, right = numClientes - 1;
    bool encontrado = false;

    while (left <= right){
        mid = left + (right - left) / 2;

        if (clientes[mid].cedula == cedula){
            encontrado = true;
            break;
        }
        if (clientes[mid].cedula < cedula){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    if (cedula == clientes[mid].cedula){
        for (int i = 0; i < numClientes; i++){
            clientes[i] = clientes[i + 1];
        }
        numClientes--;
    }

    if (encontrado) {
        char confirmar;
        cout << "Desea confirmar los cambios realizados? (Y/N): "; cin >> confirmar;

        if (confirmar == 'y' || confirmar == 'Y') {
            ifstream lectura_cliente("DATOS_CLIENTES.csv");
            ofstream escritura_cliente_Temp("DATOS_CLIENTES_TEMP.csv");
            string line;
            int cedula_actual;

            while (getline(lectura_cliente, line)) {
                istringstream ss(line);

                ss >> cliente.cedula;
                ss.ignore();
                cedula_actual = cliente.cedula;
                getline(ss, cliente.nombre, ',');
                getline(ss, cliente.apellido, ',');
                getline(ss, cliente.email, ',');
                ss >> cliente.cantidad_vehiculos_rentados;
                ss.ignore();
                getline(ss, cliente.direccion, ',');
                ss >> cliente.activo;

                if(cedula != cedula_actual) {
                    escritura_cliente_Temp << cliente.cedula << ',' << cliente.nombre << ',' << cliente.apellido << ',' << cliente.email 
                    << ',' << cliente.cantidad_vehiculos_rentados << ',' << cliente.direccion << ',' << cliente.activo << endl;
                    continue;
                }
            }
            lectura_cliente.close();
            escritura_cliente_Temp.close();

            remove("DATOS_CLIENTES.csv");
            rename("DATOS_CLIENTES_TEMP.csv", "DATOS_CLIENTES.csv");
            cout << "El Cliente fue eliminado correctamente." << endl;
	    } else{
		cout << "El cambio ha sido descartado. " << endl;
	    } 
	} else {
		cout << "El Cliente con Cedula " << cedula << " no existe en los registros." << endl;
	}
}

void Eliminar_Vehiculo() {
    string placa;
    cout << endl << "Ingrese la Placa del Vehiculo que desea eliminar: "; cin >> placa;

    ifstream lectura_vehiculo("DATOS_VEHICULOS.csv");
    ofstream escritura_vehiculo_Temp("DATOS_VEHICULOS_TEMP.csv");
    bool encontrado = false;
    string line, placa_actual;

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

        if (placa.compare(placa_actual) == 0) encontrado = true; 
        else {
            escritura_vehiculo_Temp << vehiculo.modelo << ',' << vehiculo.marca << ',' << vehiculo.placa << ',' << vehiculo.color 
            << ',' << vehiculo.year << ',' << vehiculo.kilometraje << ',' << vehiculo.rentado << ',' << vehiculo.motor 
            << ',' << vehiculo.precio_renta << ',' << vehiculo.ced_cliente << ',' << vehiculo.fecha_de_entrega << endl;
            }
    }
    lectura_vehiculo.close();
    escritura_vehiculo_Temp.close();

    if (encontrado) {
        char confirmar;
        cout << "Desea confirmar los cambios realizados? (Y/N): "; cin >> confirmar;

        if (confirmar == 'y' || confirmar == 'Y') {
            remove("DATOS_VEHICULOS.csv");
            rename("DATOS_VEHICULOS_TEMP.csv", "DATOS_VEHICULOS.csv");
            cout << "El Vehiculo fue eliminado correctamente." << endl;           
        } else{
            remove("DATOS_VEHICULOS_TEMP.csv");
		    cout << "El cambio ha sido descartado. " << endl;
	    } 
	} else {
		cout << "El Vehiculo de placa " << placa << " no existe en los registros." << endl;
        remove("DATOS_VEHICULOS_TEMP.csv");
	}
}

void Eliminar_Repuesto() {
    Lectura_Repuesto();
    int modelo;
    cout << endl << "Ingrese el Modelo del Repuesto que desea eliminar: "; cin >> modelo;

    int mid, left = 0, right = numRepuestos - 1;
    bool encontrado = false;

    while (left <= right){
        mid = left + (right - left) / 2;

        if (repuestos[mid].modelo == modelo){
            encontrado = true;
            break;
        }
        if (repuestos[mid].modelo < modelo){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    if (modelo == repuestos[mid].modelo){
        for (int i = 0; i < numRepuestos; i++)
        {
            repuestos[i] = repuestos[i + 1];
        }
        numRepuestos--;
    }

    if (encontrado) {
        char confirmar;
        cout << "Desea confirmar los cambios realizados? (Y/N): "; cin >> confirmar;

        if (confirmar == 'y' || confirmar == 'Y') {
            ifstream lectura_repuesto("DATOS_REPUESTOS.csv");
            ofstream escritura_repuesto_Temp("DATOS_REPUESTOS_TEMP.csv");
            string line;
            int modelo_actual;

            while (getline(lectura_repuesto, line)) {
                istringstream ss(line);

                ss >> repuesto.modelo;
                ss.ignore();
                modelo_actual = repuesto.modelo;
                getline(ss, repuesto.marca, ',');
                getline(ss, repuesto.nombre, ',');
                getline(ss, repuesto.modelo_carro, ',');
                ss >> repuesto.year_carro;
                ss.ignore();
                ss >> repuesto.precio;
                ss.ignore();
                ss >> repuesto.existencias;

                if(modelo != modelo_actual ) {
                    escritura_repuesto_Temp << repuesto.modelo << ',' << repuesto.marca << ',' << repuesto.nombre << ',' << repuesto.modelo_carro
                    << ',' << repuesto.year_carro << ',' << repuesto.precio << ',' << repuesto.existencias << endl;
                    continue;
                }
            }
            lectura_repuesto.close();
            escritura_repuesto_Temp.close();

            remove("DATOS_REPUESTOS.csv");
            rename("DATOS_REPUESTOS_TEMP.csv", "DATOS_REPUESTOS.csv");
            cout << "El Repuesto fue eliminado correctamente." << endl;
	    } else{
		cout << "El cambio ha sido descartado." << endl;
	    } 
	} else {
		cout << "El Repuesto de modelo " << modelo << " no existe en los registros." << endl;
	}
}

//Implementacion de funciones de actualizacion
void Actualizar_Cliente(){
    Lectura_Cliente();
    int cedula;
    cout << endl << "Ingrese la Cedula del Cliente que desea actualizar: "; cin >> cedula;

    int mid, left = 0, right = numClientes - 1;
    bool encontrado = false;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (clientes[mid].cedula == cedula) {
            encontrado = true;
            break;
        }
        if (clientes[mid].cedula < cedula) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (encontrado) {
        ifstream lectura_cliente("DATOS_CLIENTES.csv");
        ofstream escritura_cliente_Temp("DATOS_CLIENTES_TEMP.csv");
        string line;
        int cedula_actual;

        while (getline(lectura_cliente, line)) {
            istringstream ss(line);

            ss >> cliente.cedula;
            ss.ignore();
            cedula_actual = cliente.cedula;
            getline(ss, cliente.nombre, ',');
            getline(ss, cliente.apellido, ',');
            getline(ss, cliente.email, ',');
            ss >> cliente.cantidad_vehiculos_rentados;
            ss.ignore();
            getline(ss, cliente.direccion, ',');
            ss >> cliente.activo;

            if(cedula != cedula_actual) {
                escritura_cliente_Temp << cliente.cedula << ',' << cliente.nombre << ',' << cliente.apellido << ',' << cliente.email 
                << ',' << cliente.cantidad_vehiculos_rentados << ',' << cliente.direccion << ',' << cliente.activo << endl;
            } else {
            cout << endl << "Introduzca los datos del nuevo Cliente: " << endl; 

            cout << endl << " Cedula: "; cin >> cliente.cedula;
            cout << " Nombre: "; cin >> cliente.nombre;
            cout << " Apellido: "; cin >> cliente.apellido;
            cout << " Correo: "; cin >> cliente.email;
            cout << " Vehiculos rentados: "; cin >> cliente.cantidad_vehiculos_rentados;
            cout << " Direccion: "; 
            cin.ignore();
            getline(cin, cliente.direccion);
            cout << " Activo (Si = 1, No = 0): "; cin >> cliente.activo;
            
            clientes[mid].cedula = cliente.cedula;
            clientes[mid].nombre = cliente.nombre;
            clientes[mid].apellido = cliente.apellido;
            clientes[mid].email = cliente.email;
            clientes[mid].cantidad_vehiculos_rentados = cliente.cantidad_vehiculos_rentados;
            clientes[mid].direccion = cliente.direccion;
            clientes[mid].activo = cliente.activo;
            
            escritura_cliente_Temp << cliente.cedula << ',' << cliente.nombre << ',' << cliente.apellido << ',' << cliente.email 
            << ',' << cliente.cantidad_vehiculos_rentados << ',' << cliente.direccion << ',' << cliente.activo << endl;
            }
        }
        lectura_cliente.close();
        escritura_cliente_Temp.close();

        char confirmar;
        cout << "Desea confirmar los cambios realizados? (Y/N): "; cin >> confirmar;

        if (confirmar == 'y' || confirmar == 'Y') {
            remove("DATOS_CLIENTES.csv");
            rename("DATOS_CLIENTES_TEMP.csv", "DATOS_CLIENTES.csv");
            cout << "El Cliente ha sido actualizado correctamente." << endl;
	    } else {
		cout << "La actualizacion ha sido descartada. " << endl;
        remove("DATOS_CLIENTES_TEMP.csv");
	    } 
	} else {
		cout << "El Cliente con Cedula " << cedula << " no existe en los registros." << endl;
	}
}

void Actualizar_Vehiculo() {
    string placa;
    cout << endl << "Ingrese la Placa del Vehiculo que desea actualizar: "; cin >> placa;

    ifstream lectura_vehiculo("DATOS_VEHICULOS.csv");
    ofstream escritura_vehiculo_Temp("DATOS_VEHICULOS_TEMP.csv");
    bool encontrado = false;
    string line, placa_actual;

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

        if (placa.compare(placa_actual) == 0) {
            encontrado = true;
            cout << endl << "Introduzca los datos del nuevo vehiculo: " << endl; 
    	    
            cout << endl << " Modelo: "; cin >> vehiculo.modelo;
	        cout << " Marca: "; cin >> vehiculo.marca;
	        cout << " Placa: "; cin >> vehiculo.placa;
	        cout << " Color: "; cin >> vehiculo.color;
            cout << " Year: "; cin >> vehiculo.year;
            cout << " Kilometraje: "; cin >> vehiculo.kilometraje;
            cout << " Rentado (Si = 1, No = 0):: "; cin >> vehiculo.rentado;
            cout << " Motor: "; cin >> vehiculo.motor;
            cout << " Precio de renta: "; cin >> vehiculo.precio_renta;
            cout << " Cedula del cliente: "; cin >> vehiculo.ced_cliente;
            cout << " Fecha de entrega (dd/mm/aaaa): "; cin >> vehiculo.fecha_de_entrega;

            escritura_vehiculo_Temp << vehiculo.modelo << ',' << vehiculo.marca << ',' << vehiculo.placa << ',' << vehiculo.color 
            << ',' << vehiculo.year << ',' << vehiculo.kilometraje << ',' << vehiculo.rentado << ',' << vehiculo.motor 
            << ',' << vehiculo.precio_renta << ',' << vehiculo.ced_cliente << ',' << vehiculo.fecha_de_entrega << endl;
        
        } else {
            escritura_vehiculo_Temp << vehiculo.modelo << ',' << vehiculo.marca << ',' << vehiculo.placa << ',' << vehiculo.color 
            << ',' << vehiculo.year << ',' << vehiculo.kilometraje << ',' << vehiculo.rentado << ',' << vehiculo.motor 
            << ',' << vehiculo.precio_renta << ',' << vehiculo.ced_cliente << ',' << vehiculo.fecha_de_entrega << endl;
        }
    }
    lectura_vehiculo.close();
    escritura_vehiculo_Temp.close();

    if (encontrado) {
        char confirmar;
        cout << "Desea confirmar los cambios realizados? (Y/N): "; cin >> confirmar;

        if (confirmar == 'y' || confirmar == 'Y') {
            remove("DATOS_VEHICULOS.csv");
            rename("DATOS_VEHICULOS_TEMP.csv", "DATOS_VEHICULOS.csv");
            cout << "El Vehiculo ha sido actualizado correctamente." << endl;           
        } else{
            remove("DATOS_VEHICULOS_TEMP.csv");
		    cout << "La actualizacion ha sido descartada. " << endl;
	    } 
	} else {
		cout << "El Vehiculo de placa " << placa << " no existe en los registros." << endl;
        remove("DATOS_VEHICULOS_TEMP.csv");
	}
}

void Actualizar_Repuesto(){
    Lectura_Repuesto();
    int modelo;
    cout << endl << "Ingrese el Modelo del Repuesto que desea actualizar: "; cin >> modelo;

    int mid, left = 0, right = numRepuestos - 1;
    bool encontrado = false;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (repuestos[mid].modelo == modelo) {
            encontrado = true;
            break;
        }
        if (repuestos[mid].modelo < modelo) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (encontrado) {
        ifstream lectura_repuesto("DATOS_REPUESTOS.csv");
        ofstream escritura_repuesto_Temp("DATOS_REPUESTOS_TEMP.csv");
        string line;
        int modelo_actual;

        while (getline(lectura_repuesto, line)) {
            istringstream ss(line);

            ss >> repuesto.modelo;
            ss.ignore();
            modelo_actual = repuesto.modelo;
            getline(ss, repuesto.marca, ',');
            getline(ss, repuesto.nombre, ',');
            getline(ss, repuesto.modelo_carro, ',');
            ss >> repuesto.year_carro;
            ss.ignore();
            ss >> repuesto.precio;
            ss.ignore();
            ss >> repuesto.existencias;

            if(modelo != modelo_actual ) {
                escritura_repuesto_Temp << repuesto.modelo << ',' << repuesto.marca << ',' << repuesto.nombre << ',' << repuesto.modelo_carro
                << ',' << repuesto.year_carro << ',' << repuesto.precio << ',' << repuesto.existencias << endl;
            } else {
                cout << endl << "Introduzca los datos del Repuesto que desea agregar: " << endl; 
    	    
	            cout << endl << " Modelo: "; cin >> repuesto.modelo;
	            cout << " Marca: "; cin >> repuesto.marca;
	            cout << " Nombre: ";
                cin.ignore();
                getline(cin, repuesto.nombre);
	            cout << " Modelo del carro: "; cin >> repuesto.modelo_carro;
                cout << " Year Carro: "; cin >> repuesto.year_carro;
                cout << " Precio: "; cin >> repuesto.precio;
                cout << " Existencias: "; cin >> repuesto.existencias;

                repuestos[mid].modelo = repuesto.modelo;
                repuestos[mid].marca = repuesto.marca;
                repuestos[mid].nombre = repuesto.nombre;
                repuestos[mid].modelo_carro = repuesto.modelo_carro;
                repuestos[mid].year_carro = repuesto.year_carro;
                repuestos[mid].precio = repuesto.precio;
                repuestos[mid].existencias = repuesto.existencias;

                escritura_repuesto_Temp << repuesto.modelo << ',' << repuesto.marca << ',' << repuesto.nombre << ',' << repuesto.modelo_carro
                << ',' << repuesto.year_carro << ',' << repuesto.precio << ',' << repuesto.existencias << endl;
            }
        }
        lectura_repuesto.close();
        escritura_repuesto_Temp.close();

        char confirmar;
        cout << "Desea confirmar los cambios realizados? (Y/N): "; cin >> confirmar;
        if (confirmar == 'y' || confirmar == 'Y') {
            remove("DATOS_REPUESTOS.csv");
            rename("DATOS_REPUESTOS_TEMP.csv", "DATOS_REPUESTOS.csv");
            cout << "El Repuesto fue eliminado correctamente." << endl;
	    } else {
		cout << "El cambio ha sido descartado." << endl;
        remove("DATOS_REPUESTOS_TEMP.csv");
	    } 
	} else {
		cout << "El Repuesto de modelo " << modelo << " no existe en los registros." << endl;
	}
}

int main() {
    Lectura_Vehiculo();
    MenuPrincipal();
    return 0;
}
