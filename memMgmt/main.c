#include <stdio.h>
#include <stdlib.h>
#include "types.h"

int main()
{
    init_memory_block();
    int choice ;

    while(1)
    {
        choice = take_user_input();

        if (5 == choice)
        {
            break;
        }
        execute_choice(choice);
    }

    return 0;
}

int take_user_input()
{
    int choice = '\0';
    printf("1: Allocate Memory\n");
    printf("2: Free Memory\n");
    printf("3: Display Free List \n");
    printf("4: Display Busy List \n");
    printf("5: Quit\n");

    printf ("Enter choice(1/2/3/4/5): ");
    scanf("%d",&choice);

    if (( 1 > choice) || (5< choice))
    {
        printf("Program quitting, please enter right choice next time\n");
        exit(1);
    }
    return choice;

}

void execute_choice(int choice)
{
    unsigned int size = 0;
    void *alloc = NULL;
    void *addr = NULL;
    int ret_val = 1;
    switch (choice)
    {
        case 1:
            printf("Enter the size of memory to be allocated(<%d): ",MAX_MEMORY);
            scanf("%u",&size);
            alloc = first_fit_alloc(size);

            if (NULL == alloc)
            {
                printf("Memory of size %u cannot be successfully allocated\n",size);
            }
            else
            {
                printf("Memory of size %u successfully allocated at address 0x%x\n", size, alloc);
            }
            break;

        case 2:
            printf("Enter the address of memory to be freed: ");
            scanf("%x",&addr);
            ret_val = my_memfree((void *)addr);

            if (0 == ret_val)
            {
                printf("Memory at address 0x%x cannot be freed\n ", addr);
            }
            else
            {
                printf("Memory at address 0x%x successfully freed\n ", addr);
            }
            break;

        case 3:
            display_free_list();
            break;

        case 4:
            display_busy_list();
            break;

        default:
            break;
    }
    return;
}
