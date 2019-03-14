#include <stdio.h>
#include "resman.h"

void allocate_strings(char* name)
{
    char* a_string = resman_alloc(name, 10);
    int i;
    for (i=0; i<10; i++)
    {
        a_string[i] = 'A';
    }
    printf("Allocation of %s succeded %s\n",name, a_string);
}

int main(int argc, char* argv[])
{
    int i;
    printf("Testing Resman!\n");

    resman_init();
    printf("Resman inited\n");
    char name[256];

    for (i=0; i<10; i++)
    {
        sprintf(&name, "Alloc number %d", i);
        allocate_strings(name);
    }
    printf("allocate done!\nDeleting all\n");
    resman_end();
    printf("Done\n");
    return 0;
}
