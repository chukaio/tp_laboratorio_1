#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

/*
typedef struct
{
    char titulo[50];
    char genero[15];
    int duracion;
    char descripcion[300];
    int puntaje;
    char url[200];
    int isEmpty;
}eMovie2;
*/

char menu(void);
char submenu(void);
int isLwrThan(char [],int);
char *formatName(char *);
int isNum(char []);
int intOrFloat(char []);
char isThat(char,char,char);
int esCero(char []);
//int isRepeated(eMovie2 *,char [],int);
