//
// Created by Jiayi on 2022/3/17.
//

#include <string.h>
#include <stdlib.h>
#include "user.h"
#include "login.h"
#include "page.h"

//specific user borrowing book
void borrow_book(User* temp) {
    while(1) {
        //create temp to store single user's book initialisation
        int temp_borrow = temp->user_book.borrow_num;
        int max_borrow = temp->user_book.max_num;
        //ensure the number of borrowed books is small than 10
        if (temp_borrow == max_borrow) {
            printf("%s has borrowed %d books, please return a book first!\n", temp->user_name, max_borrow);
            return;
        }
        //display all the book
        display_book();
        printf("Please enter the order of the book you need to borrow(-1 to quit):\n");
        int choice;
        scanf("%d", &choice);
        if (choice == -1) {
            printf("Come back successfully!\n");
            printf("\n");
            printf("------------------------------------------------------------------------------------------------\n");
            return;
        } else if (choice > head.length || choice <= 0) {
            printf("Invalid choice!\n");
            //printf("------------------------------------------------\n");
        } else {
            //add borrowed book to the temp linklist
            //printf("Begin borrowing!\n");
            Book *tb;
            tb = head.list->next;
            for (int m = 1; m < choice; m++) {
                tb = tb->next;
            }
            temp->user_book.borrow_book[temp_borrow] = *tb;
            temp->user_book.borrow_num++;
            tb->copies = tb->copies - 1;//update the library store
            store_users();//update user info
            store_books();//update user linklist
            printf("Borrow <%s> successfully!\n", tb->temp_title);
            //printf("------------------------------------------------\n");
        }
    }
    }



//show specific borrowed books of a user
void show_borrow(User* temp){
    int temp_borrow=temp->user_book.borrow_num;
    printf("\n");
    printf("------------------------------------------------------------------------------------------------\n");
    if(!temp_borrow){
        printf("You borrow 0 books!\n");
        printf("Please borrow a book first!\n");
        printf("------------------------------------------------------------------------------------------------\n");
        printf("\n");
        return;
    }
    printf("You have borrowed:\n");
    printf("ID\t\tTitle\t\tAuthor\t\tYear\n");
    int m=0;
    for(m=0;m<temp_borrow;m++){
        struct borrow_node a=temp->user_book;
        printf("%d \t\t%s \t\t %s \t\t   %d\n",m+1,a.borrow_book[m].temp_title,a.borrow_book[m].temp_authors,a.borrow_book[m].year);
    }
}

//specific user returning book
void return_book(User* temp){
    while (1)
    {
        show_borrow(temp);
        if (!temp->user_book.borrow_num)
        {
            return;
        }
        printf("Please enter the order of the book you need to return (enter -1 to exit the book return system)!\n");
        int option = 0; scanf("%d", &option);
        if (option == -1)
        {
            printf("Come back successfully!\n");
            return;
        }
        if (option > temp->user_book.borrow_num || option <= 0)
        {
            printf("Invalid option!\n");
        }
        else {
            int i = 0;
            Book *tb;
            tb = head.list->next;
            //for (--option; i < option; ++i);

            char title[100];
            strcpy(title, temp->user_book.borrow_book[i].temp_title);
            printf("The chosen book is %s\n",temp->user_book.borrow_book[i].temp_title);

            while (tb) {
                i=option-1;
                    if (tb->id==temp->user_book.borrow_book[i].id &&(strcmp(temp->user_book.borrow_book[i].temp_title, tb->temp_title) == 0)) {
                        tb->copies = tb->copies + 1;
                        temp->user_book.borrow_book[i] = temp->user_book.borrow_book[i + 1];
                        break;
                }
                tb = tb->next;
            }
            --temp->user_book.borrow_num;
            store_users();
            store_books();
            printf("<%s> return successfully!\n", title);
        }
    }

}


//change users passwords
void change_password(User* temp){
    char password[30];
    printf("Welcome, %s !\n",temp->user_name);
    printf("Please enter the new password:\n");
    scanf("%s",password);
    strcpy(temp->password,password);
    store_users();
    printf("Changing password successfully!\n");
}