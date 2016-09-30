#include <stdio.h>
#include <ctype.h>

int main0() {

    int estado = 0;
    char entrada[50];
    char *p = entrada;
    printf("entrada: \n");
    fgets(entrada, sizeof(entrada), stdin);

    while (*p != '\0') {//cero define el final del analisis
        switch (estado) {
            case 0:
                if (isalpha(*p) || *p == '_') estado = 1;
                else if (isdigit (*p)) estado = 3;
                else if (*p == '+') estado = 5;
                else estado = 6;
                p++;
                break;

            case 1:
                if (isalpha (*p) || *p == '_' || isdigit(*p)) estado = 1;
                else estado = 2;
                p++;
                break;

            case 2:
                printf(" ID");
                estado = 0;
                p--;
                break;

            case 3:
                if (isdigit (*p)) estado = 3;
                else estado = 4;
                p++;
                break;

            case 4:
                printf(" ENT");
                estado = 0;
                p--;
                break;

            case 5:
                printf(" SUM");
                estado = 0;
                break;

            case 6:
                printf(" ERR");
                estado = 0;
            default:break;
        }
    }

    switch (estado) {//ultimo token
        case 1:
        case 2:
            printf(" ID");
            break;
        case 3:
        case 4:
            printf(" ENT");
            break;
        case 5:
            printf(" SUM");
            break;
        case 6:
            printf(" ERR");
            break;
        default:break;
    }

    return 0;

}