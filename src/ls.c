#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<gen.h>



int main(int argc,char* argv[]){
    DIR* d;int a;
    unsigned char getSetBits = getSet(argv,argc);
    ///Get first non flag argument
    if(getRealArgs(argv,argc)==1){
        d = opendir(".");
    }
    else{
        a = findArgs(argc,argv,0);
        if(a==-1){
            fprintf(stderr,"E:Could not find file\n");
            return 1;
        }
        d = opendir(argv[a]);
    }
    if(d == NULL){
        fprintf(stderr,"E: Could not open directory. Check path\n");
    }

    
    struct dirent *lastDir;
    if(CHECKBIT(0)){
        printf("W:Not implemented\n");
    }
    else{
        while((lastDir = readdir(d))!=NULL){
            printf("%s\n",lastDir->d_name);
        }
    }
    


    closedir(d);
    return 0;
}