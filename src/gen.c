#include<gen.h>

/*
    Div - 1024
    K - kilo
    M - mega
    G - giga
    we go no further for sanity

 */
bSize prettySize(long int bytes){
    bSize returnable;
    float byteF = (float)bytes;
    if(byteF>1024){
        byteF/=1024;
        //atleast kilo
        returnable.modifier='K';

        if(byteF>1024){
            byteF/=1024;
            //atleast mega
            returnable.modifier='M';

            if(byteF>1024){
                byteF/=1024;
                //Giga, we do not proceed further
                returnable.modifier = 'G';
            }
        }
        
    }
    else{
        ///bytes require no character suffix
        returnable.modifier=' ';
    }
    returnable.truncatedSize = byteF;
    return returnable;
}

///Store information about passed flags into an int flag holder.
// bits - hivl
unsigned char getSet(char** argv,int argc){
    unsigned char settings=0;
    for(int i=0;i<argc;i++){
        if(isFlag(argv[i])){
            for(int j=1;argv[i][j]!='\0';j++){
                if(argv[i][j]=='l'){
                    settings |= 1<<0;
                }
                else if(argv[i][j]=='v'){
                    settings |= 1<<1;
                }
                else if(argv[i][j]=='i'){
                    settings |= 1<<2;
                }
                else if(argv[i][j]=='h'){
                    settings |= 1<<3;
                }
            }
        }
    }
    
    return settings;

}

int compareargc(int argc,int expargc){
    if(argc>expargc) return 1;
    else if(argc<expargc) return -1;
    else return 0;
    //return ();
}

///Return 1 if flag
unsigned int isFlag(char* arg){
    return arg[0]=='-';
}

///Return -1 if not found any argument, else return the position in the array
int findArgs(int argc,char* argv[],int startFromPosition){
    int flagPos=-1;
    for(int i=startFromPosition;i<argc;i++){
        if(!isFlag(argv[i])){
            flagPos=i;break;
        }
    }
    return flagPos;
}

///Get the real number of arguments, skipping flags passed to program
int getRealArgs(char*  argv[],int argc){
    int realArgs=0;
    for(int i=0;i<argc;i++){
        if(!isFlag(argv[i])){
            realArgs++;
        }
    }
    return realArgs;
}

int strlen(char* str){
    int i=-1;
    while(str[++i]!='\0');
    return i;
}