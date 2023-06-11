//
// Created by marti on 26/05/2023.
//
#include <Windows.h>
#include <stdio.h>
#include <CommCtrl.h>
#include "main.h"
#include "dictionary.h"
void print_screen_trend(HDC hdc,Dict* dict){ //Tendencias, palabras mas usadas, usamos diccionary.h.
    RECT rect = {400, 50, 1302, 727 };//Creamos el rect, espacio de la pantalla que vamos a reservar
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
            DrawText(hdc, trend_word, -1, &rect, DT_LEFT);//Escribimos en pantalla (la implementacion esta explicada en dictionary.c)
        }
    }
}
void print_screen_error(HDC hdc){//ERROR EN EMAIL
    RECT rect = {1180, 560, 1420, 620 };//Creamos el rect, espacio de la pantalla que vamos a reservar
    DrawText(hdc, "ERROR: Email debe\nterminar con '@gmail.com'!!", -1, &rect, DT_LEFT);//Imprimimos en la interfaz
}

void print_screen_error2(HDC hdc){//ERROR EN REGISTRO
    RECT rect3 = {200, 637, 600, 687 };//Creamos el rect, espacio de la pantalla que vamos a reservar
    printf("\nERROR: Tienes que llenar todos los campos!");
    DrawText(hdc, "ERROR: Tienes que llenar todos los campos!", -1, &rect3, DT_CENTER | DT_BOTTOM);//Imprimimos en la interfaz
}

void print_screen_error3(HDC hdc){//ERROR EN REGISTRO
    RECT rect2 = {700, 637, 1100, 687 };//Creamos el rect, espacio de la pantalla que vamos a reservar
    printf("\nERROR: Gamer no disponible!");
    DrawText(hdc, "ERROR: Gamer no disponible!", -1, &rect2, DT_CENTER | DT_BOTTOM);//Imprimimos en la interfaz
}

void print_screen_error4(HDC hdc){//ERROR EN REGISTRO
    RECT rect3 = {200, 677, 600, 727 };//Creamos el rect, espacio de la pantalla que vamos a reservar
    printf("\nERROR: Tienes que llenar todos los campos!");
    DrawText(hdc, "ERROR: Tienes que llenar todos los campos!", -1, &rect3, DT_CENTER | DT_BOTTOM);//Imprimimos en la interfaz
}

void print_screen_error5(HDC hdc){//ERROR EN REGISTRO
    RECT rect = {1200, 509, 1400, 582 };//Creamos el rect, espacio de la pantalla que vamos a reservar
    printf("\nERROR: Los password\ndeben coincidir!!");
    DrawText(hdc, "ERROR: Los password\ndeben coincidir!!", -1, &rect, DT_VCENTER | DT_LEFT);//Imprimimos en la interfaz
}

void print_screen_error6(HDC hdc){//ERROR EN ENVIAR SOLICITUD
    RECT rect2 = {200, 637, 1100, 687 };//Creamos el rect, espacio de la pantalla que vamos a reservar
    printf("\nERROR: Gamer no registrado");
    DrawText(hdc, "ERROR: Gamer no registrado", -1, &rect2, DT_VCENTER | DT_LEFT);//Imprimimos en la interfaz
}


void print_screen_error7(HDC hdc){//ERROR EN ENVIAR SOLICITUD
    RECT rect3 = {200, 637, 1100, 687 };//Creamos el rect, espacio de la pantalla que vamos a reservar
    printf("\nERROR: Peticion ya enviada o gamer amigo");
    DrawText(hdc, "ERROR: Peticion ya enviada o gamer amigo", -1, &rect3, DT_VCENTER | DT_LEFT);//Imprimimos en la interfaz
}

void print_screen_error8(HDC hdc){//ERROR EN INICIAR SESION
    RECT rect3 = {900, 637, 1400, 687 };//Creamos el rect, espacio de la pantalla que vamos a reservar
    printf("\nERROR: Usuario no existente");
    DrawText(hdc, "ERROR: Gamer no existente", -1, &rect3, DT_VCENTER | DT_LEFT);//Imprimimos en la interfaz
}

void print_screen_users(User* list,HDC hdc){//Imprimir todos los usuarios
    RECT rect2 = { 100, 130, 220, 160 };//Creamos el rect, espacio de la pantalla que vamos a reservar
    User* aux=list;//Usamos una lista auxiliar que podamos vaciar
    while (aux!= NULL){//Hasta terminar con todos
        DrawText(hdc, aux->user, -1, &rect2, DT_LEFT | DT_BOTTOM);//escribimos el user
        rect2.top+=35;
        rect2.bottom+=35;
        aux = aux->next;//avanzamos
        if (rect2.bottom>=700){//Hemos terminado una columna
            rect2.bottom=160;
            rect2.top=130;
            rect2.left+=140;
            rect2.right+=140;
        }
    }
}

void print_screen_publi(User* current,Publicacion* new_post,HDC hdc,int aser){//Imprimir una publicacion
    RECT rect = {260, 240, 1122, 687 };//Creamos el rect, espacio de la pantalla que vamos a reservar
    RECT rect2 = {260, 140, 1122, 230 };//Creamos el rect, espacio de la pantalla que vamos a reservar
    SetBkColor(hdc, RGB(100, 100, 125));//Color de subrallado (fondo del texto)
    if (aser<current->numfriends){
        SetTextColor(hdc,RGB(0,0,0));//Cambiamos color de texto
        DrawText(hdc, new_post->post, -1, &rect, DT_CENTER | DT_TOP);//Imprimimos el post
        SetTextColor(hdc,RGB(80, 80, 80));//Cambiamos color de texto
        DrawText(hdc, current->friends[aser]->user, -1, &rect2, DT_RIGHT | DT_TOP);//Imprimimos el usuario autor
        printf("\nPost: %s",new_post->post);}//Imprimimos tambien por terminal
    else{//Nos quedamos sin publicaciones
        RECT rect = {260, 140, 1122, 687 };//Creamos el rect, espacio de la pantalla que vamos a reservar
        DrawText(hdc, "No hay mas publicaciones disponibles", -1, &rect, DT_CENTER | DT_TOP);}//Hemos llegado al final

}

void print_me_screen (User* user,HDC hdc){//Imprimimos un menu de usuario
    RECT rect = { 150, 50, 320, 100 };//Creamos el rect, espacio de la pantalla que vamos a reservar
    DrawText(hdc, "GAMER:", -1, &rect, DT_LEFT | DT_BOTTOM);//Indicamos el apartado
    rect.left+=200;//Hay que adaptar el rect, para no escribir en el mismo sitio.
    rect.right+=400;//Hay que adaptar el rect, para no escribir en el mismo sitio.
    DrawText(hdc, user->user, -1, &rect, DT_LEFT | DT_BOTTOM);//Imprimimos en la interfaz
    rect.top+=100;
    rect.bottom+=100;
    rect.left-=200;
    rect.right-=400;
    DrawText(hdc, "NOMBRE:", -1, &rect, DT_LEFT | DT_BOTTOM);//Imprimimos en la interfaz
    rect.left+=200;
    rect.right+=200;
    DrawText(hdc, user->name, -1, &rect, DT_LEFT | DT_BOTTOM);//Imprimimos en la interfaz
    rect.top+=100;
    rect.bottom+=100;
    rect.left-=200;
    rect.right-=200;
    DrawText(hdc, "EDAD:", -1, &rect, DT_LEFT | DT_BOTTOM);//Imprimimos en la interfaz
    rect.left+=200;
    rect.right+=200;
    char to_str[5]; // Tamaño suficiente para almacenar la cadena
    sprintf(to_str, "%d", user->age);
    DrawText(hdc, to_str, -1, &rect, DT_LEFT | DT_BOTTOM);//Imprimimos en la interfaz
    rect.top+=100;
    rect.bottom+=100;
    rect.left-=200;
    rect.right-=200;
    DrawText(hdc, "EMAIL:", -1, &rect, DT_LEFT | DT_BOTTOM);//Imprimimos en la interfaz
    rect.left+=200;
    rect.right+=550;
    DrawText(hdc, user->email, -1, &rect, DT_LEFT | DT_BOTTOM);//Imprimimos en la interfaz
    rect.top+=100;
    rect.bottom+=100;
    rect.left-=200;
    rect.right-=550;
    DrawText(hdc, "CIUDAD:", -1, &rect, DT_LEFT | DT_BOTTOM);//Imprimimos en la interfaz
    rect.left+=200;
    rect.right+=200;
    DrawText(hdc, user->city, -1, &rect, DT_LEFT | DT_BOTTOM);//Imprimimos en la interfaz
    rect.top+=100;
    rect.bottom+=100;
    rect.left-=200;
    rect.right-=200;
    DrawText(hdc, "JUEGOS:", -1, &rect, DT_LEFT | DT_BOTTOM);//Imprimimos en la interfaz
    char result[100]; // Tamaño suficiente para almacenar el resultado
    rect.left+=200;
    rect.top-=42;
    rect.right+=700;
    sprintf(result, "\n%s, %s, %s, %s, %s", user->hobbies[0], user->hobbies[1], user->hobbies[2], user->hobbies[3],user->hobbies[4]);
    DrawText(hdc, result, -1, &rect, DT_LEFT | DT_BOTTOM);
    printf("%s",result);
}

void print_screen_fr(User* current_user,HDC hdc){//Imprimimos las Friend Request
    RECT rect = {260, 140, 1122, 687 };//Creamos el rect, espacio de la pantalla que vamos a reservar
    if (current_user->friend_request->first!=NULL){//Si no esta vacio
        print_me_screen(current_user->friend_request->first->user,hdc);}//Imprimimos el perfil del solicitante por pantalla
    else DrawText(hdc, "No hay solicitudes entrantes.", -1, &rect, DT_CENTER | DT_TOP);//Esta vacio, lo informamos.
}