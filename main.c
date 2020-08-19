/*
1. El hospital cuenta con 10 camas. 
2. Se llena el hospital hasta 5 camas con un for al iniciar el programa.
3. Abrir un switch:
3a. Incorpora mas pacientes (los que se requieran), si se llenan las camas, hay
    que hacer espacio. 
3b. Ver que paciente esta asignado a una cama, o si esta libre. 
3c. Dar de alta a un paciente por el numero de cama (se borra ese paciente del 
    hospital y su cama queda libre).
3d. Mostrar la lista de todos los pacientes del hospital. 
3e. Conocer cuantas camas disponibles hay y cuantas estan ocupadas. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 5;

typedef struct {
    char * nombre;
    char * apellidos;
    int edad;
    char * telefono;
    cama c;
} paciente;

typedef struct {
    int id;
    bool enUso = false;
} cama;

typedef void (* menu_t)();

void agregarPacientes();
void checarCama();
void darDeAlta();
void listaDePacientes();
void disponiblesUsadas();

int main(int argc, const char * argv[]){
    paciente * pacientes, * ptr, * total;
    int limiteDeCamas = 20, opcion = -1;

    pacientes = (paciente *) malloc(sizeof(paciente) * limiteDeCamas);
    total = pacientes + limiteDeCamas;

    menu_t * opciones = (menu_t *) malloc(sizeof(menu_t) * N);

    *opciones = agregarPacientes;
    *(opciones + 1) = checarCama;
    *(opciones + 2) = darDeAlta;
    *(opciones + 3) = listaDePacientes;
    *(opciones + 4) = disponiblesUsadas;

    printf("--Hospital General 'Dr. Sergio Hernandez Castillo'-- 
        \n1. Agregar pacientes 
        \n2. Checar que paciente está usando que cama 
        \n3. Dar de alta a un paciente 
        \n4. Ver listado de pacientes 
        \n5. Numeros de camas disponibles y usadas 
        \n0. Salir");

    while (opcion != 0){
        printf("\nSelecciona tu opción: ");
        scanf("%d", &opcion);

        if ((opcion > 0) && (opcion <= N)){
            (*(opciones[opcion - 1]))();
        } 
    }

    free(opciones);

    return 0;
}