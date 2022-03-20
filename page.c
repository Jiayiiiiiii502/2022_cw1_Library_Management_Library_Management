//
// Created by Jiayi on 2022/3/17.
//

#include "page.h"
#include  "user.h"
#include "librarian.h"
#include "login.h"
#include "book_management.h"
void main_menu()//show_page模块
{
    while (1)
    {
        load_books();
        users_file_to_list();
        printf("Please choose an option\n");
        printf("1)Register an account\n");
        printf("2)Users login\n");
        printf("3)Librarian login\n");
        printf("4)Display all books\n");
        printf("5)Search for book\n");
        printf("6)Quit\n");
        printf("  Option:");
        int option; scanf("%d", &option);

        switch (option)
        {
            case 1: user_register();
                break;
            case 2: user_login();
                break;
            case 3: librarian_login();
                break;
            case 4: display_book();
                break;
            case 5: find_book_menu();
                break;
            case 6: return;
            default: printf("Invalid option!\n"); break;
        }
    }
}


//用户操作主页
void user_menu(User* temp)  //show_page
{
    printf("+--------------------------------------------------------------+\n");
    printf("user:%s\n", temp->user_name);
    printf("Please enter your option\n");
    printf("1)borrow book\n");
    printf("2)return book\n");
    printf("3)my borrow\n");
    printf("4)display book\n");
    printf("5)change password\n");
    //printf("6)remove account\n");
    printf("0)log out\n");
    printf("+--------------------------------------------------------------+\n");
    int option;
    scanf("%d", &option);
    switch (option)
    {
        case 1: borrow_book(temp);
            break;
        case 2: return_book(temp);
            break;
        case 3: show_borrow(temp);
            break;
        case 4: display_book();
            break;
        case 5: //user_change(account);
            printf("Borrow book!\n");
            break;
        case 0: printf("come back successfully!\n");return;
        default: printf("Invalid option!\n"); break;
    }
}



void librarian_menu(){
    printf("Welcome!\n");
    printf("Please enter your choice:\n");
    printf("1)Add book\n");
    printf("2)Remove book\n");
    printf("3)Search for book\n");
    printf("4)Display book\n");
    printf("5)Quit\n");
    int option;
    scanf("%d",&option);
    switch(option){
        case 1: add_book();
            break;
        case 2: remove_book();
            break;
        case 3: find_book_menu();
            break;
        case 4: display_book();
            break;
        case 5:printf("Librarian has been logged out!\n");
            return;
        default:printf("Invalid choice!\n");
    }
}


void find_book_menu(){
    printf("Please choose a way to find books:\n");
    printf("1)Find book by title\n");
    printf("2)Find book by author\n");
    printf("3)Find book by year\n");
    printf("4)Quit\n");
    int choice;
    scanf("%d", &choice);
    switch(choice)
    {
        case 1: find_book_by_title();
            break;
        case 2: find_book_by_author();
            break;
        case 3: find_book_by_year();
            break;
        case 4: printf("Come back successfully!\n");
            return;
        default:printf("Invalid choice!\n");
            printf("Please try again!\n");
            find_book_menu();
    }
}