#include "../inc/test_colors.h"

void test_colors_rainbow(void);
void test_colors_nested(void);

void test_colors(void) {
    RUN_TEST(test_colors_rainbow);
    RUN_TEST(test_colors_nested);
}

void test_colors_rainbow(void) {
    char dst[4][32] = {0};
    
    for(
        simile_TERM_COLOR c = simile_BLACK;
        c <= simile_WHITE;
        c++
    ) {
        printf(
            "%s%s%s%s\n",
            simile_colorizeString(dst[0], "Hello, World!", 32, c, 0),
            simile_colorizeString(dst[1], "Hello, World!", 32, c, (simile_TERM_COLOR_MOD_BG)),
            simile_colorizeString(dst[2], "Hello, World!", 32, c, (simile_TERM_COLOR_MOD_BRIGHT)),
            simile_colorizeString(dst[3], "Hello, World!", 32, c, (simile_TERM_COLOR_MOD_BG | simile_TERM_COLOR_MOD_BRIGHT))
        );
    }        
    TEST_PASS();
}

void test_colors_nested(void) {
    char dst[2][32] = {0};
    for(int i = 0; i < 8; i++) {
        printf(
            "%s%s\n",
            simile_colorizeString(
                dst[0],
                simile_colorizeString(
                    dst[0],
                    "SAMPLE TEXT",
                    32,
                    i,
                    0
                ),
                32,
                7-i,
                simile_TERM_COLOR_MOD_BG
            ),
            simile_colorizeString(
                dst[1],
                simile_colorizeString(
                    dst[1],
                    "SAMPLE TEXT",
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
    TEST_PASS();
}
