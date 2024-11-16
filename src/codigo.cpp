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

void MenuPrincipal();
void MenuConsultar();
void MenuActualizar();
void MenuBorrar();
void MenuAgregar();

void Lectura_Cliente();
void Lectura_Vehiculo();
void Lectura_Repuesto();

void Consulta_Cliente();
void Consulta_Vehiculo_x_placa(); 
void Consulta_Vehiculo_x_cedula();
void Consulta_Repuesto(); 

void QuickSortVehiculos(int left, int right);
void QuickSortClientes(int left, int right);
void QuickSortRepuestos(int left, int right);

int PartitionVehiculos(int left, int right);
int PartitionClientes(int left, int right);
int PartitionRepuestos(int left, int right);

void MenuPrincipal(){
    int opcion;
    do{
        cout << "MENU PRINCIPAL" << endl;
        cout << "1. Consultar" << endl;
        cout << "2. Actualizar" << endl;
        cout << "3. Borrar" << endl;
        cout << "4. Agregar" << endl;
        cout << "5. Salir del programa" << endl;
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
        cout << "MENU DE CONSULTA DE REGISTROS" << endl;
        cout << "Indique el tipo de consulta que desea realizar:" << endl;
        cout << "1. Vehiculo por placa" << endl;
        cout << "2. Vehiculo por cedula de cliente" << endl;
        cout << "3. Cliente" << endl;
        cout << "4. Repuesto" << endl;
        cout << "5. Regresar al Menu Principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion_consulta;

        switch (opcion_consulta){
        case 1: //Registro Vehiculo
            Consulta_Vehiculo_x_placa();
            break;
        case 2: //Registro Cliente
            Consulta_Vehiculo_x_cedula();
            break;
        case 3: //Registro Repuesto
            Consulta_Cliente();
            break;
        case 4:
            Consulta_Repuesto();
            break;
        case 5: //Menu Principal
            MenuPrincipal();
            break;
        default:
            cout << "Opcion Invalida" << endl;
        }
    } while (opcion_consulta != 5);
}

void MenuActualizar(){
    int opcion_actualizar;
    do{
        cout << "MENU DE ACTUALIZACION DE REGISTROS" << endl;
        cout << "Indique el tipo de registro que desea actualizar:" << endl;
        cout << "1. Vehiculo " << endl;
        cout << "2. Cliente" << endl;
        cout << "3. Repuesto" << endl;
        cout << "4. Regresar al Menu Principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion_actualizar;

        switch (opcion_actualizar){
        case 1: //Registro Vehiculo
            break;
        case 2: //Registro Cliente
            break;
        case 3: //Registro Repuesto
            break;
        case 4: //Menu
            MenuPrincipal();
            break;
        default:
            cout << "Opcion Invalida" << endl;
        }
     } while (opcion_actualizar!=4);
}

void MenuBorrar(){
    int opcion_actualizar;
    do{
        cout << "MENU DE ELIMINACION DE REGISTROS" << endl;
        cout << "Indique el tipo de registro que desea eliminar:" << endl;
        cout << "1. Vehiculo " << endl;
        cout << "2. Cliente" << endl;
        cout << "3. Repuesto" << endl;
        cout << "4. Regresar al Menu Principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion_actualizar;

        switch (opcion_actualizar){
        case 1: //Registro Vehiculo
            break;
        case 2: //Registro Cliente
            break;
        case 3: //Registro Repuesto
            break;
        case 4: //Menu Principal
            MenuPrincipal();
            break;
        default:
            cout << "Opcion Invalida" << endl;
        }
    } while (opcion_actualizar != 4);
}

void MenuAgregar(){
    int opcion_agregar;
    do{
        cout << "MENU DE ACTUALIZACION DE REGISTROS" << endl;
        cout << "Indique el tipo de registro que desea agregar:" << endl;
        cout << "1. Vehiculo " << endl;
        cout << "2. Cliente" << endl;
        cout << "3. Repuesto" << endl;
        cout << "4. Regresar al Menu Principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion_agregar;

        switch (opcion_agregar){
        case 1: //Registro Vehiculo
            break;
        case 2: //Registro Cliente
            break;
        case 3: //Registro Repuesto
            break;
        case 4: //Menu Principal
            MenuPrincipal();
            break;
        default:
            cout << "Opcion Invalida" << endl;
        }
    } while (opcion_agregar != 4);
}

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

void Consulta_Cliente() {
    int cedula;
    cout << "Ingrese la cedula del cliente que desea consultar: "; cin >> cedula;

    int left = 0, right = numClientes - 1;
    bool encontrado = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (clientes[mid].cedula == cedula) {
            encontrado = true;
            cout << " Cedula: " << clientes[mid].cedula << endl;
            cout << " Nombre: " << clientes[mid].nombre << endl;
            cout << " Apellido: " << clientes[mid].apellido << endl;
            cout << " Correo: " << clientes[mid].email << endl;
            cout << " Vehiculos rentados: " << clientes[mid].cantidad_vehiculos_rentados << endl;
            cout << " Direccion: " << clientes[mid].direccion << endl;
            cout << " Activo: " << (clientes[mid].activo ? "Si" : "No") << endl;
            break;
        }
        if (clientes[mid].cedula < cedula) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!encontrado) {
        cout << "Cedula " << cedula << " no encontrada." << endl;
    }
}

void Consulta_Vehiculo_x_placa() {
    ifstream lectura_vehiculo("DATOS_VEHICULOS.csv");
	string line, vehiculo_buscar, vehiculo_actual;
	bool existe = false;
	cout << "Ingrese la placa del vehiculo que desea consultar: "; cin >> vehiculo_buscar;
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
            cout << " Cedula del cliente: " << vehiculo.ced_cliente << endl;
            cout << " Fecha de entrega: " << vehiculo.fecha_de_entrega << endl;
		}
	}
	lectura_vehiculo.close();
	if (!existe) {
		cout << "Placa " << vehiculo_buscar << " no encontrado.";
	}
}

void Consulta_Vehiculo_x_cedula() {
	int cedula;
	cout << "Ingrese la cedula del cliente que alquilo el carro que desea consultar: "; cin >> cedula;

    int left = 0, right = numVehiculos - 1;
    bool encontrado = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;

	    if (vehiculos[mid].ced_cliente == cedula) {
		    encontrado = true;
		    cout << " Modelo: " << vehiculos[mid].modelo << endl;
		    cout << " Marca: " << vehiculos[mid].marca << endl;
		    cout << " Placa: " << vehiculos[mid].placa << endl;
		    cout << " Color: " << vehiculos[mid].color << endl;
            cout << " Year: " << vehiculos[mid].year << endl;
            cout << " Kilometraje: " << vehiculos[mid].kilometraje << " Km" << endl;
            cout << " Rentado: " << (vehiculos[mid].rentado? "Si" : "No")<< endl;
            cout << " Motor: " << vehiculos[mid].motor << endl;
            cout << " Precio de renta: " << vehiculos[mid].precio_renta << " $/hr" << endl;
            cout << " Cedula del cliente: " << vehiculos[mid].ced_cliente << endl;
            cout << " Fecha de entrega: " << vehiculos[mid].fecha_de_entrega << endl;
            break;
	    }
        if (vehiculos[mid].ced_cliente < cedula) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!encontrado) {
        cout << "Cedula " << cedula << " no encontrada." << endl;
    }
}

void Consulta_Repuesto() {
    int modelo;
	cout << "Ingrese el modelo del repuesto que desea consultar: "; cin >> modelo;

    int left = 0, right = numVehiculos - 1;
    bool encontrado = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (repuestos[mid].modelo == modelo) {
		    encontrado = true;
			cout << " Modelo: " << repuestos[mid].modelo << endl;
			cout << " Marca: " << repuestos[mid].marca << endl;
			cout << " Nombre: " << repuestos[mid].nombre << endl;
			cout << " Modelo del carro: " << repuestos[mid].modelo_carro << endl;
            cout << " Year Carro: " << repuestos[mid].year_carro << endl;
            cout << " Precio: " << repuestos[mid].precio << " $" << endl;
            cout << " Existencias: " << repuestos[mid].existencias << endl;
            break;
        }
        if (repuestos[mid].modelo < modelo) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!encontrado) {
        cout << "Modelo " << modelo << " no encontrado." << endl;
    }
}

int main() {
    Lectura_Cliente();
    Lectura_Vehiculo();
    Lectura_Repuesto();
    
    MenuPrincipal();
    return 0;
}
