En este repositorio se encuentra la primera parte del proyecto de la materia Programación II - 2024C, realizado por Erick Díaz (CI.29963164) y Gabriela Rey (CI. 29645414).

Este proyecto busca realizar un programa para un negocio de renta de vehiculos el cual realice las siguientes funciones:

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
