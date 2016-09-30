#include <stdio.h>
#include <ctype.h>

#define ESTADO 5
#define CODIGO 6

unsigned char caracter_actual;

unsigned int filtro();
int lexico();

int main2() {

    int token;
    printf("Entrada: ");

    while ((caracter_actual = (unsigned char) getchar()) != '\n') {

        ungetc(caracter_actual, stdin);
        token = lexico();

        switch (token) {
            case 0: printf("Raro\n"); break;
            case 1: printf("Identificador\n"); break;
            case 2: printf("Entero\n"); break;
            case 3: printf("Suma\n"); break;
            case 4: printf("No definido\n"); break;
            default:break;
        }

        ungetc(caracter_actual, stdin);

    }

    return 0;

}

int lexico() {

    unsigned int codigo;
    unsigned int salida = 0, estado = 0;

    static unsigned int matriz_transicion[ESTADO][CODIGO] = {
            {1, 2, 1, 3, 0, 4},
            {1, 1, 1, 0, 0, 0},
            {0, 2, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 4}
    };

    static unsigned int matriz_salida[ESTADO][CODIGO] = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 1, 1},
            {2, 0, 2, 2, 2, 2},
            {3, 3, 3, 3, 3, 3},
            {4, 4, 4, 4, 4, 0}
    };

    while (salida == 0) {
        codigo = filtro();
        salida = matriz_salida[estado][codigo];
        estado = matriz_transicion[estado][codigo];
    }

    return salida;

}

unsigned int filtro() {

    caracter_actual = (unsigned char) getchar();
    if (isalpha(caracter_actual))
        return 0;
    else if (isdigit(caracter_actual))
        return 1;
    else if (caracter_actual == '_')
        return 2;
    else if (caracter_actual == '+')
        return 3;
    else if (caracter_actual == ' ' || caracter_actual == '\t')
        return 4;
    else
        return 5;

}
