//
// Created by marti on 26/05/2023.
//
#include <Windows.h>
#include <stdio.h>
#include <CommCtrl.h>
#include "main.h"
void print_screen_error(HDC hdc){
    RECT rect = {1200, 600, 1400, 680 };
    DrawText(hdc, "Email debe terminar\ncon '@gmail.com'!!", -1, &rect, DT_LEFT);
}

void print_screen_error2(HDC hdc){
    RECT rect3 = {200, 637, 600, 687 };
    printf("\nERROR: Tienes que llenar todos los campos!");
    DrawText(hdc, "Tienes que llenar todos los campos!", -1, &rect3, DT_CENTER | DT_BOTTOM);
}

void print_screen_error3(HDC hdc){
    RECT rect2 = {700, 637, 1100, 687 };
    printf("\nERROR: Nombre de usuario no disponible!");
    DrawText(hdc, "Nombre de usuario no disponible!", -1, &rect2, DT_CENTER | DT_BOTTOM);
}

void print_screen_error4(HDC hdc){
    RECT rect3 = {200, 677, 600, 727 };
    printf("\nERROR: Tienes que llenar todos los campos!");
    DrawText(hdc, "Tienes que llenar todos los campos!", -1, &rect3, DT_CENTER | DT_BOTTOM);
}

void print_screen_error5(HDC hdc){
    RECT rect = {1200, 509, 1400, 582 };
    DrawText(hdc, "Los password\ndeben coincidir!!", -1, &rect, DT_VCENTER | DT_LEFT);
}

void print_screen_users(User* list,HDC hdc){
    RECT rect2 = { 100, 130, 200, 160 };
    while (list!= NULL){
        DrawText(hdc, list->user, -1, &rect2, DT_LEFT | DT_BOTTOM);
        rect2.top+=35;
        rect2.bottom+=35;
        list = list->next;
        if (rect2.bottom>=600){
            rect2.bottom=160;
            rect2.top=130;
            rect2.left+=120;
            rect2.right+=120;
        }
    }
}

void print_me_screen (User* user,HDC hdc){
    RECT rect = { 150, 50, 320, 100 };
    DrawText(hdc, "USER:", -1, &rect, DT_LEFT | DT_BOTTOM);
    rect.left+=200;
    rect.right+=400;
    DrawText(hdc, user->user, -1, &rect, DT_LEFT | DT_BOTTOM);
    rect.top+=100;
    rect.bottom+=100;
    rect.left-=200;
    rect.right-=400;
    DrawText(hdc, "NOMBRE:", -1, &rect, DT_LEFT | DT_BOTTOM);
    rect.left+=200;
    rect.right+=200;
    DrawText(hdc, user->name, -1, &rect, DT_LEFT | DT_BOTTOM);
    rect.top+=100;
    rect.bottom+=100;
    rect.left-=200;
    rect.right-=200;
    DrawText(hdc, "EDAD:", -1, &rect, DT_LEFT | DT_BOTTOM);
    rect.left+=200;
    rect.right+=200;
    char to_str[5]; // Tamaño suficiente para almacenar la cadena
    sprintf(to_str, "%d", user->age);
    DrawText(hdc, to_str, -1, &rect, DT_LEFT | DT_BOTTOM);
    rect.top+=100;
    rect.bottom+=100;
    rect.left-=200;
    rect.right-=200;
    DrawText(hdc, "EMAIL:", -1, &rect, DT_LEFT | DT_BOTTOM);
    rect.left+=200;
    rect.right+=550;
    DrawText(hdc, user->email, -1, &rect, DT_LEFT | DT_BOTTOM);
    rect.top+=100;
    rect.bottom+=100;
    rect.left-=200;
    rect.right-=550;
    DrawText(hdc, "CIUDAD:", -1, &rect, DT_LEFT | DT_BOTTOM);
    rect.left+=200;
    rect.right+=200;
    DrawText(hdc, user->city, -1, &rect, DT_LEFT | DT_BOTTOM);
    rect.top+=100;
    rect.bottom+=100;
    rect.left-=200;
    rect.right-=200;
    DrawText(hdc, "GUSTOS:", -1, &rect, DT_LEFT | DT_BOTTOM);
    char result[100]; // Tamaño suficiente para almacenar el resultado
    rect.left+=200;
    rect.right+=700;
    sprintf(result, "%s, %s, %s, %s, %s", user->hobbies[0], user->hobbies[1], user->hobbies[2], user->hobbies[3],user->hobbies[4]);
    DrawText(hdc, result, -1, &rect, DT_LEFT | DT_BOTTOM);
}