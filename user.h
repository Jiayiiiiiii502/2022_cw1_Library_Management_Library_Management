//
// Created by Jiayi on 2022/3/17.
//

#ifndef NEW_USER_H
#define NEW_USER_H

#include "book_management.h"
//用户管理链表：
typedef struct user//user
{
    char name[20];
    char user_name[30];  //user student ID
    char password[30];  //password
    int admin;  //Whether the administrator
    struct node user_book;  //Books borrowed by users.
    struct user* next;  //next user
}User;

//用户初始化：
int user_num;  //the number of user
User* user_head_node;

//用户操作：
void borrow_book(User*);
void return_book(User*);
void show_borrow(User*);



#endif //NEW_USER_H
