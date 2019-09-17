#include "types.h"
#include "user.h"

int main(int argc,char *argv[]){
    int stoptime;
    if(argc < 2){
        printf(2,"Usage: sleep seconds\n");
        exit();
    }
    stoptime = atoi(argv[1]);
    if(stoptime > 0){
        sleep(stoptime);
    }else{
        printf(2,"Invalid argument %s\n",argv[1]);
    }
    exit();
}