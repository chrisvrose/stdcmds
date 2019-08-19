#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<gen.h>


#define STRLEN 64


int mergePaths(char* p1,char* p2,char* out,int outl){
    int p1l=-1,p2l=-1;
    while(p1[++p1l]);
    while(p2[++p2l]);
    ///2 null chars - > 1 null char + optional '/'
    if(outl>p1l+p2l){
        for(int i=0;i<p1l;i++){
            out[i]=p1[i];
        }
        if(p1[p1l-1]=='/'){
            /// '<=' to copy the null too
            for(int j=0;j<=p2l;j++){
                out[j+p1l]=p2[j];
            }
        }
        else{
            out[p1l]='/';
            for(int j=0;j<=p2l;j++){
                out[j+p1l+1]=p2[j];
            }
        }
        return 0;
    }
    else{
        ///Error with mismanaged lengths
        return 1;
    }
}

int main(int argc,char* argv[]){
    DIR* d;int a;
    unsigned char getSetBits = getSet(argv,argc);
    ///Get first non flag argument
    if(getRealArgs(argv,argc)==1){
        d = opendir(".");
    }
    else{
        a = findArgs(argc,argv,1);
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