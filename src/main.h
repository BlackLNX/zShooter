#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>



/*****************/
/*** CONSTANTS ***/
/*****************/

//Boolean:
#define TRUE 1
#define FALSE 0

//Strings:
#define HALF_CHAR  "▄"
#define RESET      "\033[0m"
#define F_BLACK    "\033[30m"
#define F_RED      "\033[31m"
#define F_GREEN    "\033[32m"
#define F_GOLD     "\033[33m"
#define F_DBLUE    "\033[34m"
#define F_DMAGENTA "\033[35m"
#define F_DCYAN    "\033[36m"
#define F_SILVER   "\033[37m"
#define F_GREY     "\033[30;1m"
#define F_ROSE     "\033[31;1m"
#define F_LIME     "\033[32;1m"
#define F_YELLOW   "\033[33;1m"
#define F_BLUE     "\033[34;1m"
#define F_MAGENTA  "\033[35;1m"
#define F_CYAN     "\033[36;1m"
#define F_WHITE    "\033[37;1m"
#define B_BLACK    "\033[40m"
#define B_RED      "\033[41m"
#define B_GREEN    "\033[42m"
#define B_GOLD     "\033[43m"
#define B_DBLUE    "\033[44m"
#define B_DMAGENTA "\033[45m"
#define B_DCYAN    "\033[46m"
#define B_SILVER   "\033[47m"
#define B_GREY     "\033[40;1m"
#define B_ROSE     "\033[41;1m"
#define B_LIME     "\033[42;1m"
#define B_YELLOW   "\033[43;1m"
#define B_BLUE     "\033[44;1m"
#define B_MAGENTA  "\033[45;1m"
#define B_CYAN     "\033[46;1m"
#define B_WHITE    "\033[47;1m"
const char* F_COLOR[16] = {F_BLACK, F_RED, F_GREEN, F_GOLD, F_DBLUE, F_DMAGENTA, F_DCYAN, 
                           F_SILVER, F_GREY, F_ROSE, F_LIME, F_YELLOW, F_BLUE, F_MAGENTA, F_CYAN, F_WHITE};
const char* B_COLOR[16] = {B_BLACK, B_RED, B_GREEN, B_GOLD, B_DBLUE, B_DMAGENTA, B_DCYAN,
                           B_SILVER, B_GREY, B_ROSE, B_LIME, B_YELLOW, B_BLUE, B_MAGENTA, B_CYAN, B_WHITE};


//Achievement-Flags:
#define fACH_CHAPTER1 0b00000000000000000000000000000001 //"GOING EQUIPPED"
#define fACH_CHAPTER2 0b00000000000000000000000000000010 //"WHAT IS THIS?!"
#define fACH_CHAPTER3 0b00000000000000000000000000000100 //"BACK TO NORMALITY"
#define fACH_CHAPTER4 0b00000000000000000000000000001000 //"FINAL SOLUTION"
#define fACH_MELEE    0b00000000000000000000000000010000 //FOUND MELEE WEAPON
#define fACH_ARCHERY  0b00000000000000000000000000100000 //FOUND ARCHERY WEAPON
#define fACH_FIREARM  0b00000000000000000000000001000000 //FOUND FIREARM WEAPON
#define fACH_ZOMBIES  0b00000000000000000000000010000000 //FOUND A ZOMBIE
#define fACH_SURVIVOR 0b00000000000000000000000100000000 //FOUND A SURVIVOR
#define fACH_BASE     0b00000000000000000000001000000000 //FOUND A BASE
#define fACH_OPONENT  0b00000000000000000000010000000000 //FOUND AN OPONENT
#define fACH_RESEARCH 0b00000000000000000000100000000000 //RESEARCH AVAILABLE
#define fACH_WALLS    0b00000000000000000001000000000000 //RESEARCHED WALLS
#define fACH_GROWFOOD 0b00000000000000000010000000000000 //RESEARCHED GROWING FOOD
#define fACH_ARMORY   0b00000000000000000100000000000000 //RESEARCHED ARMORY
#define fACH_RESERVED 0b00000000000000001000000000000000 //CURRENTLY UNUSED

//Tile-Type:
#define TILE_UNDEF 0
#define TILE_WATER 1
#define TILE_PARK 2
#define TILE_STREET 3
#define TILE_BUILDING 4

//Array-Size:
#define CHUNKS 256
#define CHARACTERS 512
#define BASES 64
#define ITEMS 64

//Data-Size:
#define NAME_LENGTH 16
#define INV_SIZE 16
#define CHUNK_WIDTH 8
#define CHUNK_HEIGHT 8

//Character-Flags:
#define fCHAR_FEMALE 1
#define fCHAR_2 2
#define fCHAR_3 4
#define fCHAR_4 8
#define fCHAR_5 16
#define fCHAR_6 32
#define fCHAR_7 64
#define fCHAR_ENEMY 128
#define NAMES 24
const char* NAMES_F[NAMES] = {"Mary", "Patricia", "Jennifer", "Linda", "Elizabeth", "Barbara", "Susan", "Jessica",
                              "Sarah", "Karen", "Nancy", "Lisa", "Betty", "Margaret", "Sandra", "Ashley",
                              "Kimberly", "Emily", "Donna", "Michelle", "Dorothy", "Carol", "Amanda", "Melissa"};
const char* NAMES_M[NAMES] = {"James", "Robert", "John", "Michael", "William", "David", "Richard", "Joseph",
                              "Thomas", "Charles", "Christopher", "Daniel", "Matthew", "Anthony", "Mark", "Donald",
                              "Steven", "Paul", "Andrew", "Joshua", "Kenneth", "Kevin", "Brian", "George"};
                              
//Base-Flags:
#define fBASE_1 1
#define fBASE_2 2
#define fBASE_3 4
#define fBASE_4 8
#define fBASE_5 16
#define fBASE_6 32
#define fBASE_7 64
#define fBASE_ENEMY 128

//Tile-Flags:
#define fTILE_DAMAGED 1
#define fTILE_2 2
#define fTILE_3 4
#define fTILE_4 8
#define fTILE_5 16
#define fTILE_6 32
#define fTILE_7 64
#define fTILE_8 128

//Item-Flags:
#define fITEM_MELEE 1
#define fITEM_BOW 2
#define fITEM_GUN 4
#define fITEM_AMMO 8
#define fITEM_MEDICS 16
#define fITEM_FOOD 32
#define fITEM_MATERIAL 64
#define fITEM_8 128

//Profession:             MGEC   (MELEE, GUNS, EVADE, CRAFTING) 0- 7= f+
#define PROF_CLERK      0x7777
#define PROF_SWORDART   0xf777
#define PROF_HUNTER     0x7f77
#define PROF_BLACKSMITH 0x777f
#define PROF_MARTIALART 0xf7f0
#define PROF_REDNECK    0x7f0f
#define PROF_SECURITY   0xff70                              
#define PROF_TRAMP      0x7007
#define PROFESSIONS 8
const char* profession_name[PROFESSIONS] = {"Clerk", "Sword Fighter", "Hunter", "Blacksmith",
                                            "Martial Arts", "Redneck", "Security", "Tramp"};
const int profession[PROFESSIONS] = {PROF_CLERK, PROF_SWORDART, PROF_HUNTER, PROF_BLACKSMITH,
                                     PROF_MARTIALART, PROF_REDNECK, PROF_SECURITY, PROF_TRAMP};

/**************/
/*** SYSTEM ***/
/**************/

#ifdef linux
  #define _NEWLINE "\n"
  #define _CLEAR   "clear"
#elif _WIN32 || WIN32
  #define _NEWLINE "\r\n"
  #define _CLEAR   "cls"
#else
  #define _NEWLINE "\r"
  #define _CLEAR   "clear"
#endif

  
  
/*************/
/*** TYPES ***/
/*************/

typedef int bool;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef long long longl;
typedef unsigned long long ulongl;

typedef struct {
    char name[NAME_LENGTH];
    ushort weight;          //10g
    uchar flags;
    uchar value;            //chance // heal // food // type
} item0;

typedef struct {
    uchar id;               //Index of item
    uchar count;            //Amount of item
    uchar value;            //Reserved
    uchar reserved;
} inventory0;

typedef struct {
    char name[NAME_LENGTH];
    int x, y;
    int team, profession;
    uchar age;              //Age 12 - 80, avg 30
    uchar wounds;           //Wounds 1/16, max 10
    uchar flags;
    uchar weapon;           //Index of inventory
    uchar melee;            //Skill 1/16, max 10
    uchar guns;             //Skill 1/16, max 10
    uchar evade;            //Skill 1/16, max 10
    uchar crafting;         //Skill 1/16, max 10
    inventory0 item[INV_SIZE];
} character0;



typedef struct {
    uchar id;               //Tile Id
    uchar enemies;          //Amount of Enemies 1/4, max 64
    uchar noise;            //Amount of noise => distance 1/4, max 64
    uchar flags;
    inventory0 item[INV_SIZE];
} tile0;

typedef struct {
    short x, y; //8x8 tiles
    tile0 tile[CHUNK_WIDTH * CHUNK_HEIGHT];
} chunk0;

typedef struct {
    char name[NAME_LENGTH];
    int x, y;
    uchar flags;
} base0;


/***************/
/*** GLOBALS ***/
/***************/

int quit = 0;                           //Game-Loop-Breaker
int w = 120, h = 30;                    //Terminal Size
int x = 0, y = 0;                       //Player-Position
int z = 1;                              //Player-Position-State
uint achievements = 0;                  //Player-Tutorial

base0           base[BASES] =      {0}; //Base-Set
character0 character[CHARACTERS] = {0}; //Character-Cache
chunk0         chunk[CHUNKS] =     {0}; //Chunk-Cache
item0           item[ITEMS] =      {0}; //Item-Set



/***************/
/*** INCLUDE ***/
/***************/

void achieve(uint);                     //events.c
int add_character(uchar, int, int);//objects.c
int add_item(const char*, uchar flags, uchar value, ushort weight); //objects.c
void clear();                           //ui.c
void do_events();                       //events.c
int number(int, int);                   //events.c
void print_achievement();               //screens.c
void print_screen();                    //screens.c
void prints(char*);                     //ui.c
void remove_character(int);             //objects.c
void resize();                          //ui.c
int user_option(char**, char**, int*);  //ui.c
void user_prompt();                     //ui.c
void welcome_screen();                  //screens.c


#include "objects.c"
#include "events.c"
#include "screens.c"
#include "ui.c"
#include "map.c"
