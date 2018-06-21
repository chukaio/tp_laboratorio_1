#include "producto.h"
//Brief: Inicializa el array de estructuras de producto.
//Parameters: Un array de estructuras producto, un int tamanio del array
//Return: No Devuelve nada.
//
void init(eProducto prod[],int tam)
{
    int i;

    for(i=0 ; i<tam ; i++)
    {
        prod[i].isEmpty=VACIO;
    }
}
//Brief: Hardcodea la informacion de proovedores
//Parameters: Un array de estructuras proovedor
//Return: No Devuelve nada.
//
void hardcodeProovedor(eProovedor proov[])
{
    proov[0].id=1;
    strcpy(proov[0].descripcion,"Proovedor 1");
    proov[0].isEmpty=VACIO;

    proov[1].id=2;
    strcpy(proov[1].descripcion,"Proovedor 2");
    proov[1].isEmpty=VACIO;

    proov[2].id=3;
    strcpy(proov[2].descripcion,"Proovedor 3");
    proov[2].isEmpty=VACIO;

    proov[3].id=4;
    strcpy(proov[3].descripcion,"Proovedor 4");
    proov[3].isEmpty=VACIO;

    proov[4].id=5;
    strcpy(proov[4].descripcion,"Proovedor 5");
    proov[4].isEmpty=VACIO;
}
//Brief: Busca la rprimer posicion libre
//Parameters: Un array de estructuras producto, un int tamanio del array
//Return: Devuelve el primer indice vacio
//
int buscaLibre(eProducto prod[],int tam)
{
    int i, indice=-1;

    for(i=0 ; i<tam ; i++)
    {
        if(prod[i].isEmpty==VACIO)
        {
            indice=i;
            break;
        }
    }

    return indice;
}
//Brief: Busca el producto
//Parameters: Un array de estructuras producto, un int tamanio del array y otro int de id de proovedor
//Return: Devuelve el indice hallado.
//
int buscaprod(eProducto prod[], int tam, int idProducto)
{
    int i, hallado=-1;

    for(i=0 ; i<tam ; i++)
    {
        if(prod[i].id==idProducto && prod[i].isEmpty==LLENO)
        {
            hallado=i;
            break;
        }
    }

    return hallado;
}
//Brief: Imprime los productos
//Parameters: Un array de estructuras producto, un int indice del producto hallado y otro array de estructuras proovedor
//Return: No Devuelve nada.
//
void mostrarprod(eProducto prod[],int hallado,int printTitle,eProovedor proov[])
{
    int i;

    if(printTitle!=0)
    {
        printf("| ID | DESCRIPCION | IMPORTE | STOCK | PROOVEDOR |\n");
    }
    printf("|  %d  |  %s  |  %.2f  |  %d  |", prod[hallado].id, prod[hallado].descripcion, prod[hallado].importe, prod[hallado].stock);
    for(i=0 ; i<5 ; i++)
    {
        if(prod[hallado].idProov==proov[i].id)
        {
            printf("  %s  |\n",proov[i].descripcion);
        }
    }
}
//Brief: Realiza el alta de productos
//Parameters: Un array de estructuras producto, un int tamanio del array y otro array de estructuras proovedor
//Return: No Devuelve nada.
//
void altaprod(eProducto prod[],int tam,eProovedor proov[])
{
    int i, j, indice, hallado, error, isFloat=0, auxInt;
    char aux[50];

    system("cls");
    indice=buscaLibre(prod,tam);
    if(indice==-1)
    {
        printf("\nNo hay espacio en agenda, borre alguno primero\n");
        system("pause");
    }
    else
    {
        printf("---Alta de producto---\n");
        //ID
        printf("\nIngrese id: ");
        scanf("%s",aux);
        error=isNum(aux);
        isFloat=intOrFloat(aux);
        while(error==1||isFloat!=0)
        {
            printf("\nIngrese id correctamente: ");
            scanf("%s",aux);
            error=isNum(aux);
            isFloat=intOrFloat(aux);
        }
        prod[indice].id=atoi(aux);
        //Comprueba si ya existe ese id
        hallado=buscaprod(prod,tam,prod[indice].id);
        printf("\n");
        if(hallado!=-1)//El id ya existe
        {
            printf("El siguiente producto ya ha sido agregado previamente\n\n");
            mostrarprod(prod,hallado,1,proov);
        }
        else //El id no existe
        {
            prod[indice].isEmpty=LLENO;
            //DESCRIPCION
            printf("Ingrese descripcion: ");
            fflush(stdin);
            scanf("%[^\n]",aux);
            error=isLwrThan(aux,50);
            while(error==1)
            {
                printf("Ingrese descripcion correctamente: ");
                fflush(stdin);
                scanf("%[^\n]",aux);
                error=isLwrThan(aux,50);
            }
            strlwr(aux);
            for(i=0 ; aux[i]!='\0' ; i++)
            {
                if(i==0)
                {
                    aux[i]=toupper(aux[i]);
                }
                if(aux[i]==' ')
                {
                    aux[i+1]=toupper(aux[i+1]);
                }
            }
            strcpy(prod[indice].descripcion,aux);
            //IMPORTE
            printf("\nIngrese importe en la forma \"xx.xx\": ");
            scanf("%s",aux);
            error=isNum(aux);
            isFloat=intOrFloat(aux);
            while(error==1||isFloat!=1)
            {
                printf("\nIngrese importe correctamente en la forma \"xx.xx\": ");
                scanf("%s",aux);
                error=isNum(aux);
                isFloat=intOrFloat(aux);
            }
            prod[indice].importe=atof(aux);
            //STOCK
            printf("\nIngrese stock: ");
            scanf("%s",aux);
            error=isNum(aux);
            isFloat=intOrFloat(aux);
            while(error==1||isFloat!=0)
            {
                printf("\nIngrese stock correctamente: ");
                scanf("%s",aux);
                error=isNum(aux);
                isFloat=intOrFloat(aux);
            }
            prod[indice].stock=atoi(aux);
            //ID PROOVEDOR
            for(i=0 ; i<5 ; i++)
            {
                if(i==0)
                {
                    printf("\n| ID |  DESCRIPCION  |\n");
                }
                printf("| %d  |  %s  |\n",proov[i].id,proov[i].descripcion);
            }
            printf("\nIngrese id del proovedor listado arriba: ");
            scanf("%s",aux);
            auxInt=atoi(aux);
            error=isNum(aux);
            isFloat=intOrFloat(aux);
            while(error==1||isFloat!=0||auxInt<1||auxInt>5)
            {
                printf("\nIngrese id del proovedor listado arriba: ");
                scanf("%s",aux);
                error=isNum(aux);
                isFloat=intOrFloat(aux);
                auxInt=atoi(aux);
            }
            for(j=0 ; j<5 ; j++)
            {
                if(proov[j].id==auxInt)
                {
                    proov[j].isEmpty=LLENO;
                }
            }
            prod[indice].idProov=auxInt;
            printf("\n---Alta exitosa!\n\n\n");
        }
    }
}
//Brief: Muestra el sub menu de la funcion que modifica productos.
//Parameters: Nada
//Return: Devuelve un char con la opcion elegida
//
char menuModif(void)
{
    char opcion;

    system("cls");
    printf("Seleccione que desea modificar\n\n");
    printf(" 1 - Descripcion\n");
    printf(" 2 - Importe\n");
    printf(" 3 - Stock\n");
    printf(" 4 - Atras\n\n\n");
    printf("Opcion ingresada: ");
    fflush(stdin);
    scanf("%c",&opcion);

    return opcion;
}
//Brief: Moifica un producto
//Parameters: Un array de estructuras producto, un int tamanio del array y otro array de estructuras proovedor
//Return: No Devuelve nada.
//
void modifprod(eProducto prod[],int tam,eProovedor proov[])
{
    int i, hallado, error=0, seguir=1, auxInt, isFloat;
    char aux[50], confirma, opcion;

    system("cls");
    printf("---Modificacion de Datos---\n");
    //ID
    printf("\nIngrese id: ");
    scanf("%s",aux);
    error=isNum(aux);
    isFloat=intOrFloat(aux);
    while(error==1||isFloat!=0)
    {
        printf("\nIngrese id correctamente: ");
        scanf("%s",aux);
        error=isNum(aux);
        isFloat=intOrFloat(aux);
    }
    auxInt=atoi(aux);
    hallado=buscaprod(prod,tam,auxInt); //Comprueba si ya existe ese Id
    if(hallado==-1) //El Id no existe
    {
        printf("\nEl ID %d no corresponde a ningun producto registrado\n",auxInt);
    }
    else  //El Id existe
    {
        printf("\n");
        mostrarprod(prod,hallado,1,proov);
        printf("\nConfirma la modificacion?\n"); //Pregunta si desea modificar
        fflush(stdin);
        scanf("%c",&confirma);
        confirma=isThat(confirma,'s','n');
        if(confirma=='s')   //Confirma
        {
            do
            {
                opcion=menuModif();
                while(opcion<49||opcion>52||!isdigit(opcion))
                {
                    system("cls");
                    printf("Ingrese correctamente una de las siguientes opciones\n\n");
                    opcion=menuModif();
                }
                switch(opcion)
                {
                    case '1':
                        {
                            system("cls");
                            printf("---Descripcion---\n");
                            printf("| %s |\n",prod[hallado].descripcion);
                            printf("Ingrese nueva descripcion: ");
                            fflush(stdin);
                            scanf("%[^\n]",aux);
                            error=isLwrThan(aux,50);
                            while(error==1)
                            {
                                printf("Ingrese descripcion correctamente: ");
                                fflush(stdin);
                                scanf("%[^\n]",aux);
                                error=isLwrThan(aux,50);
                            }
                            strlwr(aux);
                            for(i=0 ; aux[i]!='\0' ; i++)
                            {
                                if(i==0)
                                {
                                    aux[i]=toupper(aux[i]);
                                }
                                if(aux[i]==' ')
                                {
                                    aux[i+1]=toupper(aux[i+1]);
                                }
                            }
                            strcpy(prod[hallado].descripcion,aux);
                            printf("\n---Modificacion exitosa!\n\n\n");
                            system("pause");
                            break;
                        }
                    case '2':
                        {
                            system("cls");
                            printf("---Importe---\n");
                            printf("| %.2f |\n",prod[hallado].importe);
                            printf("\nIngrese nuevo importe en la forma \"xx.xx\": ");
                            scanf("%s",aux);
                            error=isNum(aux);
                            isFloat=intOrFloat(aux);
                            while(error==1||isFloat!=1)
                            {
                                printf("\nIngrese importe correctamente en la forma \"xx.xx\": ");
                                scanf("%s",aux);
                                error=isNum(aux);
                                isFloat=intOrFloat(aux);
                            }
                            prod[hallado].importe=atof(aux);
                            printf("\n---Modificacion exitosa!\n\n\n");
                            system("pause");
                            break;
                        }
                    case '3':
                        {
                            system("cls");
                            printf("---Stock---\n");
                            printf("| %d |\n",prod[hallado].stock);
                            printf("\nIngrese nuevo stock: ");
                            scanf("%s",aux);
                            error=isNum(aux);
                            isFloat=intOrFloat(aux);
                            while(error==1||isFloat!=0)
                            {
                                printf("\nIngrese stock correctamente: ");
                                scanf("%s",aux);
                                error=isNum(aux);
                                isFloat=intOrFloat(aux);
                            }
                            prod[hallado].stock=atoi(aux);
                            printf("\n---Modificacion exitosa!\n\n\n");
                            system("pause");
                            break;
                        }
                    case '4':
                        {
                            seguir=0;
                            break;
                        }
                }
            }
            while(seguir==1);
        }
        else //Cancelo todo
        {
            printf("\n---Se ha cancelado la modificacion!\n\n\n");
        }
    }
}
//Brief: Realiza la baja de productos
//Parameters: Un array de estructuras producto, un int tamanio del array y otro array de estructuras proovedor
//Return: No Devuelve nada.
//
void bajaprod(eProducto prod[],int tam,eProovedor proov[])
{
    int hallado, error=0, isFloat, auxInt, idAuxProov, contProdProov=0, i;
    char aux[50], confirma;

    system("cls");
    printf("---Baja de producto---\n");
    //ID
    printf("\nIngrese id: ");
    scanf("%s",aux);
    error=isNum(aux);
    isFloat=intOrFloat(aux);
    while(error==1||isFloat!=0)
    {
        printf("\nIngrese id correctamente: ");
        scanf("%s",aux);
        error=isNum(aux);
        isFloat=intOrFloat(aux);
    }
    auxInt=atoi(aux);
    hallado=buscaprod(prod,tam,auxInt);  //Comprueba si ya existe ese ID
    if(hallado==-1)  //El ID no existe
    {
        printf("\nEl id %d no corresponde a ningun producto registrado\n",auxInt);
    }
    else  //El ID ya existe
    {
        printf("\n");
        mostrarprod(prod,hallado,1,proov);
        printf("\nConfirma la baja?\n");
        fflush(stdin);
        scanf("%c",&confirma);
        confirma=isThat(confirma,'s','n');
        if(confirma=='s')  //Desea borrarlo
        {
            idAuxProov=prod[hallado].idProov;
            for(i=0 ; i<tam ; i++)
            {
                if(prod[i].isEmpty==LLENO&&prod[i].idProov==idAuxProov)
                {
                    contProdProov++;
                }
            }
            if(contProdProov==1)
            {
                proov[idAuxProov-1].isEmpty=VACIO;
            }
            prod[hallado].isEmpty=VACIO;
            printf("\n---Baja exitosa!\n");
        }
        else  //Cancela todo
        {
            printf("\n---Se ha cancelado la baja\n");
        }
    }
}
//Brief: Muestra el sub menu de la funcion informProd
//Parameters: Nada
//Return: Devuelve un char con la opcion elegida
//
char menuInform(void)
{
    char opcion;

    system("cls");
    printf("Seleccione que desea infomar\n\n");
    printf(" 1 - Total y promedio de los importes y cuantos productos superan dicho promedio\n");
    printf(" 2 - Total y promedio de los importes y cuantos productos no superan dicho promedio\n");
    printf(" 3 - Cantidad de productos cuyo stock es menor o igual a 10\n");
    printf(" 4 - Cantidad de productos cuyo stock es mayor a 10\n");
    printf(" 5 - Atras\n\n\n");
    printf("Opcion ingresada: ");
    fflush(stdin);
    scanf("%c",&opcion);

    return opcion;
}
//Brief: Realiza los informes sobre el el total y promedio de importes y cuantos superan o no dicho promedio.
//Parameters: Un array de estructuras producto, un int tamanio del array y un int selector de casos
//Return: No Devuelve nada.
//
void inform1 (eProducto prod[], int tam, int caso)
{
    int i, contMayorProm=0, contMenorProm=0, contTotal=0;
    float prom, total=0;

    system("cls");
    printf("---Informes de productos---\n");
    for(i=0 ; i<tam ; i++)
    {
        if(prod[i].isEmpty==LLENO)
        {
            total=total+prod[i].importe;
            contTotal++;
        }
    }
    prom=total/contTotal;
    for(i=0 ; i<tam ; i++)
    {
        if(caso==1)
        {
            if(prod[i].isEmpty==LLENO && prod[i].importe>prom)
            {
                contMayorProm++;
            }
        }
        else if (caso==2)
        {
            if(prod[i].isEmpty==LLENO && prod[i].importe<=prom)
            {
                contMenorProm++;
            }
        }
    }

    printf("\nEl total de importes es %.2f y el promedio de los mismos es %.2f\n",total,prom);
    if(caso==1)
    {
       printf("La cantidad de productos que superan a dicho promedio es %d\n\n",contMayorProm);
    }
    else if(caso==2)
    {
       printf("La cantidad de productos que no lo superan a dicho promedio es %d\n\n",contMenorProm);
    }
}
//Brief: Realiza los informes sobre el stock de productos
//Parameters: Un array de estructuras producto, un int tamanio del array y un int selector de casos
//Return: No Devuelve nada.
//
void inform2 (eProducto prod[], int tam, int caso)
{
    int i, contMenor=0, contMayor=0;

    system("cls");
    printf("---Informes de productos---\n");
    for(i=0 ; i<tam ; i++)
    {
        if(prod[i].isEmpty==LLENO && prod[i].stock<=10)
        {
            contMenor++;
        }
        else if(prod[i].isEmpty==LLENO && prod[i].stock>10)
        {
            contMayor++;
        }
    }
    if(caso==1)
    {
        printf("\nLa cantidad de productos cuyo stock es menor o igual a 10 es de %d\n\n",contMenor);
    }
    else if(caso==2)
    {
        printf("\nLa cantidad de productos cuyo stock es mayor a 10 es de %d\n\n",contMayor);
    }
}
//Brief: Realiza los informes de todos los productos
//Parameters: Un array de estructuras producto, un int tamanio del array.
//Return: No Devuelve nada.
//
void informProd(eProducto prod[],int tam)
{
    int i, vacio=1, seguir=1;
    char opcion;

    system("cls");
    printf("---Informes de productos---\n");
    for(i=0 ; i<tam ; i++)
    {
        if(prod[i].isEmpty==LLENO)
        {
            vacio=0;
        }
    }
    if(vacio==1)
    {
        printf("\nLa base de datos esta vacia, ingrese productos antes\n");
    }
    else
    {
        do
        {
            printf("Elija una de las siguientes opciones\n\n");
            opcion=menuInform();
            while(opcion<49||opcion>53||isdigit(opcion)==0)
            {
                system("cls");
                printf("Ingrese correctamente una de las siguientes opciones\n\n");
                opcion=menuInform();
            }
            switch(opcion)
            {
                case '1':
                {
                    inform1(prod,tam,1);
                    system("pause");
                    system("cls");
                    break;
                }
                case '2':
                {
                    inform1(prod,tam,2);
                    system("pause");
                    system("cls");
                    break;
                }
                case '3':
                {
                    inform2(prod,tam,1);
                    system("pause");
                    system("cls");
                    break;
                }
                case '4':
                {
                    inform2(prod,tam,2);
                    system("pause");
                    system("cls");
                    break;
                }
                case '5':
                {
                    seguir=0;
                    break;
                }
            }
        }
        while(seguir==1);
    }
}
//Brief: Muestra el sub menu de la funcion listarProd
//Parameters: Nada
//Return: Devuelve un char con la opcion elegida
//
int menuListar(void)
{
    int opcion;

    printf(" 1) Listado de todos los productos segun ambos criterios\n");
    printf(" 2) Todos los productos con stock menor o igual a 10\n");
    printf(" 3) Todos los productos con stock mayor a 10\n");
    printf(" 4) Todos los productos que superan el promedio de importes\n");
    printf(" 5) Todos los productos que no superan el promedio de importes\n");
    printf(" 6) Todos los proveedores cuyo stock de productos es menor o igual a 10\n");
    printf(" 7) Todos los productos provistos por cada proveedor\n");
    printf(" 8) Todos los productos provistos por un proveedor determinado\n");
    printf(" 9) El proveedor que provee mas productos\n");
    printf(" 10) El proveedor que provee menos productos\n");
    printf(" 11) El proveedor que provee el producto mas caro\n");
    printf(" 12) El proveedor que provee el producto menos caro\n");
    printf(" 13) Salir\n\n\n");
    printf("Opcion ingresada: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
//Brief: Lista todos los productos ordenados segun ambos criterios
//Parameters: Un array de estructuras producto, un int tamanio del array
//Return: No Devuelve nada.
//
void listar1(eProducto prod[],int tam)
{
    int i, j;
    eProducto aux;

    system("cls");
    printf("---Listado de productos---\n");
    printf("\n| IMPORTE | DESCRIPCION |\n");
    for(i=0 ; i<(tam-1) ; i++)
    {
        for(j=i+1 ; j<tam ; j++)
        {
            if(prod[i].importe<prod[j].importe)
            {
               aux=prod[j];
               prod[j]=prod[i];
               prod[i]=aux;
            }
            else if(prod[i].importe==prod[j].importe)
            {
                if(strcmp(prod[i].descripcion,prod[j].descripcion)>0)
                {
                   aux=prod[j];
                   prod[j]=prod[i];
                   prod[i]=aux;
                }
            }
        }
    }
    for(i=0 ; i<tam ; i++)
    {
        if(prod[i].isEmpty==LLENO)
        {
            printf("| %.2f | %s |\n",prod[i].importe,prod[i].descripcion);
        }
    }
    printf("\n");
}
//Brief: Lista todos los productos cuyo stock supera a 10 o es menor/igual a 10, segun el caso
//Parameters: Un array de estructuras producto, un int tamanio del array
//Return: No Devuelve nada.
//
void listar2(eProducto prod[],int tam, int caso)
{
    int i, prodMenor10=0, prodMayor10=0;

    system("cls");
    printf("---Listado de productos---\n");
    for(i=0 ; i<tam ; i++)
    {
        if(prod[i].isEmpty==LLENO)
        {
            if(prod[i].stock<=10)
            {
               prodMenor10++;
            }
            else
            {
               prodMayor10++;
            }
        }
    }
    if(caso==1)
    {
        printf("\nCantidad de productos cuyo stock es menor o igual a 10: %d\n\n",prodMenor10);
    }
    else if(caso==2)
    {
        printf("\nCantidad de productos cuyo stock es mayor a 10: %d\n\n",prodMayor10);
    }
}
//Brief: Lista todos los productos cuyo importe supera el promedio o no, segun el caso
//Parameters: Un array de estructuras producto, un int tamanio del array
//Return: No Devuelve nada.
//
void listar3(eProducto prod[],int tam, int caso)
{
    int i, k, cont=0, prodSupProm=0, prodNoSupProm=0;
    float total=0, prom=0;

    system("cls");
    printf("---Listado de productos---\n");
    for(k=0 ; k<tam ; k++)
    {
        if(prod[k].isEmpty==LLENO)
        {
            total=total+prod[k].importe;
            cont++;
        }
    }
    prom=total/cont;
    for(i=0 ; i<tam ; i++)  // i-> Productos j-> Proovedores         acaaaa
    {
        if(prod[i].isEmpty==LLENO)
        {
            if(prod[i].importe>prom)
            {
                prodSupProm++;
            }
            else
            {
                prodNoSupProm++;
            }
        }
    }
    if(caso==1)
    {
        printf("\nCantidad de productos cuyo importe supera el promedio: %d\n\n",prodSupProm);
    }
    else if(caso==2)
    {
        printf("\nCantidad de productos cuyo importe no supera el promedio: %d\n\n",prodNoSupProm);
    }
}
//Brief: Lista todos los proovedores que provean productos cuyo stock sea menor o igual a 10
//Parameters: Un array de estructuras producto, un int tamanio del array
//Return: No Devuelve nada.
//
void listar4(eProducto prod[],int tam, eProovedor proov[])
{
    int i, j, proovIngresado[5]={0}, proovMenor10=0;

    system("cls");
    printf("---Listado de productos---\n");
    for(i=0 ; i<tam ; i++)  // i-> Productos j-> Proovedores
    {
        if(prod[i].isEmpty==LLENO)
        {
            for(j=0 ; j<5 ; j++)
            {
                if(proov[j].isEmpty==LLENO&&prod[i].idProov==proov[j].id) //Encontre al proovedor de ese producto
                {
                    if(prod[i].stock<=10&&proovIngresado[j]==0)
                    {
                        proovMenor10++;
                        proovIngresado[j]=1;
                    }
                }
            }
        }
    }
    printf("\nCantidad de proovedores cuyo stock es menor o igual a 10: %d\n\n",proovMenor10);
}
//Brief: Lista todos los productos de todos los provvedores
//Parameters: Un array de estructuras producto, un int tamanio del array
//Return: No Devuelve nada.
//
void listar5(eProducto prod[], int tam, eProovedor proov[])
{
    int i, j, primeraVez=1;

    system("cls");
    printf("---Listado de productos---\n");
    for(i=0 ; i<5 ; i++) // i-> Proovedores j-> Productos
    {
        primeraVez=1;
        for(j=0; j<tam ; j++)
        {
            if(prod[j].isEmpty==LLENO&&prod[j].idProov==proov[i].id)
            {
                if(primeraVez==1)
                {
                    printf("\n| %s |\n",proov[i].descripcion);
                    printf("%s\n",prod[j].descripcion);
                    primeraVez=0;
                }
                else
                {
                   printf("%s\n",prod[j].descripcion);
                }
            }
        }
    }
    printf("\n");
}
//Brief: Lista todos los productos del proovedor elegido
//Parameters: Un array de estructuras producto, un int tamanio del array
//Return: No Devuelve nada.
//
void listar6(eProducto prod[], int tam, eProovedor proov[])
{
    int i, j, auxInt, error, isFloat, proovElegido;
    char auxString[10];

    system("cls");
    printf("---Listado de productos---\n");
    printf("\nElija el id del proovedor al cual listarle sus productos\n");
    printf("\n| ID | PROOVEDOR |\n");
    for(i=0 ; i<5 ; i++)
    {
        printf("| %d | %s |\n",proov[i].id,proov[i].descripcion);
    }
    printf("\nOpcion ingresada: ");
    scanf("%s",auxString);
    auxInt=atoi(auxString);
    error=isNum(auxString);
    isFloat=intOrFloat(auxString);
    while(error==1||isFloat!=0||auxInt<1||auxInt>5||proov[auxInt-1].isEmpty==VACIO)
    {
        printf("\nIngrese id del proovedor listado arriba: ");
        printf("\nOpcion ingresada: ");
        scanf("%s",auxString);
        error=isNum(auxString);
        isFloat=intOrFloat(auxString);
        auxInt=atoi(auxString);
    }
    proovElegido=auxInt;
    for(j=0 ; j<tam ; j++)
    {
        if(prod[j].isEmpty==LLENO&&prod[j].idProov==proovElegido)
        {
            printf("\n| %s |\n",prod[j].descripcion);
        }
    }
    printf("\n");
}
//Brief: Lista el proovedore que poseen mayor cantidad de productos o el de menor cantidad segun el caso
//Parameters: Un array de estructuras producto, un int tamanio del array y un int selector de casos
//Return: No Devuelve nada.
//
void listar7(eProducto prod[], int tam, int caso, eProovedor proov[])
{
    int i, j, k, primeraVez=1, mayorCant, menorCant, cantProdProov[5]={0};

    system("cls");
    printf("---Listado de productos---\n");
    for(i=0 ; i<tam ; i++)  // i-> Productos j-> Proovedores
    {
        if(prod[i].isEmpty==LLENO)
        {
            for(j=0 ; j<5 ; j++)
            {
                if(proov[j].isEmpty==LLENO&&prod[i].idProov==proov[j].id) //Encontre al proovedor de ese producto
                {
                    if(proov[j].isEmpty==LLENO)
                    {
                       cantProdProov[j]=cantProdProov[j]+1; //Estoy incrementando la cant de productos para ese proovedor j al haber un match producto-proovedor
                    }
                }
            }
        }
    }
    for(i=0 ; i<5 ; i++) //Hallo al proovedor de mayor y menor cant de productos
    {
        if(proov[i].isEmpty==LLENO)
        {
            if(primeraVez==1)
            {
                mayorCant=cantProdProov[i];
                menorCant=cantProdProov[i];
                //printf("\n--Informe de datos\n\n");
                primeraVez=0;
            }
            if(cantProdProov[i]>mayorCant)
            {
                mayorCant=cantProdProov[i];
            }
            if(cantProdProov[i]<menorCant)
            {
                menorCant=cantProdProov[i];
                //printf("menorCant vale %d\n",menorCant);
            }
        }
    }
    for(i=0 ; i<5 ; i++) //Busco un match e imprimo al de menor y mayor cant en proovedores
    {
        if(mayorCant==cantProdProov[i] && caso==1)
        {
            printf("\nEl proovedor que provee mas productos es \"%s\" y sus productos son:\n",proov[i].descripcion);
            for(j=0 ; j<tam ; j++)
            {
                if(prod[j].isEmpty==LLENO&&prod[j].idProov==proov[i].id)
                {
                    printf("| %s |\n",prod[j].descripcion);
                }
            }
        }
        else if(menorCant==cantProdProov[i] && caso==2)
        {
            printf("\nEl proovedor que provee menos productos es \"%s\" y sus productos son:\n",proov[i].descripcion);
            for(k=0 ; k<tam ; k++)
            {
                if(prod[k].isEmpty==LLENO&&prod[k].idProov==proov[i].id)
                {
                    printf("| %s |\n",prod[k].descripcion);
                }
            }
        }
    }
    printf("\n");
}
//Brief: Lista el proovedor que poseen el producto mas caro o mas barato segun el caso
//Parameters: Un array de estructuras producto, un int tamanio del array y un int selector de casos
//Return: No Devuelve nada.
//
void listar8(eProducto prod[], int tam, int caso, eProovedor proov[])
{
    int i, j, k, primeraVez=1;
    float masCaro, masBarato;

    system("cls");
    printf("---Listado de productos---\n");
    for(i=0 ; i<tam ; i++)  // i-> Productos j-> Proovedores
    {
        if(prod[i].isEmpty==LLENO)
        {
            for(j=0 ; j<5 ; j++)
            {
                if(proov[j].isEmpty==LLENO&&prod[i].idProov==proov[j].id) //Encontre al proovedor de ese producto
                {
                    if(primeraVez==1)
                    {
                        masCaro=prod[i].importe;
                        masBarato=prod[i].importe;
                        primeraVez=0;
                    }
                    if(prod[i].importe>masCaro)
                    {
                        masCaro=prod[i].importe;
                    }
                    if(prod[i].importe<masBarato)
                    {
                        masBarato=prod[i].importe;
                    }
                }
            }
        }
    }
    for(i=0 ; i<tam ; i++)
    {
        if(prod[i].isEmpty==LLENO&&masCaro==prod[i].importe && caso==1)
        {
            for(j=0 ; j<5 ; j++)
            {
                if(prod[i].idProov==proov[j].id)
                {
                   printf("\nEl proovedor que provee el producto mas caro es \"%s\" y dicho producto es | %s |\n",proov[j].descripcion,prod[i].descripcion);
                }
            }
        }
        else if(prod[i].isEmpty==LLENO&&masBarato==prod[i].importe && caso==2)
        {
            for(k=0 ; k<5 ; k++)
            {
                if(prod[i].idProov==proov[k].id)
                {
                    printf("\nEl proovedor que provee el producto mas barato es \"%s\" y dicho producto es | %s |\n",proov[k].descripcion,prod[i].descripcion);
                }
            }
        }
    }
    printf("\n");
}
//Brief: Realiza los informes de todos los productos
//Parameters: Un array de estructuras producto, un int tamanio del array.
//Return: No Devuelve nada.
//
void listarProd(eProducto prod[],int tam, eProovedor proov[])
{
    int i, vacio=1, seguir=1;
    char opcion;

    system("cls");
    printf("---Listado de productos---\n");
    for(i=0 ; i<tam ; i++)
    {
        if(prod[i].isEmpty==LLENO)
        {
            vacio=0;
        }
    }
    if(vacio==1)
    {
        printf("\nLa base de datos esta vacia, ingrese productos antes\n");
    }
    else
    {
        do
        {
            system("cls");
            printf("Elija una de las siguientes opciones\n\n");
            opcion=menuListar();
            switch(opcion)
            {
                case 1:
                {
                    listar1(prod,tam);
                    system("pause");
                    system("cls");
                    break;
                }
                case 2:
                {
                    listar2(prod,tam,1);
                    system("pause");
                    system("cls");
                    break;
                }
                case 3:
                {
                    listar2(prod,tam,2);
                    system("pause");
                    system("cls");
                    break;
                }
                case 4:
                {
                    listar3(prod,tam,1);
                    system("pause");
                    system("cls");
                    break;
                }
                case 5:
                {
                    listar3(prod,tam,2);
                    system("pause");
                    system("cls");
                    break;
                }
                case 6:
                {
                    listar4(prod,tam,proov);
                    system("pause");
                    system("cls");
                    break;
                }
                case 7:
                {
                    listar5(prod,tam,proov);
                    system("pause");
                    system("cls");
                    break;
                }
                case 8:
                {
                    listar6(prod,tam,proov);
                    system("pause");
                    system("cls");
                    break;
                }
                case 9:
                {
                    listar7(prod,tam,1,proov);
                    system("pause");
                    system("cls");
                    break;
                }
                case 10:
                {
                    listar7(prod,tam,2,proov);
                    system("pause");
                    system("cls");
                    break;
                }
                case 11:
                {
                    listar8(prod,tam,1,proov);
                    system("pause");
                    system("cls");
                    break;
                }
                case 12:
                {
                    listar8(prod,tam,2,proov);
                    system("pause");
                    system("cls");
                    break;
                }
                case 13:
                {
                    seguir=0;
                    break;
                }
                default :
                {
                    system("cls");
                    printf("---Listado de productos---\n\n");
                    printf("Opcion Incorrecta\n\n");
                    system("pause");
                }
            }
        }
        while(seguir==1);
    }
}
