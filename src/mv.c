#include<stdio.h>
#include<gen.h>



// Buffer size to use for copying, in bytes
#define BSIZE 64

// Expected number of arguments
# define EAC 3

int main(int argc, char* argv[]){
    if (compareargc(getRealArgs(argv,argc),EAC)==-1){
        fprintf(stderr,"E:Too few arguments: %d\nUsage: cp <oldpath> <newpath>\n",argc);
        return 1;
    }

    unsigned char getSetBits = getSet(argv,argc);


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
            if((getSetBits & 1<<1)==1<<1){
                printf("I:Moved: %0.2f%c bytes\n",pS.truncatedSize,pS.modifier);
            }
            // Now to delete old file
            fclose(np);
            if(!remove(argv[1])){
                if(CHECKBIT(1)){
                    printf("I:%s removed\n",argv[1]);
                }
            }
            else{
                fprintf(stderr,"E:Could not remove old file\n");
                return 4;
            }

        }
        fclose(op);
    }
    return 0;
}
