//
// Created by marti on 26/05/2023.
//
#include <Windows.h>
#include <stdio.h>
#include <CommCtrl.h>
#include "main.h"
#include "dictionary.h"
void print_screen_trend(HDC hdc,Dict* dict){
    RECT rect = {400, 50, 1302, 727 };
    int top[10] = {0,0,0,0,0,0,0,0,0,0};
    top_10(top,dict);
    rect.top+=20;
    rect.bottom+=20;
    for (int b = 0; b<10; b++){     //imprimir top 10
        char trend_word[100];
        sprintf(trend_word, "%d. '%s' con %d repeticiones.", b+1, dict->items[top[b]].key, dict->items[top[b]].count);
        if (top[b] != 0){
            rect.top+=60;
            rect.bottom+=60;
            DrawText(hdc, trend_word, -1, &rect, DT_LEFT);
        }
    }
}
void print_screen_error(HDC hdc){
    RECT rect = {1220, 560, 1420, 620 };
    DrawText(hdc, "ERROR: Email debe\nterminar con '@gmail.com'!!", -1, &rect, DT_LEFT);
}

void print_screen_error2(HDC hdc){
    RECT rect3 = {200, 637, 600, 687 };
    printf("\nERROR: Tienes que llenar todos los campos!");
    DrawText(hdc, "ERROR: Tienes que llenar todos los campos!", -1, &rect3, DT_CENTER | DT_BOTTOM);
}

void print_screen_error3(HDC hdc){
    RECT rect2 = {700, 637, 1100, 687 };
    printf("\nERROR: Nombre de usuario no disponible!");
    DrawText(hdc, "ERROR: Nombre de usuario no disponible!", -1, &rect2, DT_CENTER | DT_BOTTOM);
}

void print_screen_error4(HDC hdc){
    RECT rect3 = {200, 677, 600, 727 };
    printf("\nERROR: Tienes que llenar todos los campos!");
    DrawText(hdc, "ERROR: Tienes que llenar todos los campos!", -1, &rect3, DT_CENTER | DT_BOTTOM);
}

void print_screen_error5(HDC hdc){
    RECT rect = {1200, 509, 1400, 582 };
    DrawText(hdc, "ERROR: Los password\ndeben coincidir!!", -1, &rect, DT_VCENTER | DT_LEFT);
}

void print_screen_error6(HDC hdc){
    RECT rect2 = {200, 637, 1100, 687 };
    DrawText(hdc, "ERROR: Gamer no registrado", -1, &rect2, DT_VCENTER | DT_LEFT);
}


void print_screen_error7(HDC hdc){
    RECT rect3 = {200, 637, 1100, 687 };
    DrawText(hdc, "ERROR: Peticion ya enviada o gamer amigo", -1, &rect3, DT_VCENTER | DT_LEFT);
}

void print_screen_error8(HDC hdc){
    RECT rect3 = {900, 637, 1200, 687 };
    DrawText(hdc, "ERROR: Usuario no existente", -1, &rect3, DT_VCENTER | DT_LEFT);
}

void print_screen_users(User* list,HDC hdc){
    RECT rect2 = { 100, 130, 220, 160 };
    User* aux=list;
    while (aux!= NULL){
        printf("asd");
        DrawText(hdc, aux->user, -1, &rect2, DT_LEFT | DT_BOTTOM);
        rect2.top+=35;
        rect2.bottom+=35;
        aux = aux->next;
        if (rect2.bottom>=700){
            rect2.bottom=160;
            rect2.top=130;
            rect2.left+=140;
            rect2.right+=140;
        }
    }
    printf("fora");
}

void print_screen_publi(User* current,Publicacion* new_post,HDC hdc,int aser){
    RECT rect = {260, 140, 1122, 687 };
    SetBkColor(hdc, RGB(100, 100, 125));
    if (aser<current->numfriends){
        DrawText(hdc, new_post->post, -1, &rect, DT_CENTER | DT_TOP);
        printf("\n%s",new_post->post);}
    else DrawText(hdc, "No hay mas publicaciones disponibles", -1, &rect, DT_CENTER | DT_TOP);

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

void print_screen_fr(User* current_user,HDC hdc){
    RECT rect = {260, 140, 1122, 687 };
    if (current_user->friend_request->first!=NULL){
        print_me_screen(current_user->friend_request->first->user,hdc);}
    else DrawText(hdc, "No hay solicitudes entrantes.", -1, &rect, DT_CENTER | DT_TOP);
}