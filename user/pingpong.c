#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char* argv[])
{
    int p[2];
    char tmp;

    pipe(p);
    if(fork() == 0)
    {
        read(p[0],&tmp,1);
        fprintf(1,"%d: received ping\n",getpid());
        close(p[0]);
        write(p[1],"a",1);
        close(p[1]);
        exit(0);
    }
    else
    {
        write(p[1],"a",1);
        close(p[1]);
        read(p[0],&tmp,1);
        fprintf(1,"%d: received pong\n",getpid());
        close(p[0]);
        exit(0);
    }
    exit(0);
}