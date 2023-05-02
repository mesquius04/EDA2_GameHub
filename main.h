#ifndef UNTITLED16_MAIN_H
#define UNTITLED16_MAIN_H
#define MAX_LENGTH 20
#define MAX_HOBBIES 5
typedef struct {
    char name[MAX_LENGTH];
    char user[MAX_LENGTH];
    char password[MAX_LENGTH];
    int age;
    char email [MAX_LENGTH];
    char city [MAX_LENGTH];
    char hobbies  [MAX_HOBBIES][MAX_LENGTH];
    struct User* next;
} User;
#endif //UNTITLED16_MAIN_H
