/*****************************************************************************
PURPOSE:    ( Process Temperature )
*****************************************************************************/
#include <stdio.h>
#include "../include/temperature.h"

int temp_process( TEMP* T ) {

    T->temp += 1;
    if (T->temp > 255) {
        T->temp = 0;
        fprintf(stderr,"temp check\n");
    }
    if (T->reset_flag) {
        fprintf(stderr,"temp reset\n");
        T->temp = 0;
    }
    return 0;
}

void temp_display( TEMP* T )
{
    printf("Temp: %d\n", T->temp );
}