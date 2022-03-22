//
// Created by Jiayi on 2022/3/17.
//

#include <malloc.h>
#include <string.h>
#include "book_management.h"

//load books from file to linklist
void load_books()
{
    book_head = (Book*)malloc(sizeof(Book));
    book_head->next = NULL;
    book_num = 0;

    FILE* fp2;
    fp2 = fopen("library_new.txt", "rb");
    Book* bp;
    bp = book_head;
    Book* tp = (Book*)malloc(sizeof(Book));
    while (fread(tp, sizeof(Book), 1, fp2))
    {
        bp->next = tp;
        book_num++;
        tp = (Book*)malloc(sizeof(Book));
        bp = bp->next;
    }
    fclose(fp2);
}


//store books from linklist to file
void store_books(){
    FILE*fp = fopen("library_new.txt", "wb");
    Book* tb = book_head->next;
    while (tb)
    {
        fwrite(tb, sizeof(Book), 1, fp);
        tb = tb->next;
    }
    fclose(fp);
}

void creat_book_list(char* title, char* author, int id, int year, int copies){
    Book* np;
    np = book_head;
    while (np->next) {
        np = np->next;
    }
    Book* tb = (Book*)malloc(sizeof(Book));
    strcpy(tb->authors, author);
    strcpy(tb->title, title);
    tb->id = id;
    tb->year = year;
    tb->copies =copies;
    tb->next = NULL;
    np->next = tb;
    store_books();
}


void find_book_by_title(){
    char temp[30];
    Book *tb=book_head->next;
    printf("Please enter the title of the book:");
    scanf("%s",temp);
    while(tb)
    {
        if(strcmp(temp,tb->title)==0)
            break;
        tb=tb->next;
    }
    if(tb==NULL)
    {
        printf("Sorry,there is no such book in the library!\n");
        return;
    }
    tb=book_head->next;
    printf("ID\t\tTitle\t\tAuthor\t\tYear\t\tCopies\n");
    while(tb)
    {
        if(strcmp(temp,tb->title)==0)
            printf("%-15d %-15s %-20s %-15d %-15d\n", tb->id, tb->title, tb->authors, tb->year, tb->copies);
        tb=tb->next;
    }
    return;
}


void find_book_by_author (){
    char temp[30];
    Book *tb=book_head->next;
    printf("Please enter the author of the book:");
    scanf("%s",temp);
    while(tb)
    {
        if(strcmp(temp,tb->authors)==0)
            break;
        tb=tb->next;
    }
    if(tb==NULL)
    {
        printf("Sorry,there is no such book in the library!\n");
        return;
    }
    tb=book_head->next;
    printf("ID\t\tTitle\t\tAuthor\t\tYear\t\tCopies\n");
    while(tb)
    {
        if(strcmp(temp,tb->authors)==0)
            printf("%-15d %-15s %-20s %-15d %-15d\n", tb->id, tb->title, tb->authors, tb->year, tb->copies);
        tb=tb->next;
    }
    return;
}

void find_book_by_year (){
    int year;
    Book *tb=book_head->next;
    printf("Please enter the year of the book:");
    scanf("%d",&year);
    while(tb)
    {
        if(year==tb->year)
            break;
        tb=tb->next;
    }
    if(tb==NULL)
    {
        printf("Sorry,there is no such book in the library!\n");
        return;
    }
    tb=book_head->next;
    printf("ID\t\tTitle\t\tAuthor\t\tYear\t\tCopies\n");
    while(tb)
    {
        if(year==tb->year)
            printf("%-15d %-15s %-20s %-15d %-15d\n", tb->id, tb->title, tb->authors, tb->year, tb->copies);
        tb=tb->next;
    }
    return;
}


//show all the books in the library by linklist
void display_book(){
    if (!book_num)
    {
        printf("Sorry! There is no book in the library!\n");
        return;
    }

    Book* all;
    all = book_head->next;
    printf("-------------------------------Library---------------------------------\n");
    printf("ID\t\tTitle\t\tAuthor\t\tYear\t\tCopies\n");
    for(int i=1;i<=book_num;i++){
        while (all)
        {
            printf("%-15d %-15s %-20s %-15d %-15d\n", i, all->title, all->authors, all->year, all->copies);
            all = all->next;
            i++;
        }
    }
}

