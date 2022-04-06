//
// Created by Jiayi on 2022/3/17.
//

#include <stdlib.h>
#include <string.h>
#include "librarian.h"
#include "page.h"
#include "login.h"
#include "user.h"


int search_id(int id){
    Book* np=head.list->next;
    while(np){
        if(id==np->id){
            return 1;
        }
        np=np->next;
    }
    return 0;
}
//add a book to the linklist and invoke create_book_list to update the linklist
void add_book(){
    //create temp array to get the size of title/author
    char title[100],author[100];
    int id,year,copies;
    printf("\n");
    printf("------------------------------------------------------------------------------------------------\n");;
    printf("Please follow the following rules:\n");
    printf("Please enter an integer of book id(0-1000):\n");
    printf("(If you enter a letter or string, the id will default to 0)\n");
    scanf("%d", &id);
    if(id>1000){
        printf("Please ensure id is smaller than 1000.\n");
        return;
    }
    if(search_id(id)==1){
        printf("This id has been used! Please change!\n");
        return;
    }
    printf("%d\n",id);
    clear();
    printf("Please enter the title:\n");
    scanf("%[^\n]",title);
    clear();
    printf("Please enter the author:\n");
    scanf("%s",author);
    printf("Please enter the year:\n");
    scanf("%d", &year);
    printf("Please enter its copies:\n");
    scanf("%d", &copies);
    head.length++;
    //invoke create_book_list to add new book to the las linklist node and update linklist to the file
    creat_book_list(title,author,id,year,copies);
    printf("<%s> has been added to the library successfully!\n", title);
    printf("------------------------------------------------------------------------------------------------\n");
    printf("\n");
    librarian_menu();
}


//librarian to remove a book from the library
void remove_book(){
    while (1)
    {
        printf("\n");
        printf("------------------------------------------------------------------------------------------------\n");
        //display all the books in the library
        display_book();
        printf("Please enter the order of the book you wanna move out:(-1 to quit):\n");
        int choice;
        scanf("%d", &choice);
        if (choice == -1)
        {
            printf("Come back successfully!\n");
            printf("\n");
            printf("------------------------------------------------------------------------------------------------\n");
            return;
        }
        else if(choice<=head.length && choice>0){
            //remove specific book from the books linklist
            Book* tb;
            Book* np;
            np = head.list;
            tb = head.list->next;
            for (int i = 1; i < choice; ++i)
            {
                np = tb;
                tb = tb->next;
            }
            np->next = tb->next;
            free(tb);
            head.length--;
            store_books();
            printf("Remove successfully!\n");
        }
        else
        {
            printf("Invalid id!\n");
            printf("Please tyr again!\n");
        }

    }
}

void display_user()
{
    int i = 1;
    User* np ;
    np = user_head_node->next;
    printf("Order  Username\t\tPassword\n");
    while (np)
    {
        printf("%d) %-20s %-20s \n", i, np->user_name, np->password);
        np = np->next;
        ++i;
    }
}

void delete_user()
{
    while (1)
    {
        display_user();
        printf("Please enter the order of the user you want to remove(input -1 back):\n");
        int option;
        scanf("%d", &option);
        clear();
        if (option == -1)
        {
            printf("Come back successfully!\n");
            printf("\n");
            printf("------------------------------------------------------------------------------------------------\n");
            return;
        }
        else if (option > user_num || option <= 0)
        {
            printf("Invalid choice!\n");
            printf("\n");
        }
        else
        {

            User* tb;
            User *np;
            np = user_head_node;
            tb = user_head_node->next;
            for (int i = 1; i < option; ++i)
            {
                np = tb;
                tb = tb->next;
            }
            np->next = tb->next;
            free(tb);
            --user_num;
            store_users();
            printf("Remove successfully!\n");
        }
    }
}

