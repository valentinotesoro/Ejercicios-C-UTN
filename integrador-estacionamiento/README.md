# Integrador - Gestión de Estacionamiento

## Descripción

Programa desarrollado en lenguaje C como ejercicio integrador de la materia de Programación I de la UTN.

El programa permite gestionar los espacios de un estacionamiento, registrar ingresos y salidas, buscar espacios y generar listados de los espacios en los que ingresaron autos y motos.

## Conceptos utilizados

- Vectores
- Funciones
- Búsqueda secuencial
- Ordenamiento
- Ciclos
- Condicionales
- Contadores
- Acumuladores
- `switch` / estructuras condicionales
- Vectores generados

## Funciones principales

### `buscar()`

Busca un número de espacio dentro del vector y devuelve su posición.

Si el espacio no existe, devuelve `-1`.

### `ordenar()`

Ordena los números de espacio utilizando el método de ordenamiento por burbujeo.

## Funcionamiento

1. Se cargan los datos iniciales de los espacios del estacionamiento.
2. Se ingresa el legajo del encargado.
3. Se busca el espacio correspondiente.
4. Se registra un ingreso o una salida.
5. Se actualizan las horas del vehículo.
6. Se generan listados separados para autos y motos.
7. Los listados se ordenan de menor a mayor.

## Nota

La constante `cant` está definida como `2` para realizar pruebas durante el desarrollo.

La cantidad utilizada en el ejercicio original puede ser diferente.
