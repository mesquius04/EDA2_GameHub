//
// Created by marti on 26/05/2023.
//
#include <Windows.h>
#include <stdio.h>
#include <CommCtrl.h>
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_PALABRAS 100

int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
} //potencia

int mod(int num1, int num2){
    return num1 - (num1/num2)*num2;
}   //residuo

int hash_function (char* key, int size){
    //palabra y tamaño diccionario
    int sum= 0;
    int length = strlen(key);
    for (int i= 0; i<length; i++){
        sum+= power(key[i], length-i);
    }
    //devolvemos el residuo para asegurarnos
    //indice dentro del diccionario
    return abs(mod(sum, size));
}

Dict* initialize_dictionary(int size){
    //puntero diccionario
    Dict* dict = malloc(sizeof(Dict));
    dict->size = size;
    dict->count = 0;
    //espacio para todos los items
    dict->items = malloc(sizeof(Node)*dict->size);
    for (int i =0; i<dict->size; i++){
        //inicializamos items
        dict->items[i].key = NULL;
        dict->items[i].count = 0;
    }
    return dict;
}

void resize_dictionary(Dict* dict){
    //reasignamos memoria y la ensanchamos (doble de espacio)
    dict = realloc(dict,(2*(dict->size))*sizeof(Dict));
    for (int i= dict->size; i<(2*dict->size); i++){
        dict->items[i].key = NULL;
        dict->items[i].count = 0;
    }
    dict->size = 2*dict->size; //actualizamos tamaño
}

int add_item(Dict* dict, char* key){
    int key_value = hash_function(key,dict->size);
    if (dict->items[key_value].key == NULL){
        //nueva palabra -> reservar espacio
        dict->items[key_value].key = malloc(strlen(key)*sizeof(char));
        // guardamos palabra
        strcpy(dict->items[key_value].key,key);
        dict->items[key_value].count += 1;
        dict->count +=1;
        //tanto contador palabra como diccionario augmentan en uno
    }
    else if (strcmp(dict->items[key_value].key, key)==0){
        //palabra ya creada -> sumar contador
        dict->items[key_value].count += 1;
    }
    else {
        //no coincide -> item esta cogido
        //case1: existe pero no en su posición natural
        int found = 0;
        for (int i=0; i<dict->size;i++){
            if (dict->items[i].key != NULL)
                if (strcmp(dict->items[i].key, key)==0){
                    //palabra ya creada -> sumar contador
                    dict->items[i].count += 1;
                    found = 1;
                }
        }
        //case2: palabra es nueva; usaremos linear probing
        if (found != 1){
            for (int j=key_value+1; j<dict->size; j++){
                if (dict->items[j].key == NULL){
                    //nueva palabra -> reservar espacio
                    dict->items[j].key = malloc(strlen(key)*sizeof(char));
                    // guardamos palabra
                    strcpy(dict->items[j].key,key);
                    dict->items[j].count += 1;
                    dict->count +=1;
                    //tanto contador palabra como diccionario augmentan en uno
                    found = 1;
                    break;
                }
            }
            if (found != 1){
                for (int j=0; j<key_value; j++){
                    if (dict->items[j].key == NULL){
                        //nueva palabra -> reservar espacio
                        dict->items[j].key = malloc(strlen(key)*sizeof(char));
                        // guardamos palabra
                        strcpy(dict->items[j].key,key);
                        dict->items[j].count += 1;
                        dict->count +=1;
                        //tanto contador palabra como diccionario augmentan en uno
                        found = 1;
                        break;
                    }
                }
            }
        }
    }
    return 1;
}

int dictionary(char* post, char* words[MAX_PALABRAS]) {
    int word_count = 0;    //n palabras
    char* word;
    word = strtok(post, " \t\n\r.,;:!?'\"");
    //funcion split python, divide string
    while (word != NULL && word_count < MAX_PALABRAS) {
        words[word_count] = word;       //guardamos palabra
        word_count++;
        word = strtok(NULL, " \t\n\r.,;:!?'\"");
    }
    return word_count;  //devolvemos idx máximo
}

int setup_top(int* top, Dict* dict){
    //necesitamos valores iniciales para poder establecer una comparación (determinar top10)
    int i = 0, idx = 0;
    while ( i<(dict->size) || idx>=9){
        //no salir indice dicc ni superar indice top
        if(dict->items[i].key != NULL){ //
            top[idx] = i;
            idx +=1;
        }
        i++;
    }
    return idx;
}

void top_10(int idx_max, int* top, Dict* dict){
    int idx, aux_idx; //necesitamos dos variables extra para no influir en los for
    for (int j =0; j<(dict->size); j++){
        idx = j;
        if (dict->items[j].key != NULL){
            //si la entrada no está vacía
            for(int i=0; i<idx_max; i++) {
                if (dict->items[idx].count >= dict->items[top[i]].count) {
                    //si es más grande o igual empieza bola de nieve
                    aux_idx = top[i];
                    top[i] = idx;
                    idx = aux_idx;
                }
            }
        }
    }
}

void create_post (char* post, User* user){
    //crear espacio y almacenar datos nueva publicación
    Publicacion* publi = malloc (sizeof(Publicacion));
    strcpy(publi->post, post);
    publi-> next = NULL;
    //primera publicación usuario
    if (user->publicacion ==  NULL){
        user->publicacion = publi;
        printf("entra");
    }
    else{
        printf("b");
        while (user->publicacion->next != NULL){
            //nos quedamos con la última completa
            user->publicacion = user->publicacion->next;
            printf("a");
        }
        user->publicacion->next = publi;
    }

    printf("sale");
}

int new_post(char* post, Dict* dict, User* user){
    //añadir post al usuario al que pertenece
    create_post(post, user);
    //guardaremos palabras troceadas aquí
    char* single_word[MAX_PALABRAS];
    //num_palabras que hay
    int word_count = dictionary(post, single_word);
    if(((float)(dict->count+word_count)/(float)dict->size) >= 0.75) resize_dictionary(dict);
    //ampliar diccionario si va a estar al 75% de su capacidad
    for (int z=0; z<word_count; z++) {
        add_item(dict, single_word[z]);
        //añadir items al diccionario
    }
}

//    char hola[30] ="Hola me llaman plex,mami "; //publicacion
//    char* single_word[MAX_PALABRAS];
//    Dict* dict = initialize_dictionary(1000);
//    int word_count = dictionary(hola, single_word);
//    for (int z=0; z<word_count; z++){
//        add_item(dict,single_word[z]);
//    }
//
//    for (int a=0 ; a<dict->size;a++){
//        //imprimir todos los elementos
//        if(dict->items[a].key !=NULL){
//            printf("%d: %s (%d)\n",a,dict->items[a].key, dict->items[a].count);
//        }
//    }
//
//    int top[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
//    // -1 -> elemento vacío
//    int idx_max = setup_top(top,dict);
//    top_10(idx_max,top,dict);
//    for (int b = 0; b<idx_max; b++){     //imprimir top 10
//        printf("%d", top[b]);
//        if (top[b] != -1){
//            printf("Pos%d: %s, %d times\n", b+1, dict->items[top[b]].key,dict->items[top[b]].count);
//        }
//    }

void revisar_timeline (User* user){
    while (user->publicacion != NULL){
        // recorrer lista de publicaciones
        printf("%s\n", user->publicacion->post);
        user->publicacion = user->publicacion->next;
    }
}