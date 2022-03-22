//
// Created by Jiayi on 2022/3/17.
//

#include <string.h>
#include "user.h"
#include "login.h"


void borrow_book(User* temp) {
    //create temp to store single user's book initialisation
    int temp_borrow = temp->user_book.borrow_num;
    int max_borrow = temp->user_book.max_num;
    //ensure the number of borrowed books is small than 10
    if (temp_borrow == max_borrow) {
        printf("%s has borrowed %d books, please return a book first!\n", temp->user_name, max_borrow);
    }
    display_book();
    printf("Please enter the order of the book you need to borrow(-1 to quit):\n");
    int choice;
    scanf("%d", &choice);
    if (choice == -1) {
        printf("Come back successfully!\n");
        return;
    }
    else if (choice > book_num || choice <= 0) {
        printf("Invalid choice!\n");
    }
    else {
        //add borrowed book to the temp linklist
        printf("Begin borrowing!\n");
        Book *tb;
        tb = book_head->next;
        for (int m = 1; m < choice; m++) {
            tb = tb->next;
        }
        temp->user_book.borrow_book[temp_borrow] = *tb;
        temp->user_book.borrow_num++;
        tb->copies = tb->copies - 1;//update the library store
        store_users();//update user info
        store_books();//update user linklist
        printf("Borrow <%s> successfully!\n", tb->title);
    }
}

void show_borrow(User* temp){
    int temp_borrow=temp->user_book.borrow_num;
    printf("Welcome! %s\n",temp->user_name);
    if(!temp_borrow){
        printf("You borrow 0 books!\n");
        printf("Please borrow a book first!\n");
        return;
    }
    printf("You have borrowed:\n");
    printf("ID\t\tTitle\t\tAuthor\t\tYear\n");
    for(int m=0;m<temp_borrow;m++){
        struct node a=temp->user_book;
        printf("%d \t\t%s \t\t %s \t\t   %d\n",m+1,a.borrow_book[m].title,a.borrow_book[m].authors,a.borrow_book[m].year);
    }
}


void return_book(User* account){
    while (2)
    {
        show_borrow(account);
        if (!account->user_book.borrow_num)
        {
            return;
        }
        printf("Please enter the serial number of the book you need to return (enter -1 to exit the book return system)!\n");
        int option;
        scanf("%d", &option);
        if (option == -1)
        {
            printf("Exiting the review system\n");
            return;
        }
        if (option > account->user_book.borrow_num || option < 0)
        {
            printf("invalid option!\n");
        }
        else
        {
            int i = 0;
            Book* tb;
            tb = book_head->next;
            for (--option; i < option; ++i);
            char title[100];
            strcpy(title, account->user_book.borrow_book[i].title);
            printf("------------------------------------------------------\n");
            for (; i < account->user_book.borrow_num; ++i)
            {
                account->user_book.borrow_book[i] = account->user_book.borrow_book[i + 1];
                tb->copies= tb->copies+1;
            }
            --account->user_book.borrow_num;
            store_users();
            store_books();
            printf("<%s>return successfully!\n", title);
        }
    }

}