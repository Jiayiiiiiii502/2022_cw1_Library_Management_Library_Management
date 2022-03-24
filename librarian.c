//
// Created by Jiayi on 2022/3/17.
//

#include <stdlib.h>
#include "librarian.h"
#include "page.h"

//add a book to the linklist and invoke create_book_list to update the linklist
void add_book(){
    //create temp array to get the size of title/author
    char title[100],author[100];
    int id,year,copies;
    printf("------------------------------------------------\n");
    printf("Please follow the following rules (use '_' to represent ' '):\n");
    printf("Please enter the title:\n");
    scanf("%s",title);
    printf("Please enter the author:\n");
    scanf("%s",author);
    printf("Please enter the id:\n");
    scanf("%d", &id);
    printf("Please enter the year:\n");
    scanf("%d", &year);
    printf("Please enter its copies:\n");
    scanf("%d", &copies);
    book_num++;
    //invoke create_book_list to add new book to the las linklist node and update linklist to the file
    creat_book_list(title,author,id,year,copies);
    printf("<%s> has been added to the library successfully!\n", title);
    printf("------------------------------------------------\n");
    librarian_menu();
}


//librarian to remove a book from the library
void remove_book(){
    while (1)
    {
        printf("------------------------------------------------\n");
        //display all the books in the library
        display_book();
        printf("Please enter the order of the book you wanna move out:(-1 to quit):\n");
        int choice;
        scanf("%d", &choice);
        if (choice == -1)
        {
            printf("Come back successfully!\n");
            printf("------------------------------------------------\n");
            return;
        }
        else if(choice<=book_num && choice>0){
            //remove specific book from the books linklist
            Book* tb;
            Book* np;
            np = book_head;
            tb = book_head->next;
            for (int i = 1; i < choice; ++i)
            {
                np = tb;
                tb = tb->next;
            }
            np->next = tb->next;
            free(tb);
            book_num--;
            store_books();
            printf("Remove successfully!\n");
            printf("------------------------------------------------\n");
        }
        else
        {
            printf("Invalid id!\n");
            printf("Please tyr again!\n");
        }

    }
}