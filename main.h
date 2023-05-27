#ifndef UNTITLED16_MAIN_H
#define UNTITLED16_MAIN_H
#define MAX_LENGTH 20
#define MAX_HOBBIES 5
#define MAX_FRIENDS 50

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
    Publicacion* publicacion;
    struct _User** friends; //array dinámico de pointers de users
    int num_friends;
    struct _User* next;
    struct _Queue* friend_request;
} User;

typedef struct _Queue{
    int head;
    int tail;
    User** array;
    int size;
} Queue;

typedef struct{
    int top;
    User* array[3];
}Stack;

#endif //UNTITLED16_MAIN_H
