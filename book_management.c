//
// Created by Jiayi on 2022/3/17.
//

#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "book_management.h"

//load books from file to linklist
void load_books()
{
    //create head node to point to the book linklist
//    book_head = (Book*)malloc(sizeof(Book));
//    book_head->next = NULL;
//    book_num = 0;
    head.list=(Book*)malloc(sizeof(Book));
    head.list->next=NULL;
    head.length=0;

    //check the file exist
    FILE* fp2;
    fp2 = fopen("library.txt", "rb");
    if(fp2==NULL){
        fp2=fopen("library.txt","wb");
        if(fp2==NULL){
            printf("Fail to load the file!\n");
            exit(0);
        }
        fclose(fp2);
    }
    else{
        Book* bp;
        bp = head.list;
        Book* tp = (Book*)malloc(sizeof(Book));
        while (fread(tp, sizeof(Book), 1, fp2))
        {
            bp->next = tp;
            head.length++;
            tp = (Book*)malloc(sizeof(Book));
            bp = bp->next;
        }
        fclose(fp2);
    }
}





//store books from linklist to binary file
void store_books(){
    FILE*fp = fopen("library.txt", "wb");
    Book* tb = head.list->next;
    while (tb)
    {
       fwrite(tb, sizeof(Book), 1, fp);
       tb = tb->next;
    }
    fclose(fp);
}




//used in the add_book function to add new structure to the linklist, and update linklist to the file
void creat_book_list(char* title, char* author, int id, int year, int copies){
    Book* np;
    //np = book_head;
    np=head.list;
    while (np->next) {
        np = np->next;
    }

    //dynamic create a structure Book and its *title and *authors!important!
    Book* tb = (Book*)malloc(sizeof(Book));
    tb->title=(char*)malloc(sizeof(title));
    tb->authors=(char*)malloc(sizeof(author));

    //copy the temp_authors/temp_title to the *author/*title
    strcpy(tb->temp_authors, author);
    strcpy(tb->temp_title, title);
    tb->id = id;
    tb->year = year;
    tb->copies =copies;
    tb->next = NULL;
    np->next = tb;

    //update the linklist to the file
    store_books();
}







//search book in the library linklist by title
void find_book_by_title(){
    char temp[30];
    Book *tb=head.list->next;
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
    tb=head.list->next;
    printf("ID\t\tTitle\t\tAuthor\t\tYear\t\tCopies\n");
    while(tb)
    {
        if(strcmp(temp,tb->title)==0)
            printf("%-15d %-15s %-20s %-15d %-15d\n", tb->id, tb->title, tb->authors, tb->year, tb->copies);
        tb=tb->next;
    }
    return;
}






//search book in the library linklist by author
void find_book_by_author (){
    char temp[30];
    Book *tb=head.list->next;
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
    tb=head.list->next;
    printf("ID\t\tTitle\t\tAuthor\t\tYear\t\tCopies\n");
    while(tb)
    {
        if(strcmp(temp,tb->authors)==0)
            printf("%-15d %-15s %-20s %-15d %-15d\n", tb->id, tb->title, tb->authors, tb->year, tb->copies);
        tb=tb->next;
    }
    return;
}





//search book in the library linklist by year
void find_book_by_year (){
    int year;
    Book *tb=head.list->next;
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
    tb=head.list->next;
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
    if (!head.length)
    {
        printf("Sorry! There is no book in the library!\n");
        return;
    }

    Book* all;
    all = head.list->next;
    printf("-------------------------------Library---------------------------------\n");
    printf("ID\t\tTitle\t\tAuthor\t\tYear\t\tCopies\n");

    //use book_num to ensure dynamic id
    int i;
    for(i=1;i<=head.length;i++){
        while (all)
        {
            printf("%-15d %-15s %-20s %-15d %-15d\n", i, all->temp_title, all->temp_authors, all->year, all->copies);
            all = all->next;
            i++;
        }
    }
}

