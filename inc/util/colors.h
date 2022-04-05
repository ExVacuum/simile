/**
 * @file colors.h
 */

#ifndef SIMILE_COLOR_H
#define SIMILE_COLOR_H

#include <stdio.h>
#include <string.h>

/// Available ANSI terminal colors
typedef enum {
    simile_BLACK,
    simile_RED,
    simile_GREEN, 
    simile_YELLOW,
    simile_BLUE,
    simile_MAGENTA,
    simile_CYAN,
    simile_WHITE
} simile_TERM_COLOR;

/// Availble ANSI terminal color modifiers
typedef enum {
    simile_TERM_COLOR_MOD_BG        = 0b01, //!< Set color background
    simile_TERM_COLOR_MOD_BRIGHT    = 0b10  //!< Use bright color
} simile_TERM_COLOR_MOD;

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
extern char* simile_colorizeString(char* dst, char* src, simile_TERM_COLOR color, simile_TERM_COLOR_MOD mod);

#endif
