#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

/* Use the list for that mission, every list can be a queue ;) */

struct queue {
    List l;
};

typedef struct queue Queue;

int queue_init(Queue* q);                   /* Initialize the queue */
int queue_destroy(Queue* q);                /* Free the queue */
Node* queue_enqueue(Queue* q, void* value); /* Add to the queue */
void* queue_dequeue(Queue* q);              /* Pop from queue */
int queue_size(Queue* q);                   /* Get queue size */
void* queue_peek(Queue* q);                 /* Get queue first value */

#endif
