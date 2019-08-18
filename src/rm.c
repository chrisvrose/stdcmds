#include<stdio.h>
#include<gen.h>

//Every file in argv gets eradicated, hopefully



int main(int argc, char* argv[]){
    if(compareargc(getRealArgs(argv,argc),2)==-1){
        fprintf(stderr,"E:Too few inputs - Specify atleast one filename");
    }
    int statusflag=0,laststatus=0;
    unsigned char getSetBits = getSet(argv,argc);
    for(int i=1;i<argc;i++){
        ///Skip flags
        if(isFlag(argv[i])){
            continue;
        }
        laststatus = remove(argv[i])==-1;
        if(CHECKBIT(1)){
            printf("I:%c: Removal - %s\n",!laststatus?'S':'F',argv[i]);
        }
        else{
            fprintf(stderr,"E:Could not remove \"%s\"",argv[i]);
        }
        statusflag=statusflag||laststatus;
    }
    return statusflag;
}