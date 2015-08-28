#include "list.h"

// T: better use defines for functions return values,

/**
* Initializes the dynamic list.
* Input: List* l - pointer to list struct
* Output: int - 1 for true, 0 for false
**/
int list_init(List* l) {
    // T: check l is not null
    l->_size = 0; // T: better use NULL define
    l->_first = 0;
    l->_last = 0;
    l->_sum = 0;

    return 1;
}

/**
* Releases the dynamic list.
* Input: List* l - pointer to list struct
* Output: int - 1 for true, 0 for false
**/
int list_destroy(List* l) {
    // T: check l is not null
    /* Iterate through all elements and release them */
    l->_size = 0;
    l->_sum = 0;

    Node* cur = l->_first;

    if(cur == 0) // T: better use null define
        return 1;

    while(cur->_next != 0) /*TODO: fix */ // T: do your todo
    {
        Node* n = cur->_next;
        free_node(cur);
        cur = n;
    }

    free_node(l->_last);
    // T: free list struct 
    return 1;
}

/**
* Adds a node to the dynamic list.
* Input: List* l - pointer to list struct, void* value - the node value to add.
* Output: Node* - pointer to the node added
**/
Node* list_add(List* l, void* value) {
    Node* n;

    if((n = (Node*)malloc(sizeof(Node)))==0)
        return 0;

    void* v = (void*)malloc(sizeof(*value));// T: what? no. you can tell what the size of value, you should assume the value
                                            // was alloced before and the list will only hold the pointer
    v = memcpy (v, value, sizeof(*value));

    if(v==0) { // T: better use NULL define
        free(n);
        return 0;
    }

    n->value = v; // T: should be -> n->value = value
    n->_next = 0;
    n->_prev = 0;

    /* Include in the list chain */
    // T: check l is not null
    if(l->_last == 0) { /* if first */
        l->_first = n;
        n->_prev = 0;
        l->_last = n;
    }
    else { /* if not */
        n->_prev = l->_last;
        l->_last->_next = n;
        l->_last = n;

    }
    /* Update list info */
    ++l->_size;
    l->_sum+=list_getint(n);

    return n;
}

/**
* Deletes a node from the dynamic list.
* Input: List* l - pointer to list struct, Node* node - the node to delete.
* Output: int - 1 for true, 0 for false
**/
int list_delete(List *l, Node* node) { // T: check l and node are not null
    /* Exclude the node from the chain */
    if(node->_prev == 0 && node->_next == 0) { /* if the only one */
        l->_last = 0; // T: you assume node in the list, what if not? what happend if i create a node, zero it and send to this function?
        l->_first = 0;
    } 
    else if(node->_prev==0) { /* if first */
        l->_first = node->_next;
        node->_next->_prev = 0;
    } else if(node->_next == 0) { /* if last */
        l->_last = node->_prev;
        l->_last->_next = 0;
    } else { /* if not */
        node->_prev->_next = node->_next;
        node->_next->_prev = node->_prev;
    }
    /* Update information on the list struct */
    l->_sum -= list_getint(node);
    --l->_size;

    free_node(node);
}

/**
* Gets the first node of the dynamic list.
* Input: List* l - pointer to list struct
* Output: Node* the first node
**/
Node* list_first(List* l) {
    return l->_first; // T: check l is not null
}

/**
* Gets the last node of the dynamic list.
* Input: List* l - pointer to list struct
* Output: Node* the last node
**/
Node* list_last(List* l) {
    return l->_last; // T: check l is not null
}

/**
* Gets the next node in the dynamic list, from a node from the list.
* Input: Node* node - node to count from.
* Output: Node* next node after the node given in the args.
**/
Node* list_next(Node* node) {
    return node->_next; // T: check node is not null
}

/**
* Get value of a node from the list
* Input: List* l - pointer to the list, Node* node - pointer to node to get value from.
* Output: void* - the value of the node.
**/
void* list_value(Node* node) {
    return node->value; // T: check node is not null
}

/**
* Get average value of a node from the list
* Input: List* l - pointer to the list.
* Output: float - the average value.
**/
float list_average(List* l) {
    if(l==0)
        return 0;

    if(l->_size == 0)
        return 0;

    return l->_sum/(float)(l->_size);
}

/**
* List length getter.
* Input: List* l - pointer to the list.
* Output: int - the length of the list.
**/
int list_length(List* l) {
    return l->_size; // T: check l is not null
}

/**
* Frees a node.
* Input: Node* n - the node to free.
* Output: void - nothing
**/
void free_node(Node* node) {
    free(node->value);
    free(node);
}

/************* Supplement Functions (not required) ******************/

/**
* Get integer value
* Input: Node* node
* Output: int - the int value
**/
int list_getint(Node* node) {
    if(node == 0)
        return 0;
    return *(int*)list_value(node);
}

/**
* Adds a node to the dynamic list.
* Input: List* l - pointer to list struct, Node* n - the node to add.
* Output: Node* - pointer to the node added
**/
Node* list_insert(List* l, Node* n) {
    // T: check l and l are not null
    n->_next = 0;

    /* Include in the list chain */

    if(l->_last == 0) { /* if first */
        l->_first = n;
        n->_prev = 0;
        l->_last = n;
    }
    else { /* if not */
        n->_prev = l->_last;
        l->_last->_next = n;
        l->_last = n;
    }

    return n;
}


