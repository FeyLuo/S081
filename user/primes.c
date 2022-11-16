#include "kernel/types.h"
#include "user/user.h"

uint IsDivisible(uint dividend, uint divisor){
    return (dividend % divisor == 0);
}


int main(int argc, char* argv[])
{
    int pipes[12][2];
    uint index = 0;
    uint Existed_Prime = 0, tmp = 0, HasChildren = 0;
    pipe(pipes[index]);
    for(uint i=2;i<=35;i++)
    {
        write(pipes[index][1],&i,4);
    }
    close(pipes[index][1]);
    while(read(pipes[index][0],&tmp,4))
    {   
        if(Existed_Prime == 0)
        {
            fprintf(1,"prime %d\n",tmp);
            Existed_Prime = tmp;
            pipe(pipes[index+1]);
        }
        else
        {
            if(!IsDivisible(tmp, Existed_Prime))
            {
                write(pipes[index+1][1],&tmp,4);
                if(!HasChildren)
                {
                    if(fork() == 0)
                    {
                        Existed_Prime = 0;
                        index++;
                        close(pipes[index][1]);
                    }
                    else
                        HasChildren = 1;
                }
            }
        }
    }
    close(pipes[index+1][1]);
    wait((int*) 0);
    exit(0);
}