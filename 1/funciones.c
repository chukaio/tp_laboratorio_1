#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
*\brief ... Suma dos float
*\param ... Dos float
*\return ... Devuelve la suma de los 2 float
*
*/
float suma ( float a , float b )
{
    float res;

    res=a+b;

    return res;
}
/**
*\brief ... Resta dos float
*\param ... Dos float
*\return ... Devuelve la resta entre ambos float
*
*/
float resta ( float a , float b )
{
    float res;

    res=a-b;

    return res;
}
/**
*\brief ... Multiplica dos float
*\param ... Dos float
*\return ... Devuelve el producto entre ambos float y siempre distinto de cero negativo
*
*/
float multiplicacion ( float a , float b )
{
    float res;

    res=a*b;
    if ( res== 0.00 )
        {
            res=0.00;
        }

    return res;
}
/**
*\brief ... Divide dos float
*\param ... Dos float
*\return ... Devuelve el cociente entre ambos float si es correcto y siempre distinto de cero negativo
*
*/
float division ( float a , float b )
{
    float res;

    res=a/b;
    if ( res==0.00 )
    {
        res=0.00;
    }

    return res;
}
/**
*\brief ... Calcula el factorial de un float sin decimales
*\param ... Un float
*\return ... Devuelve el factorial de dicho float sin decimales o 0 si da error.
*
*/
int factorial ( float num )
{
    int res=1, numI;

    if ( num-(int)num==0 )
    {
       numI=(int)num;
    }
    else
    {
        printf("No es posible calcular el factorial de un numero no entero\n");
        res=0;
        return res;
    }
    if ( numI!=0 && numI>0 )
    {
        for ( int i=numI ; i>0 ; i-- )
        {
            res=res*i;
        }
    }
    if ( numI==0 )
    {
        printf("No es posible calcular el factorial de 0\n");
        res=0;
    }
    if ( numI<0 )
    {
        printf("No es posible calcular el factorial de un negativo\n");
        res=0;
    }

    return res;
}


