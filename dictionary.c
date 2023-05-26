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
    dict = realloc(dict,(2*dict->size)*sizeof(Dict));
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
        return 0;
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

void top_10(int* top, Dict* dict){
    int aux_idx;
    int j;
    for (int i =0; i<(dict->size); i++){
        if (dict->items[i].key != NULL){
            j= 0;
            while((j<10) && (aux_idx != -1)) {
                aux_idx = i;
                if (dict->items[aux_idx].count >= dict->items[top[j]].count) {
                    //si es más grande o igual empieza bola de nieve
                    printf("s ");
                    aux_idx = top[j];
                    top[j] = aux_idx;
                    j++;
                }
            }
        }
    }
}
//int main() {
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
//    top_10(top,dict);
//    for (int b = 0; b<10; b++){     //imprimir top 10
//        printf("%d", top[b]);
//        if (top[b] != -1){
//            printf("Pos%d: %s, %d times\n", b+1, dict->items[top[b]].key,dict->items[top[b]].count);
//        }
//    }
//
//    //diccionario 75 % -> resize
//    //if(((float)dict->count/(float)dict->size) >= 0.75) resize_dictionary(dict);
//
//}

void revisar_timeline (User* user){
    while (user->publicacion != NULL){
        // recorrer lista de publicaciones
        printf("%s\n", user->publicacion->post);
        user->publicacion = user->publicacion->next;
    }
}