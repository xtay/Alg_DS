#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void raise( status_t stat, char *message )
{
    if( stat == WARNING ){
        printf("\n>>>WARNING: %s\n", message );
        g_nWarnings++;
        if(g_stat <= WARNING) g_stat = stat;
    }
    else if( stat == ERROR ){
        printf("\n>>>ERROR: %s\n", message );
        g_nErrors++;
        g_stat = ERROR;
        if(g_stat <= ERROR) g_stat = stat;
    }
    
    return;
}

void check_status( char *message )
{
#ifdef DEBUG_F
    printf("\n-------------------------------------------------");
    printf("\n***%d WARNINGS occured since last check\n", g_nWarnings);
    printf("***%d ERRORS occured since last check\n", g_nErrors);

    char command;
    //if something wrong with the last stat
    if(g_stat == WARNING){
        printf("\n***There is a WARNING!\n");
        printf("***what do you prefer?['y': continue; 'n': exit]");

        command = getchar();
        if( command == 'y' || command == 'Y' ){
            return;
        }
        else{
            printf("\n***program exit halfway!\n");
            exit(WARNING);
        }
    }
    else if(g_stat == ERROR){
        printf("\n***There is an ERROR!\n");

        printf("\n***program exit halfway!\n");
        exit(ERROR);
    }
    //if last stat is a SUCCESS, check about the history.
    else{
        printf("\n***Everything is alright!\n\n");
    }

    g_nWarnings = 0;
    g_nErrors = 0;
    printf("-------------------------------------------------\n\n");
#endif
    return;
}
