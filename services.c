//
// Created by marti on 26/05/2023.
//
#include <Windows.h>
#include <stdio.h>
#include <CommCtrl.h>
#include "main.h"
#include <time.h>
void print_console_users(User* list){
    while(list != NULL){
        printf("%s\n",list->user);
        list = list->next;
    }
}

int validar_email(char *mail) { //un mail válido tiene esta estructura ______@gmail.com
    char delimitador[] = "@";
    char arroba[] = "gmail.com";
    char *token = strtok(mail, delimitador);   //función split python (divide string)
    // token == primera parte mail
    if (token == NULL)return FALSE;                        // no contiene nada
    else {
        for (int x = 0; x < strlen(token); x++) {
            if ((('a' <= token[x] && token[x] <= 'z') || ('0' <= token[x] && token[x] <= '9') || (token[x]=='.'))==0)return FALSE;
            //nos aseguramos de que la primera parte contenga letras números arroba y punto
        }
        token = strtok(NULL, delimitador);  // token == segunda parte mail
        if ((token == NULL) || (strcmp(token, arroba) != 0) || (strtok(NULL, delimitador) != NULL)) return FALSE;
        // hay algo después de arroba, es gmail.com y no hay más arrobas
        return TRUE;
    }

}


//genera un número eneteo aleatotio con un mínimo (incluido) y un máximo (sin incluir) de rango
int entero_aleatorio_fronteras(int min, int max){
    srand(time(NULL));
    int num = rand();
    //se calcula el resto del número del rango y se le añade el mínimo, por lo tanto siempre estará en el rango
    return num%(max-min) + min;
}