//
// Created by marti on 26/05/2023.
//
#include <Windows.h>
#include <stdio.h>
#include <CommCtrl.h>
#include "main.h"
#include "user_functions.h"
#include <string.h>
#include <time.h>

int are_friends(User u1, User u2){
    for(int i = 0; i<u1.numfriends; i++){
        if (u1.friends[i] == &u2) return TRUE;
        //compara toda la lista de amigos, si en alguna coincide, entonces es TRUE
    }
    return FALSE;
    //si no coincide, devuelve FALSE
}

int friend_request_already(User sender, User sended){
    Element* aux = sender.friend_request->first;
    while(aux != NULL){
        if(aux->user == &sended) return TRUE;//si ya ha sido enviada
        aux = aux->next;
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

void send_friend_request(User** list,User** user,char* name) {
    User *newfriend = find_user(name, *list); //se encuentra al ususari que se quiere añadir
    if (newfriend == NULL) printf("Invalid Name\n"); //si no existe se notifica
    else if (are_friends(**user, *newfriend) == TRUE || friend_request_already(**user, *newfriend)  == TRUE
    || friend_request_already(*newfriend, **user) ==TRUE || newfriend == (*user) ){
        //si ya son amigos o la petición había sido enviada o recibida del usuario, entonces lo notifica
        printf("Request already sent or Already friends\n");
    }
    else {//encolamos en la queue de friend request
        Element* node = malloc(sizeof(Element));
        node->user = *user;
        node->next = NULL;//es el último de la lista, el siguiente apunta a null
        if((newfriend)->friend_request->first == NULL){//si es el primeo de la lista
            node->prev = NULL; //no hay previo
            (newfriend)->friend_request->first = node; //el primero será el último
        }else{//si no es el único de la lista
            node->prev = (newfriend)->friend_request->last; //el previo al nodo será el anterior último
        }
        (newfriend)->friend_request->last = node; //estamos encolando, así que el nuevo elemento siempre será el último
    }
}


void makefriends(User* u1, User* u2) {
    //si la lista está llena la realocamos
    if (u1->numfriends + 1 >= u1->maxfriends) {
        u1->maxfriends += 20;
        u1->friends = (User **) realloc(u1->friends, sizeof(User *) * u1->maxfriends);
    }
    if (u2->numfriends + 1 >= u2->maxfriends) {
        u2->maxfriends += 20;
        u2->friends = (User **) realloc(u2->friends, sizeof(User *) * u2->maxfriends);
    }
    //uno se hace amigo del otro
    u1->friends[u1->numfriends] = u2;
    u1->numfriends++;
    //el otro también se hace amigo
    u2->friends[u1->numfriends] = u2;
    u2->numfriends++;
}

User* dequeue(User* user){
    User* primero = user->friend_request->first->user;
    Element* aux = user->friend_request->first;
    //si solo hay 1 elemento, pasa a no haber cola
    if(user->friend_request->first == user->friend_request->last){
        user->friend_request->first = NULL;
        user->friend_request->last = NULL;
    } else { //si hay varios elementos, el primero se quita y el 2o pasa a ser el primero
        user->friend_request->first = user->friend_request->first->next;
        user->friend_request->first->prev = NULL;
    }
    free(aux);
    return primero;
}

void manage_friend_request(User* current){
    int menu;
    User* newfriend;
    while(current->friend_request->first!=NULL){ //mientras la friendrequest no este vacia
        newfriend = dequeue(current);
        printf("Quieres hacerte amigo de %s?",newfriend->name);
        printf(" Pulsa 1 para aceptar, 2 para rechazar o 3 para salir \n");
        scanf("%d", &menu);
        if(menu == 1) makefriends(current,newfriend); //si aceptas, se hacen amigos
        if(menu == 3) return; //si quieres salir
        //si rechazas, pasas al siguiente user
    }
    //has salido, por lo tanto no quedan peticiones, o no tenías ninguna originalmente
    printf("no tienes ninguna peticion");
}
