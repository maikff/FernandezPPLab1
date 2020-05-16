#include <stdio.h>
#include <stdlib.h>
#ifndef VETERINARIA_H_INCLUDED
#define VETERINARIA_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}sFecha;

typedef struct{
    int id;
    char descripcion[20];
}sTipo;

typedef struct{
    int id;
    char nombreColor[20];
}sColor;

typedef struct{
    int id;
    char nombre[20];
    int idTipo;//validar
    int idColor;//validar
    int edad;
    int isEmpty;
}sMascota;

typedef struct{
    int id;
    char descripcion[25];
    float precio;
}sServicio;

typedef struct{
    int id;//autoincremental
    int idMascota;//validar debe existir
    int idServicio;//Validar debe existir
    sFecha fecha;//Validar dia,mes,anio
}sTrabajo;

#endif // VETERINARIA_H_INCLUDED

void inicializarMascota(sMascota mascota[],int tamMascota);

void hardcodearTipos(sTipo tipo[], int cant);
void hardcodearColores(sColor color[],int cant);
void hardcodearServicios(sServicio servicio[],int cant);

void harcodearMascotas(sMascota mascota[],int tamHC);

int buscarLibre(sMascota vec[], int tam);

int altaMascota(int idX, sMascota vec[], int tam,sTipo tipo[],int tamTipo,sColor color[],int tamColor);

void mostrarTipos(sTipo tipos[], int cantidad);

void mostrarColores(sColor color[], int cantidad);

void listarServicios(sServicio servicio[],int tam);

int buscarMascota(int id, sMascota vec[], int tam);

void modificarMascota(sMascota vec[],int tam, sTipo tipo[], int tamTipo);

int cargarDescripcionTipo(char descripcion[], int id, sTipo tipo[], int tam);//para mostrar la descripcion del sector, no el numero

void mostrarMascota(sMascota x, sTipo tipo[], int tamSec);

void mostrarMascotas(sMascota lista[], int cantidad, sTipo tipo[], int tamSec);

void bajaMascota(sMascota vec[], int tam, sTipo tipo[], int tamTipo);

