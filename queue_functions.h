//
// Created by marti on 26/05/2023.
//
#include <Windows.h>
#include <stdio.h>
#include <CommCtrl.h>
#include "main.h"
#ifndef UNTITLED16_QUEUE_FUNCTIONS_H
#define UNTITLED16_QUEUE_FUNCTIONS_H
int are_friends(User u1, User u2);
int friend_request_already(User sender, User sended);
void send_friend_request(User** list,User** user,char* name);
void makefriends(User* u1, User* u2);
User* queue_dequeue(User* user);
#endif //UNTITLED16_QUEUE_FUNCTIONS_H
