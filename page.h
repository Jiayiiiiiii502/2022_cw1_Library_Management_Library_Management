//
// Created by Jiayi on 2022/3/17.
//

#ifndef NEW_PAGE_H
#define NEW_PAGE_H

#include "book_management.h"
#include "user.h"

//all pages
//initial page for all browsers
void main_menu();
//specific user function page
void user_menu(User*);
//library function page
void librarian_menu();
//find books function page
void find_book_menu();
//clear the controller content
void clear();
#endif //NEW_PAGE_H
