/**
 * @file colors.c
 */

#include "../inc/colors.h"

#ifdef NOT_WINDOWS

char* simile_colorizeString(char* dst, char* src, int size, simile_TERM_COLOR color, simile_TERM_COLOR_MOD mod) {

    char* intermediate = calloc(size, sizeof(char));
                         
    char colorCode = (((mod & simile_TERM_COLOR_MOD_BG) == simile_TERM_COLOR_MOD_BG) ? 40 : 30) + color;

    sprintf(
        intermediate, 
        "%s%s%s\033[%d%sm%s",
        ((mod & simile_TERM_COLOR_MOD_ULINE) == simile_TERM_COLOR_MOD_ULINE)
        ? "\033[4m" : "",
        ((mod & simile_TERM_COLOR_MOD_BOLD) == simile_TERM_COLOR_MOD_BOLD)
        ? "\033[1m" : "",
        ((mod & simile_TERM_COLOR_MOD_INVRT) == simile_TERM_COLOR_MOD_INVRT)
        ? "\033[7m" : "",
        colorCode,
        ((mod & simile_TERM_COLOR_MOD_BRIGHT) == simile_TERM_COLOR_MOD_BRIGHT) 
        ? ";1" : "",
        src
    );


    if(strstr(intermediate, "\033[0m") == NULL) {
        sprintf(
            dst,
            "%s\033[0m",
            intermediate
        );
        return dst;
    }

    strcpy(dst, intermediate);

    return dst;
}

#else

char* simile_colorizeString(char* dst, char* src, int size, simile_TERM_COLOR color, simile_TERM_COLOR_MOD mod) {
    strcpy(dst, src);
    return dst;
}

#endif
