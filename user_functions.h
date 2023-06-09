//
// Created by marti on 26/05/2023.
//
#include <Windows.h>
#include <stdio.h>
#include <CommCtrl.h>
#include "main.h"
#ifndef UNTITLED16_USER_FUNCTIONS_H
#define UNTITLED16_USER_FUNCTIONS_H

User* find_user(char* user, User* list);
void init_user(User* user);
int log_in_data (char* name, char* password, User* list);
void add_user_to_list(User** list, User user);
#endif //UNTITLED16_USER_FUNCTIONS_H
