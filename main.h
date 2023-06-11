#ifndef UNTITLED16_MAIN_H
#define UNTITLED16_MAIN_H
#define MAX_LENGTH 20
#define MAX_HOBBIES 5



#define MAX_PUBLI 120
typedef struct _Node{
    char* key;
    int count;
}Node;

typedef struct _Dict{
    int size,count;
    struct _Node* items;
}Dict;

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
    struct _User* next;
    struct _Queue* friend_request;
    int numfriends;
    int maxfriends;
    struct _User** friends; //dynamic list of pointers of User
} User;

typedef struct _element{
    User* user;
    struct _element* next;
    struct _element* prev;
}Element;

typedef struct _Queue{
    Element* first;
    Element* last;
} Queue;



#endif //UNTITLED16_MAIN_H
