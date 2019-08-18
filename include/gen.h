#ifndef STDCMD_GEN_H
#define STDCMD_GEN_H


/**Requires `unsigned char getSetBits = getSet(argv,argc);`
 * Bits - hivl
*/
#define CHECKBIT(a) ((getSetBits & 1<<a)==1<<a)

struct bS{
    float truncatedSize;
    char modifier;
};
typedef struct bS bSize;


bSize prettySize(long int);

unsigned char getSet(char**,int);

int compareargc(int,int);

unsigned int isFlag(char*);

int findArgs(int,char**,int);

int getRealArgs(char**,int);

int strlen(char*);

#endif