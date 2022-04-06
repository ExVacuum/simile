/**
 * @file colors.h
 */

#ifndef SIMILE_COLOR_H
#define SIMILE_COLOR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/// Available ANSI terminal colors
typedef enum {
    simile_BLACK, //!< ANSI Color 0
    simile_RED, //!< ANSI Color 1
    simile_GREEN,  //!< ANSI Color 2
    simile_YELLOW, //!< ANSI Color 3
    simile_BLUE, //!< ANSI Color 4
    simile_MAGENTA, //!< ANSI Color 5
    simile_CYAN, //!< ANSI Color 6
    simile_WHITE //!< ANSI Color 7
} simile_TERM_COLOR;

/// Availble ANSI terminal color modifiers
typedef enum {
    simile_TERM_COLOR_MOD_BG        = 0b00001,  //!< Set color background
    simile_TERM_COLOR_MOD_BRIGHT    = 0b00010,  //!< Use bright color
    simile_TERM_COLOR_MOD_ULINE     = 0b00100,  //!< Underline
    simile_TERM_COLOR_MOD_BOLD      = 0b01000,  //!< Bold
    simile_TERM_COLOR_MOD_INVRT     = 0b10000  //!< Inverted Terminal Base Color
} simile_TERM_COLOR_MOD;

/**
 * Colorize a string using ANSI escape codes
 *
 * @param[out]  dst   The destination buffer for the colorized string
 * @param[in]   src   The source buffer of the string to be colorized
 * @param[in]   size  The size of the destination buffer
 * @param[in]   color The color to make the string
 * @param[in]   mod   A bitmask of modifiers
 *
 * @return      A pointer to the destination buffer
 */
extern char* simile_colorizeString(char* dst, char* src, int size, simile_TERM_COLOR color, simile_TERM_COLOR_MOD mod);

#endif
