#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <conio.h>

int main()
{
    //Declaracion de variables
    int opcion, seguir=1, entero=1, fact=0;
    float num1=0,num2=0,res;

    //Cuerpo del programa main.c
    printf("---------------------------------------\n");
    printf("|                                     |\n");
    printf("| BIENVENIDO A LA CALCULADORA DEL TP1 |\n");
    printf("|                                     |\n");
    printf("---------------------------------------\n");
    printf("\n\n");
    while ( seguir==1 )
    {
        printf("*** Seleccione una de las siguientes opciones ***\n");
        printf("\n\n");
        printf(" 1) Ingresar 1er operando      ====> A=%.2f\n",num1);
        printf(" 2) Ingresar 2do operando      ====> B=%.2f\n",num2);
        printf(" 3) Calcular la suma           ====> %.2f + %.2f\n",num1,num2);
        printf(" 4) Calcular la resta          ====> %.2f - %.2f\n",num1,num2);
        printf(" 5) Calcular la division       ====> %.2f / %.2f\n",num1,num2);
        printf(" 6) Calcular la multiplicacion ====> %.2f * %.2f\n",num1,num2);
        //Si el float ingresado en cualquiera de los operandos tiene decimales, dara error
        if ( entero==1 )
        {
           printf(" 7) Calcular el factorial      ====> %d!\n",fact);
        }
        else
        {
           printf(" 7) Calcular el factorial      ====> Math ERROR\n");
        }
        printf(" 8) Calcular todas las operaciones\n");
        printf(" 9) Salir\n");
        printf("\n");
        printf("Opcion ingresada: ");
        scanf("%d",&opcion);
        system("cls");
        while ( opcion<1 || opcion>9 )
        {
            printf("*** Seleccione una de las siguientes opciones [1-9] ***\n");
            printf("\n\n");
            printf(" 1) Ingresar 1er operando      ====> A=%.2f\n",num1);
            printf(" 2) Ingresar 2do operando      ====> B=%.2f\n",num2);
            printf(" 3) Calcular la suma           ====> %.2f + %.2f\n",num1,num2);
            printf(" 4) Calcular la resta          ====> %.2f - %.2f\n",num1,num2);
            printf(" 5) Calcular la division       ====> %.2f / %.2f\n",num1,num2);
            printf(" 6) Calcular la multiplicacion ====> %.2f * %.2f\n",num1,num2);
            if ( entero==1 )
            {
                printf(" 7) Calcular el factorial      ====> %d!\n",fact);
            }
            else
            {
                printf(" 7) Calcular el factorial      ====> Math ERROR\n");
            }
            printf(" 8) Calcular todas las operaciones\n");
            printf(" 9) Salir\n");
            printf("\n");
            printf("Opcion ingresada: ");
            scanf("%d",&opcion);
            system("cls");
        }
        switch ( opcion )
        {
            case 1:
                {
                    printf("Ingrese 1er operando\n");
                    printf("\n");
                    printf("A=");
                    scanf("%f",&num1);
                    if ( num1-(int)num1==0 )
                    {
                        fact=num1;
                        entero=1;
                    }
                    else
                    {
                        entero=0;
                    }
                    system("cls");
                    break;
                }
            case 2:
                {
                    printf("Ingrese 2do operando\n");
                    printf("\n");
                    printf("B=");
                    scanf("%f",&num2);
                    system("cls");
                    break;
                }
            case 3:
                {
                    printf("*** Operacion elegida: Suma ***\n");
                    printf("\n\n");
                    res=suma( num1 , num2 );
                    printf("El resultado de la suma es %.2f\n",res);
                    printf("\n\n");
                    printf("Presione cualquier tecla para continuar\n");
                    getch();
                    system("cls");
                    break;
                }
            case 4:
                {
                    printf("*** Operacion elegida: Resta ***\n");
                    printf("\n\n");
                    res=resta( num1 , num2 );
                    printf("El resultado de la resta es %.2f\n",res);
                    printf("\n\n");
                    printf("Presione cualquier tecla para continuar\n");
                    getch();
                    system("cls");
                    break;
                }
            case 5:
                {
                    printf("*** Operacion elegida: Division ***\n");
                    printf("\n\n");
                    if ( num2!=0 )
                    {
                        res=division( num1 , num2 );
                        printf("El resultado de la division es %.2f\n",res);
                        printf("\n\n");
                        printf("Presione cualquier tecla para continuar\n");
                        getch();
                        system("cls");
                    }
                    else
                    {
                        printf("No es posible dividir por 0\n");
                        printf("\n\n");
                        printf("Presione cualquier tecla para continuar\n");
                        getch();
                        system("cls");
                    }
                    break;
                }
            case 6:
                {
                    printf("*** Operacion elegida: Multiplicacion ***\n");
                    printf("\n\n");
                    res=multiplicacion( num1 , num2 );
                    printf("El resultado de la multiplicacion es %.2f\n",res);
                    printf("\n\n");
                    printf("Presione cualquier tecla para continuar\n");
                    getch();
                    system("cls");
                    break;
                }
            case 7:
                {
                    printf("*** Operacion elegida: Factorial ***\n");
                    printf("\n\n");
                    res=(float)factorial( num1 );
                    if ( res!=0 )
                    {
                        printf("El resultado de %d! es %d\n",(int)num1,(int)res);
                    }
                    printf("\n\n");
                    printf("Presione cualquier tecla para continuar\n");
                    getch();
                    system("cls");
                    break;
                }
            case 8:
                {
                    //SUMA
                    printf("*** Suma ***\n");
                    printf("\n\n");
                    res=suma( num1 , num2 );
                    printf("El resultado de la suma es %.2f\n",res);
                    printf("\n\n");
                    //RESTA
                    printf("*** Resta ***\n");
                    printf("\n\n");
                    res=resta( num1 , num2 );
                    printf("El resultado de la resta es %.2f\n",res);
                    printf("\n\n");
                    //DIVISION
                    printf("*** Division ***\n");
                    printf("\n\n");
                    if ( num2!=0 )
                    {
                        res=division( num1 , num2 );
                        printf("El resultado de la division es %.2f\n",res);
                        printf("\n\n");
                    }
                    else
                    {
                        printf("No es posible dividir por 0\n");
                        printf("\n\n");
                    }
                    //MULTIPLICACION
                    printf("*** Multiplicacion ***\n");
                    printf("\n\n");
                    res=multiplicacion( num1 , num2 );
                    printf("El resultado de la multiplicacion es %.2f\n",res);
                    printf("\n\n");
                    //FACTORIAL
                    printf("*** Factorial ***\n");
                    printf("\n\n");
                    res=(float)factorial( num1 );
                    if ( res!=0 )
                    {
                        printf("El resultado de %d! es %d\n",(int)num1,(int)res);
                    }
                    printf("\n\n");
                    printf("Presione cualquier tecla para continuar\n");
                    getch();
                    system("cls");
                    break;
                }
            case 9:
                {
                    printf("Gracias por usar nuestro servicio, vuelva pronto!\n");
                    seguir=0;
                    break;
                }
        }

    }

    //Retorno del programa main.c
    return 0;
}
