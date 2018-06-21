#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#define TAM 6
#define VACIO 1
#define LLENO 0

typedef struct
{
    int id;
    char descripcion[50];
    int isEmpty;
}eProovedor;

typedef struct
{
    int id;
    char descripcion[50];
    float importe;
    int stock;
    int idProov;
    int isEmpty;
}eProducto;

void init(eProducto[],int);
void hardcodeProovedor(eProovedor[]);
int buscaLibre(eProducto[],int);
int buscaprod(eProducto[],int,int);
void mostrarprod(eProducto[],int,int,eProovedor[]);
void altaprod(eProducto[],int,eProovedor[]);
char menuModif();
void modifprod(eProducto[],int,eProovedor[]);
void bajaprod(eProducto[],int,eProovedor[]);
char menuInform(void);
void inform1 (eProducto[],int,int);
void inform2 (eProducto[],int,int);
void informProd(eProducto[],int);
int menuListar(void);
void listar1(eProducto[],int);
void listar2(eProducto[],int,int);
void listar3(eProducto[],int,int);
void listar4(eProducto[],int,eProovedor[]);
void listar5(eProducto[],int,eProovedor[]);
void listar6(eProducto[],int,eProovedor[]);
void listar7(eProducto[],int,int,eProovedor[]);
void listar8(eProducto[],int,int,eProovedor[]);
void listarProd(eProducto[],int,eProovedor[]);

#endif // PRODUCTO_H_INCLUDED
