#include <Windows.h>
#include <stdio.h>
#include <CommCtrl.h>
#include "main.h"
#include "services.h"
#include "visual_functions.h"
#include "dictionary.h"
#include "queue_functions.h"
#include "user_functions.h"
HINSTANCE hInst;
HBRUSH hBrush;
int LOGGED=FALSE;
User* current_user;
#define MAX_LENGHT 20
char username[30],usersearch[30],userlogin[30],userpass[30],new_publi[300],password1[30],password2[30],newname[MAX_LENGTH],age[3],newhobbie[MAX_LENGTH],newemail[MAX_LENGHT],newcity[MAX_LENGTH];
User new_user;
int condition=0,condition2=0,condition3=0,condition4=0,condition5=0,condition6=0;
User* list_of_user = NULL;
Dict* dict;
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
HWND button1,button2,button3,button4,button5,buttonLIST,button388,button_next_post,button_prev_post,button6,button7,button8,button9,button10,button188,buttonCHAT,button288,button_me,button_log_out,button11,button12,button66,buttonFR,buttonFRprev,buttonFRcheck,buttoncreatepubli,buttonshowpubli,hEditControlCHAT,hEditControlFR,hEditControl22,hEditControl33,hEditControl,hEditControl2,hEditControl3,hEditControl4,hEditControl5,hEditControl6,hEditControl7,hEditControl7_1,hEditControl7_2,hEditControl7_3,hEditControl7_4,hEditControl8;
int i=0,h=0,k=0,error=0,pass_error=0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    HWND hWnd;
    MSG msg;
    WNDCLASS wc;
    hInst = hInstance;
    ZeroMemory(&wc, sizeof(WNDCLASS));
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.lpszClassName = "MyWindowClass";



    RegisterClass(&wc);

    // Crear finestra
    hWnd = CreateWindow("MyWindowClass", "GAMEHUB", WS_OVERLAPPEDWINDOW, 77, 43, 1382, 777, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, nCmdShow);
    SetClassLongPtr(hWnd, GCLP_HBRBACKGROUND, (LONG)GetStockObject(LTGRAY_BRUSH));

    ShowWindow(hWnd, nCmdShow);

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    HFONT hFont; //Definim una primera font(tipus de lletra)
    hFont = CreateFont(400, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
                       CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial");
    switch (msg) {
        case WM_CREATE:{ //Creem tots els elements que utlitzarem, EditControl per poder entrar text i Buttons per poder clickar
            dict = initialize_dictionary(1000);//Inicialitzem diccionari

            FILE* fp= fopen("../resources/user_list","r");//Obrim el fitxer que conté users inicials
            while (fscanf(fp,"%s %s %s %d %s h:%s %s %s %s %s %s",new_user.user,new_user.password,new_user.name,&new_user.age,new_user.city,new_user.hobbies[0],new_user.hobbies[1],new_user.hobbies[2],new_user.hobbies[3],new_user.hobbies[4],new_user.email)>0){
                new_user.friends = NULL;
                add_user_to_list(&list_of_user, new_user); //Els afegim a la llista
            }
            fclose(fp);//Tanquem el fitxer
            hEditControl = CreateWindow("EDIT", "", SW_HIDE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                        300, 300, 800, 70, hWnd, (HMENU)20, hInst, NULL);
            hFont = CreateFont(20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                               CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Courier New Black");

            SendMessage(hEditControl, WM_SETFONT, (WPARAM)hFont, TRUE);

            hEditControl2 = CreateWindow("EDIT", "", SW_HIDE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_PASSWORD,
                                         300, 420, 800, 70, hWnd, (HMENU)21, hInst, NULL);//Cada Editcontrol té: 1.Nom, 2.Text inicial, 3.Propietats i
            hEditControl3 = CreateWindow("EDIT", "", SW_HIDE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_PASSWORD,
                                         300, 510, 800, 70, hWnd, (HMENU)22, hInst, NULL);
            hEditControl4 = CreateWindow("EDIT", "", SW_HIDE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                         300, 200, 900, 60, hWnd, (HMENU)23, hInst, NULL);
            hEditControl5 = CreateWindow("EDIT", "", SW_HIDE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                         300, 300, 900, 60, hWnd, (HMENU)24, hInst, NULL);
            hEditControl6 = CreateWindow("EDIT", "", SW_HIDE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                         300, 400, 900, 60, hWnd, (HMENU)25, hInst, NULL);
            hEditControl7 = CreateWindow("EDIT", "", SW_HIDE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                         300, 500, 170, 60, hWnd, (HMENU)26, hInst, NULL);
            hEditControl8 = CreateWindow("EDIT", "", SW_HIDE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                         300, 600, 900, 60, hWnd, (HMENU)27, hInst, NULL);
            hEditControl7_1 = CreateWindow("EDIT", "", SW_HIDE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                         482, 500, 170, 60, hWnd, (HMENU)2743, hInst, NULL);
            hEditControl7_2 = CreateWindow("EDIT", "", SW_HIDE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                           664, 500, 170, 60, hWnd, (HMENU)2217, hInst, NULL);
            hEditControl7_3 = CreateWindow("EDIT", "", SW_HIDE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                           847, 500, 170, 60, hWnd, (HMENU)1227, hInst, NULL);
            hEditControl7_4 = CreateWindow("EDIT", "", SW_HIDE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                           1030, 500, 170, 60, hWnd, (HMENU)2527, hInst, NULL);
            button66 = CreateWindowEx(
                    0,
                    "BUTTON",
                    "LOG IN",
                    SW_HIDE | WS_CHILD | BS_DEFPUSHBUTTON,
                    550, 600, 270, 110,
                    hWnd,
                    (HMENU)31,
                    hInst,
                    NULL
            );
            hEditControl22 = CreateWindow("EDIT", "", SW_HIDE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                          350, 300, 800, 70, hWnd, (HMENU)28, hInst, NULL);
            hEditControl33 = CreateWindow("EDIT", "", SW_HIDE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_PASSWORD,
                                          350, 420, 800, 70, hWnd, (HMENU)29, hInst, NULL);
            hEditControlFR = CreateWindow("EDIT", "", SW_HIDE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                          620, 641, 620, 55, hWnd, (HMENU)30, hInst, NULL);
            hEditControlCHAT = CreateWindow("EDIT", "", SW_HIDE | WS_CHILD | WS_BORDER | ES_MULTILINE,
                                          200, 535, 922, 190, hWnd, (HMENU)41, hInst, NULL);
            buttonCHAT = CreateWindowEx(
                    0,
                    "BUTTON",
                    "SEND",
                    SW_HIDE | WS_CHILD | BS_DEFPUSHBUTTON,
                    1122, 645, 100, 80,
                    hWnd,
                    (HMENU)100,
                    hInst,
                    NULL
            );
            buttonFR = CreateWindowEx(
                    0,
                    "BUTTON",
                    "FOLLOW",
                    SW_HIDE | WS_CHILD | BS_DEFPUSHBUTTON,
                    1250, 639, 75, 62,
                    hWnd,
                    (HMENU)66,
                    hInst,
                    NULL
            );
            buttonFRprev = CreateWindowEx(
                    0,
                    "BUTTON",
                    "ENVIAR SOLICITUD",
                    SW_HIDE | WS_CHILD | BS_DEFPUSHBUTTON,
                    30, 387, 260, 60,
                    hWnd,
                    (HMENU)200,
                    hInst,
                    NULL
            );
            buttonFRcheck = CreateWindowEx(
                    0,
                    "BUTTON",
                    "ACEPTAR GAMERS",
                    SW_HIDE | WS_CHILD | BS_DEFPUSHBUTTON,
                    30, 297, 260, 60,
                    hWnd,
                    (HMENU)201,
                    hInst,
                    NULL
            );
            buttonLIST = CreateWindowEx(
                    0,
                    "BUTTON",
                    "LISTADO DE USERS",
                    SW_HIDE | WS_CHILD | BS_DEFPUSHBUTTON,
                    30, 477, 260, 60,
                    hWnd,
                    (HMENU)203,
                    hInst,
                    NULL
            );
            buttonshowpubli = CreateWindowEx(
                    0,
                    "BUTTON",
                    "VER PUBLICACIONES",
                    SW_HIDE | WS_CHILD | BS_DEFPUSHBUTTON,
                    30, 567, 260, 60,
                    hWnd,
                    (HMENU)204,
                    hInst,
                    NULL
            );
            buttoncreatepubli = CreateWindowEx(
                    0,
                    "BUTTON",
                    "NUEVA PUBLICACION",
                    SW_HIDE | WS_CHILD | BS_DEFPUSHBUTTON,
                    30, 657, 260, 60,
                    hWnd,
                    (HMENU)205,
                    hInst,
                    NULL
            );
            button_me = CreateWindowEx(
                    0,
                    "BUTTON",
                    "ME",
                    SW_HIDE | WS_CHILD | BS_DEFPUSHBUTTON,
                    5, 5, 150, 40,
                    hWnd,
                    (HMENU)221,
                    hInst,
                    NULL
            );
            button_log_out = CreateWindowEx(
                    0,
                    "BUTTON",
                    "LOG OUT",
                    SW_HIDE | WS_CHILD | BS_DEFPUSHBUTTON,
                    165, 5, 150, 40,
                    hWnd,
                    (HMENU)222,
                    hInst,
                    NULL
            );
            SendMessage(hEditControl2, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hEditControl3, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hEditControl4, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hEditControl5, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hEditControl6, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hEditControl7, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hEditControl7_1, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hEditControl7_2, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hEditControl7_3, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hEditControl7_4, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hEditControl8, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hEditControl22, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hEditControl33, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hEditControlFR, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hEditControlCHAT, WM_SETFONT, (WPARAM)hFont, TRUE);
            button5 = CreateWindowEx(
                    0,
                    "BUTTON",
                    "Apply",
                    SW_HIDE | WS_CHILD | BS_DEFPUSHBUTTON,
                    1100, 299, 100, 73,
                    hWnd,
                    (HMENU)6,
                    hInst,
                    NULL
            );
            button6 = CreateWindowEx(
                    0,
                    "BUTTON",
                    "Apply",
                    SW_HIDE | WS_CHILD | BS_DEFPUSHBUTTON,
                    1100, 419, 100, 73,
                    hWnd,
                    (HMENU)7,
                    hInst,
                    NULL
            );
            button7 = CreateWindowEx(
                    0,
                    "BUTTON",
                    "Apply",
                    SW_HIDE | WS_CHILD | BS_DEFPUSHBUTTON,
                    1100, 509, 100, 73,
                    hWnd,
                    (HMENU)8,
                    hInst,
                    NULL
            );
            button12 = CreateWindowEx(
                    0,
                    "BUTTON",
                    "REGISTRAR",
                    SW_HIDE | WS_CHILD | BS_DEFPUSHBUTTON,
                    1200, 596, 120, 69,
                    hWnd,
                    (HMENU)13,
                    hInst,
                    NULL
            );
            button188 = CreateWindowEx(
                    0,
                    "BUTTON",
                    "BACK",
                    SW_HIDE | WS_CHILD | BS_DEFPUSHBUTTON,
                    10, 10, 82, 40,
                    hWnd,
                    (HMENU)188,
                    hInst,
                    NULL
            );
            button288 = CreateWindowEx(
                    0,
                    "BUTTON",
                    "BACK",
                    SW_HIDE | WS_CHILD | BS_DEFPUSHBUTTON,
                    10, 10, 82, 40,
                    hWnd,
                    (HMENU)288,
                    hInst,
                    NULL
            );
            button388 = CreateWindowEx(
                    0,
                    "BUTTON",
                    "BACK",
                    SW_HIDE | WS_CHILD | BS_DEFPUSHBUTTON,
                    10, 10, 82, 40,
                    hWnd,
                    (HMENU)388,
                    hInst,
                    NULL
            );
            button1 = CreateWindowEx(
                    0,
                    "BUTTON",
                    "Button 1",
                    WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                    160, 335, 430, 170,
                    hWnd,
                    (HMENU)1,
                    hInst,
                    NULL
            );

            button2 = CreateWindowEx(
                    0,
                    "BUTTON",
                    "Button 2",
                    WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                    740, 335, 430, 170,
                    hWnd,
                    (HMENU)2,
                    hInst,
                    NULL);

            button3 = CreateWindowEx(
                    0,
                    "BUTTON",
                    "Button 3",
                    WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                    160, 535, 430, 170,
                    hWnd,
                    (HMENU)3,
                    hInst,
                    NULL);

            button4 = CreateWindowEx(
                    0,
                    "BUTTON",
                    "Button 4",
                    WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                    740, 535, 430, 170,
                    hWnd,

                    (HMENU)4,
                    hInst,
                    NULL);
            button_next_post = CreateWindowEx(
                    0,
                    "BUTTON",
                    "BACK",
                    SW_HIDE | WS_CHILD | BS_DEFPUSHBUTTON,
                    1182, 612, 100, 65,
                    hWnd,
                    (HMENU)208,
                    hInst,
                    NULL
            );
            button_prev_post = CreateWindowEx(
                    0,
                    "BUTTON",
                    "NEXT",
                    SW_HIDE | WS_CHILD | BS_DEFPUSHBUTTON,
                    100, 612, 100, 65,
                    hWnd,
                    (HMENU)209,
                    hInst,
                    NULL
            );
            break;
        }
        case WM_COMMAND: {
            switch (LOWORD(wParam)) {
                case 1: { //Registro de usuario
                    i=1;
                    ShowWindow(button1, SW_HIDE);
                    ShowWindow(button2, SW_HIDE);
                    ShowWindow(button3, SW_HIDE);
                    ShowWindow(button4, SW_HIDE);//Amaguem pestanya principal

                    ShowWindow(button188,SW_SHOW); //Boton de back (case 188)

                    ShowWindow(hEditControl,SW_SHOW);
                    ShowWindow(button5,SW_SHOW);
                    ShowWindow(hEditControl2,SW_SHOW);
                    ShowWindow(button6,SW_SHOW);
                    ShowWindow(hEditControl3,SW_SHOW);
                    ShowWindow(button7,SW_SHOW);//Ensenyem els nous botons i EditControls(espai on posar text)

                    InvalidateRect(hWnd, NULL, TRUE); //Invalidem la disposició de l'anterior pestanya
                    break;
                }
                case 2: { //PRINT LISTADO DE USERS
                    i=2;//Cal canviar 'i' ja que aquesta determina WM_PAINT, marca el fons de pantalla i les lletres.
                    ShowWindow(button1, SW_HIDE);
                    ShowWindow(button2, SW_HIDE);
                    ShowWindow(button3, SW_HIDE);
                    ShowWindow(button4, SW_HIDE);//Amaguem pestanya principal

                    ShowWindow(button188,SW_SHOW); //Ensenyem botó de back amb id button188
                    print_console_users(list_of_user); //FUNCIÓ EN DOC VISUALFUNCTIONS
                    InvalidateRect(hWnd, NULL, TRUE); //Invalidem la disposició de l'anterior pestanya
                    break;
                }
                case 3: { //INICIAR SESION
                    i=3;//Cal canviar 'i' ja que aquesta determina WM_PAINT, marca el fons de pantalla i les lletres.
                    ShowWindow(button1, SW_HIDE);
                    ShowWindow(button2, SW_HIDE);
                    ShowWindow(button3, SW_HIDE);
                    ShowWindow(button4, SW_HIDE);//Amaguem pestanya principal

                    ShowWindow(hEditControl22,SW_SHOW);
                    ShowWindow(hEditControl33,SW_SHOW);
                    ShowWindow(button66,SW_SHOW);//Boton iniciar sesion

                    ShowWindow(button188,SW_SHOW);//Boton del back

                    InvalidateRect(hWnd, NULL, TRUE);//Invalidem la disposició de l'anterior pestanya
                    break;
                }
                case 4: {//CASE SALIR
                    DestroyWindow(hWnd); //Destrueix la finestra creada i finalitza l'execució.
                    break;
                }
                case 6:{
                    if (find_user(username,list_of_user)==NULL && strlen(username)<MAX_LENGHT && strlen(username)>=5){
                        strcpy(new_user.user,username);
                        printf("\nuser: %s",new_user.user);
                        condition=1;}
                    else {error=1;
                    InvalidateRect(hWnd, NULL, TRUE);
                    UpdateWindow(hWnd);}
                    break;
                }
                case 7:{
                    if (strlen(password1)<MAX_LENGHT && strlen(password1)>=5){
                        condition2=1;}
                    break;
                }
                case 8:{
                    if (condition==1 && condition2==1 && strcmp(password1,password2)==0){
                        condition=0;
                        pass_error=0;
                        strcpy(new_user.password,password1);
                        printf("\npass: %s",new_user.password);
                        i=7;
                        error=0;
                        ShowWindow(hEditControl4, SW_SHOW);
                        ShowWindow(hEditControl5, SW_SHOW);
                        ShowWindow(hEditControl6, SW_SHOW);
                        ShowWindow(hEditControl7, SW_SHOW);
                        ShowWindow(hEditControl7_1, SW_SHOW);
                        ShowWindow(hEditControl7_2, SW_SHOW);
                        ShowWindow(hEditControl7_3, SW_SHOW);
                        ShowWindow(hEditControl7_4, SW_SHOW);
                        ShowWindow(hEditControl8, SW_SHOW);
                        ShowWindow(button288,SW_SHOW);
                        ShowWindow(button8,SW_SHOW);
                        ShowWindow(button9,SW_SHOW);
                        ShowWindow(button10,SW_SHOW);
                        ShowWindow(button11,SW_SHOW);
                        ShowWindow(button12,SW_SHOW);
                        ShowWindow(button5,SW_HIDE);
                        ShowWindow(hEditControl,SW_HIDE);
                        ShowWindow(button6,SW_HIDE);
                        ShowWindow(button188,SW_HIDE);
                        ShowWindow(hEditControl2,SW_HIDE);
                        ShowWindow(button7,SW_HIDE);
                        ShowWindow(hEditControl3,SW_HIDE);
                        SetWindowText(hEditControl, "");
                        SetWindowText(hEditControl2, "");
                        SetWindowText(hEditControl3, "");
                        error=0;
                        InvalidateRect(hWnd, NULL, TRUE);
                        UpdateWindow(hWnd);}
                    else if (error==1){
                        error=3;
                        InvalidateRect(hWnd, NULL, TRUE);
                        UpdateWindow(hWnd);}
                    else {error=2;
                        InvalidateRect(hWnd, NULL, TRUE);
                        UpdateWindow(hWnd);}
                    if (strcmp(password1,password2)!=0){
                        pass_error=1;
                    }
                    break;
                }
                case 13:{
                    GetWindowText(hEditControl8, newemail, 30);
                    if (strlen(newemail)<=MAX_LENGTH){
                        GetWindowText(hEditControl6, newcity, 30);
                        GetWindowText(hEditControl4, newname, 30);
                        GetWindowText(hEditControl5, age, 3);
                        GetWindowText(hEditControl7, new_user.hobbies[0], 30);
                        GetWindowText(hEditControl7_1, new_user.hobbies[1], 30);
                        GetWindowText(hEditControl7_2, new_user.hobbies[2], 30);
                        GetWindowText(hEditControl7_3, new_user.hobbies[3], 30);
                        GetWindowText(hEditControl7_4,new_user.hobbies[4], 30);
                        if (strlen(newcity)<=MAX_LENGTH){
                            strcpy(new_user.city,newcity);
                            printf("\ncity: %s",new_user.city);
                            condition5=1;
                        }
                        if (strcmp(new_user.hobbies[0],"")!=0){
                            strcpy(new_user.city,newcity);
                            printf("\nhobbie1: %s",new_user.hobbies[0]);
                            condition6=1;
                        }
                        if (strlen(newname)<=MAX_LENGTH){
                            condition3=1;
                            strcpy(new_user.name,newname);
                            printf("\nname: %s",new_user.name);
                        }
                        if (strlen(age)<=3){
                            int newage=0;
                            for (int k=0;k<2;k++){
                                newage*=10;
                                newage+=(int)age[k]-48;
                            }
                            new_user.age=newage;
                            condition4=1;
                            printf("\nage: %d",new_user.age);
                        }
                        strcpy(new_user.email,newemail);
                        printf("\nCorreu: %s", new_user.email);
                        if (validar_email(newemail)) {
                            printf("\nCorreu: %s", new_user.email);
                            printf("\n%d %d %d %d %d",condition3,condition4,condition5,condition6);
                            if (condition3 == 1 && condition4 == 1 && condition5 == 1 && condition6 == 1) {
                                new_user.friends = NULL;
                                add_user_to_list(&list_of_user, new_user);
                                condition = 0, condition2 = 0, condition3 = 0, condition4 = 0, condition5 = 0, condition6 = 0;
                                ShowWindow(hEditControl4, SW_HIDE);
                                ShowWindow(hEditControl5, SW_HIDE);
                                ShowWindow(hEditControl6, SW_HIDE);
                                ShowWindow(hEditControl7, SW_HIDE);
                                ShowWindow(hEditControl7_1, SW_HIDE);
                                ShowWindow(hEditControl7_2, SW_HIDE);
                                ShowWindow(hEditControl7_3, SW_HIDE);
                                ShowWindow(hEditControl7_4, SW_HIDE);
                                ShowWindow(hEditControl8, SW_HIDE);
                                SetWindowText(hEditControl4, "");
                                SetWindowText(hEditControl5, "");
                                SetWindowText(hEditControl6, "");
                                SetWindowText(hEditControl7, "");
                                SetWindowText(hEditControl7_1, "");
                                SetWindowText(hEditControl7_2, "");
                                SetWindowText(hEditControl7_3, "");
                                SetWindowText(hEditControl7_4, "");
                                SetWindowText(hEditControl8, "");
                                ShowWindow(button8, SW_HIDE);
                                ShowWindow(button9, SW_HIDE);
                                ShowWindow(button10, SW_HIDE);
                                ShowWindow(button11, SW_HIDE);
                                ShowWindow(button12, SW_HIDE);
                                ShowWindow(button1, SW_SHOW);
                                ShowWindow(button2, SW_SHOW);
                                ShowWindow(button3, SW_SHOW);
                                ShowWindow(button4, SW_SHOW);
                                ShowWindow(button288, SW_HIDE);
                                i = 0;
                                k = 0;
                                InvalidateRect(hWnd, NULL, TRUE);
                                UpdateWindow(hWnd);
                            }
                            else {error=2;
                                InvalidateRect(hWnd, NULL, TRUE);
                                UpdateWindow(hWnd);}
                        }
                        else {
                            k=1;
                            InvalidateRect(hWnd, NULL, TRUE);
                        UpdateWindow(hWnd);
                        }
                        break;

                    }
                    break;
                }
                case 20:
                {
                    GetWindowText(hEditControl, username, 30);
                    break;}
                case 21:
                {
                    GetWindowText(hEditControl2, password1, 30);
                    break;}
                case 22:
                {
                    GetWindowText(hEditControl3, password2, 30);
                    break;}
                case 66: //FRIEND REQUEST SEND
                {
                    char searchfr[30];
                    GetWindowText(hEditControlFR,searchfr, 30);
                    SetWindowText(hEditControlFR, "");
                    if (find_user(searchfr,list_of_user)!=NULL){
                        send_friend_request(&list_of_user,&current_user,searchfr); //ROMAN MIRA AIXÒ (aqui cridem la funció)
                        printf("\nSortim de la funció");
                    }
                    else printf("\nNo registrat, SOLICITUD ERROR.");


                    break;
                }
                case 30:
                {
                    GetWindowText(hEditControl8,usersearch, 30);
                    break;}
                case 31:{ //INICIAR SESION
                    GetWindowText(hEditControl22,userlogin,MAX_LENGTH);
                    GetWindowText(hEditControl33,userpass,MAX_LENGHT);
                    if (log_in_data(userlogin,userpass,list_of_user)!=FALSE){
                        i=10;
                        current_user= find_user(userlogin,list_of_user);
                        SetWindowText(hEditControl22, "");
                        SetWindowText(hEditControl33, "");
                        ShowWindow(hEditControl22,SW_HIDE);
                        ShowWindow(hEditControl33,SW_HIDE);
                        ShowWindow(button66,SW_HIDE);
                        ShowWindow(button188,SW_HIDE);
                        ShowWindow(buttonLIST,SW_SHOW);
                        ShowWindow(buttonshowpubli,SW_SHOW);
                        ShowWindow(buttonFRcheck,SW_SHOW);
                        ShowWindow(buttoncreatepubli,SW_SHOW);
                        ShowWindow(button_me,SW_SHOW);
                        ShowWindow(button_log_out,SW_SHOW);
                        ShowWindow(buttonFRprev,SW_SHOW);
                        InvalidateRect(hWnd, NULL, TRUE);
                        UpdateWindow(hWnd);
                        LOGGED=TRUE;}
                    break;
                }


                case 100:{ //NEW PUBLI CASE. ALEX!!
                    GetWindowText(hEditControlCHAT,new_publi,120);
                    SetWindowText(hEditControlCHAT, "");
                    new_post(new_publi,dict, current_user);
                    int top[10] = {0,0,0,0,0,0,0,0,0,0};
                    //0 -> elemento está vacío
                    top_10(top,dict);
                    for (int b = 0; b<10; b++){     //imprimir top 10
                        if (top[b] != 0){
                            printf("[%d} Pos%d: %s, %d times\n", top[b], b+1, dict->items[top[b]].key,dict->items[top[b]].count);
                        }
                    }
                    printf("\nNew msg: %s",new_publi);
                    UpdateWindow(hWnd);
                    break;
                }


                case 188:{//BACK; FIRST ONE
                    i=0;
                    ShowWindow(button1, SW_SHOW);
                    ShowWindow(button2, SW_SHOW);
                    ShowWindow(button3, SW_SHOW);
                    ShowWindow(button4, SW_SHOW);
                    ShowWindow(button188,SW_HIDE);
                    ShowWindow(hEditControl,SW_HIDE);
                    ShowWindow(button5,SW_HIDE);
                    ShowWindow(hEditControl2,SW_HIDE);
                    ShowWindow(button6,SW_HIDE);
                    ShowWindow(hEditControl3,SW_HIDE);
                    ShowWindow(button7,SW_HIDE);
                    ShowWindow(hEditControl22,SW_HIDE);
                    ShowWindow(hEditControl33,SW_HIDE);
                    ShowWindow(button66,SW_HIDE);
                    InvalidateRect(hWnd, NULL, TRUE);
                    break;
                }
                case 288:{ //BACK; SECOND ONE, AFTER FIRST REGISTER SCREEN
                    i=1;
                    ShowWindow(hEditControl4, SW_HIDE);
                    ShowWindow(hEditControl5, SW_HIDE);
                    ShowWindow(hEditControl6, SW_HIDE);
                    ShowWindow(hEditControl7, SW_HIDE);
                    ShowWindow(hEditControl8, SW_HIDE);
                    ShowWindow(button8,SW_HIDE);
                    ShowWindow(button9,SW_HIDE);
                    ShowWindow(button10,SW_HIDE);
                    ShowWindow(button11,SW_HIDE);
                    ShowWindow(button12,SW_HIDE);
                    ShowWindow(button188,SW_SHOW);
                    ShowWindow(hEditControl,SW_SHOW);
                    ShowWindow(button5,SW_SHOW);
                    ShowWindow(hEditControl2,SW_SHOW);
                    ShowWindow(button6,SW_SHOW);
                    ShowWindow(hEditControl3,SW_SHOW);
                    ShowWindow(button7,SW_SHOW);
                    InvalidateRect(hWnd, NULL, TRUE);
                    UpdateWindow(hWnd);
                    break;
                }
                case 388:{ //BACK TO MAIN SCREEN
                    i=10;
                    ShowWindow(buttonLIST,SW_SHOW);
                    ShowWindow(buttonshowpubli,SW_SHOW);
                    ShowWindow(buttonFRcheck,SW_SHOW);
                    ShowWindow(buttoncreatepubli,SW_SHOW);
                    ShowWindow(button_me,SW_SHOW);
                    ShowWindow(button_log_out,SW_SHOW);
                    ShowWindow(button_me,SW_SHOW);
                    ShowWindow(button_log_out,SW_SHOW);
                    ShowWindow(buttonFRprev,SW_SHOW);//Enseñamos los elementos de la pestaña anterior, y cambiamos 'i'.

                    ShowWindow(button_next_post,SW_HIDE);
                    ShowWindow(button_prev_post,SW_HIDE);
                    ShowWindow(hEditControlCHAT,SW_HIDE);
                    ShowWindow(buttonCHAT,SW_HIDE);
                    ShowWindow(button388,SW_HIDE);
                    ShowWindow(hEditControlFR,SW_HIDE);
                    ShowWindow(buttonFR,SW_HIDE); //Escondemos los elementos de todas las ventanas posibles desde la que podemos acceder al boton

                    InvalidateRect(hWnd, NULL, TRUE);
                    UpdateWindow(hWnd);
                    break;
                }
                case 200:{
                    i=12;
                    ShowWindow(buttonLIST,SW_HIDE);
                    ShowWindow(buttonshowpubli,SW_HIDE);
                    ShowWindow(buttonFRcheck,SW_HIDE);
                    ShowWindow(buttoncreatepubli,SW_HIDE);
                    ShowWindow(button_me,SW_HIDE);
                    ShowWindow(button_log_out,SW_HIDE);
                    ShowWindow(buttonFRprev,SW_HIDE);
                    ShowWindow(button_me,SW_HIDE);
                    ShowWindow(button_log_out,SW_HIDE);
                    ShowWindow(hEditControlFR,SW_SHOW);
                    ShowWindow(buttonFR,SW_SHOW);
                    ShowWindow(button388,SW_SHOW);
                    InvalidateRect(hWnd, NULL, TRUE);
                    UpdateWindow(hWnd);
                    break;
                }
                case 203:{
                    i=2;
                    ShowWindow(buttonLIST,SW_HIDE);
                    ShowWindow(buttonshowpubli,SW_HIDE);
                    ShowWindow(buttonFRcheck,SW_HIDE);
                    ShowWindow(buttoncreatepubli,SW_HIDE);
                    ShowWindow(button_me,SW_HIDE);
                    ShowWindow(button_log_out,SW_HIDE);
                    ShowWindow(buttonFRprev,SW_HIDE);

                    ShowWindow(button388,SW_SHOW); //Ensenyem botó de back amb id button188
                    print_console_users(list_of_user);
                    InvalidateRect(hWnd, NULL, TRUE); //Invalidem la disposició de l'anterior pestanya
                    break;
                }
                case 204:{//Ver publicaciones
                    i=15;
                    ShowWindow(buttonLIST,SW_HIDE);
                    ShowWindow(buttonshowpubli,SW_HIDE);
                    ShowWindow(buttonFRcheck,SW_HIDE);
                    ShowWindow(button_me,SW_HIDE);
                    ShowWindow(button_log_out,SW_HIDE);
                    ShowWindow(buttoncreatepubli,SW_HIDE);
                    ShowWindow(buttonCHAT,SW_HIDE);
                    ShowWindow(hEditControlCHAT,SW_HIDE);
                    ShowWindow(buttonFRprev,SW_HIDE);

                    ShowWindow(button_next_post,SW_SHOW);
                    ShowWindow(button_prev_post,SW_SHOW);
                    ShowWindow(button388,SW_SHOW);
                    InvalidateRect(hWnd, NULL, TRUE);
                    UpdateWindow(hWnd);
                    break;
                }
                case 205:{ //Nueva publicacion selecionada.
                    i=13;
                    ShowWindow(buttonLIST,SW_HIDE);
                    ShowWindow(buttonshowpubli,SW_HIDE);
                    ShowWindow(buttonFRcheck,SW_HIDE);
                    ShowWindow(button_me,SW_HIDE);
                    ShowWindow(button_log_out,SW_HIDE);
                    ShowWindow(buttoncreatepubli,SW_HIDE);
                    ShowWindow(buttonCHAT,SW_HIDE);
                    ShowWindow(hEditControlCHAT,SW_HIDE);
                    ShowWindow(buttonFRprev,SW_HIDE);

                    ShowWindow(button388,SW_SHOW);
                    ShowWindow(buttonCHAT,SW_SHOW);
                    ShowWindow(hEditControlCHAT,SW_SHOW);
                    InvalidateRect(hWnd, NULL, TRUE);
                    UpdateWindow(hWnd);
                    break;
                }
                case 221:{ //me screen
                    ShowWindow(buttonLIST,SW_HIDE);
                    ShowWindow(buttonshowpubli,SW_HIDE);
                    ShowWindow(buttonFRcheck,SW_HIDE);
                    ShowWindow(buttoncreatepubli,SW_HIDE);
                    ShowWindow(buttonCHAT,SW_HIDE);
                    ShowWindow(button_me,SW_HIDE);
                    ShowWindow(button_log_out,SW_HIDE);
                    ShowWindow(hEditControlCHAT,SW_HIDE);
                    ShowWindow(buttonFRprev,SW_HIDE);
                    ShowWindow(button388,SW_SHOW);
                    i=14;
                    InvalidateRect(hWnd, NULL, TRUE);
                    UpdateWindow(hWnd);
                    break;
                }
                case 222:{ //log out
                    ShowWindow(buttonLIST,SW_HIDE);
                    ShowWindow(buttonshowpubli,SW_HIDE);
                    ShowWindow(buttonFRcheck,SW_HIDE);
                    ShowWindow(buttoncreatepubli,SW_HIDE);
                    ShowWindow(buttonCHAT,SW_HIDE);
                    ShowWindow(button_me,SW_HIDE);
                    ShowWindow(button_log_out,SW_HIDE);
                    ShowWindow(hEditControlCHAT,SW_HIDE);
                    ShowWindow(buttonFRprev,SW_HIDE);

                    i=0;
                    ShowWindow(button1, SW_SHOW);
                    ShowWindow(button2, SW_SHOW);
                    ShowWindow(button3, SW_SHOW);
                    ShowWindow(button4, SW_SHOW);
                    LOGGED=FALSE;
                    current_user=NULL;
                    InvalidateRect(hWnd, NULL, TRUE);
                    UpdateWindow(hWnd);
                    break;
                }
            }
            break;
        }

        case WM_DESTROY:
            free(list_of_user);
            printf("\n\nVuelva pronto!\n\nExecuccion finalizada correctamente.");
            PostQuitMessage(00);
            break;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            RECT rect;
            HFONT hFont = (HFONT)SendMessage(button4, WM_GETFONT, 0, 0);


            HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);
            if (i==0){
                hBrush = CreateSolidBrush(RGB(70, 0, 70));
                LOGFONT lf = { 0 };
                GetObject(hFont, sizeof(LOGFONT), &lf);
                lf.lfHeight = 23;
                lf.lfItalic=BOLD_FONTTYPE;
                strcpy(lf.lfFaceName,"Courier New Black");
                HFONT hNewFont = CreateFontIndirect(&lf);
                SendMessage(button4, WM_SETFONT, (WPARAM)hNewFont, TRUE);
                SendMessage(button3, WM_SETFONT, (WPARAM)hNewFont, TRUE);
                SendMessage(button2, WM_SETFONT, (WPARAM)hNewFont, TRUE);
                SendMessage(button1, WM_SETFONT, (WPARAM)hNewFont, TRUE);
                SetWindowText(button4, "SALIR");
                SetWindowText(button1, "CREAR NUEVA CUENTA");
                SetWindowText(button2, "LISTADO DE GAMERS");
                SetWindowText(button3, "INICIAR SESION");

                // Seleccionar la fuente en el contexto del dispositivo
                hFont = CreateFont(200, 95, 0, 0, FW_NORMAL, BOLD_FONTTYPE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                                   CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial Black");
                SetBkColor(hdc, RGB(70, 0, 70));
                hOldFont = (HFONT)SelectObject(hdc, hFont);
                SetTextColor(hdc, RGB(200, 160, 200));
                GetClientRect(hWnd, &rect);
                GetClientRect(hWnd, &rect);
                FillRect(hdc, &rect, hBrush); // Pintar la ventana con el brush creado
                DeleteObject(hBrush); // Liberar el brush creado
                rect.top-=360;
                DrawText(hdc, "GAMEHUB", -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

                if (LOGGED){
                    hFont = CreateFont(20, 0, 0, 0, FW_NORMAL, BOLD_FONTTYPE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                                       CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Courier New Black");
                    hOldFont = (HFONT)SelectObject(hdc, hFont);
                    RECT rect5 = { 30, 30, 200, 50 };
                    DrawText(hdc,new_user.user,-1,&rect5,DT_LEFT | DT_VCENTER);
                }}
            else if (i==1){
                hBrush = CreateSolidBrush(RGB(100, 100, 125)); // Crear un brush con el color deseado (en este caso, azul)
                RECT rect;
                GetClientRect(hWnd, &rect);
                FillRect(hdc, &rect, hBrush); // Pintar la ventana con el brush creado
                DeleteObject(hBrush); // Liberar el brush creado
                SetBkColor(hdc, RGB(100, 100, 125));
                if (error==1){
                    print_screen_error3(hdc);
                }
                else if (error==2){
                    print_screen_error2(hdc);
                }
                else if (error==3){
                    print_screen_error2(hdc);
                    print_screen_error3(hdc);
                }
                if (pass_error==1){
                    print_screen_error5(hdc);
                }
                rect.top-=280;
                SetTextColor(hdc, RGB(0, 0, 0));
                rect.top-=170;
                hFont = CreateFont(110, 0, 0, 0, FW_NORMAL, BOLD_FONTTYPE, TRUE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                                   CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial Black");

                hOldFont = (HFONT)SelectObject(hdc, hFont);
                DrawText(hdc, "REGISTRO DE NUEVO USUARIO", -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                rect.top+=260;

                hFont = CreateFont(25, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                                   CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Courier New Black");
                hOldFont = (HFONT)SelectObject(hdc, hFont);
                SetTextColor(hdc,RGB(0,0,0));
                RECT rect2 = { 80, 320, 300, 360 };
                DrawText(hdc, "USER:", -1, &rect2, DT_LEFT | DT_VCENTER);
                RECT rect3 = { 80, 440, 300, 480 };
                DrawText(hdc, "PASSWORD:", -1, &rect3, DT_LEFT | DT_VCENTER);
                RECT rect4 = { 80, 520, 300, 580 };
                DrawText(hdc, "CONFIRMAR \nPASSWORD:", -1, &rect4, DT_LEFT | DT_VCENTER);
            }
            else if (i==2){
                hBrush = CreateSolidBrush(RGB(102, 0, 51)); // Crear un brush con el color deseado (en este caso, azul)
                RECT rect;
                GetClientRect(hWnd, &rect);
                FillRect(hdc, &rect, hBrush); // Pintar la ventana con el brush creado
                DeleteObject(hBrush); // Liberar el brush creado
                SetBkColor(hdc, RGB(102, 0, 51));
                rect.top-=600;

                SetTextColor(hdc, RGB(235, 235, 235));
                hFont = CreateFont(80, 0, 0, 0, FW_NORMAL, BOLD_FONTTYPE, TRUE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                                   CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial Black");
                hOldFont = (HFONT)SelectObject(hdc, hFont);
                DrawText(hdc, "LISTADO DE USERS", -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                hFont = CreateFont(24, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                                   CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial");
                hOldFont = (HFONT)SelectObject(hdc, hFont);
                print_screen_users(list_of_user,hdc);
            }
            else if (i==3){
                hBrush = CreateSolidBrush(RGB(100, 100, 125)); // Crear un brush con el color deseado (en este caso, azul)
                RECT recta;
                GetClientRect(hWnd, &recta);
                FillRect(hdc, &recta, hBrush); // Pintar la ventana con el brush creado
                DeleteObject(hBrush); // Liberar el brush creado
                SetBkColor(hdc, RGB(100, 100, 125));
                recta.top-=280;
                SetTextColor(hdc, RGB(0, 0, 0));
                recta.top-=170;
                hFont = CreateFont(115, 0, 0, 0, FW_NORMAL, BOLD_FONTTYPE, TRUE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                                   CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial Black");


                hOldFont = (HFONT)SelectObject(hdc, hFont);
                DrawText(hdc, "INCIAR SESION", -1, &recta, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                rect.top+=260;


                hFont = CreateFont(28, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                                   CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Courier New Black");
                hOldFont = (HFONT)SelectObject(hdc, hFont);
                SetTextColor(hdc,RGB(0,0,0));
                RECT rect2 = { 130, 320, 400, 360 };
                DrawText(hdc, "USER:", -1, &rect2, DT_LEFT | DT_VCENTER);
                RECT rect3 = { 130, 440, 400, 480 };
                DrawText(hdc, "PASSWORD:", -1, &rect3, DT_LEFT | DT_VCENTER);
            }

            else if (i==7){
                hBrush = CreateSolidBrush(RGB(100, 100, 125));
                RECT rect;
                GetClientRect(hWnd, &rect);
                FillRect(hdc, &rect, hBrush);
                DeleteObject(hBrush);
                SetBkColor(hdc, RGB(100, 100, 125));
                rect.top-=280;
                SetTextColor(hdc, RGB(0, 0, 0));
                if (error==2){
                    print_screen_error4(hdc);
                }
                rect.top-=170;
                hFont = CreateFont(110, 0, 0, 0, FW_NORMAL, BOLD_FONTTYPE, TRUE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                                   CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial Black");

                hOldFont = (HFONT)SelectObject(hdc, hFont);
                rect.top-=100;
                DrawText(hdc, "REGISTRO DE NUEVO USUARIO", -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                rect.top+=260;

                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                                   CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Courier New Black");
                hOldFont = (HFONT)SelectObject(hdc, hFont);
                SetTextColor(hdc,RGB(0,0,0));
                RECT rect2 = { 100, 220, 300, 280 };
                DrawText(hdc, "NOMBRE:", -1, &rect2, DT_LEFT | DT_VCENTER);
                RECT rect3 = { 100, 320, 300, 380 };
                DrawText(hdc, "EDAD:", -1, &rect3, DT_LEFT | DT_VCENTER);
                RECT rect4 = { 100, 420, 300, 480 };
                DrawText(hdc, "CIUDAD:", -1, &rect4, DT_LEFT | DT_VCENTER);
                RECT rect5 = { 100, 520, 300, 580 };
                DrawText(hdc, "VIDEOJUEGOS:", -1, &rect5, DT_LEFT | DT_VCENTER);
                RECT rect6 = { 100, 620, 300, 680 };
                DrawText(hdc, "EMAIL:", -1, &rect6, DT_LEFT | DT_VCENTER);
                hFont = CreateFont(18, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                                   CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Courier New Black");
                hOldFont = (HFONT)SelectObject(hdc, hFont);
                if(k==1){
                    print_screen_error(hdc);}
            }
            else if (i==10){
                RECT rectCHAT = {320, 0, 1382, 777 };
                SetWindowText(button_me, current_user->user);
                hBrush = CreateSolidBrush(RGB(0, 0, 0));
                FillRect(hdc, &rectCHAT, hBrush);
                DeleteObject(hBrush);

                RECT rect10 = {0, 0, 320, 777 };

                hBrush = CreateSolidBrush(RGB(100, 100, 125));
                FillRect(hdc, &rect10, hBrush);
                DeleteObject(hBrush);

                RECT rectCombined;
                UnionRect(&rectCombined, &rect10, &rectCHAT);

                hBrush = CreateSolidBrush(RGB(0, 0, 0));
                FillRect(hdc, &rectCombined, hBrush);
                DeleteObject(hBrush);

                hBrush = CreateSolidBrush(RGB(100, 100, 125));
                FillRect(hdc, &rect10, hBrush);
                DeleteObject(hBrush);

                DeleteObject(hBrush);
                SetBkColor(hdc, RGB(100, 100, 125));
            }
            else if (i==12){
                hBrush = CreateSolidBrush(RGB(0, 0, 51)); // Crear un brush con el color deseado (en este caso, azul)
                RECT rect;
                GetClientRect(hWnd, &rect);
                FillRect(hdc, &rect, hBrush); // Pintar la ventana con el brush creado
                DeleteObject(hBrush); // Liberar el brush creado
                SetBkColor(hdc, RGB(0, 0, 51));
                rect.top-=600;

                SetTextColor(hdc, RGB(235, 235, 235));
                hFont = CreateFont(70, 0, 0, 0, FW_NORMAL, BOLD_FONTTYPE, TRUE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                                   CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial Black");
                hOldFont = (HFONT)SelectObject(hdc, hFont);
                DrawText(hdc, "ENVIAR SOLICITUD DE AMISTAD", -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                hFont = CreateFont(24, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                                   CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial");
                hOldFont = (HFONT)SelectObject(hdc, hFont);
                print_screen_users(list_of_user,hdc);
            }
            else if (i==13){
                hBrush = CreateSolidBrush(RGB(25, 121, 169)); // Crear un brush con el color deseado (en este caso, azul)
                RECT rect;
                GetClientRect(hWnd, &rect);
                FillRect(hdc, &rect, hBrush);
            }
            else if (i==14){
                hBrush = CreateSolidBrush(RGB(178, 102, 255)); // Crear un brush con el color deseado (en este caso, azul)
                RECT rect;
                GetClientRect(hWnd, &rect);
                FillRect(hdc, &rect, hBrush); // Pintar la ventana con el brush creado
                DeleteObject(hBrush); // Liberar el brush creado
                SetBkColor(hdc, RGB(178, 102, 255));
                hFont = CreateFont(42, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                                   CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial");
                hOldFont = (HFONT)SelectObject(hdc, hFont);
                print_me_screen(current_user,hdc);
            }
            else if (i==15){
                RECT rectCHAT= {0, 0, 1382, 777 };
                hBrush = CreateSolidBrush(RGB(100, 100, 125));
                FillRect(hdc, &rectCHAT, hBrush);
                DeleteObject(hBrush);

                RECT rect10 = {240, 120, 1142, 707 };

                hBrush = CreateSolidBrush(RGB(0, 0, 51));
                FillRect(hdc, &rect10, hBrush);
                DeleteObject(hBrush);

                RECT rectCombined;
                UnionRect(&rectCombined, &rect10, &rectCHAT);

                hBrush = CreateSolidBrush(RGB(180, 180, 180));
                FillRect(hdc, &rectCombined, hBrush);
                DeleteObject(hBrush);

                hBrush = CreateSolidBrush(RGB(100, 100, 125));
                FillRect(hdc, &rect10, hBrush);
                DeleteObject(hBrush);

                print_screen_publi(current_user,hdc);

            }
            SelectObject(hdc, hOldFont);
            DeleteObject(hFont);
            EndPaint(hWnd, &ps);
        }
            break;
        default:
            return DefWindowProc(hWnd, msg, wParam, lParam);
    }
    return 0;
}