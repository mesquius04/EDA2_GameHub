//
// Created by marti on 26/05/2023.
//
#include <Windows.h>
#include <stdio.h>
#include <CommCtrl.h>
#include "main.h"
#ifndef UNTITLED16_VISUAL_FUNCTIONS_H
#define UNTITLED16_VISUAL_FUNCTIONS_H
void print_screen_publi(User* current,HDC hdc);
void print_screen_error(HDC hdc);
void print_screen_users(User* list,HDC hdc);
void print_screen_error4(HDC hdc);
void print_screen_error2(HDC hdc);
void print_screen_trend(HDC hdc,Dict* dict);
void print_screen_error3(HDC hdc);
void print_screen_error5(HDC hdc);
void print_me_screen (User* user,HDC hdc);
#endif //UNTITLED16_VISUAL_FUNCTIONS_H
