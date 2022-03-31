#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "page.h"
#include "book_management.h"

int main(int argc,char*argv[]) {
    printf("------------------------------------------------------------------------------------------------\n");
    printf("Welcome to the library!\n");
//    if(strcmp(argv[1],"./library")==0){
//        if(argv[2]!=NULL){
//            bookfilename=(char*)malloc(sizeof(argv[2]));
//            strcpy(bookfilename,argv[2]);
//
//        }
//    }
//    for(int i=0;i<argc;i++){
//        printf("%s\n",argv[i]);
//    }
//    main_menu();
//    return 0;
//check the command line and assgin name to library
    if(strcmp(argv[0],"./library")==0 && argc==3){
        bookfilename=(char*)malloc(sizeof(argv[1])+1);
        userfilename=(char*)malloc(sizeof(argv[2]+1));
        strcpy(bookfilename,argv[1]);
        strcpy(userfilename,argv[2]);
        main_menu();
        return 0;
    }

    else{
        printf("Please enter three command lines!\n");
        return 0;
    }

}
