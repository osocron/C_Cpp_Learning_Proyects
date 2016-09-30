#include <stdio.h>

#define INICIO 0
#define FINAL 9
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)>(B)?(B):(A))
#define CUBO(A) ((A)*(A)*(A))
//#define CUBO_EQUIVOCADO(A) A*A*A
#define SUMA(A) ((A)+(A))
#define SUMA_EQUIVOCADA(A) (A)+(A)
#define CUADRADO(A) (A)*(A)


int main()
{
    int indice,mn,mx,i;
    int offset = 5;
    int contador = 5;

    for (indice = INICIO; indice <= FINAL ; ++indice) {
        mx = MAX(indice,contador);
        mn = MIN(indice,contador);
        printf("Maximo = %d Minimo = %d\n",mx,mn);
    }

    for (i = INICIO; i <= FINAL; ++i) {
        printf("El cuadrado de %3d es %4d, y su cubo ", CUADRADO(i),CUBO(i+offset));
    }

    printf("\nProbramos la macro de la suma\n");
    for (i = INICIO; i < FINAL; ++i) {
        printf("La macro de suma EQUIVOCADA = %6d, y la correcto = %6d\n",5*SUMA_EQUIVOCADA(i),5*SUMA(i));
    }

    return 0;
}