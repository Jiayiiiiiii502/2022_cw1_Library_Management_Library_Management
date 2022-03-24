//
// Created by Jiayi on 2022/3/17.
//

#ifndef NEW_LOGIN_H
#define NEW_LOGIN_H
#include "user.h"
//user login:
//load user info from file to linklist
void users_file_to_list();
//user borrowed book linklist
void user_borrow(User*);
//store user from linklist to file
void store_users();
//register a new user account
void user_register();
//traverse user linklist to check if there are the same username
User* search_username(char*);
//add new user to the uesr linklist
void add_user_to_list(char* ,char*, char*);
//registered user login
void user_login();

//librarian login:
//librarian info initialisation
User* librarian_info();
//library login
void librarian_login();
#endif //NEW_LOGIN_H
