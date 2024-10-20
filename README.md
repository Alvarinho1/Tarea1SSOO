# Tarea 1 - Simulador de Carrera de Autos

**Profesor**: Alejandro Valdes Jimenez  
**Integrantes**: Alvaro Jorquera Godoy y Lucas Melgarejo Albornoz  
**Grupo**: 6

## Descripción
Este es un simulador de carrera de autos implementado en C++ utilizando hilos (threads). Cada auto se ejecuta en un hilo separado, lo que permite simular el avance de los autos de forma concurrente hasta que todos cruzan la meta.

## Requisitos
- Sistema operativo Linux.
- Compilador **g++** con soporte para C++11.
- **htop** para monitorear las hebras del proceso.
- **git** para clonar el repositorio.

## Instrucciones para la instalación y ejecución

1. **Clonar el repositorio**  
   Ingrese a la terminal de su sistema operativo Linux y ejecute el siguiente comando para clonar el repositorio:
   
   git clone https://github.com/Alvarinho1/Tarea1SSOO.git

   Si no tiene git instalado, puede hacerlo con:
   
   sudo apt install git

3. **Acceder al directorio del proyecto**
   Una vez clonado el repositorio, ingrese al directorio del proyecto con:
   
   cd Tarea1SSOO

5. **Ejecutar el programa**
   Para ejecutar el programa, use el siguiente comando:
   
   ./carrera (metros) (cantidad de autos)

   ejemplo: ./carrera 350 4

7. **Monitorear las hebras usando htop**
   Abra una nueva terminal y navegue nuevamente al directorio del proyecto:
   
   cd Tarea1SSOO

   Inicie htop con el siguiente comando:
   
   htop
   
   Diríjase al final de la lista para ver el proceso de la carrera y sus hebras.

   Vuelva a la terminal anterior y ejecute nuevamente el programa con el comando:
   
   ./carrera (metros) (cantidad de autos)
   
   Observe cómo las hebras del proceso aparecen en htop en tiempo real y se van eliminando a 
   medida que los autos terminan la carrera.

   
   
   

