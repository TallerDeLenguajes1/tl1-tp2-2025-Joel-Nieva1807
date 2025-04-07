#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TAMA 5

struct compu { 
    int velocidad; // Velocidad de procesamiento en GHz (valor entre 1 y 3) 
    int anio; // Año de fabricación (valor entre 2015 y 2024) 
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8) 
    char *tipo_cpu; // Tipo de procesador (apuntador a cadena de caracteres) 
   };
void listarPCs(struct compu pcs[], int cantidad);
int main()
{
    struct compu arreglo_PCs[TAMA];
    int indice;
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"}; 
    srand(time(NULL));

    for (int i = 0; i < TAMA; i++)
    {
        arreglo_PCs[i].velocidad= rand() % 3 + 1;
        arreglo_PCs[i].anio= rand() % (2024-2015 + 1) + 2015;
        arreglo_PCs[i].cantidad_nucleos= rand() % 8 + 1;

        indice= rand() % 6; //genera un numero aletaorio entre 0 y 5, me servirá para apuntar a una cadena aleatoriamente posterirormente
        arreglo_PCs[i].tipo_cpu = tipos[indice];
    }

    listarPCs(arreglo_PCs, TAMA);
    
    
    
    return 0;
}

void listarPCs(struct compu pcs[], int cantidad){
    puts("Lista completa de PCs:");
    puts("--------------------------------");
    for (int i = 0; i < cantidad; i++)
    {
        printf("Datos de PCs %d:\n", i+1);
        printf("Velocidad de procesamiento: %d GHZ.\n", pcs[i].velocidad);
        printf("Anio de fabricacion: %d.\n", pcs[i].anio);
        printf("Cantidad de nucleos: %d.\n", pcs[i].cantidad_nucleos);
        printf("Tipo de procesador: %s.\n", pcs[i].tipo_cpu);

        puts("--------------------------------");
    }
    

}
