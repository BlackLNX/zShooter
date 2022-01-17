#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*****************/
/*** CONSTANTS ***/
/*****************/

#define TRUE 1
#define FALSE 0

/**************/
/*** SYSTEM ***/
/**************/

#ifdef linux
  const char* _NEWLINE = "\n";
  const char* _CLEAR = "clear";
#elif _WIN32 || WIN32
  const char* _NEWLINE = "\r\n";
  const char* _CLEAR = "cls";
#else
  const char* _NEWLINE = "\r";
  const char* _CLEAR = "clear";
#endif
  
/***************/
/*** INCLUDE ***/
/***************/

void clear();                           //ui.c
void do_events();                       //events.c
void print_screen();                    //screens.c
void prints(char*);                     //ui.c
int user_option(char**, char**, int*);  //ui.c
void user_prompt();                     //ui.c
void welcome_screen();                  //screens.c
  
#include "events.c"
#include "screens.c"
#include "ui.c"

/***************/
/*** GLOBALS ***/
/***************/

int quit = 0;
