#include "dataWarhouse.h"
#include "veterinaria.h"
#include <string.h>


void inicializarMascota(sMascota mascota[],int tamMascota)
{
    for(int i = 0; i < tamMascota; i++)
    {
        mascota[i].isEmpty = 1; //esta vacio
    }
}

void harcodearMascotas(sMascota mascota[],int tamHC)
{
    sMascota y[] =
    {
        {1, "Carlos",1,1, 4,0},
        {2, "Mabel",2,2, 3,0},
        {3, "Ruperto",3,3, 5,0},
        {4, "Ernesto",4,4, 2,0},
        {5, "Juan",5,5, 1,0},
        {6, "Jose",4,4, 2,0},
        {7, "Alberto",3,3, 1,0}
    };

    for(int i=0; i<tamHC; i++)
    {
        mascota[i] = y[i];
    }
}

void hardcodearTipos(sTipo tipo[], int cant)
{
    for(int i = 0; i < cant; i++)
    {
        tipo[i].id=idHTipos[i];
        strcpy(tipo[i].descripcion,descripcionHTipos[i]);
    }
}
void hardcodearColores(sColor color[], int cant)
{
    for(int i = 0; i < cant; i++)
    {
        color[i].id=idHColor[i];
        strcpy(color[i].nombreColor,descripcionHColores[i]);
    }
}
void hardcodearServicios(sServicio servicio[], int cant)
{
    for(int i = 0; i < cant; i++)
    {
        servicio[i].id=idHServicios[i];
        strcpy(servicio[i].descripcion,descripcionHTipos[i]);
    }
}

int buscarLibre(sMascota vec[], int tam)
{
    //-1 no consiguio lugar
    int indice = -1;//-1 no es una posicion en el vec
    for(int i = 0; i < tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i; //devuelvo el valor que tiene el indice
            break;
        }
    }
    return indice;
}

int altaMascota(int idX, sMascota vec[], int tam,sTipo tipo[],int tamTipo,sColor color[],int tamColor)
{
    int todoOk = 0; //no pudo dar de alta
    int indice = buscarLibre(vec, tam);
    sMascota auxMascota;

    system("cls");
    printf("***** Alta Mascota *****\n");
    if(indice == -1)
    {
        printf("Sistema completo\n\n");
    }
    else
    {
        auxMascota.id = idX;

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxMascota.nombre);

        mostrarTipos(tipo,tamTipo);
        printf("\nIngrese id del Tipo: ");
        fflush(stdin);
        scanf("%d", &auxMascota.idTipo);

        mostrarColores(color,tamColor);
        printf("\nIngrese id del Color: ");
        fflush(stdin);
        scanf("%d", &auxMascota.idColor);

        printf("Ingrese edad: ");
        fflush(stdin);
        scanf("%d", &auxMascota.edad);

        auxMascota.isEmpty = 0;

        vec[indice] = auxMascota; //copio al vec el empleado nuevo en el indice libre que me devolvio buscarIndice
        todoOk = 1; //exito
    }
    return todoOk;
}

void mostrarTipos(sTipo tipos[], int cantidad)
{
    system("cls");
    printf("***** Tipos de Mascota *****\n");
    printf("  ID  Descripcion \n\n");

    for(int i = 0; i < cantidad; i++)
    {
        printf("  %d   %7s\n",tipos[i].id,tipos[i].descripcion);
    }
}

void mostrarColores(sColor color[], int cantidad)
{
    system("cls");
    printf("***** Tipos de Mascota *****\n");
    printf("  ID  Descripcion \n\n");

    for(int i = 0; i < cantidad; i++)
    {
        printf("  %d   %7s\n",color[i].id,color[i].nombreColor);
    }
}

void listarServicios(sServicio servicio[],int tam)
{
    printf("***** Listado Comidas *****\n");
    printf("  id  Descripcion  Precio\n");
    for(int i=0; i<tam; i++)
    {
        printf("  %d  %10s  %5.2f\n",servicio[i].id,servicio[i].descripcion,servicio[i].precio);
    }
    printf("\n");
}

int buscarMascota(int id, sMascota vec[], int tam)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(vec[i].id == id && vec[i].isEmpty == 0) //si el vec id existe ya, me devuelve donde esta
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int menuModificar()
{
    int opcion;

    //system("cls");
    printf("\n***** Menu de Modificaciones *****\n\n");
    printf("1. Modificar Tipo\n");
    printf("2. Modificar Edad\n");
    printf("3. Salir\n\n");
    printf("Ingrese la opcion elegida: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

void modificarMascota(sMascota vec[],int tam, sTipo tipo[], int tamTipo)
{
    int id,indice;
    char confirma,salir;

    system("cls");
    printf("***** Modificar Mascota *****\n\n");
    mostrarMascotas(vec,tam,tipo,tamTipo);
    printf("\nIngrese id: ");
    scanf("%d", &id);

    indice = buscarMascota(id, vec, tam); //devuelve la posicion donde esta el empleado, o -1
    if(indice == -1)
    {
        printf("El id %d no existe en sistema.\n", id);
    }
    else
    {
        system("cls");
        printf("***** Modificar Empleado *****\n\n");
        printf("El empleado con el id %d es:\n", id);
        printf("------------------------------\n");
        printf("  ID   Nombre      Tipo  Edad\n");

        mostrarMascota(vec[indice], tipo, tamTipo);

        printf("\nDesea modificar? 's' o 'n': ");
        fflush(stdin);
        scanf("%c", &confirma);

        while(confirma == 's')
        {
            system("cls");
            printf("\n  ID   Nombre   Sexo  Edad   Sueldo    Fecha Ingreso    Sector\n");
            mostrarMascota(vec[indice],tipo,tamTipo);
                switch(menuModificar())
                {
                case 1:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    scanf("%s",vec[indice].nombre);
                    break;
                case 2:
                    printf("Ingrese nueva edad: ");
                    fflush(stdin);
                    scanf("%d",&vec[indice].edad);
                    break;
                case 3:
                    printf("Confirma salida? s/n: ");
                    fflush(stdin);
                    scanf("%c",&salir);
                    if(salir == 's')
                    {
                        confirma = 'n';
                    }
                    break;
                }
            }
        if(confirma!='s')
        {
            printf("\nSe ha cancelado la operacion.\n");
        }
    }
}

void mostrarMascota(sMascota x, sTipo tipo[], int tamTipo)
{
    char nombreTipo[20];

    cargarDescripcionTipo(nombreTipo, x.idTipo, tipo, tamTipo);
    printf(" %d %7s     %10s  %d \n", x.id, x.nombre, nombreTipo, x.edad);

}

void mostrarMascotas(sMascota lista[], int cantidad, sTipo tipo[], int tamTipo)
{
    int flag = 0;

    //system("cls");
    printf("***** Listado de empleados *****\n\n");
    printf("  ID   Nombre   Tipo  Edad\n\n");
    for(int i = 0; i < cantidad; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            mostrarMascota(lista[i], tipo, tamTipo);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("No hay Mascotas que listar\n");
    }
}

int cargarDescripcionTipo(char descripcion[], int id, sTipo tipo[], int tam)//para mostrar la descripcion del sector, no el numero
{
    int todoOk = 0;

    for(int i = 0; i < tam; i++)
    {
        if(tipo[i].id == id) //si el id del sector es igual al id sector que estor buscando(lo pase por parametros)
        {
            strcpy(descripcion, tipo[i].descripcion); //copio a descripcion la descripcion que tengo en ese sector
            todoOk = 1; //exito
        }
    }
    return todoOk;
}

void bajaMascota(sMascota vec[], int tam, sTipo tipo[], int tamTipo)
{
    int id,indice;
    char confirma;

    system("cls");
    printf("***** Baja Tipo *****\n\n");
    mostrarMascotas(vec,tam,tipo,tamTipo);
    printf("\nIngrese id: ");
    scanf("%d", &id);

    indice = buscarMascota(id, vec, tam); //devuelve la posicion donde eta el empleado, o -1
    if(indice == -1)
    {
        printf("El id %d no existe en sistema.\n", id);
    }
    else
    {
        printf("El empleado con el id %d es: ", id);
        mostrarMascota(vec[indice], tipo, tamTipo);

        printf("Confirma la baja? 's' o 'n': ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {
            vec[indice].isEmpty = 1;
            printf("Se ha realizado la baja con exito\n\n");
        }
        else
        {
            printf("Se cancelo la operacion.\n");
        }
    }
}
