#ifndef UNTITLED16_MAIN_H
#define UNTITLED16_MAIN_H
#define MAX_LENGTH 20
#define MAX_HOBBIES 5

/*
typedef struct  _user{
    struct _user* queue_users[MAX_LENGTH];
    int head;
    int tail;
}Cola;
*/
#define MAX_PUBLI 120
typedef struct _Publicacion{
    char post[MAX_PUBLI];
    struct _Publicacion* next;
}Publicacion;


typedef struct _User{
    char name[MAX_LENGTH];
    char user[MAX_LENGTH];
    char password[MAX_LENGTH];
    int age;
    char email [MAX_LENGTH];
    char city [MAX_LENGTH];
    char hobbies  [MAX_HOBBIES][MAX_LENGTH];
    //Cola friend_request;
    Publicacion* publicacion ;
    struct _User* next;
} User;
#endif //UNTITLED16_MAIN_H
