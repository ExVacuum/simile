#include "../inc/test_colors.h"

void test_colors(void) {
    RUN_TEST(test_colors_rainbow);
}

void test_colors_rainbow(void) {
    simile_TERM_COLOR_MOD mod = 0;
    char dst[32] = {0};
    
    for(
        simile_TERM_COLOR c = simile_BLACK;
        c <= simile_WHITE;
        c++
    ) {
        simile_colorizeString(dst, "Hello, World!", c, mod);
        printf("%s\n", dst);
    }

    mod = simile_TERM_COLOR_MOD_BRIGHT;

    for(
        simile_TERM_COLOR c = simile_BLACK;
        c <= simile_WHITE;
        c++
    ) {
        simile_colorizeString(dst, "Hello, World!", c, mod);
        printf("%s\n", dst);
    }

    mod = simile_TERM_COLOR_MOD_BG;

    for(
        simile_TERM_COLOR c = simile_BLACK;
        c <= simile_WHITE;
        c++
    ) {
        simile_colorizeString(dst, "Hello, World!", c, mod);
        printf("%s\n", dst);
    }

    mod = (simile_TERM_COLOR_MOD_BRIGHT | simile_TERM_COLOR_MOD_BG);

    for(
        simile_TERM_COLOR c = simile_BLACK;
        c <= simile_WHITE;
        c++
    ) {
        simile_colorizeString(dst, "Hello, World!", c, mod);
        printf("%s\n", dst);
    }

    
    TEST_ASSERT(1);
}
