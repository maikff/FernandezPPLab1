#include <stdio.h>
#include <stdlib.h>
#include "veterinaria.h"

#define TAMTIPO 5
#define TAMCOLOR 3
#define TAMMASCOTAS 7
#define TAMSERVICIOS 5
#define TAMTRABAJOS 5
#define CANTHARDCODE 3


int menu();

int main()
{
    char confirma,seguir='s';
    int proximoIdMascota,proximoIdTipo=1000,proximoIdColor=5000,proximoIdServicio=20000,proximoIdTrabajo;

    sMascota mascota[TAMMASCOTAS];
    sTipo tipo[TAMTIPO];
    sColor color[TAMCOLOR];
    sServicio servicio[TAMSERVICIOS];

    inicializarMascota(mascota,TAMMASCOTAS);

    hardcodearTipos(tipo,TAMTIPO);
    hardcodearColores(color,TAMCOLOR);
    hardcodearServicios(servicio,TAMSERVICIOS);

    harcodearMascotas(mascota,CANTHARDCODE);

    do
    {
        switch(menu())
        {
        case 1:
            printf("Alta\n");
            if(altaMascota(proximoIdMascota,mascota,TAMMASCOTAS,tipo,TAMTIPO,color,TAMCOLOR))
            {
                // si me devuelve 1, incremento proxId
                proximoIdMascota++;
            }
            system("pause");
            break;
        case 2:
            printf("Modificar\n");
            modificarMascota(mascota, TAMMASCOTAS, tipo,TAMTIPO);
            system("pause");
            break;
        case 3:
            printf("Baja\n");
            bajaMascota(mascota, TAMMASCOTAS, tipo, TAMTIPO);
            break;
        case 4:
            system("cls");
            mostrarMascotas(mascota, TAMMASCOTAS, tipo, TAMTIPO);
            system("pause");
            break;
        case 5:
            printf("Listar\n");
            system("cls");
            //mostrarEmpleados(lista, TAM, sector, TAMSEC);
            system("pause");
            break;
        case 6:
            printf("Informes\n");
            //informar(lista, TAM, sector, TAMSEC);
            break;
        case 7:
            printf("Alta\n");
            //if(altaAlmuerzo(proximoIdAlmuerzo,almuerzos,TAMAL,lista,TAM,sector,TAMSEC,comidas,TAMCOM))
            //{
                // si me devuelve 1, incremento proxId
            //    proximoIdAlmuerzo++;
            //}
            system("pause");
            break;
        case 8:
            //listarAlmuerzos(almuerzos,TAMAL,comidas,TAMCOM,lista,TAM);
            system("pause");
            break;
        case 9:
            printf("Alta Almuerzo\n");
            break;
        case 10:
            printf("Confirma Salida:");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        }
    }
    while(seguir == 's');

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("***** Menu de Opciones *****\n");
    printf("1. Alta Mascota\n");
    printf("2. Modificar Mascota\n");
    printf("3. Baja Mascota\n");
    printf("4. Listar Mascotas\n");
    printf("5. Listar Tipos\n");
    printf("6. Listar Colores\n");
    printf("7. Listar Servicios\n");
    printf("8. Alta Trabajo\n");
    printf("9. Listar Trabajo\n");
    printf("10. Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


