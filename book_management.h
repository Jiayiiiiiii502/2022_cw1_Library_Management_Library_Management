//
// Created by Jiayi on 2022/3/17.
//

#ifndef NEW_BOOK_MANAGEMENT_H
#define NEW_BOOK_MANAGEMENT_H

#include <stdio.h>

/*You can extend the structs (Book and BookList) defined in this head file;
  However, you may not change the function prototypes.
  You are also free to add additional head files and data structures as needed.
*/


typedef struct _Book {
    unsigned int id; //Book ID
    char *title; //book title
    char temp_title[50];
    char *authors; //comma separated list of authors
    char temp_authors[50];
    unsigned int year; // year of publication
    unsigned int copies; //number of copies the library has
    struct _Book *next; //pointer to the next book element
}Book;

Book* book_head;
int book_num;

typedef struct _BookList {
    Book* list; // pointer to a list of struct Book.
    unsigned int length; // number of elements in the (Book*) List
}BookList;

typedef struct _BookArray {
    Book* array; // pointer to array (or linked list) of struct Book.
    unsigned int length; // number of elements in the (Book*) array
}BookArray;


struct node{
    int borrow_num;
    int max_num;
    Book borrow_book[3];
};

//saves the database of books in the specified file
//returns 0 if books were stored correctly, or an error code otherwise
//int store_books(FILE *file);
void store_books();

//loads the database of books from the specified file
//the file must have been generated by a previous call to store_books()
//returns 0 if books were loaded correctly, or an error code otherwise
//int load_books(FILE *file);
void load_books();





//finds books with a given title.
//returns a BookList structure, where the field "list" is a list of books, or null if no book with the
//provided title can be found. The length of the list is also recorded in the returned structure, with 0 in case
//list is the NULL pointer.
//BookList find_book_by_title (const char *title);

//finds books with the given authors.
//returns a Booklist structure, where the field "list" is a newly allocated list of books, or null if no book with the
//provided title can be found. The length of the list is also recorded in the returned structure, with 0 in case
//list is the NULL pointer.
//BookList find_book_by_author (const char *author);

//finds books published in the given year.
//returns a Booklist structure, where the field "list" is a list of books, or null if no book with the
//provided title can be found. The length of the list is also recorded in the returned structure, with 0 in case
//list is the NULL pointer.
//BookList find_book_by_year (unsigned int year);


void find_book_by_title ();
void find_book_by_author ();
void find_book_by_year ();


void creat_book_list(char*, char*, int, int, int);
void display_book();

#endif //NEW_BOOK_MANAGEMENT_H
