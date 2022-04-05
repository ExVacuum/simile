
#include "../../inc/util/colors.h"

#ifdef NOT_WINDOWS

/**
 * Colorize a string using ANSI escape codes
 *
 * @param[out]  dst   The destination buffer for the colorized string
 * @param[in]   src   The source buffer of the string to be colorized
 * @param[in]   size  Size of destination buffer
 * @param[in]   color The color to make the string
 * @param[in]   mod   A bitmask of modifiers
 *
 * @return      A pointer to the destination buffer
 */
char* simile_colorizeString(char* dst, char* src, int size, simile_TERM_COLOR color, simile_TERM_COLOR_MOD mod) {

    char* intermediate = calloc(size, sizeof(char));
                         
    char colorCode = (((mod & simile_TERM_COLOR_MOD_BG) == simile_TERM_COLOR_MOD_BG) ? 40 : 30) + color;

    sprintf(
        intermediate, 
        "\033[%d%sm%s\033[0m",
        colorCode,
        ((mod & simile_TERM_COLOR_MOD_BRIGHT) == simile_TERM_COLOR_MOD_BRIGHT) 
        ? ";1" 
        : "",
        src
    );

    strcpy(dst, intermediate);
    return dst;
}

#else

/**
 * Colorize a string using ANSI escape codes
 *
 * @param[out]  dst   The destination buffer for the colorized string
 * @param[in]   src   The source buffer of the string to be colorized
 * @param[in]   color The color to make the string
 * @param[in]   mod   A bitmask of modifiers
 *
 * @return      A pointer to the destination buffer
 */
char* simile_colorizeString(char* dst, char* src, simile_TERM_COLOR color, simile_TERM_COLOR_MOD mod) {
    strcpy(dst, src);
    return dst;
}

#endif
