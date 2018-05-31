#include "Funciones.h"

//Brief: Obtiene el tamaño del file
//Parameters: void
//Return: Devuelve el tamaño
//
int tamMovie(void)
{
    int n=1, total;
    FILE *listMovie;

    listMovie=fopen("MovieList.dat","rb");
    if(listMovie==NULL)
    {
        printf("\nError\n");
        return -1;
    }
    else
    {
        listMovie=fopen("MovieList.dat","r+b");
        if(listMovie==NULL)
        {
            printf("\nError\n");
            return -1;
        }
    }
    fseek(listMovie,0L,SEEK_END);
    total=ftell(listMovie);
    n=total/sizeof(eMovie);

    fclose(listMovie);
    return n;
}
//Brief: Inicializa el arrayMovie
//Parameters: 1 puntero a estructura eMovie
//Return: void
//
void initArrayMovie(eMovie *peli)
{
    if(peli!=NULL)
    {
        peli->isEmpty=VACIO;
    }
    else
    {
        printf("No se puede inicilizar, hay un error en el puntero al array\n");
        return;
    }
}
//Brief: Setea la URL
//Parameters: 1 puntero a estructura eMovie
//Return: void
//
void setURL(eMovie *peli)
{
    int nombreURL, error, isFloat;
    char URL[200]="./FOTOS/", aux[20], auxString[200];

    printf("\n-URL\n");
    printf("1) Abra la carpeta \"FOTOS\"\n");
    printf("2) Seleccione la foto a añadir segun el numero correspondiente\n\nOpcion ingresada : ");
    fflush(stdin);
    scanf("%s",auxString);
    error=isNum(auxString);
    isFloat=intOrFloat(auxString);
    while(error==1||isFloat!=0)
    {
        printf("\nIngrese numero correctamente: ");
        scanf("%s",auxString);
        error=isNum(auxString);
        isFloat=intOrFloat(auxString);
    }
    nombreURL=atoi(auxString);
    sprintf(aux,"%d.jpg",nombreURL);
    strcat(URL,aux);
    strcpy(peli->url,URL);
}
/*
void setID(int n)
{
    int i, cant, posicion;
    float pos;
    eMovie *peli;
    FILE *listMovie;

    printf("n dentro de setID vale %d\n",n);
    listMovie=fopen("MovieList.dat","rb");
    if(listMovie==NULL)
    {
        printf("\nNo existe lista de peliculas, primero cree una\n");
        return;
    }
    else
    {
        listMovie=fopen("MovieList.dat","r+b");
        if(listMovie==NULL)
        {
            printf("\nNo puede abrirse la lista de peliculas\n");
            return;
        }
    }
    peli=(eMovie *)malloc(sizeof(eMovie)*n);
    if(peli==NULL)
    {
        printf("No se puede reservar memoria para dicha estructura\n");
        return;
    }
    else
    {
        printf("---------------------------------------------\n");
        fseek(listMovie,0L,SEEK_SET);
        posicion=ftell(listMovie);
        pos=posicion/sizeof(eMovie);
        printf("Posicion antes del for=%.2f\n",pos);
        for(i=0 ; i<n ; i++)
        {
            cant=fread(peli+i,sizeof(eMovie),1,listMovie);
            if(cant!=1)
            {
                printf("EEEEEEEEEEEEEEEEEEEEE\n");
                system("pause");
            }
            posicion=ftell(listMovie);
            pos=posicion/sizeof(eMovie);
            printf("Posicion dentro del for y dps del 1er fread=%.2f\n",pos);
            printf("Antes de evaluar cant: peli+i -> titulo es \"%s\", peli+i -> isEmpty es %d\n",(peli+i)->titulo,(peli+i)->isEmpty);
            if(cant!=1)
            {
                printf("\nError\n");
                return;
            }
            else
            {
                printf("Despues de evaluar cant: peli+i -> titulo es \"%s\", peli+i -> isEmpty es %d\n",(peli+i)->titulo,(peli+i)->isEmpty);
                if((peli+i)->isEmpty==VACIO)
                {
                    printf("Entre al continue? Vuelta i=%d\n",i);
                    printf("---------------------------------------------\n");
                    continue;
                }
                else if((peli+i)->isEmpty==LLENO)
                {
                    printf("Entre al LLENO? Vuelta i=%d\n",i);
                    (peli+i)->id=i;
                    printf("Dentro de LLENO: peli+i -> id es %d, peli+i -> titulo es \"%s\", peli+i -> isEmpty es %d\n",(peli+i)->id,(peli+i)->titulo,(peli+i)->isEmpty);
                    fseek(listMovie,sizeof(eMovie)*-1,SEEK_CUR);
                    posicion=ftell(listMovie);
                    pos=posicion/sizeof(eMovie);
                    printf("Posicion en LLENO y tras el fseek -1=%.2f\n",pos);
                    fwrite(peli+i,sizeof(eMovie),1,listMovie);
                    posicion=ftell(listMovie);
                    pos=posicion/sizeof(eMovie);
                    printf("Posicion en LLENO y tras el fwrite =%.2f\n",pos);
                    printf("Dentro de LLENO y dps de escribir el FILE: peli+i -> id es %d, peli+i -> titulo es \"%s\", peli+i -> isEmpty es %d\n",(peli+i)->id,(peli+i)->titulo,(peli+i)->isEmpty);
                    printf("---------------------------------------------\n");
                }
            }
        }
    }

    fclose(listMovie);
}
*/
//Brief: Setea los datos de un puntero a estructura eMovie
//Parameters: 1 puntero a estructura eMovie
//Return: void
//
void setDataMovie(eMovie *peli)
{
    int error, isFloat, isCero;
    char auxString[400], aux[100];

    //ID
    printf("\nIngrese id distinto de 0 (cero): ");
    scanf("%s",aux);
    error=isNum(aux);
    isFloat=intOrFloat(aux);
    isCero=esCero(aux);
    while(error==1||isFloat!=0||isCero==1)
    {
        printf("\nIngrese id correctamente: ");
        scanf("%s",aux);
        error=isNum(aux);
        isFloat=intOrFloat(aux);
        isCero=esCero(aux);
    }
    peli->id=atoi(aux);
    //TITULO
    printf("\nIngrese titulo: ");
    fflush(stdin);
    scanf("%[^\n]",auxString);
    error=isLwrThan(auxString,50);
    while(error==1)
    {
        printf("\nSe ha excedido de los 50 caracteres, ingrese titulo nuevamente: ");
        fflush(stdin);
        scanf("%[^\n]",auxString);
        error=isLwrThan(auxString,50);
    }
    strcpy(peli->titulo,formatName(auxString));
    //GENERO
    printf("\nIngrese genero: ");
    fflush(stdin);
    scanf("%[^\n]",auxString);
    error=isLwrThan(auxString,15);
    while(error==1)
    {
        printf("\nSe ha excedido de los 15 caracteres, ingrese genero nuevamente: ");
        fflush(stdin);
        scanf("%[^\n]",auxString);
        error=isLwrThan(auxString,15);
    }
    strcpy(peli->genero,formatName(auxString));
    //DURACION
    printf("\nIngrese duracion: ");
    fflush(stdin);
    scanf("%s",auxString);
    error=isNum(auxString);
    isFloat=intOrFloat(auxString);
    while(error==1||isFloat!=0)
    {
        printf("\nIngrese duracion correctamente: ");
        scanf("%s",auxString);
        error=isNum(auxString);
        isFloat=intOrFloat(auxString);
    }
    peli->duracion=atoi(auxString);
    //DESCRIPCION
    printf("\nIngrese descripcion: ");
    fflush(stdin);
    scanf("%[^\n]",auxString);
    error=isLwrThan(auxString,300);
    while(error==1)
    {
        printf("\nSe ha excedido de los 300 caracteres, ingrese descripcion nuevamente: ");
        fflush(stdin);
        scanf("%[^\n]",auxString);
        error=isLwrThan(auxString,300);
    }
    strcpy(peli->descripcion,auxString);
    //PUNTAJE
    printf("\nIngrese puntaje: ");
    fflush(stdin);
    scanf("%s",auxString);
    error=isNum(auxString);
    isFloat=intOrFloat(auxString);
    while(error==1||isFloat!=0)
    {
        printf("\nIngrese puntaje correctamente: ");
        scanf("%s",auxString);
        error=isNum(auxString);
        isFloat=intOrFloat(auxString);
    }
    peli->puntaje=atoi(auxString);
    //URL
    setURL(peli);
    //ESTADO
    peli->isEmpty=LLENO;
    printf("\n----------\n");
}
//Brief: Agrega estructuras eMovie
//Parameters: void
//Return: void
//
void addMovie(void)
{
    int i, dim=1;
    char confirma;
    eMovie *peli, *auxPeli;
    FILE *listMovie;

    system("cls");
    printf("---Agregar pelicula---\n\n");
    listMovie=fopen("MovieList.dat","rb");
    if(listMovie==NULL)
    {
        listMovie=fopen("MovieList.dat","wb");
        if(listMovie==NULL)
        {
            printf("El archivo no puede ser abierto\n");
            return;
        }
    }
    else
    {
        listMovie=fopen("MovieList.dat","r+b");
    }
    peli=(eMovie *)malloc(sizeof(eMovie)*1);
    if(peli==NULL)
    {
        printf("No se puede reservar memoria para dicha estructura\n");
        return;
    }
    else
    {
        initArrayMovie(peli);
        fseek(listMovie,0L,SEEK_END);
        for(i=0 ; (peli+i)->isEmpty==VACIO ; i++)
        {
            printf("\n----------\n");
            setDataMovie(peli+i);
            fwrite(peli+i,sizeof(eMovie),1,listMovie);
            printf("\nDesea continuar ingresando peliculas?\n\n-Opcion ingresada: ");
            fflush(stdin);
            scanf("%c",&confirma);
            confirma=isThat(confirma,'s','n');
            printf("\n");
            if(confirma=='n')
            {
                printf("\n-Alta exitosa!\n\n");
                break;
            }
            else
            {
                dim++;
                auxPeli=(eMovie *)realloc(peli,(sizeof(eMovie)*dim));
                if(auxPeli==NULL)
                {
                    printf("No hay espacio en memoria para agregar nueva pelicula\n");
                    return;
                }
                else
                {
                    peli=auxPeli;
                    initArrayMovie(peli+i+1);
                }
            }
        }
    }

    free(peli);
    fclose(listMovie);
}
//Brief: Borra una estructuras eMovie
//Parameters: 1 entero tamaño
//Return: void
//
void deleteMovie(int n)
{
    int i, j, indice, cant, auxInt, error, isFloat, firstTime=1;
    char confirma, auxString[100];
    eMovie *peli;
    FILE *listMovie;

    system("cls");
    printf("---Borrar pelicula---\n\n");
    listMovie=fopen("MovieList.dat","rb");
    if(listMovie==NULL)
    {
        printf("\nNo existe lista de peliculas, primero cree una\n");
        return;
    }
    else
    {
        listMovie=fopen("MovieList.dat","r+b");
        if(listMovie==NULL)
        {
            printf("\nNo puede abrirse la lista de peliculas\n");
            return;
        }
    }
    peli=(eMovie *)malloc(sizeof(eMovie)*n);
    if(peli==NULL)
    {
        printf("No se puede reservar memoria para dicha estructura\n");
        return;
    }
    else
    {
        fseek(listMovie,0L,SEEK_SET);
        for(i=0 ; i<n ; i++)
        {
            cant=fread(peli+i,sizeof(eMovie),1,listMovie);
            if(cant!=1)
            {
                printf("Error\n");
                return;
            }
        }
        fseek(listMovie,0L,SEEK_SET);
        printf("Indique el ID de la pelicula a borrar o 0 (cero) para salir\n\n|ID| TITULO |\n\n");
        for(i=0 ; i<n ; i++)
        {
            if((peli+i)->isEmpty==LLENO)
            {
                printf("|%d| %s | ",(peli+i)->id,(peli+i)->titulo);
                if(i==n-1)
                {
                    printf("\n\n");
                }
            }
        }
        printf("-Opcion ingresada: ");
        fflush(stdin);
        scanf("%s",auxString);
        error=isNum(auxString);
        isFloat=intOrFloat(auxString);
        while(error==1||isFloat!=0)
        {
            printf("\nIngrese ID correctamente: ");
            fflush(stdin);
            scanf("%s",auxString);
            error=isNum(auxString);
            isFloat=intOrFloat(auxString);
        }
        auxInt=atoi(auxString);
        printf("\n");
        if(auxInt==0)
        {
            printf("\n\n-Borrado cancelado!");
            return;
        }
        fseek(listMovie,0L,SEEK_SET);
        for(i=0 ; i<n ; i++)
        {
            if((peli+i)->isEmpty==LLENO&&(peli+i)->id==auxInt&&firstTime==1)
            {
                (peli+i)->isEmpty=VACIO;
                indice=i;
                for(j=0 ; j<n ; j++)
                {
                    if(j==indice)
                    {
                        printf("Confirma que desea borrar \"%s\"?\n\n-Opcion elegida: ",(peli+indice)->titulo);
                        fflush(stdin);
                        scanf("%c",&confirma);
                        confirma=isThat(confirma,'s','n');
                        if(confirma=='n')
                        {
                            printf("\n\n-Borrado cancelado!");
                            return;
                        }
                        else
                        {
                            fwrite(peli+indice,sizeof(eMovie),1,listMovie);
                            printf("\n\n-Borrado exitoso!");
                            firstTime=0;
                        }
                    }
                    fseek(listMovie,sizeof(eMovie)*1,SEEK_CUR);
                }
            }
            else if((peli+i)->isEmpty==LLENO&&(peli+i)->id!=auxInt&&firstTime==1&&i==(n-1))
            {
                i=-1;
                printf("Indique el ID correctamente de la pelicula a borrar o 0 (cero) para salir\n\n");
                printf("-Opcion ingresada: ");
                fflush(stdin);
                scanf("%s",auxString);
                error=isNum(auxString);
                isFloat=intOrFloat(auxString);
                while(error==1||isFloat!=0)
                {
                    printf("\nIngrese ID correctamente: ");
                    fflush(stdin);
                    scanf("%s",auxString);
                    error=isNum(auxString);
                    isFloat=intOrFloat(auxString);
                }
                auxInt=atoi(auxString);
                printf("\n");
                if(auxInt==0)
                {
                    printf("\n\n-Borrado cancelado!");
                    return;
                }
            }
        }
    }

    fclose(listMovie);
    free(peli);
}
//Brief: Modifica una estructura eMovie
//Parameters: 1 entero tamaño
//Return: void
//
void modMovie(int n)
{
    int i, j, indice, cant, seguir=1, error, isFloat, repetido=0, auxInt, firstTime=1;
    char confirma, auxString[100], opcion;
    eMovie *peli;
    FILE *listMovie;

    system("cls");
    printf("---Modificar pelicula---\n\n");
    listMovie=fopen("MovieList.dat","rb");
    if(listMovie==NULL)
    {
        printf("\nNo existe lista de peliculas, primero cree una\n");
        return;
    }
    else
    {
        listMovie=fopen("MovieList.dat","r+b");
        if(listMovie==NULL)
        {
            printf("\nNo puede abrirse la lista de peliculas\n");
            return;
        }
    }
    peli=(eMovie *)malloc(sizeof(eMovie)*n);
    if(peli==NULL)
    {
        printf("No se puede reservar memoria para dicha estructura\n");
        return;
    }
    else
    {
        fseek(listMovie,0L,SEEK_SET);
        for(i=0 ; i<n ; i++)
        {
            cant=fread(peli+i,sizeof(eMovie),1,listMovie);
            if(cant!=1)
            {
                printf("Error\n");
                return;
            }
        }
        fseek(listMovie,0L,SEEK_SET);
        printf("Indique el ID de la pelicula a modificar o 0 (cero) para salir\n\n|ID| TITULO |\n\n");
        for(i=0 ; i<n ; i++)
        {
            if((peli+i)->isEmpty==LLENO)
            {
                printf("|%d| %s | ",(peli+i)->id,(peli+i)->titulo);
                if(i==n-1)
                {
                    printf("\n\n");
                }
            }
        }
        printf("-Opcion ingresada: ");
        fflush(stdin);
        scanf("%s",auxString);
        error=isNum(auxString);
        isFloat=intOrFloat(auxString);
        while(error==1||isFloat!=0)
        {
            printf("\nIngrese ID correctamente: ");
            scanf("%s",auxString);
            error=isNum(auxString);
            isFloat=intOrFloat(auxString);
        }
        auxInt=atoi(auxString);
        printf("\n");
        if(auxInt==0)
        {
            printf("\n\n-Modificados cancelado!");
            return;
        }
        fseek(listMovie,0L,SEEK_SET);
        for(i=0 ; i<n ; i++)
        {
            if((peli+i)->isEmpty==LLENO&&(peli+i)->id==auxInt)
            {
                indice=i;
                for(j=0 ; j<n ; j++)
                {
                    if(j==indice&&firstTime==1)
                    {
                        printf("Confirma que desea modificar \"%s\"?\n\n-Opcion elegida: ",(peli+indice)->titulo);
                        fflush(stdin);
                        scanf("%c",&confirma);
                        confirma=isThat(confirma,'s','n');
                        if(confirma=='n')
                        {
                            printf("\n\n-Modificado cancelado!\n\n");
                            return;
                        }
                        else
                        {
                            do
                            {
                                opcion=submenu();
                                while(opcion<49||opcion>55||isdigit(opcion)==0)
                                {
                                    system("cls");
                                    printf("Ingrese correctamente una de las siguientes opciones\n\n");
                                    opcion=submenu();
                                }
                                switch(opcion)
                                {
                                    case '1':
                                    {
                                        printf("\n\"%s\"\n",(peli+indice)->titulo);
                                        printf("\nIngrese titulo: ");
                                        fflush(stdin);
                                        scanf("%[^\n]",auxString);
                                        /*
                                        for(i=0 ; i<n ; i++)
                                        {
                                            if(strcmp((peli+i)->titulo,auxString)==0)
                                            {
                                                repetido=1;
                                            }
                                        }
                                        */
                                        error=isLwrThan(auxString,50);
                                        while(error==1||repetido==1)
                                        {
                                            printf("\nSe ha excedido de los 50 caracteres, ingrese titulo nuevamente: ");
                                            fflush(stdin);
                                            scanf("%[^\n]",auxString);
                                            /*
                                            for(i=0 ; i<n ; i++)
                                            {
                                                if(strcmp((peli+i)->titulo,auxString)==0)
                                                {
                                                    repetido=1;
                                                }
                                            }
                                            */
                                            error=isLwrThan(auxString,50);
                                        }
                                        strcpy((peli+indice)->titulo,formatName(auxString));
                                        printf("\n\n");
                                        system("pause");
                                        system("cls");
                                        break;
                                    }
                                    case '2':
                                    {
                                        printf("\n\"%s\"\n",(peli+indice)->genero);
                                        printf("\nIngrese genero: ");
                                        fflush(stdin);
                                        scanf("%[^\n]",auxString);
                                        error=isLwrThan(auxString,15);
                                        while(error==1)
                                        {
                                            printf("\nSe ha excedido de los 15 caracteres, ingrese genero nuevamente: ");
                                            fflush(stdin);
                                            scanf("%[^\n]",auxString);
                                            error=isLwrThan(auxString,15);
                                        }
                                        strcpy((peli+indice)->genero,formatName(auxString));
                                        printf("\n\n");
                                        system("pause");
                                        system("cls");
                                        break;
                                    }
                                    case '3':
                                    {
                                        printf("\n\"%d\"\n",(peli+indice)->duracion);
                                        printf("\nIngrese duracion: ");
                                        fflush(stdin);
                                        scanf("%s",auxString);
                                        error=isNum(auxString);
                                        isFloat=intOrFloat(auxString);
                                        while(error==1||isFloat!=0)
                                        {
                                            printf("\nIngrese duracion correctamente: ");
                                            scanf("%s",auxString);
                                            error=isNum(auxString);
                                            isFloat=intOrFloat(auxString);
                                        }
                                        (peli+indice)->duracion=atoi(auxString);
                                        printf("\n\n");
                                        system("pause");
                                        system("cls");
                                        break;
                                    }
                                    case '4':
                                    {
                                        printf("\n\"%s\"\n",(peli+indice)->descripcion);
                                        printf("\nIngrese descripcion: ");
                                        fflush(stdin);
                                        scanf("%[^\n]",auxString);
                                        error=isLwrThan(auxString,300);
                                        while(error==1)
                                        {
                                            printf("\nSe ha excedido de los 300 caracteres, ingrese descripcion nuevamente: ");
                                            fflush(stdin);
                                            scanf("%[^\n]",auxString);
                                            error=isLwrThan(auxString,300);
                                        }
                                        strcpy((peli+indice)->descripcion,auxString);
                                        printf("\n\n");
                                        system("pause");
                                        system("cls");
                                        break;
                                    }
                                    case '5':
                                    {
                                        printf("\n\"%d\"\n",(peli+indice)->puntaje);
                                        printf("\nIngrese puntaje: ");
                                        fflush(stdin);
                                        scanf("%s",auxString);
                                        error=isNum(auxString);
                                        isFloat=intOrFloat(auxString);
                                        while(error==1||isFloat!=0)
                                        {
                                            printf("\nIngrese puntaje correctamente: ");
                                            scanf("%s",auxString);
                                            error=isNum(auxString);
                                            isFloat=intOrFloat(auxString);
                                        }
                                        (peli+indice)->puntaje=atoi(auxString);
                                        printf("\n\n");
                                        system("pause");
                                        system("cls");
                                        break;
                                    }
                                    case '6':
                                    {
                                        printf("\n\"%s\"\n",(peli+indice)->url);
                                        setURL(peli+indice);
                                        printf("\n\n");
                                        system("pause");
                                        system("cls");
                                        break;
                                    }
                                    case '7':
                                    {
                                        fwrite(peli+indice,sizeof(eMovie),1,listMovie);
                                        seguir=0;
                                        firstTime=0;
                                        break;
                                    }
                                }
                            }
                            while(seguir==1&&firstTime==1);
                            printf("\n\n-Modificado exitoso!");
                        }
                    }
                    fseek(listMovie,sizeof(eMovie)*1,SEEK_CUR);
                }
            }
            else if((peli+i)->isEmpty==LLENO&&(peli+i)->id!=auxInt&&i==(n-1)&&firstTime==1)
            {
                i=-1;
                printf("Indique el ID correctamente de la pelicula a modificar o 0 (cero) para salir\n\n");
                printf("-Opcion ingresada: ");
                fflush(stdin);
                scanf("%s",auxString);
                error=isNum(auxString);
                isFloat=intOrFloat(auxString);
                while(error==1||isFloat!=0)
                {
                    printf("\nIngrese ID correctamente: ");
                    fflush(stdin);
                    scanf("%s",auxString);
                    error=isNum(auxString);
                    isFloat=intOrFloat(auxString);
                }
                auxInt=atoi(auxString);
                printf("\n");
                if(auxInt==0)
                {
                    printf("\n\n-Modificado cancelado!");
                    return;
                }
            }
        }
    }

    fclose(listMovie);
    free(peli);
}
