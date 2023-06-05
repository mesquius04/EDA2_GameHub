//
// Created by marti on 26/05/2023.
//
#include <Windows.h>
#include <stdio.h>
#include <CommCtrl.h>
#include "main.h"
#define MAX_PALABRAS 100
#ifndef UNTITLED16_DICTIONARY_H
#define UNTITLED16_DICTIONARY_H
int power(int base, int exponent);
int mod(int num1, int num2);
int hash_function (char* key, int size);
Dict* initialize_dictionary(int size);
void resize_dictionary(Dict* dict);
void revisar_timeline (User* user);
int add_item(Dict* dict, char* key);
int dictionary(char* post, char* words[MAX_PALABRAS]);
//int setup_top(int* top, Dict* dict);
void top_10 (int* top, Dict* dict);
void create_post (char* post, User* user);
int new_post(char* post, Dict* dict, User* user);
#endif //UNTITLED16_DICTIONARY_H
