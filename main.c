/*
Autór: Sergio Hernandez Castillo
Matrícula: A01025210
Descripción: Actividad 1 - Hospital
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char * nombre;
    char * apellido;
    int edad;
    char * telefono;
} paciente;

typedef struct {
    int id;
    int enUso;
    paciente * p;
} cama;

int main(){
    cama * camas;
    cama * totalCamas;
    int limiteDeCamas = 3;
    int opcion;
    int contadorCamas = 0;
    int opcionCama;
    int camasOcupadas = 0;
    int camasDesocupadas = 0;
    int menu = 0;

    camas = (cama *) malloc(sizeof(cama) * limiteDeCamas);
    totalCamas = camas + limiteDeCamas; 

    printf("\nA continuación, proporcione los datos de los primeros 3 pacientes: ");

    for (cama * c = camas; c < totalCamas; ++c){
        paciente * pac = (paciente *) malloc(sizeof(paciente));

        pac->nombre = (char *) malloc(sizeof(char) * 25);
        printf("\nProporcione el nombre del paciente: ");
        scanf("%s", pac->nombre);

        pac->apellido = (char *) malloc(sizeof(char) * 25);
        printf("Proporcione el apellido del paciente: ");
        scanf("%s", pac->apellido);

        printf("Proporcione la edad del paciente: ");
        scanf("%d", &pac->edad);

        pac->telefono = (char *) malloc(sizeof(char) * 15);
        printf("Proporcione el numero telefónico del paciente: ");
        scanf("%s", pac->telefono);

        contadorCamas++;
        c->id = contadorCamas;
        printf("Cama: %d", c->id);

        c->enUso = 1;
        c->p = pac;
    }

    printf("\n--Hospital General 'Dr. Sergio Hernandez Castillo'-- \n1. Agregar pacientes \n2. Checar que paciente está usando que cama \n3. Dar de alta a un paciente \n4. Ver listado de pacientes \n5. Numeros de camas disponibles y usadas \n6. Salir");
    
    printf("\nElija una opción: ");
    scanf("%d", &opcion);

    while (menu != -99){
        switch (opcion){
            case 1:
                if (contadorCamas == limiteDeCamas){
                    limiteDeCamas += 5;
                    camas = (cama *) realloc(camas, sizeof(cama) * limiteDeCamas);
                    totalCamas = camas + limiteDeCamas;

                    cama * c = camas + contadorCamas;
                    paciente * pac = (paciente *) malloc(sizeof(paciente));

                    pac->nombre = (char *) malloc(sizeof(char) * 25);
                    printf("\nProporcione el nombre del paciente: ");
                    scanf("%s", pac->nombre);

                    pac->apellido = (char *) malloc(sizeof(char) * 25);
                    printf("Proporcione el apellido del paciente: ");
                    scanf("%s", pac->apellido);

                    printf("Proporcione la edad del paciente: ");
                    scanf("%d", &pac->edad);

                    pac->telefono = (char *) malloc(sizeof(char) * 15);
                    printf("Proporcione el numero telefónico del paciente: ");
                    scanf("%s", pac->telefono);

                    contadorCamas++;
                    c->id = contadorCamas;
                    printf("Cama: %d", c->id);

                    c->enUso = 1;
                    c->p = pac;
                }

                else if (contadorCamas < limiteDeCamas){
                    for (cama * c = camas; c < totalCamas; ++c){
                        if (c->enUso == 0){
                            paciente * pac = (paciente *) malloc(sizeof(paciente));

                            pac->nombre = (char *) malloc(sizeof(char) * 25);
                            printf("\nProporcione el nombre del paciente: ");
                            scanf("%s", pac->nombre);

                            pac->apellido = (char *) malloc(sizeof(char) * 25);
                            printf("Proporcione el apellido del paciente: ");
                            scanf("%s", pac->apellido);

                            printf("Proporcione la edad del paciente: ");
                            scanf("%d", &pac->edad);

                            pac->telefono = (char *) malloc(sizeof(char) * 15);
                            printf("Proporcione el numero telefónico del paciente: ");
                            scanf("%s", pac->telefono);

                            contadorCamas++;
                            c->id = contadorCamas;
                            printf("Cama: %d", c->id);

                            c->enUso = 1;
                            c->p = pac;
                        }
                    }
                }
            break;

            case 2:
                printf("La lista de camas es la siguiente: \n");

                for (cama * c = camas; c < totalCamas; ++c){
                    printf("Cama #%d", c->id);
                }

                printf("\nSeleccione una cama: ");
                scanf("%d", &opcionCama);

                for (cama * c = camas; c < totalCamas; ++c){
                    if (opcionCama == c->id){
                        if (c->enUso == 1){
                            printf("\nLa cama está siendo ocupada por: %s %s", c->p->nombre, c->p->apellido);
                        }

                        else {
                            printf("\nLa cama está desocupada.");
                        }
                    }

                    else if (opcionCama != c->id){
                        printf("\nNo existe una cama con ese ID.");
                    }
                }
            break;

            case 3:
                printf("\nProporcione el ID de la cama con el paciente que desea dar de alta: ");
                scanf("%d", &opcionCama);

                for (cama * c = camas; c < totalCamas; ++c){
                    if (opcionCama == c->id){
                        free(c->p->nombre);
                        free(c->p->apellido);
                        free(c->p->telefono);
                        free(c->p);

                        c->enUso = 0;

                        printf("El paciente %s %s fue dado de alta. Su cama ahora está desocupada.", c->p->nombre, c->p->apellido);
                    }

                    else if (opcionCama != c->id){
                        printf("\nNo existe una cama con ese ID.");
                    }
                }
            break;

            case 4:
                for (cama * c = camas; c < totalCamas; ++c){
                    printf("\nNombre y apellido: %s %s \nEdad: %d \nTeléfono: %s \nCama #%d", c->p->nombre, c->p->apellido, c->p->edad, c->p->telefono, c->id);
                }
            break;

            case 5:
                for (cama * c = camas; c < totalCamas; ++c){
                    if (c->id == 0){
                        camasDesocupadas++;
                    }

                    else if (c->id == 1){
                        camasOcupadas++;
                    }
                }

                printf("\nCamas desocupadas: %d", camasDesocupadas);
                printf("\nCamas ocupadas: %d", camasOcupadas);
            break;

            case 6:
                for (cama * c = camas; c < totalCamas; ++c){
                    free(c->p->nombre);
                    free(c->p->apellido);
                    free(c->p->telefono);
                    free(c->p);
                }

                free(camas);

                menu == -99;
            break;

            default:
                printf("\nElija una opción válida: ");
                scanf("%d", &opcion);
            break;
        }
    }
    
    return 0;
}