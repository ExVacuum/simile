#include <criterion/criterion.h>
#include "../inc/expected.h"
#include "../../inc/colors.h"
#include "base64.h"

void initColors(void) {
    initExpectations("colors");
}

void finiColors(void) {
    freeExpectations();
}

TestSuite(colors, .init = initColors, .fini = finiColors);

Test(colors, rainbow) {

    const char** expected = NULL;
    cr_assert((expected = getExpectedResult("rainbow")) != NULL);

    char result[10000] = {0};
    char dst[32][64] = {0};
   
    char* msg = " シミリー ";
    
    size_t offset = 0;
    for(
        simile_TERM_COLOR c = simile_BLACK;
        c <= simile_WHITE;
        c++
    ) {
        for(int mod = 0; mod <= (simile_TERM_COLOR_MOD_BG | simile_TERM_COLOR_MOD_BRIGHT | simile_TERM_COLOR_MOD_ULINE | simile_TERM_COLOR_MOD_BOLD | simile_TERM_COLOR_MOD_INVRT); mod++) {
            offset += sprintf(result + offset, "%s", simile_colorizeString(dst[mod], msg, 64, c, mod));
            if(mod % 4 == 3) {
                offset += sprintf(result + offset, "\n");
            }
        }
    }       
    uint64_t expbinlen = 0; 
    char* expbin = (char*)base64_decode((uint8_t*)expected[0], strlen(expected[0]), &expbinlen);
    cr_assert(strncmp(expbin, result, expbinlen) == 0);
}

Test(colors, nesting) {

    char* test = " シミリー ";
    const char** expected = NULL;
    cr_assert((expected = getExpectedResult("nesting")) != NULL);

    char result[1024] = {0};
    char dst[2][64] = {0};
    size_t offset = 0;
    for(int i = 0; i < 8; i++) {
        offset += sprintf(
            result + offset,
            "%s",
            simile_colorizeString(
                dst[0],
                simile_colorizeString(
                    dst[0],
                    test,
                    64,
                    i,
                    simile_TERM_COLOR_MOD_ULINE 
                ),
                64,
                7-i,
                simile_TERM_COLOR_MOD_BG
            )
        );
        offset += sprintf(
            result + offset,
            "%s\n",
            simile_colorizeString(
                dst[1],
                simile_colorizeString(
                    dst[1],
                    test,
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
    uint64_t expbinlen = 0; 
    char* expbin = (char*)base64_decode((uint8_t*)expected[0], strlen(expected[0]), &expbinlen);
    cr_assert(strncmp(expbin, result, expbinlen) == 0);
}
