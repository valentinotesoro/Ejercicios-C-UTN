#include <stdio.h>
#include <stdlib.h>

#define T 2    // Para pruebas. Luego cambiar a 250.

//---------------- PROTOTIPOS ----------------
int Buscar(int pat[], int bus);
void Ordenar(int gen[], int cant);

//---------------- MAIN ----------------
int main()
{
    int patente[T], codRep[T], gen[T];
    float importe[T];
    int i;
    int legajo;
    int buscado;
    int opcion;
    float monto;
    float anterior;
    int reparaciones = 0;
    int presupuestos = 0;

    //--------------- CARGA INICIAL ----------------
    for(i=0; i<T; i++)
    {
        printf("PATENTE: ");
        scanf("%d", &patente[i]);

        printf("CODIGO DE REPARACION: ");
        scanf("%d", &codRep[i]);

        printf("IMPORTE ACUMULADO: ");
        scanf("%f", &importe[i]);
    }

    //--------------- MOVIMIENTOS ----------------
    printf("\nLEGAJO DEL MECANICO: ");
    scanf("%d", &legajo);

    while(legajo != 0)
    {
        printf("\nPATENTE DEL VEHICULO: ");
        scanf("%d", &buscado);

        i = Buscar(patente, buscado);

        if(i == -1)
        {
            printf("\nPATENTE INEXISTENTE\n");
        }
        else
        {
            printf("\nCODIGO DE REPARACION: %d", codRep[i]);
            printf("\nIMPORTE ACUMULADO: %.2f\n", importe[i]);

            printf("\n1- REGISTRAR REPARACION");
            printf("\n2- REGISTRAR PRESUPUESTO");
            printf("\nOPCION: ");
            scanf("%d", &opcion);

            printf("IMPORTE: ");
            scanf("%f", &monto);

            anterior = importe[i];

            switch(opcion)
            {
                case 1:
                    importe[i] += monto;
                    printf("\nREPARACION: %.2f\n", monto);
                    printf("IMPORTE ACTUALIZADO: %.2f\n", importe[i]);

                    gen[reparaciones] = codRep[i];
                    reparaciones++;
                    break;

                case 2:
                    printf("PRESUPUESTO: %.2f\n", monto);
                    printf("IMPORTE ACTUALIZADO: %.2f\n", importe[i]);
                    presupuestos++;
                    break;

                default:
                    printf("OPCION INCORRECTA\n");
            }

            printf("\n******** COMPROBANTE ********\n");
            printf("LEGAJO: %d\n", legajo);
            printf("PATENTE: %d\n", patente[i]);
            printf("CODIGO REPARACION: %d\n", codRep[i]);
            printf("IMPORTE ANTERIOR: %.2f\n", anterior);
        }

        printf("\n---------------------------------\n");
        printf("LEGAJO DEL MECANICO: ");
        scanf("%d", &legajo);
    }

    //---------------- ORDENAMIENTO ----------------
    if(reparaciones > 0)
        Ordenar(gen, reparaciones);

    //---------------- INFORMES ----------------
    printf("\nCODIGOS DE REPARACION REALIZADOS\n");

    if(reparaciones == 0)
    {
        printf("NO HUBO REPARACIONES\n");
    }
    else
    {
        for(i=0; i<reparaciones; i++)
        {
            printf("%d\n", gen[i]);
        }
    }

    printf("\nCANTIDAD DE REPARACIONES: %d", reparaciones);
    printf("\nCANTIDAD DE PRESUPUESTOS: %d", presupuestos);

    return 0;
}

//---------------- BUSQUEDA ----------------
int Buscar(int pat[], int bus)
{
    int i = 0;
    int k = 0;

    while(k == 0 && i < T)
    {
        if(bus == pat[i])
            k = 1;
        else
            i++;
    }

    if(k == 0)
        return -1;
    else
        return i;
}

//---------------- ORDENAMIENTO ----------------
void Ordenar(int gen[], int cant)
{
    int k = 0;
    int x = cant;
    int i;
    int aux;

    while(k == 0)
    {
        k = 1;
        x--;

        for(i=0; i<x; i++)
        {
            if(gen[i] > gen[i+1])
            {
                aux = gen[i];
                gen[i] = gen[i+1];
                gen[i+1] = aux;
                k = 0;
            }
        }
    }
}
