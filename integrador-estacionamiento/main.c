#include <stdio.h>
#include <stdlib.h>

#define cant 2

//---------------- PROTOTIPOS ----------------
int buscar(int numespacio[], int espaciobuscar);
void ordenar(int gen[], int n);

//---------------- MAIN ----------------
int main()
{
    int numespacio[cant], categoria[cant], canthoras[cant];
    int genauto[cant], genmoto[cant];

    int legajo, espaciobuscar, opcion;
    int tiempoestacionado, i, anterior;
    int cantmotos = 0, cantautos = 0;

    //--------------- CARGA INICIAL ----------------
    for(i = 0; i < cant; i++)
    {
        printf("Numero de espacio: ");
        scanf("%d", &numespacio[i]);

        printf("Categoria 1=auto 2=moto: ");
        scanf("%d", &categoria[i]);

        printf("Cantidad de horas: ");
        scanf("%d", &canthoras[i]);
    }

    //--------------- MOVIMIENTOS ----------------
    printf("Ingrese su legajo: ");
    scanf("%d", &legajo);

    while(legajo != 0)
    {
        printf("\nIngrese numero de espacio: ");
        scanf("%d", &espaciobuscar);

        i = buscar(numespacio, espaciobuscar);

        if(i == -1)
        {
            printf("\nNo se encontro el espacio.\n");
        }
        else
        {
            printf("\nCategoria: %d", categoria[i]);
            printf("\nCantidad de horas: %d\n", canthoras[i]);

            anterior = canthoras[i];

            printf("\n1 = Registrar ingreso");
            printf("\n2 = Registrar salida");
            printf("\nOpcion: ");
            scanf("%d", &opcion);

            if(opcion == 1)
            {
                printf("Horas que va a permanecer estacionado: ");
                scanf("%d", &tiempoestacionado);

                canthoras[i] += tiempoestacionado;

                if(categoria[i] == 1)
                {
                    if(cantautos < cant)
                    {
                        genauto[cantautos] = numespacio[i];
                        cantautos++;
                    }
                }
                else if(categoria[i] == 2)
                {
                    if(cantmotos < cant)
                    {
                        genmoto[cantmotos] = numespacio[i];
                        cantmotos++;
                    }
                }
            }
            else if(opcion != 2)
            {
                printf("\nOpcion incorrecta.\n");
            }

            printf("\n-- COMPROBANTE --\n");
            printf("Legajo: %d\n", legajo);
            printf("Numero de espacio: %d\n", numespacio[i]);
            printf("Categoria: %d\n", categoria[i]);
            printf("Horas anteriores: %d\n", anterior);
            printf("Tipo de operacion: %d\n", opcion);
            printf("Horas actualizadas: %d\n", canthoras[i]);
        }

        printf("\nIngrese su legajo: ");
        scanf("%d", &legajo);
    }

    //--------------- INFORMES ----------------
    printf("\nCantidad de autos que ingresaron: %d\n", cantautos);
    printf("Cantidad de motos que ingresaron: %d\n", cantmotos);

    //--------------- ORDENAMIENTO ----------------
    if(cantautos != 0)
    {
        ordenar(genauto, cantautos);
    }

    if(cantmotos != 0)
    {
        ordenar(genmoto, cantmotos);
    }

    //--------------- LISTADO ----------------
    printf("\nEspacios de autos con ingreso:\n");

    for(i = 0; i < cantautos; i++)
    {
        printf("%d\n", genauto[i]);
    }

    printf("\nEspacios de motos con ingreso:\n");

    for(i = 0; i < cantmotos; i++)
    {
        printf("%d\n", genmoto[i]);
    }

    return 0;
}

//---------------- BUSQUEDA ----------------
int buscar(int numespacio[], int espaciobuscar)
{
    int k = 0;
    int i = 0;

    while(k == 0 && i < cant)
    {
        if(espaciobuscar == numespacio[i])
        {
            k = 1;
        }
        else
        {
            i++;
        }
    }

    if(k == 0)
    {
        return -1;
    }
    else
    {
        return i;
    }
}

//---------------- ORDENAMIENTO ----------------
void ordenar(int gen[], int n)
{
    int k = 0;
    int x = n;
    int i;
    int aux;

    while(k == 0)
    {
        k = 1;
        x--;

        for(i = 0; i < x; i++)
        {
            if(gen[i + 1] < gen[i])
            {
                k = 0;

                aux = gen[i];
                gen[i] = gen[i + 1];
                gen[i + 1] = aux;
            }
        }
    }
}
