#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "page.h"
#include "book_management.h"

int main(int argc,char*argv[]) {
    //check the command line and assgin name to library
//    if(strcmp(argv[0],"./library")==0 && argc==3){
//        printf("------------------------------------------------------------------------------------------------\n");
//        printf("Welcome to the library!\n");
//        bookfilename=(char*)malloc(sizeof(argv[1])+1);
//        userfilename=(char*)malloc(sizeof(argv[2]+1));
//        strcpy(bookfilename,argv[1]);
//        strcpy(userfilename,argv[2]);
//        main_menu();
//        return 0;
//    }
//
//    else{
//        printf("Please enter three command lines!\n");
//        return 0;
//    }
        char book[20];
        char user[20];
        bookfilename=(char*)malloc(sizeof(book+1));
        userfilename=(char*)malloc(sizeof(user+1));
        strcpy(bookfilename,"library.bin");
        strcpy(userfilename,"users.bin");
        main_menu();
        return 0;
}
