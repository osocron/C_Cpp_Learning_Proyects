#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//opcion 1
/*
struct Alumno{
    char matricula[11];
    char paterno[20];
    char materno[20];
    char nombre[20];
}alu1,alu2; //Declaracion de Variables del tipo alumno
O declarar las variables como:
struct Alumno alu1,alu2;
*/

typedef struct {
    char matricula[11];
    char paterno[20];
    char materno[20];
    char nombre[20];
}Alumno;

int main(int args, char *argv[]) {
    FILE *f;
    Alumno alu1,alu2;

    if ((f=fopen("pruebaBinario.bin","wb+")) != NULL){
        strcpy(alu1.matricula,"S010000012\0");
        strcpy(alu1.paterno,"Hernandez\0");
        strcpy(alu1.materno,"Gonzalez\0");
        strcpy(alu1.nombre,"Lizbeth\0");

        fwrite(&alu1, sizeof(Alumno),1,f);

        strcpy(alu1.matricula,"S010000018\0");
        strcpy(alu1.paterno,"Diaz\0");
        strcpy(alu1.materno,"Ocadiz\0");
        strcpy(alu1.nombre,"Sofia\0");

        fwrite(&alu1, sizeof(Alumno),1,f);

        rewind(f);

        int c;
        while ((c=fread(&alu2, sizeof(Alumno),1,f)) != 0){
            printf("%10s %s %s %s\n",alu2.matricula,alu2.paterno,alu2.materno,alu2.nombre);
        }
    }

    return 0;
}