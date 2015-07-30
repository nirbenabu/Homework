#include <stdio.h>
#include "list.h"

int main()
{
    List l; /* Our list */

    /* Test all functions */
    if(list_init(&l)!=0)
        printf("INIT OK!\n");

    int a = 5, b=2;
    Node* n = list_add(&l, &a);

    if(n!=0)
        printf("INSERTION OK!\n");

    n = list_add(&l, &b);
    printf("Should be 2: %d\n",list_getint(list_next(list_first(&l)))); /* list_getint is using the required list_value(), it is a subcase */
    printf("Should be 3.5: %.1f \n", list_average(&l));
    printf("Is it working? %s!\n", (list_last(&l)==n)?"YES":"NO");
    list_delete(&l, n);
    a=0; /* Checking if memory is copied and not pointed to */
    printf("Should be 5.0: %.1f \n", list_average(&l));

    if(list_destroy(&l)!=0)
        printf("DESTROY OK!\n");

    return 0;
}
