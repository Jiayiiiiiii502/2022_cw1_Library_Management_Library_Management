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
//    if (fp2 == NULL)
//    {
//        fp2 = fopen("library.txt", "wb");
//        if (fp2 == NULL)
//        {
//            printf("Fail to load the books!\n"); exit(0);
//        }
//        fclose(fp2);
//    }
//    else
//    {
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
//    }
}


//store books from linklist to file
void store_books()//将链表写入图书文件
{
    FILE*fp = fopen("library_new.txt", "wb");
    Book* tb = book_head->next;
    while (tb)
    {
        fwrite(tb, sizeof(Book), 1, fp);
        tb = tb->next;
    }
    fclose(fp);
}

void creat_book_list(char* title, char* author, int id, int year, int copies)//更新所有书籍链表，调用store函数将新链表写入文件中
{
    Book* np;
    np = book_head;
    while (np->next) np = np->next;
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

