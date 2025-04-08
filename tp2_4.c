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
void mostrarMasVieja(struct compu pcs[], int cantidad);
void mostrarMasVeloz(struct compu pcs[], int cantidad);
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

        indice= rand() % 6; //genera un numero aleatorio entre 0 y 5, me servirá luego para apuntar a una cadena aleatoriamente
        arreglo_PCs[i].tipo_cpu = tipos[indice];
    }

    listarPCs(arreglo_PCs, TAMA);
    mostrarMasVieja(arreglo_PCs, TAMA);
    mostrarMasVeloz(arreglo_PCs, TAMA);
    
    
    
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

void mostrarMasVieja(struct compu pcs[], int cantidad){
    int masViejo = 2025;
    int num=0;
    for (int i = 0; i < cantidad; i++)
    {

        if (pcs[i].anio < masViejo)
        {
            masViejo= pcs[i].anio;
            num= i;

        }
        
    }
    puts("Datos del PCs mas antiguo:");
    puts("--------------------------------");
    printf("Anio de fabricacion: %d.\n", pcs[num].anio);
    printf("Velocidad de procesamiento: %d GHZ.\n", pcs[num].velocidad);
    printf("Cantidad de nucleos: %d.\n", pcs[num].cantidad_nucleos);
    printf("Tipo de procesador: %s.\n", pcs[num].tipo_cpu);
    puts("--------------------------------");
    

}

void mostrarMasVeloz(struct compu pcs[], int cantidad){
    int masVeloz = 0;
    int num=0;
    for (int i = 0; i < cantidad; i++)
    {

        if (pcs[i].velocidad > masVeloz)
        {
            masVeloz= pcs[i].velocidad;
            num=i;

        }
        
    }
    puts("Datos del PCs mas rapido:");
    puts("--------------------------------");
    printf("Velocidad de procesamiento: %d GHZ.\n", pcs[num].velocidad);
    printf("Anio de fabricacion: %d.\n", pcs[num].anio);
    printf("Cantidad de nucleos: %d.\n", pcs[num].cantidad_nucleos);
    printf("Tipo de procesador: %s.\n", pcs[num].tipo_cpu);
    puts("--------------------------------");


}