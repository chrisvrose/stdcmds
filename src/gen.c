typedef struct bS{
    float truncatedSize;
    char modifier;
} bSize;

typedef struct settingS{
    unsigned char l;
    unsigned char v;
}settingS;


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
                //Giga
                returnable.modifier = 'G';
            }
        }
        
    }
    else{
        returnable.modifier=' ';
    }
    returnable.truncatedSize = byteF;
    return returnable;
}

settingS getSet(char* input){
    settingS settings = (settingS){.l=0,.v=0};
    for(int i=1;input[i]!='\0';i++){
        if(input[i]=='l'){
            settings.l=1;
        }
        else if(input[i]=='v'){
            settings.v=1;
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