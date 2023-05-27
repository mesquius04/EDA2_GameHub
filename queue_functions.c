//
// Created by marti on 26/05/2023.
//
#include <Windows.h>
#include <stdio.h>
#include <CommCtrl.h>
#include "main.h"
#include <time.h>

int are_friends(User u1, User u2){
    for(int i = 0; i<u1.num_friends; i++){
        if (u1.friends[i] == &u2) return TRUE;
        //compara toda la lista de amigos, si en alguna coincide, entonces es TRUE
    }
    return FALSE;
    //si no coincide, devuelve FALSE
}

int friend_request_already(User sender, User sended){
    for(int i = sended.friend_request->head; i<sended.friend_request->tail; i++){
        //recorremos todas las posiciones del array donde la cola es efectiva
        if(sended.friend_request->array[i] == &sender) return TRUE;
        //compara los elementos de la cola con la dirección del que ha enviado la petición de amistad
    }
    return FALSE;
}

/*
void add_3random_Stack(User* list, User* user, Stack stack){
    srand(time(NULL));
    int len = len_user_list(list);
    int success = 0;
    int num;
    while(success<3){
        num = entero_aleatorio_fronteras(0,len+1);

    }
}
 */

//la lista de users, el user que envía, el nombre del usuario al que le envia
void send_friend_request(User** list,User** user,char* name){
    User* newfriend = find_user(name,*list); //se encuentra al ususari que se quiere añadir
    if(newfriend == NULL) printf("Invalid Name\n"); //si no existe se notifica
    else if(are_friends(**user,*newfriend) || friend_request_already(**user,*newfriend))
        //si ya son amigos o la petición había sido enviada, entonces lo notifica
        printf("Request already sent or Already friends\n");
    else{
        int i = (*user)->friend_request->tail;
        if(i+1>=MAX_FRIENDS){ //si se pasa del tamanyo del array, aumenta en 20 el tamaño del array dinámico
            int new_size;
            new_size= (*user)->friend_request->size + 20;
            (*user)->friend_request->size = new_size;
            (*user)->friend_request->array =
                    (User**) realloc((*user)->friend_request->array,sizeof(User*)*new_size);
        }
            //lo añade a la cola de friend_requests

        (*user)->friend_request->array[i] = newfriend;
        (*user)->friend_request->tail++;

    }
}
