#include<stdio.h>
#include "gen.h"
#define BSIZE 64

int main(int argc, char* argv[]){
    if (argc<3){
        fprintf(stderr,"E:Too few arguments: %d\nUsage: cp <oldpath> <newpath>\n",argc);
        return 1;
    }
    if(argc>3){
        printf("W:Too many arguments:\nIgnoring arguments not required\n",argc);
    }
    
}
