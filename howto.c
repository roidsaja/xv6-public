#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc,char *argv[]){
    // 0 - stdin
    // 1 - stdout
    // 2 - stderr
    printf(1,"--------------------\n");
    printf(1,"To add a system call that can be called in xv6's shell:\n");
    printf(1,"sysproc.c ; syscall.h ; user.h ; syscall.c ; usys.S ; defs.h ; sysfunc.h\n");
    printf(1,"or go here: https://stackoverflow.com/questions/8021774/how-do-i-add-a-system-call-utility-in-xv6");
    exit();
}