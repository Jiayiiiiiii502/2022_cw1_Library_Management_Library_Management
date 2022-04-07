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
    //create head node of user info
    user_head_node = (User*)malloc(sizeof(User));//apply the memory
    user_head_node->next = NULL;//user_head_node->next=null
    user_num = 0;//initialise users numbers

    //open the file
    FILE* file;
    file = fopen(userfilename, "rb");
    if(file==NULL){
        return;
    }
    User* np;
    np = user_head_node;
    User* temp = (User*)malloc(sizeof(User));
    while (fread(temp, sizeof(User), 1, file)){
        np->next = temp;
        user_num++;
        temp = (User*)malloc(sizeof(User));
        np = np->next;
    }
    //add librarian to the user linklist
    librarian= user_head_node->next;
    fclose(file);
}

//user borrow books initial info
void user_borrow(User* borrow)
{
    borrow->user_book.borrow_num = 0;
    borrow->user_book.max_num = 10;
    //initialise the memory
    memset(borrow->user_book.borrow_book, 0, sizeof(borrow->user_book.borrow_book));
}

//store user borrow info from linklist to file
void store_users(){
    FILE* file = fopen(userfilename, "wb");
    User* temp = user_head_node->next;
    while (temp)
    {
        fwrite(temp, sizeof(User), 1, file);
        temp = temp->next;
    }
    fclose(file);
}

//add new user to the user linklist
void add_user_to_list(char* username, char*name,char* password){
    User* np;
    np = user_head_node;
    while (np->next) np = np->next;
    User* tp = (User*)malloc(sizeof(User));
    strcpy(tp->user_name, username);
    strcpy(tp->name,name);
    strcpy(tp->password, password);
    tp->next = NULL;
    user_borrow(tp);
    np->next = tp;
    store_users();
}


//user_registration:
void user_register(){
    char username[30];
    printf("------------------------------------------------------------------------------------------------\n");
    printf("Please enter your username:\n");
    scanf("%s", username);
    User* account;
    if (account = search_username(username), account != NULL)
    {
        printf("This username has been already registered!\n");
        printf("Please change your username or login directly!\n");
        printf("\n");
        printf("------------------------------------------------------------------------------------------------\n");
        return;
    }
    char name[20];
    printf("Please enter your name:\n");
    scanf("%s",name);
    printf("Please input your password(no more than 30 letters or numbers):\n");
    char password[30];
    scanf("%s", password);
    //add new user information to the link list
    add_user_to_list(username,name, password);
    printf("<%s> had registered successfully!\n",username);
    user_num++;
    printf("------------------------------------------------------------------------------------------------\n");
}

//traverse username in the linklist
User* search_username(char* name)  {
    User* np = user_head_node->next;
    while (np)
    {
        if (!strcmp(np->user_name, name)) return np;
        np = np->next;
    }
    return NULL;
}



//user login
void user_login()
{
    char username[25];
    char password[25];
    printf("------------------------------------------------------------------------------------------------\n");
    printf("Please enter your username:\n");
    scanf("%s", username);
    clear();
    User* temp;
    if (temp = search_username(username), temp == NULL)
    {
        printf("Invalid username!\n");
        printf("Please go registration first!\n");
        printf("------------------------------------------------------------------------------------------------\n");
        return;
    }
    printf("Please enter your password:\n");
    scanf("%s", password);
    clear();
    if (strcmp(temp->password, password))
    {
        printf("Invalid password!\n");
        printf("Please try again!");
        printf("\n");
        printf("------------------------------------------------------------------------------------------------\n");
        return;
    }
    printf("<%s> login successfully!...\n",username);
    printf("\n");
    printf("------------------------------------------------------------------------------------------------\n");
    //jump to the user function menu
    user_menu(temp);
}





//librarian login:
User* librarian_info()
{
    librarian = (User*)malloc(sizeof(User));
    strcpy(librarian->name,"Librarian");
    strcpy(librarian->user_name, "0");
    strcpy(librarian->password, "0");
    return librarian;
}

//login page
void librarian_login(){
    User* initial=librarian_info();
    char username[30];
    char password[30];
    printf("\n");
    printf("------------------------------------------------------------------------------------------------\n");
    printf("Welcome!\n");
    printf("Please enter your username:\n");
    scanf("%s",username);
    if(strcmp(initial->user_name,username)){
        printf("Invalid librarian username!\n");
        printf("\n");
        printf("------------------------------------------------------------------------------------------------\n");
        return;
    }
    printf("Please enter your password:\n");
    scanf("%s",password);
    if(strcmp(initial->password,password)){
        printf("Invalid librarian password!\n");
        printf("\n");
        printf("------------------------------------------------------------------------------------------------\n");
        return;
    }
    printf("Successfully login as librarian!\n");
    printf("\n");
    printf("------------------------------------------------------------------------------------------------\n");
    librarian_menu();
}