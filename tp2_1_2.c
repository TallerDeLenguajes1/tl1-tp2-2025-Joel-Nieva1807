#include <stdio.h>
#define N 20
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));

    int i; 
    double vt[N], *puntero;
    puntero = vt;
    for(i = 0;i<N; i++) 
    {  
    *(puntero+i)=1+rand()%100;
    printf("%.2f   ", vt[i]); 
    }
    
    return 0;
}