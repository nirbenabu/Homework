#if !defined(_LIFE_H_)
#define _LIFE_H_

#include <stdio.h>

/* The fact that the cell is enum helps us to use binary system of "alive" "dead" states as 1 and 0 */
enum cell {
  DEAD, ALIVE
};

typedef enum cell Cell;

struct gol {
  Cell** _board;
  int _generation;
  int _width, _height;
};

typedef struct gol Life;

int life_init(Life* l, int width, int height, Cell** board); /* Set board NULL to generate an empty one; What a simulation theory title */
int life_advance(Life* l); /* Calculate next generation */
void life_print(Life* l, FILE* output); /* Print it to whatever output device you want */
Cell** life_board(Life* l); /* Get the array */
int life_clear(Life* l); /* Clears the board */
int life_generation(Life* l); /* Get current generation */
int life_set(Life* l, int x, int y, Cell value); /* Set cell value */
int life_toggle(Life* l, int x, int y); /* Toggle cell value */
void life_destroy(Life* l); /* Release */

/* Supplement static functions */
static int _neighbours_alive(Cell** board, int x, int y, int width, int height);
static Cell** _make_board(int width, int height);
static void _free_board(Cell** board, int width);
static int _check_board(Cell** board, int width, int height);

#endif
