/**************************************************
* life.c - A game of life implementation          *
* based on life.h interface; no UI                *
* is presented except using the standart output   *
* by default console presentation.                *
* Each cell is of type Cell (enum), having ALIVE  *
* or DEAD as states.                              *
* Written by NiR.                                 *
**************************************************/

#include <stdio.h>
#include "life.h"

#if !defined(NULL)
#define NULL ((void*)0)
#endif

/**
* Count neighbours alive; A STATIC FUNCTION.
* Input: l - pointer to life struct; x - width array position; y - height array position;
* Output: int - the requested number.
**/
static int _neighbours_alive(Cell** board, int x, int y, int width, int height) { /* BEWARE OF MAKING A SEGMENTATION FAULT! */
                    /* T: why not send to function life struct instead of all his data?
                     * S: Because someone might want to implement his own version of life, maybe a copy of mine
                     *    but with different rules etc... either way you get more flexibility for example
                     *    making the GUI follow you each step and coloring the neighbours or something (of course this
                     *    would require us to make it non static). */

  int i,k,res = 0; /* iterators */

  for(i=-1; i<2; i++)
  {
      for(k=-1; k<2; k++)
      {
        if(!((i==0 && k==0) || (x+i)<0 || (x+i)>=width || (y+k)>=height || (y+k)<0)) {
            if(board[x+i][y+k]==ALIVE) {
                ++res;
            }
        }
      }
  }

  return res;
}

/**
* Makes a 2D game board.
* Input: width & height - board dimentions.
* Output: The board as a Cell array.
**/
static Cell** _make_board(int width, int height) {
  int i; /* iterator */
  Cell** board = (Cell**)malloc(width*sizeof(Cell*));
  for(i=0; i<width; i++) {
    board[i] = (Cell*)malloc(height*sizeof(Cell));
  }

  return board;
}

/**
* Frees the board array
* Input: board array (Cell** or Cell[][]), width - the board width.
* Output: void - nothing.
**/
static void _free_board(Cell** board, int width) {
  /* Free each Cell* of width seperately */
  int i;

  for(i=0; i < width; i++) {
    free(board[i]);
  }

  free(board);
}

/**
* Checks if the board is valid.
* Input: board - the Cel** board, width & height - the board dimentions.
* Output: int - 1 for yes; 0 - for no.
**/
static int _check_board(Cell** board, int width, int height)
{
  int i, j; /* iterators */
  int res = 1;

  for(i=0; i<width; i++) {
    for(j=0; j<height; j++){
      if(board[i][j]!=ALIVE && board[i][j]!=DEAD) {
        res = 0;
      }
    }
  }

  return res;
}

/**
* Initializes a new Conway's Game of Life game.
* Input: l - pointer to a Life struct, width & height - board size parameters, board - a board to import;
*             The board must be a Cell two dimentional array containing ALIVE or DEAD values; (int: 0 or 1)
*             Setting the board to NULL will generate a new empty board.
* Output: int - 1 for success; 0 for error.
**/
int life_init(Life* l, int width, int height, Cell** board) {
  /* T: check also for MAX values
     S: there are no MAX values lol, dynamically allocated board. */
  if(!(width > 0 && height > 0))
    return 0;
  if(l == NULL)
    return 0;

  /* Reset everything */
  l->_generation = 0;
  l->_width = width;
  l->_height = height;
  /* Take care of board */
  if(board == NULL) {
    l->_board = _make_board(width, height);
    life_clear(l);
  } else if (_check_board(board,width, height)){
    l->_board = board;
  }
  else
    return 0;

  return 1;
}

/**
* Generates next generation
* Input: l - the life struct.
* Output: int - current generation number.
**/
int life_advance(Life* l) {
  int i, j; /* iterators */r
  if(l == NULL)
    return 0;

  ++(l->_generation);
  Cell** temp = _make_board(l->_width, l->_height); /* The next generation board */

  for(i=0; i< (l->_width); i++) {
    for(j=0; j< (l->_height); j++) {
      /* Game of Life logic */
      int neighbours = _neighbours_alive(l->_board, i,j,l->_width, l->_height);

      if(l->_board[i][j] == DEAD && neighbours == 3) { /* A dead cell with exactly three live neighbors becomes a live cell (birth). */
        temp[i][j] = ALIVE;
      }
      else if(l->_board[i][j] == ALIVE && (neighbours == 2 || neighbours == 3)) { /* A live cell with two or three live neighbors stays alive (survival). */
        temp[i][j] = ALIVE;
      }
      else /* In all other cases, a cell dies or remains dead (overcrowding or loneliness). */
        temp[i][j] = DEAD;
    }
  }

  _free_board(l->_board, l->_width);
  l->_board = temp;

  return l->_generation;
}

/**
* Print the game board
* Input: l - the life struct, output - output device; default - console.
* Output: int - 1 for OK, 0 for ERROR
**/
int life_print(Life* l, FILE* output) {
  int i, j, k; /* Iterators */
  char r; /* For file operations output */

  if(l==NULL)
    return 0;

  if(output == NULL)
    output = stdout;

  /* create top line */
  for(k = 0; k<l->_width*2; k++) {
    r = fputc('-',output);
    if(r==EOF)
      break;
  }

  if(r==EOF)
    return 0;

  if(fputc('\n',output)==EOF)
    return 0;

  for(i=0; i<l->_width; i++) {
    for(j=0; j<l->_height; j++) {
      if((r = fprintf(output, "%c|", (l->_board[i][j]==ALIVE)?'*':' '))==EOF)
        break;
    }

    if(r==EOF)
      return 0;
    /* create bottom line */
    if(fputc('\n',output)==EOF)
      return 0;

    for(k = 0; k<l->_width*2; k++)
      if((r=fputc('-',output))==EOF)
        break;

    if(r==EOF)
      return 0;

    if(fputc('\n',output)==EOF)
      return 0;
      
  }
    return 1;
}

/**
* Give you the board array; int values: 1 - alive; 0 - dead;
* Input: l - life struct
* Output: char** - the array;
**/
Cell** life_board(Life* l) {
  return l->_board;
}

/**
* Clears the board entirely
* Input: l - the life struct
* Output: int - 1 for success; 0 for error.
**/
int life_clear(Life* l) {
  int i, j; /* Iterators */

  for(i=0; i < (l->_width); i++) {
    for(j=0; j < (l->_height); j++) {
      l->_board[i][j]=DEAD;
    }
  }

  l->_generation = 0;
}

/**
* Gives the current generation number (starting from 0)
* Input: l - the life struct
* Output: int - the generation number
**/
int life_generation(Life* l) {
  return l->_generation;
}

/**
* Sets a cell of location x,y; value - the value to assign; xE[0,width-1]; yE[0, height-1].
* Input: l - the life struct, x - position along width array, y - position along height array.
* Output: int - 1 for success; 0 for error.
**/
int life_set(Life* l, int x, int y, Cell value) {
  if(value==0 || value == 1) {
    l->_board[x][y] = value;
    return 1;
  }

  return 0;
}

/**
* Toggle cell value
* Input: l - pointer to life struct, x&y - position
* Output: int - 1 success; 0 error
**/
int life_toggle(Life* l, int x, int y) {
  return life_set(l, x,y, l->_board[x][y] == DEAD);
}

/**
* Cleans the struct and frees everything; NOTICE: the board WILL BE FREED! EVEN IF ITS EXTERNAL!
* Input: l - life struct
* Output: void - nothing
**/
void life_destroy(Life* l) {
  _free_board(l->_board, l->_width);
  l->_width = 0;
  l->_height = 0;
  l->_generation = 0;
}
