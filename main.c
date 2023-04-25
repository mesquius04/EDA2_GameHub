#include "main.h"

#include <stdio.h>
void printMenu(){
    printf("Pulsa el boton correspondiente.\n");
    printf("1. Crear cuenta gamer\n");
    printf("2. Mostrar lista de gamers\n");
    printf("3. Iniciar sesión\n");
    printf("4. Salir\n");
}
void insert_user(){

}
void list_user(){

}

int main(void) {
    int option;
    printMenu();
    scanf("%d",&option);
    while (option!=4){
        if (option==1){
            printf("%d\n",option);
            insert_user();
        }
        else if (option==2){
            //Imprimir lista
            printf("%d\n",option);
            list_user();
        }
        else if (option==3){

            printf("%d\n",option);
        }
        else printf("Ingresa un entero del 1 al 4!!");
        scanf("%d",&option);
    }
    if (option==4){ printf("Vuelve pronto!!");}
    return 0;
}