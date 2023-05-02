#include <Windows.h>
#include <stdio.h>
#include <CommCtrl.h>
#include "main.h"
HINSTANCE hInst;
HBRUSH hBrush;
int LOGGED=FALSE;
#define NOT_TAKEN TRUE
#define MAX_LENGHT 20
char username[30],password1[30],password2[30],newname[MAX_LENGTH],age[3],newhobbie[MAX_LENGTH],newemail[MAX_LENGHT],newcity[MAX_LENGTH];
User*new_user=NULL;
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
HWND button1,button2,button3,button4,button5,button6,button7,button8,button9,button10,button11,button12,hEditControl,hEditControl2,hEditControl3,hEditControl4,hEditControl5,hEditControl6,hEditControl7,hEditControl8;
int i=0,h=0,condition=0;
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


    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);


    //TAMANY FINESTRA
    int windowWidth = screenWidth * 0.9;
    int windowHeight = screenHeight * 0.9;
    int windowX = (screenWidth - windowWidth) / 2;
    int windowY = (screenHeight - windowHeight) / 2;

    // Crear finestra
    hWnd = CreateWindow("MyWindowClass", "GAMEHUB", WS_OVERLAPPEDWINDOW, windowX, windowY, windowWidth, windowHeight, NULL, NULL, hInstance, NULL);
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
    HFONT hFont;
    hFont = CreateFont(400, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
                       CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial");

    switch (msg) {
        case WM_CREATE:{

            hEditControl = CreateWindow("EDIT", "", SW_HIDE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                        300, 300, 800, 70, hWnd, (HMENU)20, hInst, NULL);
            hFont = CreateFont(20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                               CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Courier New Black");

            SendMessage(hEditControl, WM_SETFONT, (WPARAM)hFont, TRUE);

            hEditControl2 = CreateWindow("EDIT", "", SW_HIDE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                         300, 420, 800, 70, hWnd, (HMENU)21, hInst, NULL);
            hEditControl3 = CreateWindow("EDIT", "", SW_HIDE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                         300, 510, 800, 70, hWnd, (HMENU)22, hInst, NULL);
            hEditControl4 = CreateWindow("EDIT", "", SW_HIDE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                         300, 200, 800, 60, hWnd, (HMENU)23, hInst, NULL);
            hEditControl5 = CreateWindow("EDIT", "", SW_HIDE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                         300, 300, 800, 60, hWnd, (HMENU)24, hInst, NULL);
            hEditControl6 = CreateWindow("EDIT", "", SW_HIDE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                         300, 400, 800, 60, hWnd, (HMENU)25, hInst, NULL);
            hEditControl7 = CreateWindow("EDIT", "", SW_HIDE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                         300, 500, 800, 60, hWnd, (HMENU)26, hInst, NULL);
            hEditControl8 = CreateWindow("EDIT", "", SW_HIDE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                         300, 600, 800, 60, hWnd, (HMENU)27, hInst, NULL);
            SendMessage(hEditControl2, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hEditControl3, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hEditControl4, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hEditControl5, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hEditControl6, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hEditControl7, WM_SETFONT, (WPARAM)hFont, TRUE);
            SendMessage(hEditControl8, WM_SETFONT, (WPARAM)hFont, TRUE);
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
            button8 = CreateWindowEx(
                    0,
                    "BUTTON",
                    "Apply",
                    SW_HIDE | WS_CHILD | BS_DEFPUSHBUTTON,
                    1100, 199, 100, 63,
                    hWnd,
                    (HMENU)9,
                    hInst,
                    NULL
            );
            button9 = CreateWindowEx(
                    0,
                    "BUTTON",
                    "Apply",
                    SW_HIDE | WS_CHILD | BS_DEFPUSHBUTTON,
                    1100, 299, 100, 63,
                    hWnd,
                    (HMENU)10,
                    hInst,
                    NULL
            );
            button10 = CreateWindowEx(
                    0,
                    "BUTTON",
                    "Apply",
                    SW_HIDE | WS_CHILD | BS_DEFPUSHBUTTON,
                    1100, 399, 100, 63,
                    hWnd,
                    (HMENU)11,
                    hInst,
                    NULL
            );
            button11 = CreateWindowEx(
                    0,
                    "BUTTON",
                    "Apply",
                    SW_HIDE | WS_CHILD | BS_DEFPUSHBUTTON,
                    1100, 499, 100, 63,
                    hWnd,
                    (HMENU)12,
                    hInst,
                    NULL
            );
            button12 = CreateWindowEx(
                    0,
                    "BUTTON",
                    "Apply",
                    SW_HIDE | WS_CHILD | BS_DEFPUSHBUTTON,
                    1100, 599, 100, 63,
                    hWnd,
                    (HMENU)13,
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
            break;
        }
        case WM_COMMAND: {
            switch (LOWORD(wParam)) {
                case 1: {
                    new_user=(User*)malloc(sizeof(User));
                    i=1;
                    ShowWindow(button1, SW_HIDE);
                    ShowWindow(button2, SW_HIDE);
                    ShowWindow(button3, SW_HIDE);
                    ShowWindow(button4, SW_HIDE);
                    ShowWindow(hEditControl,SW_SHOW);
                    ShowWindow(button5,SW_SHOW);
                    ShowWindow(hEditControl2,SW_SHOW);
                    ShowWindow(button6,SW_SHOW);
                    ShowWindow(hEditControl3,SW_SHOW);
                    ShowWindow(button7,SW_SHOW);
                    SetClassLongPtr(hWnd, GCLP_HBRBACKGROUND, (LONG)GetStockObject(WHITE_BRUSH)); //Cambiar color de fondo a blanco
                    InvalidateRect(hWnd, NULL, TRUE);
                    break;
                }
                case 2: {
                    // BOTÓ 2
                    break;
                }
                case 3: {
                    // BOTÓ 3
                    break;
                }
                case 4: {
                    DestroyWindow(hWnd);
                    break;
                }
                case 6:{
                    if (NOT_TAKEN && strlen(username)<MAX_LENGHT && strlen(username)>=5){
                        strcpy(new_user->user,username);
                        printf("\nuser: %s",new_user->user);
                        condition=1;}
                    break;
                }
                case 7:{
                    if (NOT_TAKEN && strlen(password1)<MAX_LENGHT && strlen(password1)>=5){
                        if (condition==1){condition=2;}}
                    break;
                }
                case 8:{
                    if (NOT_TAKEN && strlen(password2)<MAX_LENGHT && condition==2 &&strcmp(password1,password2)==0){
                        condition=0;
                        strcpy(new_user->password,password1);
                        printf("\npass: %s",new_user->password);
                        i=7;
                        ShowWindow(hEditControl4, SW_SHOW);
                        ShowWindow(hEditControl5, SW_SHOW);
                        ShowWindow(hEditControl6, SW_SHOW);
                        ShowWindow(hEditControl7, SW_SHOW);
                        ShowWindow(hEditControl8, SW_SHOW);
                        ShowWindow(button8,SW_SHOW);
                        ShowWindow(button9,SW_SHOW);
                        ShowWindow(button10,SW_SHOW);
                        ShowWindow(button11,SW_SHOW);
                        ShowWindow(button12,SW_SHOW);
                        ShowWindow(button5,SW_HIDE);
                        ShowWindow(hEditControl,SW_HIDE);
                        ShowWindow(button6,SW_HIDE);
                        ShowWindow(hEditControl2,SW_HIDE);
                        ShowWindow(button7,SW_HIDE);
                        ShowWindow(hEditControl3,SW_HIDE);
                        InvalidateRect(hWnd, NULL, TRUE);
                        UpdateWindow(hWnd);}
                    break;
                }
                case 9:{
                    if (strlen(newname)<=MAX_LENGTH){
                        condition++;
                        strcpy(new_user->name,newname);
                        printf("\nname: %s",new_user->name);
                    }
                    break;
                }
                case 10:{
                    if (strlen(age)<=3){
                        int newage=0;
                        for (int k=0;k<2;k++){
                            newage*=10;
                            newage+=(int)age[k]-48;
                        }
                        new_user->age=newage;
                        condition++;
                        printf("\nage: %d",new_user->age);
                    }
                    break;
                }
                case 11:{
                    if (strlen(newcity)<=MAX_LENGTH){
                        strcpy(new_user->city,newcity);
                        printf("\ncity: %s",new_user->city);
                        condition++;
                    }
                    break;
                }
                case 12:{
                    if (strlen(newhobbie)<=MAX_LENGTH && h<MAX_HOBBIES){
                        strcpy(new_user->hobbies[h],newhobbie);
                        h++;
                        condition++;
                        printf("\nhobbie%d: %s",h,new_user->hobbies[h-1]);
                    }
                    break;
                }
                case 13:{
                    if (strlen(newemail)<=MAX_LENGTH){
                        strcpy(new_user->email,newemail);
                        printf("%s",newemail);
                        condition++;
                        printf("\nemail: %s",new_user->email);
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
                        ShowWindow(button1, SW_SHOW);
                        ShowWindow(button2, SW_SHOW);
                        ShowWindow(button3, SW_SHOW);
                        ShowWindow(button4, SW_SHOW);
                        i=0;
                        LOGGED=TRUE;
                        InvalidateRect(hWnd, NULL, TRUE);
                        UpdateWindow(hWnd);}
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
                case 23:
                {
                    GetWindowText(hEditControl4, newname, 30);
                    break;}
                case 24:
                {
                    GetWindowText(hEditControl5, age, 3);
                    break;}
                case 25:
                {
                    GetWindowText(hEditControl6, newcity, 30);
                    break;}
                case 26:
                {
                    GetWindowText(hEditControl7, newhobbie, 20);
                    break;}
                case 27:
                {
                    GetWindowText(hEditControl8,newemail, 30);

                    break;}

            }
            break;
        }

        case WM_DESTROY:
            free(new_user); //TREURE DPS
            printf("\n\nHa acabat correctament.");
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
                    DrawText(hdc,new_user->user,-1,&rect5,DT_LEFT | DT_VCENTER);
                }}

            if (i==1){
                hBrush = CreateSolidBrush(RGB(100, 100, 125)); // Crear un brush con el color deseado (en este caso, azul)
                RECT rect;
                GetClientRect(hWnd, &rect);
                FillRect(hdc, &rect, hBrush); // Pintar la ventana con el brush creado
                DeleteObject(hBrush); // Liberar el brush creado
                SetBkColor(hdc, RGB(100, 100, 125));
                rect.top-=280;
                SetTextColor(hdc, RGB(0, 0, 0));
                rect.top-=170;
                hFont = CreateFont(110, 0, 0, 0, FW_NORMAL, BOLD_FONTTYPE, TRUE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                                   CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial Black");

                hOldFont = (HFONT)SelectObject(hdc, hFont);
                DrawText(hdc, "REGISTRE DE NOU USUARI", -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                rect.top+=260;

                hFont = CreateFont(25, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                                   CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Courier New Black");
                hOldFont = (HFONT)SelectObject(hdc, hFont);
                SetTextColor(hdc,RGB(0,0,0));
                RECT rect2 = { 80, 320, 300, 360 };
                DrawText(hdc, "NOM D'USUARI:", -1, &rect2, DT_LEFT | DT_VCENTER);
                RECT rect3 = { 80, 440, 300, 480 };
                DrawText(hdc, "CONTRASENYA:", -1, &rect3, DT_LEFT | DT_VCENTER);
                RECT rect4 = { 80, 520, 300, 580 };
                DrawText(hdc, "CONFIRMAR \nCONTRASENYA:", -1, &rect4, DT_LEFT | DT_VCENTER);
            }
            if (i==7){
                hBrush = CreateSolidBrush(RGB(100, 100, 125));
                RECT rect;
                GetClientRect(hWnd, &rect);
                FillRect(hdc, &rect, hBrush);
                DeleteObject(hBrush);
                SetBkColor(hdc, RGB(100, 100, 125));
                rect.top-=280;
                SetTextColor(hdc, RGB(0, 0, 0));
                rect.top-=170;
                hFont = CreateFont(110, 0, 0, 0, FW_NORMAL, BOLD_FONTTYPE, TRUE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                                   CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial Black");

                hOldFont = (HFONT)SelectObject(hdc, hFont);
                rect.top-=100;
                DrawText(hdc, "REGISTRE DE NOU USUARI", -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                rect.top+=260;

                hFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                                   CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Courier New Black");
                hOldFont = (HFONT)SelectObject(hdc, hFont);
                SetTextColor(hdc,RGB(0,0,0));
                RECT rect2 = { 100, 220, 300, 280 };
                DrawText(hdc, "NOM:", -1, &rect2, DT_LEFT | DT_VCENTER);
                RECT rect3 = { 100, 320, 300, 380 };
                DrawText(hdc, "EDAD:", -1, &rect3, DT_LEFT | DT_VCENTER);
                RECT rect4 = { 100, 420, 300, 480 };
                DrawText(hdc, "CIUTAT:", -1, &rect4, DT_LEFT | DT_VCENTER);
                RECT rect5 = { 100, 520, 300, 580 };
                DrawText(hdc, "HOBBIES:", -1, &rect5, DT_LEFT | DT_VCENTER);
                RECT rect6 = { 100, 620, 300, 680 };
                DrawText(hdc, "EMAIL:", -1, &rect6, DT_LEFT | DT_VCENTER);

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