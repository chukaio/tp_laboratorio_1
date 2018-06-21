#include "input.h"

char menu(void)
{
    char opcion;

    printf(" 1) Alta\n");
    printf(" 2) Modificar\n");
    printf(" 3) Baja\n");
    printf(" 4) Informar\n");
    printf(" 5) Listar\n");
    printf(" 6) Salir\n\n\n");
    printf("Opcion ingresada: ");
    fflush(stdin);
    scanf("%c",&opcion);

    return opcion;
}
//Brief: Chequea si el string ingresado es un numero
//Parameters: Un string
//Return: "0" si el string ingresado es un numero o "1" si no es un numero
//
int isNum(char aux[])
{
    int i, error=0, cont=0, soyUnPosibleFloat=0;

    for(i=0 ; i<strlen(aux) ; i++)
    {
        if(aux[i]=='.')
        {
            cont=cont+1;
        }
        if(cont==1)
        {
            soyUnPosibleFloat=1;
        }
    }
    for(i=0 ; i<strlen(aux) ; i++)
    {
        if(!isdigit(aux[i]))
        {
            if(soyUnPosibleFloat==1)
            {
                soyUnPosibleFloat=0;
                continue;
            }
            error=1;
            break;
        }
    }

    return error;
}
//Brief: Cuenta la cantidad de puntos en un string
//Parameters: Un string
//Return: Devuelve el numero de puntos
//
int intOrFloat(char aux[])
{
    int i, cont=0;

    for(i=0 ; aux[i]!='\0' ; i++)
    {
        if(aux[i]=='.')
        {
          cont++;
        }
    }

    return cont;
}
//Brief: Chequea si el string ingresado tiene como maximo tantos caracteres como indicado por tam
//Parameters: Un string y el tamanio
//Return: Devuelve un "0" si no hay errores o "1" si hay.
//
int isLwrThan(char nombre[], int tam)
{
    int error=1;

    if(strlen(nombre)<=49)
    {
        error=0;
    }

    return error;
}
//Brief: Chequea si source es distinto a los 2 char a y b
//Parameters: 1 char source y 2 char a y b al que compararlo con source
//Return: Devuelve el char source
//
char isThat(char source,char a, char b)
{
    source=tolower(source);
    a=tolower(a);
    b=tolower(b);
    while(source!=a&&source!=b)
    {
        printf("\nError, vuelva a ingresar\n");
        fflush(stdin);
        scanf("%c",&source);
        source=tolower(source);
    }

    return source;
}

