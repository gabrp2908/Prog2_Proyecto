En este repositorio se encuentra la primera parte del proyecto de la materia Programación II - 2024C, realizado por Erick Díaz (CI.29963164) y Gabriela Rey (CI. 29645414).

Este proyecto se divide en dos partes.

Parte I:
Se busca realizar un programa para un negocio de renta de vehiculos el cual realice las siguientes funciones:

1. Administrar los datos de tres archivos .csv, uno para los vehiculos, otro para los clientes y otro para los respuestos disponibles. Las columnas en cada .csv son:
Vehículos: modelo, marca,  placa, color, año, kilometraje, rentado, motor, precio_renta, ced_cliente, fecha_de_entrega.
Cliente: cedula, nombre, apellido, email, cantidad_vehiculos_rentados, direccion, activo.
Repuestos: modelo, marca, nombre, modelo_carro, año_carro, precio, existencias.

2. Realizar las acciones de borrado, actualización, inserción y lectura en cada archivo, manteniendo la coherencia en los datos.

3. Realizar consultas sobre un cliente, carro o repuesto (principalmente mostrar los datos del carro solicitado, cliente o repuesto).

4. No alterar los archivos hasta confirmar los cambios hechos en el programa, es decir, el archivo no se modifica hasta que el usuario no indique que se quiera modificar generando uno nuevo eliminando el anterior.

Este proyecto cuenta sigue la siguiente estructura de carpetas:
Una carpeta bin en donde se encuentran los datos a manejar, y el ejecutable del programa realizado.
Una carpeta src donde se encuentra el codigo del proyecto.

Nota: Los datos empleados en los tres archivos .csv fueron generados mediante el uso de mockaroo para la generación de mock data.


Parte II: 

1. Crear clases para cada estructura creada en el programa.

2. El proyecto se separa en diferentes módulos (seguir una estructura similar a MVC).

3. De utilizar arreglos o vectores, reemplazar por arreglos dinámicos.

4. Agregar una función que cree en una carpeta aparte diferentes copias de seguridad de los archivos, a los nombres de los archivos de seguridad colocar la fecha de creación como nombre. 

5. Agregar registro y acceso de usuarios por roles.
            1. Admin (puede realizar todas las funciones con todos los archivos).
            2. Manager (solo puede realizar las funciones que se relacionen con los vehículos, clientes o empleados).
            3. Empleado (solo puede consultar los datos  y realizar ventas a los clientes).


Notas Adicionales:

1. Para inicializar el programa se debe posicionar en la carpeta bin y ejecutar el siguiente comando:

g++ -std=c++17 -lstdc++fs -I../src -o programa ../src/main.cpp ../src/model/model.cpp ../src/controller/controller.cpp ../src/view/view.cpp

./programa

2. Para acceder a los diferentes roles, los datos requeridos son:

Usuario: admin    ; Contraseña: 1234 ; Rol: Admin
Usuario: manager  ; Contraseña: 1234 ; Rol: Manager
Usuario: empleado ; Contraseña: 1234 ; Rol: Empleado