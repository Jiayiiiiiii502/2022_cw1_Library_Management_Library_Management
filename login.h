//
// Created by Jiayi on 2022/3/17.
//

#ifndef NEW_LOGIN_H
#define NEW_LOGIN_H
#include "user.h"

//user login:
void users_file_to_list();

void user_borrow(User*);

void store_users();

void user_register();


User* search_username(char*);

void creat_user_list(char*, char*,char* );

void user_login();



//librarian login:
//管理员信息初始化：
User* librarian_info();
//管理员登录：
void librarian_login();
#endif //NEW_LOGIN_H
