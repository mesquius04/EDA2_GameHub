//
// Created by marti on 26/05/2023.
//
#include <Windows.h>
#include <stdio.h>
#include <CommCtrl.h>
#include "main.h"
void print_screen_error(HDC hdc){
    RECT rect9 = {1200, 600, 1400, 680 };
    DrawText(hdc, "Email must have\n'@gmail.com' ending!!", -1, &rect9, DT_LEFT);
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