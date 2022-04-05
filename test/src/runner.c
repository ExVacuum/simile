#include <unity/unity.h>

#include "../../inc/simile.h"

#include "../inc/test_simile.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_hello);
    return UNITY_END();
}
