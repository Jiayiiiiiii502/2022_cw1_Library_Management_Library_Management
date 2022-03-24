//
// Created by Jiayi on 2022/3/17.
//

#ifndef NEW_USER_H
#define NEW_USER_H
#include "book_management.h"

//borrow book linklist of a specific user
struct borrow_node{
    int borrow_num;//number of borrowed books
    int max_num;//constrain the number of every user(10)
    Book borrow_book[3];
};

typedef struct user
{
    char name[20];
    char user_name[30];
    char password[30];
    struct borrow_node user_book;  //create a borrow book linklist for a specific user
    struct user* next;  //user linklist
}User;

//initialisation
int user_num;  //the number of user
User* user_head_node;//create user linklist head node


//user function (every user has one)
void borrow_book(User*);
void return_book(User*);
void show_borrow(User*);

#endif //NEW_USER_H
