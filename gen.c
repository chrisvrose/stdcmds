typedef struct bSize{
    float truncatedSize;
    char modifier;
} bSize;

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
