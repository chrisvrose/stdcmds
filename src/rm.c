#include<stdio.h>

//Every file in argv gets eradicated

int main(int argc, char* argv[]){
    int statusflag=0,laststatus=0;
    for(int i=1;i<argc;i++){
        laststatus = remove(argv[i])==-1;
        printf("%c: Removal - %s\n",!laststatus?'S':'F',argv[i]);
        statusflag=statusflag||laststatus;
    }
    return statusflag;
}