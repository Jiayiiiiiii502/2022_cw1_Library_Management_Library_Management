//
// Created by Jiayi on 2022/3/17.
//

#include <malloc.h>
#include <string.h>
#include "login.h"
#include "book_management.h"
#include "user.h"
#include "librarian.h"
#include "page.h"

//users login module

//load user info from file to linklist
void users_file_to_list()
{
    user_head_node = (User*)malloc(sizeof(User));//user_head_node
    user_head_node->next = NULL;//user_head_node->next=null
    user_num = 0;//user_num

    FILE* fp1;
    fp1 = fopen("the_users.txt", "rb");
    User* np;
    np = user_head_node;
    User* temp = (User*)malloc(sizeof(User));
    while (fread(temp, sizeof(User), 1, fp1))
    {
        np->next = temp;
        user_num++;
        temp = (User*)malloc(sizeof(User));
        np = np->next;
    }
    librarian= user_head_node->next;
    fclose(fp1);
}

//user borrow books initial info
void user_borrow(User* borrow)
{
    borrow->user_book.borrow_num = 0;
    borrow->user_book.max_num = 10;
    memset(borrow->user_book.borrow_book, 0, sizeof(borrow->user_book.borrow_book));
}

//store user borrow info from linklist to flie
void store_users(){
    FILE* fp = fopen("the_users.txt", "wb");
    User* temp = user_head_node->next;
    while (temp)
    {
        fwrite(temp, sizeof(User), 1, fp);
        temp = temp->next;
    }
    fclose(fp);
}

//user_registration:
void user_register(){
    char username[30];
    printf("Please enter your username:\n");
    scanf("%s", username);
    User* account;
    if (account = search_username(username), account != NULL)
    {
        printf("This username has been already registered!\n");
        printf("Please change your username or login directly!\n");
        return;
    }
    char name[20];
    printf("Please enter your name:\n");
    scanf("%s",name);
    printf("Please input your password(no more than 30 letters or numbers):\n");
    char password[30];
    scanf("%s", password);
    creat_user_list(username,name, password);
    printf("register successfully!\n");
    user_num++;
}

//search username in the linklist
User* search_username(char* name)  {
    User* np = user_head_node->next;
    while (np)
    {
        if (!strcmp(np->user_name, name)) return np;
        np = np->next;
    }
    return NULL;
}


void creat_user_list(char* username, char*name,char* password){
    User* np;
    np = user_head_node;
    while (np->next) np = np->next;
    User* tp = (User*)malloc(sizeof(User));
    strcpy(tp->user_name, username);
    strcpy(tp->name,name);
    strcpy(tp->password, password);
    tp->admin = 0;
    tp->next = NULL;
    user_borrow(tp);
    np->next = tp;
    store_users();
}

//user login
void user_login()//用户登录
{
    char username[25];
    char password[25];
    printf("Please enter your username:\n");
    scanf("%s", username);
    User* temp;
    if (temp = search_username(username), temp == NULL)
    {
        printf("Invalid username!\n");
        printf("Please registrate first!\n");
        return;
    }
    printf("Please enter your password:\n");
    scanf("%s", password);
    if (strcmp(temp->password, password))
    {
        printf("Invalid password!\n");
        printf("Please try again!");
        return;
    }
    printf("Login successfully!...\n");
    user_menu(temp);
}










//librarian login:
User* librarian_info()
{
    librarian = (User*)malloc(sizeof(User));
    strcpy(librarian->name,"Librarian");
    strcpy(librarian->user_name, "0000");
    strcpy(librarian->password, "0000");
    return librarian;
}

//login page
void librarian_login(){
    User* initial=librarian_info();
    char name[25];
    char username[30];
    char password[30];
    printf("Welcome!\n");
    printf("Please enter your username:\n");
    scanf("%s",username);
    if(strcmp(initial->user_name,username)){
        printf("Invalid librarian username!\n");
        return;
    }
    printf("Please enter your password:\n");
    scanf("%s",password);
    if(strcmp(initial->password,password)){
        printf("Invalid librarian password!\n");
        return;
    }
    printf("Successfully login as librarian!\n");
    librarian_menu();
}