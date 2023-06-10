//
// Created by marti on 26/05/2023.
//
#include <Windows.h>
#include <stdio.h>
#include <CommCtrl.h>
#include "main.h"

#define INITIAL_FRIENDS 40
User* find_user(char* user, User* list){
    while (list != NULL){
        //recorremos la lista hasta el final
        if (strcmp(user,list->user)==0){
            //nombre = usuario  (lo hemos encontrado)
            return list;
        }
        list = list->next;     // si no pasamos al siguiente
    }
    return NULL;     //no ha habido suerte/ list vacía
}


int log_in_data (char* name, char* password, User* list){
    if (find_user(name, list) != NULL) {
        //usuario coincide
        if(strcmp(find_user(name,list)->password, password)==0){
            printf("\nBienvenido %s",(find_user(name,list)->user));
            return TRUE;};     //miramos que la contraseña también concida
    }
    return FALSE;                                            //no hay matches
}

void init_user(User* user){
    user->friend_request = (Queue*) malloc(sizeof(Queue));
    user->friend_request->first = NULL;
    user->friend_request->last = NULL;
    user->friends = (User**) malloc(INITIAL_FRIENDS*sizeof(User*));
    user->numfriends = 0;
    user->maxfriends = INITIAL_FRIENDS;
    user->publicacion = NULL;
    user->next = NULL;
}


void add_user_to_list(User** list, User user){
     User* aux = (User*) malloc(sizeof(User));
     *aux = user;
     init_user(aux);
     aux->next = *list;
     *list = aux;
}

int len_user_list(User* list){
    int count = 0;
    while(list != NULL){
        //recorremos la lista y actualizamos el contador
        list = list->next;
        count++;
    }
    return count;
}

void read_user_file(FILE* fd){
    while ( !feof(fd) ){
        char* user_name;
        fscanf(fd,"%s,", user_name);  // recoge usuarios
        printf("%s\n", user_name);    // los imprime
    }
}


