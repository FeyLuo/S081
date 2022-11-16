#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char* argv[])
{
    if(argc<2)
    {
        fprintf(2, "usage: sleep [some times].\n");
        exit(1);
    }
    uint ticks0;
    ticks0 = atoi(argv[1]);
    exit(sleep(ticks0));
}