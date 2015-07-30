/*************************************
* cmd_interface.c - a command line interface
* for my game of life implementation.
* No cleaning of screen & using scanf in order to 
* keep the code cross platfrom                    
* (debugged with linux)                           
* Usage: life <width> <height>
*************************************/

#include <stdio.h>
#include <string.h>
#include "life.h"

/* error consts */
#define BAD_ARGS (-1)
#define BAD_INIT (-2)

void set(Life* l); /* Handles the set interaction */
void advance(Life* l); /* Handles the advance interaction */

/* main */
int main(int argc, char* argv[])
{
  /* args */
  if(argc != 3) {
    printf("ERROR: invalid arguments.\n\tUsage: life <width> <height>\n");
    return BAD_ARGS;
  }

  /* get board size from commandline */
  int width = atoi(argv[1]);
  int height = atoi(argv[2]);

  Life l;
  /* init */
  if(life_init(&l,width, height, NULL) != 0)
    printf("INIT OK!\n");
  else {
    printf("BAD INIT!\n");
    return BAD_INIT;
  }


  char c =' ';

  while(c!='q'&&c!='Q') {
    printf("\n\n");
    life_print(&l, 0); /* print board to console */
    printf("generation: %d\n", life_generation(&l));
    printf("press S for setting the board; C to clean the board; A to advance; Q to quit.\n");
    scanf("%c", &c);
    if(c=='s'||c=='S')
      set(&l);
    if(c=='a' || c=='A')
      advance(&l);
    if(c=='C' || c=='c'){
      printf("Are you sure you want to clear the board? y/n ");
      getchar(); /* to fix that motherfu**ing \n problem of the stupid scanf */
      scanf("%c", &c);
      if(c=='y' || c=='Y')
        life_clear(&l);
    }
  }

  life_destroy(&l);
  printf("\nDESTROYED!\n");

  return 0;
}

/**
* Lets the user set the board for his liking.
* Input: l - pointer to the life struct
* Output: void -none
**/
void set(Life* l) {
  int x = 0, y = 0;
  char buffer[11*2]; /* largest int32 digits x 2 */
  char* temp;

  while(x!=-1 && y!=-1) {
    life_print(l, 0);
    printf("\n\n");
    printf("To set a cell please provide the next format: <x position> <y position>\n this will toggle the selected cell state.\nto quit enter -1 in both x & y\n");
    scanf("%d %d", &x, &y);
    if(x<=0 || y<=0 || x> l->_width || y> l->_height) {
      printf("Bad position! Try again:\n");
    } else{
      life_toggle(l,x-1,y-1);
    }
  }

}

/**
* Lets the user advance
* Input: l - pointer to life struct
* Output: void - nothing
**/
void advance(Life* l)
{
    int n, i;
    printf("Enter number of generations to simulate: ");
    scanf("%d", &n);
    printf("\n",n);

    for(i=0; i<n; i++) {
        printf("generation %d ----------------------", life_advance(l));
        life_print(l,0);
        /* You may put a sleep function to control speed; I won't do it in order to keep code cross-platform */
    }

    printf("-------------------------------");
}

