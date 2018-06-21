#include "producto.h"

int main()
{
    int seguir=1;
    char opcion;
    eProducto prod[TAM];
    eProovedor proov[5];

    printf("---------------------------------------\n");
    printf("|                                     |\n");
    printf("|         BIENVENIDO AL ABM           |\n");
    printf("|                                     |\n");
    printf("---------------------------------------\n\n\n");
    init(prod,TAM);
    hardcodeProovedor(proov);
    do
    {
        printf("Elija una de las siguientes opciones\n\n");
        opcion=menu();
        while(opcion<49||opcion>54||isdigit(opcion)==0)
        {
            system("cls");
            printf("Ingrese correctamente una de las siguientes opciones\n\n");
            opcion=menu();
        }
        switch(opcion)
        {
            case '1':
            {
                altaprod(prod,TAM,proov);
                system("pause");
                system("cls");
                break;
            }
            case '2':
            {
                modifprod(prod,TAM,proov);
                printf("\n\n");
                system("pause");
                system("cls");
                break;
            }
            case '3':
            {
                bajaprod(prod,TAM,proov);
                printf("\n\n");
                system("pause");
                system("cls");
                break;
            }
            case '4':
            {
                informProd(prod,TAM);
                printf("\n\n");
                system("pause");
                system("cls");
                break;
            }
            case '5':
            {
                listarProd(prod,TAM,proov);
                printf("\n\n");
                system("pause");
                system("cls");
                break;
            }
            case '6':
            {
                seguir=0;
                break;
            }
        }
    }
    while(seguir==1);

    return 0;
}
