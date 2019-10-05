#include "types.h"
#include "user.h"

int global_array[2048] = {0};
int global_var = 0;

void testcase4(){
    int pid;

    printf(1,"\n----- Test case 4 -----\n");
    printf(1,"[prnt] v1 --> ");
    print_free_frame_cnt();

    if((pid = fork()) == 0)
    {
        //child
        sleep(100);
        printf(1,"[chld] v4 --> ");
        print_free_frame_cnt();
        
        global_array[0] = 222;
        printf(1,"[chld] modified one element in the 1st page, global_array[0]=%d\n", global_array[0]);

        printf(1,"[chld] v5 --> ");
        print_free_frame_cnt();

        global_array[2047] = 333;           
        printf(1,"[chld] modified two elements in the 2nd page, global_array[2047]=%d\n", global_array[2047]);

        printf(1,"[chld] v6 --> ");
        print_free_frame_cnt();
        
        exit();
    }
    else 
    {
        //parent
        printf(1,"[prnt] v2 --> ");
        print_free_frame_cnt();
        
        global_array[0] = 111;     
        printf(1,"[prnt] modified one element in the 1st page, global_array[0]=%d\n", global_array[0]);

        printf(1,"[prnt] v3 --> ");
        print_free_frame_cnt();
    }

    if (wait() != pid)
    {
        printf(1,"wait() error!");
        exit();
    }    

    printf(1, "[prnt] v7 --> ");
    print_free_frame_cnt();
}

void testcase3(){
    int pid;

    printf(1,"\n----- Test case 3 -----\n");
    printf(1,"[prnt] v1 --> ");
    print_free_frame_cnt();

    if((pid = fork()) == 0)
    {
        //child
        sleep(100);
        printf(1,"[chld] v4 --> ");
        print_free_frame_cnt();
        
        global_var = 100;
        printf(1,"[chld] modified global_var, global_var=%d\n", global_var);
        
        printf(1,"[chld] v5 --> ");        
        print_free_frame_cnt();
        
        exit();
    }
    else 
    {
        //parent
        printf(1,"[prnt] v2 --> ");
        print_free_frame_cnt();
        
        printf(1,"[prnt] read global_var, global_var=%d\n", global_var);

        printf(1,"[prnt] v3 --> ");
        print_free_frame_cnt();
    }
    
    if (wait() != pid)
    {
        printf(1,"wait() error!");
        exit();
    }    

    printf(1, "[prnt] v6 -->  ");
    print_free_frame_cnt();
}

void testcase2(){
    int pid;
    
    printf(1,"\n----- Test case 2 -----\n");
    printf(1,"[prnt] v1 ---> ");
    print_free_frame_cnt();

    if((pid = fork()) == 0)
    {
        //child
        sleep(100);
        printf(1,"[chld] v3 ---> ");
        print_free_frame_cnt();
        
        printf(1,"[chld] read global_var, global_var=%d\n", global_var);
        
        printf(1,"[chld] v4 ---> ");
        print_free_frame_cnt();
        
        exit();
    }
    else 
    {
        //parent
        printf(1,"[prnt] v2 ---> ");
        print_free_frame_cnt();
    }
    
    if (wait() != pid)
    {
        printf(1,"wait() error!");
        exit();
    }    

    printf(1, "[prnt] v5 --> ");
    print_free_frame_cnt();
}

void testcase1(){
    int pid;

    printf(1,"\n----- Test case 1 -----\n");
    printf(1,"[prnt] v1 --> ");
    print_free_frame_cnt();
    
    if((pid = fork()) == 0)
    {
        //child
        sleep(100);        
        printf(1, "[chld] v2 --> ");
        print_free_frame_cnt();
        exit();
    }
    else 
    {
        //parent
        printf(1, "[prnt] v3 --> ");
        print_free_frame_cnt();
    }
    
    if (wait() != pid)
    {
        printf(1, "wait() error!");
        exit();
    }
    
    printf(1, "[prnt] v4 --> ");
    print_free_frame_cnt();
}

int main(){
    testcase1();
    testcase2();
    testcase3();
    testcase4();
    exit();
}
