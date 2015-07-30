#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

/* Define structs */

/* Node in the list */

struct node{
    void* value;        /* Pointer to value */
    struct node *_next; /* Pointer to next node */
    struct node* _prev; /* Pointer to last node */
};

typedef struct node Node;

/* The list structure */

struct list{
  Node* _first;   /* Pointer to first node */
  Node* _last;    /* Pointer to last node */
  int _size;      /* Size of the list */
  int _sum;       /* Numerical sum of the nodes */
};

typedef struct list List;

/* Function definitions */

int   list_init(List* l);                   /* Initializes       */
int   list_destroy(List* l);                /* Release           */
Node* list_add(List* l, void* value);       /* Add a node        */
int   list_delete(List *l, Node* node);     /* Delete a node     */
Node* list_first(List* l);                  /* Get first node    */
Node* list_last(List* l);                   /* Get last node     */
Node* list_next(Node* node);                /* Get next node     */
void* list_value(Node* node);               /* Get node value    */
float list_average(List* l);                /* Get value average */
int   list_length(List* l);                 /* Get list length   */

/* Not required but essential */
void free_node(Node* node);                  /* Frees a node      */

/* Supplement function */
int   list_getint(Node* node);               /* Get int value     */
Node* list_insert(List* l, Node* n);         /* Insert a node     */


#endif
