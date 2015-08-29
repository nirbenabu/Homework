#include <stdio.h>
#include "queue.h"

int main()
{
    Queue q;
    if(queue_init(&q)!=0)
        printf("INIT OK!\n");
    /* Test Functions */
    int a = 5, b=2;
    if(queue_enqueue(&q, &a)!=0)
        printf("INSERTION OK!\n");
    printf("Should be 5: %d\n", *(int*)queue_peek(&q));
    queue_enqueue(&q, &b);
    printf("Should be 2: %d\n", *(int*)queue_dequeue(&q));
    printf("Should be 5: %d\n", *(int*)queue_peek(&q));

    if(queue_destroy(&q)!=0)
        printf("DESTROY OK!");

    return 0;
}
