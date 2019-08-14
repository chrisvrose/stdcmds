#include<stdio.h>
#include<gen.h>

// Buffer size to use for copying, in bytes
#define BSIZE 64

// Expected number of arguments
# define EAC 3
//#define eprintf() fprintf()
int main(int argc, char* argv[]){
    if (compareargc(argc,EAC)==-1){
        fprintf(stderr,"E:Too few arguments: %d\nUsage: cp <oldpath> <newpath>\n",argc);
        return 1;
    }
    if(compareargc(argc,EAC)==1){
        printf("W:Too many arguments:\nIgnoring arguments not required\n",argc);
    }


    FILE* op = fopen(argv[1],"rb");
    if(op==NULL){
        fprintf(stderr,"E:Source file could not be opened\n");
        return 2;
    }
    else{
        FILE* np = fopen(argv[2],"wb+");
        if(np==NULL){
            fprintf(stderr,"E:Destination file cannot be used\n");
            return 3;
        }
        else{
            char buffer[BSIZE];
            long int lastCopySize=0,copiedBytes=0;
            while(!feof(op)){
                lastCopySize = fread(buffer,1,BSIZE,op);
                copiedBytes+=lastCopySize;
                fwrite(buffer,1,lastCopySize,np);
            }
            bSize pS = prettySize(copiedBytes);
            printf("I:Copied: %0.2f%c bytes\n",pS.truncatedSize,pS.modifier);
            fclose(np);
        }
        fclose(op);
    }
    return 0;
}