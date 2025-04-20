# Taller de Punteros en C

Este repositorio contiene la solución a un taller de punteros desarrollado como parte del curso de **Computación de Alto Desempeño** de la **Universidad de Medellín**. A través de una serie de ejercicios, se abordan conceptos clave como el uso de punteros, memoria dinámica, estructuras, manipulación de arreglos, y más. Además, se aplica una estructura organizada del proyecto y el uso de Makefiles para facilitar la compilación.

*La carpeta de Ejercicios en clase no hace parte de la tarea, todo lo que hace parte de la segunda tarea del curso de HPC está dentro de la carpeta "tarea2_punteros"*

## Estructura del Proyecto

```
tarea2_punteros/
├── bin/                # Archivos binarios compilados 
├── src/                # Archivos fuente .c (ejercicio1.c, ejercicio2.c, ...)
├── Makefile            # Automatiza la compilación
└── README.md            
```

## Ejercicios

- `ejercicio1.c` a `ejercicio5.c`: prácticas de punteros básicas, sin explicación adicional.
- `ejercicio6.c` a `ejercicio10.c`: prácticas más complejas, con documentación y análisis.

## Requisitos

- Sistema operativo con entorno tipo Unix (Linux/MacOS) o WSL en Windows.
- `gcc` instalado.
- `make` instalado.

## Compilación y Ejecución

### 1. Compilar todos los ejercicios

```bash
make
```

Esto generará todos los ejecutables dentro de la carpeta `bin/`.

### 2. Ejecutar un ejercicio específico

```bash
./bin/ejercicio3
```

(Reemplaza `ejercicio3` por el nombre del archivo que desees ejecutar.)

### 3. Compilar solo un ejercicio específico

```bash
make ejercicio3
```

Esto compilará únicamente `src/ejercicio3.c` y generará su ejecutable en `bin/`.

### 4. Limpiar los ejecutables

```bash
make clean
```

Esto eliminará todos los archivos generados dentro de la carpeta `bin/`.

