#include <criterion/criterion.h>
#include "../../inc/colors.h"

void initColors(void) {
}

void finiColors(void) {
}

TestSuite(colors, .init = initColors, .fini = finiColors);

Test(colors, rainbow) {
    char result[1024] = {0};
    char dst[32][32] = {0};
   
    char* msg = " シミリー ";

    for(
        simile_TERM_COLOR c = simile_BLACK;
        c <= simile_WHITE;
        c++
    ) {
        for(int mod = 0; mod <= (simile_TERM_COLOR_MOD_BG | simile_TERM_COLOR_MOD_BRIGHT | simile_TERM_COLOR_MOD_ULINE | simile_TERM_COLOR_MOD_BOLD | simile_TERM_COLOR_MOD_INVRT); mod++) {
            sprintf(result, "%s", simile_colorizeString(dst[mod], msg, 32, c, mod));
            if(mod % 4 == 3) {
                sprintf(result, "\n");
            }
        }
    }        
}

Test(colors, nesting) {
    char result[1024] = {0};
    char dst[2][32] = {0};
    for(int i = 0; i < 8; i++) {
        sprintf(
            result,
            "%s",
            simile_colorizeString(
                dst[0],
                simile_colorizeString(
                    dst[0],
                    " シミリー ",
                    32,
                    i,
                    simile_TERM_COLOR_MOD_ULINE 
                ),
                32,
                7-i,
                simile_TERM_COLOR_MOD_BG
            )
        );
        sprintf(
            result,
            "%s\n",
            simile_colorizeString(
                dst[1],
                simile_colorizeString(
                    dst[1],
                    " シミリー ",
                    32,
                    7-i,
                    0
                ),
                32,
                i,
                (simile_TERM_COLOR_MOD_BG | simile_TERM_COLOR_MOD_BRIGHT)
            )

        );
    }
    cr_assert(1);
}
