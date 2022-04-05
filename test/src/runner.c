#include <unity/unity.h>

#include "../inc/test_colors.h"
#include "../inc/test_simile.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

int main(void) {
    UNITY_BEGIN();
    test_simile();
    test_colors();
    return UNITY_END();
}
