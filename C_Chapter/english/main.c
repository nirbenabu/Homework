/************************************************************************************
* english.c - A program that replaces words from a text file with synonyms from
* other text file, having the following format:
*  ---------------------------------
*  " <word1> <word2> <word3>"
*  " <word4> <word5> <word6>"
*   etc...
*  ---------------------------------
*  Where word1, word 2 and word 3 are synonyms,
*  And word4 word5 and word6 are also synonyms.
* PLEASE NOTICE THE SPACE IN THE BEGINNING OF EACH LINE!
* PLEASE NOTICE ALL WORDS ARE IN LOWERCASE!
*
* NOTES:
* The program does not deal with puncuation even, though it's easy to tweak it to.
* Also, the program does not take care of caps, though it's "" "" "" "" "".
* Written by NiR.
***********************************************************************************/

#include <stdio.h>
#include <string.h>

#define WRONG_ARGUMENTS (-1)
#define CANNOT_OPEN_INPUT_FILE (-2)
#define CANNOT_OPEN_OUTPUT_FILE (-3)
#define CANNOT_CLOSE_INPUT_FILE (-4)
#define CANNOT_CLOSE_OUTPUT_FILE (-5)
/* Words info */
#define LONGEST_DICTIONARY_WORD 45
#define MAX_SYNONYMS 120
/* readsection consts: */
#define READ_LINE 1
#define READ_WORD 0
/* Supplement functions */
char readsection(char* buffer, FILE* file, int flag);
void copyfile(FILE* dest, FILE* src);
void lower(char* str);

/* main */
int main(int argc, char* argv[])
{
    /******************* ARGS *******************/
    if(argc != 3)
    {
        printf("Error: invalid arguments\n Usage: english <destination> <vocabulary>\n");
        return WRONG_ARGUMENTS;
    }

    FILE* dest = NULL;
    FILE* voc = NULL;
    FILE* temp_file = NULL;

    /******************* OPEN *******************/
    dest = fopen(argv[1], "r+");
    if(dest == NULL)
    {
        printf("Error: couldn't open %s\n", argv[1]);
        return CANNOT_OPEN_INPUT_FILE;
    }

    voc = fopen(argv[2], "r");
    if(voc == NULL)
    {
        printf("Error: couldn't open %s\n", argv[2]);
        return CANNOT_OPEN_INPUT_FILE;
    }

    temp_file = fopen("tmp.txt", "w+");
    if(temp_file == NULL)
    {
      printf("Error: couldn't create a temporary file");
      return CANNOT_OPEN_OUTPUT_FILE;
    }

    /******************* DOING IT *******************/
    /* Largest voc line buffer ever needed - about 4.05 KB */
    char buffer_voc[LONGEST_DICTIONARY_WORD*MAX_SYNONYMS];
    /* Largest word buffer ever needed */
    char buffer_word[LONGEST_DICTIONARY_WORD];
    char temp[LONGEST_DICTIONARY_WORD];
    char k=0;

    while((k=readsection(buffer_word, dest, READ_WORD))!=EOF) { /* Read each word in the text */
        /* Add a space before and after the word */
      lower(buffer_word);
      sprintf(temp, " %s ", buffer_word);
      lower(temp);
      char* c = NULL;

      while(readsection(buffer_voc, voc, READ_LINE)!=EOF) { /* Check in each line of voc for the word */
        /* Add space */

        buffer_voc[strlen(buffer_voc)] = ' ';
        buffer_voc[strlen(buffer_voc)+1] = 0;

        if(strstr(buffer_voc, temp)!=NULL){ /* Is there a word to replace? */
            /* Find a synonym */
            c = strtok(buffer_voc, " ");
            /* Make sure it's not the word already used if possible */
            while(strcmp(c,buffer_word) == 0) {
              c = strtok(NULL, " ");
            }
            if(c != NULL) /* If there's a synonym - Write c */
              strcpy(buffer_word, c);

            break;
          }
        }

        /* Write to the tepmorary file */
        fprintf(temp_file, "%s ", buffer_word);
        if(k=='\n')
          fprintf(temp_file,"\n");

        fseek(voc, 0, SEEK_SET);
      }

      copyfile(dest, temp_file);

    /******************* CLOSE *******************/
    int rc = 0;

    if(0!=fclose(dest)) {
        rc = CANNOT_CLOSE_OUTPUT_FILE;
        printf("Error: couldn't close %s", argv[1]);
    }

    if(0!=fclose(voc)) {
        rc = CANNOT_CLOSE_INPUT_FILE;
        printf("Error: couldn't close %s", argv[2]);
    }

    if(0!=fclose(temp_file)) {
        rc = CANNOT_CLOSE_OUTPUT_FILE;
        printf("Error: couldn't close tmp.txt");
    }

    remove("tmp.txt");

    printf("Done!");

    return rc;
}

/**
* Reads a single line or word from file and saves it on a provided buffer.
* Input: char* buffer - the buffer to write to, FILE* file - the file to read from, flag - 0 for line; 1 for word
* Output: char - last character read
**/
char readsection(char* buffer, FILE* file, int flag)
{
    int i;
    char c='0';

    for(i=0; c!='\n'&&(flag||c!=' '); i++)
    {
        c = fgetc(file);

        if(c==EOF)
            break;

        buffer[i] = c;
    }

    buffer[i-1] = 0;

    return c;
}

/**
* Copys file src to dest
* Input: FILE* - file pointers for the destination and source files;
* Output: void - nothing
**/
void copyfile(FILE* dest, FILE* src)
{
  char c;
  fseek(src,0,SEEK_SET);
  fseek(dest, 0, SEEK_SET);

  while((c=fgetc(src))!=EOF)
  {
    fputc(c, dest);
  }
}

/**
* Lowers all string characters
* Input: char* str - the string to lower
* Output: void - none
**/

void lower(char* str)
{
  int i;
  for(i = 0; i<strlen(str); i++)
  {
    str[i] = tolower(str[i]);
  }
}
