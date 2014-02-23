#ifndef COMMON_H
#define COMMON_H

//define the flag so that some errors could be detected
#define DEBUG_F

//every function in this Package returns such type
typedef enum{
    SUCCESS,
    ERROR,
    WARNING
} status_t;

static int g_stat = SUCCESS;
//counters to know how many errors and warnings has encounterd
static int g_nWarnings = 0;
static int g_nErrors = 0;

//functions to track the errors
void raise( status_t stat, char *message );
void check_status( char *message );

//C do not have its own boolean type
typedef int bool_t;
#define TRUE    (1==1)
#define FALSE   (!TRUE)

//element type in data structures
typedef int element_t;
#define ELEM_INIT_VALUE 0

//handy macros
#define MAX(x,y)    ((x)>(y)?(x):(y))
#define MIN(x,y)    ((x)<=(y)?(x):(y))
#define ABS(x)      ((x)>0?(x):(-x))

//some conventions
#define ILLEGAL_LENGTH -1

#endif
