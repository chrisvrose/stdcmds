#ifndef STDCMD_GEN_H
#define STDCMD_GEN_H

#define CHECKBIT(a) ((getSetBits & 1<<a)==1<<a)

struct bS{
    float truncatedSize;
    char modifier;
};
typedef struct bS bSize;


bSize prettySize(long int);

unsigned char getSet(char**,int);

int compareargc(int,int);

#endif