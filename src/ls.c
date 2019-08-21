#include<stdio.h>

///Standard sys types
#include<sys/types.h>
///Managing time types
#include<time.h>


///Directory management
#include<dirent.h>

///fstat, lstat
#include<sys/stat.h>


///For Uid,Gid and formatted time
#include<pwd.h>
#include<grp.h>
#include<time.h>

///Contains some symbols and definitions
#include<unistd.h>


///Header for gen.c
#include<gen.h>

///Length of (most) strings defined
#define STRLEN 64


///Return the formatted permissions string
///Outvar is expected to be atleast size 11
int formatPerms(struct stat* statPtr,char* outVar){
    char permRemainder[] = "rwx";
    outVar[0]= S_ISDIR(statPtr->st_mode)?'d':'-';
    for(int i=1;i<10;i++){
        ///Check with 10-i'th bit (left shift 9-i bits).
        ///If true, get perm char from permRemainder
        outVar[i]= (statPtr->st_mode & (1<<(9-i)) )? permRemainder[(i-1)%3] : '-';
    }
    ///Set last to null
    outVar[10]='\0';
    return 0;
}

int formatUid(struct stat* statPtr,char* outVar){
    struct passwd*  userStat = getpwuid(statPtr->st_uid);
    if(userStat==NULL){
        return 1;
    }
    int i;
    for(i=0;i<STRLEN/2 && userStat->pw_name[i]!='\0';i++){
        outVar[i]=userStat->pw_name[i];
    }
    outVar[i]=0;
    return 0;
}

int formatGid(struct stat* statPtr,char* outVar){
    struct group* grpStat = getgrgid(statPtr->st_gid);
    if(grpStat==NULL){
        return 1;
    }
    int i;
    for(i=0; i<STRLEN/2 && grpStat->gr_name!='\0';i++){
        outVar[i]=grpStat->gr_name[i];
    }
    outVar[i]=0;
    return 0;
}



int mergePaths(char* p1,char* p2,char* out,int outl){
    int p1l=-1,p2l=-1;
    while(p1[++p1l]);
    while(p2[++p2l]);
    //printf("<INFO>%d%d\n",p1l,p2l);
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
    DIR* d;int argSensible;
    unsigned char getSetBits = getSet(argv,argc);
    char defaultLocation[]=".";
    char* openLocation;
    ///Get first non flag argument
    ///printf("D:%d",getRealArgs(argv,argc));
    if(getRealArgs(argv,argc)==1){
        openLocation = defaultLocation;   
    }
    else{
        argSensible = findArgs(argc,argv,1);
        if(argSensible==-1){
            fprintf(stderr,"E:Could not find file\n");
            return 1;
        }
        openLocation = argv[argSensible];
        //d = opendir(openLocation);
    }
    if( (d = opendir(openLocation)) == NULL){
        fprintf(stderr,"E: Could not open directory. Check path\n");
    }

    
    struct dirent *lastDir;
    struct stat lastStats;
    struct tm *lastTm;
    char lastMergePath[STRLEN],lastPerms[11],lastUid[STRLEN],lastGid[STRLEN],*lastAccT;
    int lastAccTl;
    if(CHECKBIT(0)){
        //printf("W:Not implemented\n");
        while((lastDir = readdir(d))!=NULL){
            //printf("OH DEAR HERE WE GO %s\n",openLocation);
            mergePaths(openLocation,lastDir->d_name,lastMergePath,STRLEN);
            //printf("%s",lastMergePath);
            ///Get stats, checking if error
            if( lstat(lastMergePath,&lastStats) ==0 ){
                formatPerms(&lastStats,lastPerms);
                formatUid(&lastStats,lastUid);
                formatGid(&lastStats,lastGid);
                lastAccT =  ctime(&(lastStats.st_atime));
                lastAccTl=0;
                while(lastAccT[++lastAccTl]);
                lastAccT[lastAccTl-1]=0;
                printf("%s %2d %s %s %4d %s %s\n",lastPerms,lastStats.st_nlink ,lastUid,lastGid,lastStats.st_size,lastAccT,lastDir->d_name);
            }
        }
    }
    else{
        while((lastDir = readdir(d))!=NULL){
            printf("%s\n",lastDir->d_name);
        }
    }
    


    closedir(d);
    return 0;
}