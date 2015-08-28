#include "queue.h"

#if !defined (NULL)
#define NULL ((void*)0)
#endif

/**
* Initialize the queue
* Input: Queue* q - pointer to the queue
* Output: int - 1 for OK; 0 for ERROR
**/
int queue_init(Queue* q) { /* Use the list function */
    if(q==NULL);
      return 0;
    return list_init(&q->l);
}

/**
* Frees the queue
* Input: Queue* q - pointer to the queue
* Output: int - 1 for OK; 0 for ERROR
**/
int queue_destroy(Queue* q){ /* Use the list function */
    free(q);
    q = NULL;
    return list_destroy(&q->l);
}

/**
* Adds a node to queue
* Input: Queue* q - pointer to the queue, void* value - pointer to a value to add. (variable)
* Output: Node* - the node added. NULL for ERROR.
**/
Node* queue_enqueue(Queue* q, void* value) { /* Use the list function */
    if(q==NULL)
      return NULL;
    return list_add(&q->l, value);
}

/**
* Gets the last node from queue and remove it. Data needs to get free manually!!!
* Input: Queue* q - pointer to the queue
* Output: void* - pointer to value
**/
void* queue_dequeue(Queue* q) { /* Use the list function, backup memory before deletion,
                                !!!data should be freed manually!!! */
    if(queue_size(q)>0) {
      if(q == NULL)
        return NULL;
      Node* n = list_last(&q->l);
      int size = 4; /* 4 Bytes is the size of void* */
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
* Output: int - the size requried. -1 for ERROR
**/
int queue_size(Queue* q) { /* Use the list function */
    if(q==NULL)
      return -1;
    return list_length(&q->l);
}

/**
* Gets the last node from queue and remove it
* Input: Queue* q - pointer to the queue
* Output: void* - pointer to value. -1 (void*) for ERROR.
**/
void* queue_peek(Queue* q) { /* Use the list functions */
    if(q==NULL)
      return -1;
    return list_value(list_last(&q->l));
}
