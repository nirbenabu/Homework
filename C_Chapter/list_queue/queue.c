#include "queue.h"

/**
* Initialize the queue
* Input: Queue* q - pointer to the queue
* Output: int - 1 for OK; 0 for ERROR
**/
int queue_init(Queue* q) { /* Use the list function */
    return list_init(&q->l); // T: check q is not null
}

/**
* Frees the queue
* Input: Queue* q - pointer to the queue
* Output: int - 1 for OK; 0 for ERROR
**/
int queue_destroy(Queue* q){ /* Use the list function */
    return list_destroy(&q->l); // T: check q is not null 
    // T: destroy Queue struct
}

/**
* Adds a node to queue
* Input: Queue* q - pointer to the queue, void* value - pointer to a value to add. (variable)
* Output: Node* - the node added.
**/
Node* queue_enqueue(Queue* q, void* value) { /* Use the list function */
    return list_add(&q->l, value); // T: check q is not null
}

/**
* Gets the last node from queue and remove it. Data needs to get free manually!!!
* Input: Queue* q - pointer to the queue
* Output: void* - pointer to value
**/
void* queue_dequeue(Queue* q) { /* Use the list function, backup memory before deletion,
                                !!!data should be freed manually!!! */
    if(queue_size(q)>0) {
        Node* n = list_last(&q->l); // T: check q is not null
        int size = sizeof(list_value(n)); // T: list value returns void* pointer, sizeof pointer is 4
        void* data = (void*)malloc(size);
        memcpy(data, list_value(list_last(&q->l)), size);
        list_delete(&q->l, n);

        return data;
    } else
        return 0;
}

/**
* Get queue size
* Input: Queue* q - pointer to queue
* Output: int - the size requried
**/
int queue_size(Queue* q) { /* Use the list function */
    return list_length(&q->l); // T: check q is not null
}

/**
* Gets the last node from queue and remove it
* Input: Queue* q - pointer to the queue
* Output: void* - pointer to value
**/
void* queue_peek(Queue* q) { /* Use the list functions */
    return list_value(list_last(&q->l)); // T: check q is not null
}
